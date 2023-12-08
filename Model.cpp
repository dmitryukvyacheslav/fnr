#include "Model.h"

Model::Model(
	std::string in="input.txt",
	std::string out="output.txt"
):
	inputfile(in),
	outputfile(out)
{

	std::ifstream infile;
	infile.open(in);
	if (!infile.is_open()) {
		perror("could not open input file");
		return;
	}
	// Cols Rows Steps          Dirc
	// nRab nFox                0 - UP 
	// RabX RabY Dirc Stab      1 - RIGHT 
	// ...                      2 - DOWN 
	// FoxX FoxY Dirc Stab      3 - LEFT
	// ... 
	infile >> this->m_width;
	infile >> this->m_height;
	infile >> this->m_steps;
	infile >> this->m_nRabbits;
	infile >> this->m_nFoxes;
	printf("constructing model %dx%d[%d stps] r:%d f:%d\n", 
		this->m_width,
		this->m_height,
		this->m_steps,
		this->m_nRabbits,
		this->m_nFoxes);
	int r_x, r_y, r_s, r_d;
	for (int i = 0; i < m_nRabbits; i++) {
		infile >> r_x;
		infile >> r_y;
		infile >> r_d;
		infile >> r_s;
		
		addR(r_x, r_y, r_s, r_d);
	}
	for (int i = 0; i < m_nFoxes; i++) {
		infile >> r_x;
		infile >> r_y;
		infile >> r_d;
		infile >> r_s;
		
		addF(r_x, r_y, r_s, r_d);
	}
	printf("done constructing\n");
	infile.close();
}


void Model::addR(int x, int y, int s, int dir)
{
	masR.push_back(Rabbit(x, y, s, dir));
}

void Model::addF(int x, int y, int s, int dir)
{
	masF.push_back(Fox(x, y, s, dir));
}

void Model::step() {
	//Движение зайцев
	for (Rabbit& rabbit : masR) {
		rabbit.move();
		auto pos = rabbit.getPosition();
		if (pos.x > m_width) pos.x %= (m_width-1);
		if (pos.y > m_width) pos.y %= (m_height-1);
		if (pos.x < 0) pos.x = m_width+pos.x;
		if (pos.y < 0) pos.y = m_height+pos.y;
		rabbit.setPosition(pos);
	}
	//Движение лис
	for (Fox& fox : masF) {
		fox.move();
		auto pos = fox.getPosition();
		if (pos.x > m_width) pos.x %= (m_width - 1);
		if (pos.y > m_width) pos.y %= (m_height - 1);
		if (pos.x < 0) pos.x = m_width + pos.x;
		if (pos.y < 0) pos.y = m_height + pos.y;
		fox.setPosition(pos);
	}
	// Питание лис
	// проход по всем кроликам
	for (Rabbit& rabbit : masR) {
		Fox* oldestFox = nullptr;
		auto posR = rabbit.getPosition();
		// поиск старшей лисы в клетке
		for (Fox& fox : masF) {
			auto posF = fox.getPosition();
			if (posR.x == posF.x && posR.y == posF.y) {
				if (oldestFox == nullptr || (oldestFox->getAge() > fox.getAge()))
					oldestFox = &fox;
			}
		}
		// а есть ли в клетке с ней еще кролики?
		if (oldestFox != nullptr) {
			auto posF = oldestFox->getPosition();
			for (int i = 0; i < masR.size(); i++) {
				auto posR = masR.at(i).getPosition();
				if (posR.x == posF.x && posR.y == posF.y) {
					// Схавали бедолагу.
					// удаление кролика
					// добавление насыщенности
					oldestFox->addSaturation();
					masR.erase(masR.begin() + i);
					i--;
				}
			}
		}
	}
	//Размножение и смерть
	for (int i = 0; i < masF.size(); i++) {
		if (masF.at(i).getSaturation() >= 2) {
			masF.at(i).resetSaturation();
			masF.push_back(masF.at(i));
		}
		if (masF.at(i).isDying()) {
			masF.erase(masF.begin() + i);
			i--;
		}
	}
	//Размножение и смерть
	for (int i = 0; i < masF.size(); i++) {
		if (masR.at(i).canReproduce()) 
			masR.push_back(masR.at(i));
		if (masR.at(i).isDying()) {
			masR.erase(masR.begin() + i);
			i--;
		}
	}
}

// Метод вывода результата(выходной файл)
void Model::write() {
	for (int i = 0; i < m_steps; i++)
		step();

	// alloc
	int** mas = new int* [m_height];
	for (int i = 0; i < m_height; ++i)
		mas[i] = new int[m_width];

	// init
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			mas[i][j] = 0;

	for (Rabbit& r : masR) {
		auto pos = r.getPosition();
		mas[pos.y][pos.x]++;
	}
	for (Fox& f : masF) {
		auto pos = f.getPosition();
		mas[pos.y][pos.x]--;
	}

	std::ofstream outfile;
	outfile.open(outputfile);
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
			mas[i][j] ? outfile << mas[i][j] : outfile << "*";
		outfile << "\n";	
	}
	
	for (int i = 0; i < m_height; ++i)
		delete mas[i];
	delete mas;

	outfile.close();
}

// Деструктор
Model::~Model() {
	// Дестрой векторов
	masF.clear();
	masR.clear();
}


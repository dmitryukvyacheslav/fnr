#pragma once
#include <vector>
class Model
{
	int width;
	int height;
	int steps;

	// геттер и сеттер на эти поля
	vector<Fox> masF;
	vector<Rabbit> masR;
	int** mas;

	// Метод добавления зайцев
	void addR(int x, int y, int s, int dir)
	{
		masR.push_back(Rabbit(x, y, s, dir));
		mas[x][y] += 1;
	}

	// Метод добавления лис
	void addF(int x, int y, int s, int dir)
	{
		masF.push_back(Rabbit(x, y, s, dir));
		mas[x][y] += -1;
	}
	
	// Метод Шаг
	void step() {
		//Движение зайцев
		//Движение лис и питание
		//Смена направления
		//Старение
		//Размножение
		//Вымирание
	}
	
	// Метод вывода результата(выходной файл)
	void write() {
	}
	
	// Деструктор
	~Model() {

	}
};


#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Fox.h"
#include <algorithm>

#include "Rabbit.h"
class Model
{
	std::string inputfile;
	std::string outputfile;

	int m_width;
	int m_height;
	int m_steps;
	int m_nFoxes, m_nRabbits;
	// геттер и сеттер???? на эти поля
	std::vector<Fox> masF;
	std::vector<Rabbit> masR;

public:
	Model(std::string infile, std::string outfile);
	void addR(int x, int y, int s, int dir);
	void addF(int x, int y, int s, int dir);
	void addF(Fox& fox);
	void addR(Rabbit& rabbit);
	void step();
	void write();
	~Model();
};
#pragma once
#include <cstdlib>
#include <ctime>
ref class cuervo
{
public:
	int destruye;
	int comeFruto;
	int probabilidad;
	int row = 0;
	int col = 0;
	cuervo() {
		srand(static_cast<unsigned int>(time(nullptr)));
		this->row = rand() % 7;
		this->col = rand() % 7;
	}

};


ref class oveja
{
public:
	int destruye;
	int comeFruto;
	int probabilidad;
	int row;
	int col;

	oveja() {
		srand(static_cast<unsigned int>(time(nullptr)));
		this->row = rand() % 7;
		this->col = rand() % 7;
	
	}

};


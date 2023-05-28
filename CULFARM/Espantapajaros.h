#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;


#pragma once
ref class Espantapajaros
{
public: 
	int id;
	int x;
	int y;
	int costo;
	BackgroundWorker^ ThreadEspantapajaros;

	Espantapajaros() {

	}
};


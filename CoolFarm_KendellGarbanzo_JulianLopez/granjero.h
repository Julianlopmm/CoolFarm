#pragma once
#include "arbolSplay.cpp"
#include "Espantapajaros.h"
#include <list>
#include <vcclr.h>

ref class granjero
{
	
public:
	int dinero = 200;
	int arbolesBinarios = 10;
	int arbolesAVL = 10;
	int arboleSplay = 100;
	int arbolesHeap = 10;
	//int splay = 0;
	int espantapajaros = 15;
	int cantidadActualEspantapajaros = 0;

	// Variables que cambian según la configuración
	int tiempoDeCosecha = 0;
	int precioTienda = 0;
	int tiempoDePlagas = 0;
	int probabilidadDePlagas = 0;

	String^ nombre = "";
	int puntaje = 0;



	List<SplayTree^>^ ListaSplay = gcnew List<SplayTree^>();
	List<Heap_tree^>^ ListaHEAP = gcnew List<Heap_tree^>();
	List<AVLTree^>^ ListaAVL = gcnew List<AVLTree^>();
	List<BinarySearchTree^>^ ListaBinario = gcnew List<BinarySearchTree^>();
	List<Espantapajaros^>^ ListaEspantapajaros = gcnew List<Espantapajaros^>();
	granjero(){};

};





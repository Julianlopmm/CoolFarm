#pragma once

#include <Windows.h>
#include <string>
#include "granjero.h"
#include "Mercado.h"
#include "CaracteristicasArbol.h"
#include "Configuracion.h"
#include "top10Ventana.h"
#include <thread>
#include "plaga.h"
using namespace System;
using namespace System::IO;
namespace CULFARM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		array<Button^, 2>^ buttonGrid;
		cli::array<int, 2>^ matriz = gcnew cli::array<int, 2>(8, 8);
		granjero^ g = gcnew granjero();
		cli::array<bool, 2>^ matrizbool = gcnew cli::array<bool, 2>(8, 8);
		int precioxdxd = 0;
		String^ rutaArchivo = "C:\\Users\\Juli\\Desktop\\Proyecto COOLFARM\\CULFARM\\top10.txt";
		oveja^ ovejas = gcnew oveja();
		cuervo^ cuervos = gcnew cuervo();
	


	private: System::Windows::Forms::Button^ button6;
	public: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	public: System::Threading::Thread^ threadOvejasSplay;
	public: System::Threading::Thread^ threadCuervos;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Button^ button7;
	public:
		Mercado^ ventanaSecundaria = gcnew Mercado();
		


	private: System::Windows::Forms::Button^ botonEspantapajaros;
	private: System::Windows::Forms::Button^ botonConfiguracion;
	private: System::Windows::Forms::Button^ button8;
	public:
		CaracteristicasArbol^ ventanaArbol = gcnew CaracteristicasArbol();
		Configuracion^ ventanaConfiguracion = gcnew Configuracion();
		top10Ventana^ ventanaTop10 = gcnew top10Ventana();


		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//backgroundWorker1->RunWorkerAsync();
			backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);

			threadOvejasSplay = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::metodoOvejasSplay));
			threadCuervos = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::metodoCuervos));
			
			//Establecer los botones como false antes de empezar
			botonEspantapajaros->Enabled = false;
			button2->Enabled = false;
			button3->Enabled = false;
			button4->Enabled = false;
			button5->Enabled = false;
			button6->Enabled = false;



			matriz[5, 5] = 1;
			int rows = 8;    // Número de filas
			int cols = 8;    // Número de columnas

			buttonGrid = gcnew array<Button^, 2>(rows, cols);

			for (int row = 0; row < rows; ++row)
			{
				for (int col = 0; col < cols; ++col)
				{
					buttonGrid[row, col] = gcnew Button();
					//buttonGrid[row, col]->Text = String::Format("xd");
					if (matriz[row, col] == 1) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Red;
					}
					else if (matriz[row, col] == 2) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Black;
					}

					else if (matriz[row, col] == 3) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Yellow;
					}
					else if (matriz[row, col] == 4) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Pink;
					}
					else if (matriz[row, col] == 5) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Cyan;
					}
					else if (matriz[row, col] == 6) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Brown;
					}
					else if (matriz[row, col] == 7) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Purple;
					}
					else if (matriz[row, col] == 8) {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Orange;
					}
					else {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Green;
					}
					buttonGrid[row, col]->Click += gcnew EventHandler(this, &MyForm::Button_Click);
					buttonGrid[row, col]->Enabled = false;

					// Agregar el botón al TableLayoutPanel
					tableLayoutPanel1->Controls->Add(buttonGrid[row, col], col, row);
				}
			}



			for (int i = 0; i < matrizbool->GetLength(0); i++)
			{
				for (int j = 0; j < matrizbool->GetLength(1); j++)
				{
					matrizbool[i, j] = false;
				}
			}

			/*
			

			*/



			// Crear y configurar los botones





		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	public: System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label2;

	public:


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button65;
	private: System::Windows::Forms::Button^ button1;
private: System::ComponentModel::IContainer^ components;



	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		/// 
		/// 
		/// 
		/// 
		/// 
		/// 



		void Button_Click(Object^ sender, EventArgs^ e)
		{
			
			Button^ button = dynamic_cast<Button^>(sender);


			int row = -1;
			int col = -1;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (buttonGrid[i, j] == button)
					{
						row = i;
						col = j;
						break;
					}
				}
			}

			int tipo;
			int p = 0;
		


			
		if (matriz[row, col] == 2) {
				tipo  = 2;
			
		}
		else if (matriz[row, col] == 3) {
			tipo = 3;
	
		}
		else if (matriz[row, col] == 4) {
		tipo = 4;
	

		}
		else if (matriz[row, col] == 5) {
			tipo = 5;

		}
			
		//busca en la lista splay el arbol que tiene en x e y los mismos valores que row y col
		//si lo encuentra, muestra la ventana con las caracteristicas del arbol







			//if (ventanaArbol == nullptr || ventanaArbol->IsDisposed) {
				ventanaArbol = gcnew CaracteristicasArbol();
			
					if (tipo == 2) {
						for (int i = 0; i < g->ListaSplay->Count; i++)
						{
							if (g->ListaSplay[i]->x == row && g->ListaSplay[i]->y == col)
							{

								ventanaArbol->xa = row;
								ventanaArbol->ya = col;
								ventanaArbol->label1->Text = g->ListaSplay[i]->tipo;
								System::String^ xx = gcnew System::String(std::to_string(row).c_str());
								System::String^ yy = gcnew System::String(std::to_string(col).c_str());
								ventanaArbol->label2->Text = xx + "," + yy;
								System::String^ cant = gcnew System::String(std::to_string(g->ListaSplay[i]->contarElementos((g->ListaSplay[i]->raiz))).c_str());
								ventanaArbol->label3->Text = cant;
								int cantfr = g->ListaSplay[i]->contarElementos(g->ListaSplay[i]->raiz);
								int multi = 1;
								int todo = cantfr * multi;
								System::String^ precio = gcnew System::String(std::to_string(todo).c_str());
								ventanaArbol->label4->Text = precio;
								System::String^ vendidoss = gcnew System::String(std::to_string(g->ListaSplay[i]->vendidos).c_str());
								ventanaArbol->label5->Text = vendidoss;
								System::String^ p = gcnew System::String(std::to_string(g->ListaSplay[i]->perdidos).c_str());
								ventanaArbol->label6->Text = p;
								ventanaArbol->botonVenderClickedEvent += gcnew EventHandler(this, &MyForm::venderArbolSplay);
								
							}
						}
						ventanaArbol->Show();
					}


					else if (tipo == 3) {
						for (int i = 0; i < g->ListaAVL->Count; i++)
						{
							if (g->ListaAVL[i]->x == row && g->ListaAVL[i]->y == col)
							{

								ventanaArbol->xa = row;
								ventanaArbol->ya = col;
								ventanaArbol->label1->Text = g->ListaAVL[i]->tipo;
								System::String^ xx = gcnew System::String(std::to_string(row).c_str());
								System::String^ yy = gcnew System::String(std::to_string(col).c_str());
								ventanaArbol->label2->Text = xx + "," + yy;
								System::String^ cant = gcnew System::String(std::to_string(g->ListaAVL[i]->contarElementos((g->ListaAVL[i]->root))).c_str());
								ventanaArbol->label3->Text = cant;
								int cantfr = g->ListaAVL[i]->contarElementos(g->ListaAVL[i]->root);
								int multi = 1;
								int todo = cantfr * multi;
								System::String^ precio = gcnew System::String(std::to_string(todo).c_str());
								ventanaArbol->label4->Text = precio;
								System::String^ vendidoss = gcnew System::String(std::to_string(g->ListaAVL[i]->vendidos).c_str());
								ventanaArbol->label5->Text = vendidoss;
								System::String^ perdidos = gcnew System::String(std::to_string(g->ListaAVL[i]->perdidos).c_str());
								ventanaArbol->label6->Text = perdidos;
								ventanaArbol->botonVenderClickedEvent += gcnew EventHandler(this, &MyForm::venderArbolAVL);
								
							}
						}
						ventanaArbol->Show();
					}





					else if (tipo == 4) {
						for (int i = 0; i < g->ListaBinario->Count; i++)
						{
							if (g->ListaBinario[i]->x == row && g->ListaBinario[i]->y == col)
							{
								ventanaArbol->xa = row;
								ventanaArbol->ya = col;
								ventanaArbol->label1->Text = g->ListaBinario[i]->tipo;
								System::String^ xx = gcnew System::String(std::to_string(row).c_str());
								System::String^ yy = gcnew System::String(std::to_string(col).c_str());
								ventanaArbol->label2->Text = xx + "," + yy;
								System::String^ cant = gcnew System::String(std::to_string(g->ListaBinario[i]->contarElementos((g->ListaBinario[i]->root))).c_str());
								ventanaArbol->label3->Text = cant;
								int cantfr = g->ListaBinario[i]->contarElementos(g->ListaBinario[i]->root);
								int multi = 1;
								int todo = cantfr * multi;
								System::String^ precio = gcnew System::String(std::to_string(todo).c_str());
								ventanaArbol->label4->Text = precio;
								System::String^ vendidoss = gcnew System::String(std::to_string(g->ListaBinario[i]->vendidos).c_str());
								ventanaArbol->label5->Text = vendidoss;
								System::String^ perdidos = gcnew System::String(std::to_string(g->ListaBinario[i]->perdidos).c_str());
								ventanaArbol->label6->Text = perdidos;
								ventanaArbol->botonVenderClickedEvent += gcnew EventHandler(this, &MyForm::venderArbolBinario);
								
							}
						}
						ventanaArbol->Show();
					}



					else if (tipo == 5) {
						for (int i = 0; i < g->ListaHEAP->Count; i++)
						{
							if (g->ListaHEAP[i]->x == row && g->ListaHEAP[i]->y == col)
							{

								ventanaArbol->xa = row;
								ventanaArbol->ya = col;
								ventanaArbol->label1->Text = g->ListaHEAP[i]->tipo;
								System::String^ xx = gcnew System::String(std::to_string(row).c_str());
								System::String^ yy = gcnew System::String(std::to_string(col).c_str());
								ventanaArbol->label2->Text = xx + "," + yy;
								System::String^ cant = gcnew System::String(std::to_string(g->ListaHEAP[i]->contarElementos()).c_str());
								ventanaArbol->label3->Text = cant;
								int cantfr = g->ListaHEAP[i]->contarElementos();
								int multi = 1;
								int todo = cantfr * multi;
								System::String^ precio = gcnew System::String(std::to_string(todo).c_str());
								ventanaArbol->label4->Text = precio;
								System::String^ vendidoss = gcnew System::String(std::to_string(g->ListaHEAP[i]->vendidos).c_str());
								ventanaArbol->label5->Text = vendidoss;
								System::String^ perdidos = gcnew System::String(std::to_string(g->ListaHEAP[i]->perdidos).c_str());
								ventanaArbol->label6->Text = perdidos;
								ventanaArbol->botonVenderClickedEvent += gcnew EventHandler(this, &MyForm::venderArbolHeap);
							}
						}
						ventanaArbol->Show();
					}

					else {
						int p = 0;
						int h = 0;

						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
							{
								if (buttonGrid[i, j] == button)
								{
									p = i;
									h = j;
									break;
								}
							}
						}
						if (matrizbool[p, h] == true) {
							label2->Text = "protegido";
						}
						else {
							label2->Text = "no esta protegido";
						}


					}

				
			//}
			
		}

		
		

		System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::W) {
				label2->Text = "W";

				int p = 0;
				int u = 0;
				bool flag = false;
				while (flag != true) {
					int h = 0;
					while (h < 8) {
						if (matriz[p, h] == 1) {

							u = h;

							flag = true;
						}
						h++;
					}
					p++;
				}

				if (p - 1 > 0 && (matriz[p-2, u] == 0 || matriz[p - 2, u] ==7 || matriz[p - 2, u] ==8 )) {
					p--;
				
						matriz[p, u] = 0;

						matriz[p - 1, u] = 1;
				
				}
		
				else {
					label2->Text ="No puedes llegar ahí";
					p--;
					
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple; //////////////////////////////////////
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}
						// Haga algo con el control
					}
				}
			}

			if (e->KeyCode == Keys::A) {
				label2->Text = "A";

				int p = 0;
				int u = 0;
				bool flag = false;
				while (flag != true) {
					int h = 0;
					while (h < 8) {
						if (matriz[p, h] == 1) {

							u = h;

							flag = true;
						}
						h++;
					}
					p++;
				}



				if (u - 1 >= 0 &&(matriz[p-1, u-1] == 0 || matriz[p - 1, u-1] == 7 || matriz[p - 1, u-1] == 8)) {
					p--;
					
						matriz[p, u] = 0;

						matriz[p , u - 1] = 1;
					
					
					




					
					//matriz[p, u] = 0;
					
					//matriz[p, u - 1] = 1;
				}
				


				else {
					label2->Text = "No puedes llegar ahí";
					p--;
					//label2->Text = String::Format("p: {0} u: {1}", p, u);
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple;
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}
						// Haga algo con el control
					}
				}
			}

			if (e->KeyCode == Keys::D) {

				int p = 0;
				int u = 0;
				bool flag = false;
				while (flag != true) {
					int h = 0;
					while (h < 8) {
						if (matriz[p, h] == 1) {

							u = h;

							flag = true;
						}
						h++;
					}
					p++;
				}



				if (u + 1 <= 7 && (matriz[p-1,u+1] == 0 || matriz[p -1, u+1] == 7 || matriz[p - 1, u + 1] == 8)) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					matriz[p, u] = 0;
					matriz[p, u + 1] = 1;
				}
				
				else {
					label2->Text = "No puedes llegar ahí";
					p--;
					
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple;
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}
						// Haga algo con el control
					}
				}


			}

			if (e->KeyCode == Keys::S) {

				int p = 0;
				int u = 0;
				bool flag = false;
				while (flag != true) {
					int h = 0;
					while (h < 8) {
						if (matriz[p, h] == 1) {

							u = h;

							flag = true;
						}
						h++;
					}
					p++;
				}



				if (p + 1 <= 8 &&(matriz[p ,u] == 0 || matriz[p , u] == 7 || matriz[p  , u] == 8)) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					
					matriz[p, u] = 0;
				
					matriz[p + 1, u] = 1;
				}

		
				else {
					
					p--;
					label2->Text = "no puedes llegar ahí";
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple;
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}
						// Haga algo con el control
					}
				}


			}



		}


		void plantarAVL() {



		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->botonEspantapajaros = (gcnew System::Windows::Forms::Button());
			this->botonConfiguracion = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				55)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(203, 52);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(405, 396);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(724, 133);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 336);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 47);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Plantar Binario";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(74, 336);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 47);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Plantar AVL";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 389);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 47);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Plantar HEAP";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(74, 389);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(61, 47);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Plantar Splay";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(727, 369);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(98, 67);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Mercado";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(38, 165);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// botonEspantapajaros
			// 
			this->botonEspantapajaros->Location = System::Drawing::Point(12, 283);
			this->botonEspantapajaros->Name = L"botonEspantapajaros";
			this->botonEspantapajaros->Size = System::Drawing::Size(123, 47);
			this->botonEspantapajaros->TabIndex = 10;
			this->botonEspantapajaros->Text = L"Poner Espantapájaros";
			this->botonEspantapajaros->UseVisualStyleBackColor = true;
			this->botonEspantapajaros->Click += gcnew System::EventHandler(this, &MyForm::botonEspantapajaros_Click);
			// 
			// botonConfiguracion
			// 
			this->botonConfiguracion->Location = System::Drawing::Point(13, 13);
			this->botonConfiguracion->Name = L"botonConfiguracion";
			this->botonConfiguracion->Size = System::Drawing::Size(138, 62);
			this->botonConfiguracion->TabIndex = 11;
			this->botonConfiguracion->Text = L"Configuración";
			this->botonConfiguracion->UseVisualStyleBackColor = true;
			this->botonConfiguracion->Click += gcnew System::EventHandler(this, &MyForm::botonConfiguracion_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(727, 300);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(98, 63);
			this->button8->TabIndex = 12;
			this->button8->Text = L"TOP 10";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 460);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->botonConfiguracion);
			this->Controls->Add(this->botonEspantapajaros);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->KeyPreview = true;
			this->Location = System::Drawing::Point(492, 160);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion





	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		if (g->arbolesAVL == 0) {
			return;
		}

		int p = 0;
		int u = 0;
		bool flag = false;
		while (flag != true) {
			int h = 0;
			while (h < 8) {
				if (matriz[p, h] == 1) {

					u = h;

					flag = true;
				}
				h++;
			}
			p++;
		}
		p--;



		if (p - 1 >= 0 && matriz[p - 1, u] == 0) {

			matriz[p, u] = 3;
			matriz[p - 1, u] = 1;

			g->ListaAVL->Insert(0, gcnew AVLTree());
			g->ListaAVL[0]->x = p;
			g->ListaAVL[0]->y = u;

			g->arbolesAVL--;
			g->ListaAVL[0]->startBackGroundTask();
		}
		else if (p + 1 < 8 && matriz[p + 1, u] == 0) {
			matriz[p, u] = 3;
			matriz[p + 1, u] = 1;
			g->ListaAVL->Insert(0, gcnew AVLTree());
			g->ListaAVL[0]->x = p;
			g->ListaAVL[0]->y = u;
			g->arbolesAVL--;
			g->ListaAVL[0]->startBackGroundTask();

		}
		else if (u + 1 < 8 && matriz[p, u + 1] == 0) {
			matriz[p, u] = 3;
			matriz[p, u + 1] = 1;
			g->ListaAVL->Insert(0, gcnew AVLTree());
			g->ListaAVL[0]->x = p;
			g->ListaAVL[0]->y = u;
			g->arbolesAVL--;
			g->ListaAVL[0]->startBackGroundTask();

		}
		else if (u - 1 >= 0 && matriz[p, u - 1] == 0) {
			matriz[p, u] = 3;
			matriz[p, u - 1] = 1;
			g->ListaAVL->Insert(0, gcnew AVLTree());
			g->ListaAVL[0]->x = p;
			g->ListaAVL[0]->y = u;
			g->arbolesAVL--;
			g->ListaAVL[0]->startBackGroundTask();

		}
		else {
			label2->Text = "no se puede plantar aquí";
		}

		for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
			for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
				Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
				if (matriz[i, j] == 1) {
					control->BackColor = System::Drawing::Color::Red;

				}
				else if (matriz[i, j] == 2) {
					control->BackColor = System::Drawing::Color::Black;
				}
				else if (matriz[i, j] == 3) {
					control->BackColor = System::Drawing::Color::Yellow;
				}
				else if (matriz[i, j] == 4) {
					control->BackColor = System::Drawing::Color::Pink;
				}
				else if (matriz[i, j] == 5) {
					control->BackColor = System::Drawing::Color::Cyan;
				}
				else if (matriz[i, j] == 6) {
					control->BackColor = System::Drawing::Color::Brown;
				}
				else if (matriz[i, j] == 7) {
					control->BackColor = System::Drawing::Color::Purple;
				}
				else if (matriz[i, j] == 8) {
					control->BackColor = System::Drawing::Color::Orange;
				}

				else {
					control->BackColor = System::Drawing::Color::Green;
				}
				// Haga algo con el control
			}
		}

	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (g->arbolesBinarios == 0) {
			return;
		}

		int p = 0;
		int u = 0;
		bool flag = false;
		while (flag != true) {
			int h = 0;
			while (h < 8) {
				if (matriz[p, h] == 1) {

					u = h;

					flag = true;
				}
				h++;
			}
			p++;
		}
		p--;



		if (p - 1 >= 0 && matriz[p - 1, u] == 0) {

			matriz[p, u] = 4;
			matriz[p - 1, u] = 1;
			g->ListaBinario->Insert(0, gcnew BinarySearchTree());
			g->ListaBinario[0]->x = p;
			g->ListaBinario[0]->y = u;
			g->ListaBinario[0]->tasaTiempo = g->tiempoDeCosecha;
			g->arbolesBinarios--;
			g->ListaBinario[0]->startBackGroundTask();
		}
		else if (p + 1 < 8 && matriz[p + 1, u] == 0) {
			matriz[p, u] = 4;
			matriz[p + 1, u] = 1;
			g->ListaBinario->Insert(0, gcnew BinarySearchTree());
			g->ListaBinario[0]->x = p;
			g->ListaBinario[0]->y = u;
			g->ListaBinario[0]->tasaTiempo = g->tiempoDeCosecha;
			g->arbolesBinarios--;
			g->ListaBinario[0]->startBackGroundTask();
		}
		else if (u + 1 < 8 && matriz[p, u + 1] == 0) {
			matriz[p, u] = 4;
			matriz[p, u + 1] = 1;
			g->ListaBinario->Insert(0, gcnew BinarySearchTree());
			g->ListaBinario[0]->x = p;
			g->ListaBinario[0]->y = u;
			g->ListaBinario[0]->tasaTiempo = g->tiempoDeCosecha;
			g->arbolesBinarios--;
			g->ListaBinario[0]->startBackGroundTask();

		}
		else if (u - 1 >= 0 && matriz[p, u - 1] == 0) {
			matriz[p, u] = 4;
			matriz[p, u - 1] = 1;
			g->ListaBinario->Insert(0, gcnew BinarySearchTree());
			g->ListaBinario[0]->x = p;
			g->ListaBinario[0]->y = u;
			g->ListaBinario[0]->tasaTiempo = g->tiempoDeCosecha;
			g->arbolesBinarios--;
			g->ListaBinario[0]->startBackGroundTask();

		}
		else {
			label2->Text = "no se puede plantar aquí";
		}

		for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
			for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
				Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
				if (matriz[i, j] == 1) {
					control->BackColor = System::Drawing::Color::Red;

				}
				else if (matriz[i, j] == 2) {
					control->BackColor = System::Drawing::Color::Black;
				}
				else if (matriz[i, j] == 3) {
					control->BackColor = System::Drawing::Color::Yellow;
				}
				else if (matriz[i, j] == 4) {
					control->BackColor = System::Drawing::Color::Pink;
				}
				else if (matriz[i, j] == 5) {
					control->BackColor = System::Drawing::Color::Cyan;
				}
				else if (matriz[i, j] == 6) {
					control->BackColor = System::Drawing::Color::Brown;
				}
				else if (matriz[i, j] == 7) {
					control->BackColor = System::Drawing::Color::Purple;
				}
				else if (matriz[i, j] == 8) {
					control->BackColor = System::Drawing::Color::Orange;
				}
				else {
					control->BackColor = System::Drawing::Color::Green;
				}
				// Haga algo con el control
			}
		}

	}


private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (g->arboleSplay == 0) {
		return;
	}
	int p = 0;
	int u = 0;
	bool flag = false;
	while (flag != true) {
		int h = 0;
		while (h < 8) {
			if (matriz[p, h] == 1) {

				u = h;

				flag = true;
			}
			h++;
		}
		p++;
	}
	p--;
	


	if (p - 1 >= 0 && matriz[p-1, u] == 0) {

		matriz[p, u] = 2;
		matriz[p - 1, u] = 1;
		g->ListaSplay->Insert(0, gcnew SplayTree());
		g->ListaSplay[0]->x = p;
		g->ListaSplay[0]->y = u;
		g->ListaSplay[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arboleSplay--;
		g->ListaSplay[0]->startBackGroundTask();
		
	}
	else if(p+1 <8 && matriz[p + 1, u] == 0) {
		matriz[p, u] = 2;
		matriz[p + 1, u] = 1;
		g->ListaSplay->Insert(0, gcnew SplayTree());
		g->ListaSplay[0]->x = p;
		g->ListaSplay[0]->y = u;
		g->ListaSplay[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arboleSplay--;
		g->ListaSplay[0]->startBackGroundTask();
		
		
	}
	else if (u + 1 < 8 && matriz[p, u + 1] == 0) {
		matriz[p, u] = 2;
		matriz[p, u + 1] = 1;
		g->ListaSplay->Insert(0, gcnew SplayTree());
		g->ListaSplay[0]->x = p;
		g->ListaSplay[0]->y = u;
		g->ListaSplay[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arboleSplay--;
		g->ListaSplay[0]->startBackGroundTask();
		
	}
	else if (u - 1 >= 0 && matriz[p, u - 1] == 0) {
		matriz[p, u] = 2;
		matriz[p, u - 1] = 1;
		g->ListaSplay->Insert(0, gcnew SplayTree());
		g->ListaSplay[0]->x = p;
		g->ListaSplay[0]->y = u;
		g->ListaSplay[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arboleSplay--;
		g->ListaSplay[0]->startBackGroundTask();
		
	}
	else {
		label2->Text = "no se puede plantar aquí";
	}
	
	for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
		for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
			Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
			if (matriz[i, j] == 1) {
				control->BackColor = System::Drawing::Color::Red;

			}
			else if (matriz[i, j] == 2) {
				control->BackColor = System::Drawing::Color::Black;
			}
			else if (matriz[i, j] == 3) {
				control->BackColor = System::Drawing::Color::Yellow;
			}
			else if (matriz[i, j] == 4) {
				control->BackColor = System::Drawing::Color::Pink;
			}
			else if (matriz[i, j] == 5) {
				control->BackColor = System::Drawing::Color::Cyan;
			}
			else if (matriz[i, j] == 6) {
				control->BackColor = System::Drawing::Color::Brown;
			}
			else if (matriz[i, j] == 7) {
				control->BackColor = System::Drawing::Color::Purple;
			}
			else if (matriz[i, j] == 8) {
				control->BackColor = System::Drawing::Color::Orange;
			}
			else {
				control->BackColor = System::Drawing::Color::Green;
			}
			// Haga algo con el control
		}
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	if (g->arbolesHeap == 0) {
		return;
	}

	int p = 0;
	int u = 0;
	bool flag = false;
	while (flag != true) {
		int h = 0;
		while (h < 8) {
			if (matriz[p, h] == 1) {

				u = h;

				flag = true;
			}
			h++;
		}
		p++;
	}
	p--;



	if (p-1  >= 0 && matriz[p - 1, u] == 0) {

		matriz[p, u] = 5;
		matriz[p - 1, u] = 1;
		g->ListaHEAP->Insert(0, gcnew Heap_tree());
		g->ListaHEAP[0]->x = p;
		g->ListaHEAP[0]->y = u;
		g->ListaHEAP[0]-> tasaTiempo = g->tiempoDeCosecha;
		g->arbolesHeap--;
		g->ListaHEAP[0]->startBackGroundTask();
	}
	else if (p + 1 < 8 && matriz[p + 1, u] == 0) {
		matriz[p, u] = 5;
		matriz[p + 1, u] = 1;
		g->ListaHEAP->Insert(0, gcnew Heap_tree());
		g->ListaHEAP[0]->x = p;
		g->ListaHEAP[0]->y = u;
		g->ListaHEAP[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arbolesHeap--;
		g->ListaHEAP[0]->startBackGroundTask();
	}
	else if (u + 1 < 8 && matriz[p, u + 1] == 0) {
		matriz[p, u] = 5;
		matriz[p, u + 1] = 1;
		g->ListaHEAP->Insert(0, gcnew Heap_tree());
		g->ListaHEAP[0]->x = p;
		g->ListaHEAP[0]->y = u;
		g->ListaHEAP[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arbolesHeap--;
		g->ListaHEAP[0]->startBackGroundTask();
	}
	else if (u - 1 >= 0 && matriz[p, u - 1] == 0) {
		matriz[p, u] = 5;
		matriz[p, u - 1] = 1;
		g->ListaHEAP->Insert(0, gcnew Heap_tree());
		g->ListaHEAP[0]->x = p;
		g->ListaHEAP[0]->y = u;
		g->ListaHEAP[0]->tasaTiempo = g->tiempoDeCosecha;
		g->arbolesHeap--;
		g->ListaHEAP[0]->startBackGroundTask();
	}
	else {
		label2->Text = "no se puede plantar aquí";
	}

	for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
		for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
			Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
			if (matriz[i, j] == 1) {
				control->BackColor = System::Drawing::Color::Red;

			}
			else if (matriz[i, j] == 2) {
				control->BackColor = System::Drawing::Color::Black;
			}
			else if (matriz[i, j] == 3) {
				control->BackColor = System::Drawing::Color::Yellow;
			}
			else if (matriz[i, j] == 4) {
				control->BackColor = System::Drawing::Color::Pink;
			}
			else if (matriz[i, j] == 5) {
				control->BackColor = System::Drawing::Color::Cyan;
			}
			else if (matriz[i, j] == 6) {
				control->BackColor = System::Drawing::Color::Brown;
			}
			else if (matriz[i, j] == 7) {
				control->BackColor = System::Drawing::Color::Purple;
			}
			else if (matriz[i, j] == 8) {
				control->BackColor = System::Drawing::Color::Orange;
			}
			else {
				control->BackColor = System::Drawing::Color::Green;
			}
			// Haga algo con el control
		}
	}

}
	void Form2BotonArbolBinarioAccion(System::Object^ sender, System::EventArgs^ e) {
		int precioArbolBinario = g->precioTienda * 100;

		if (g->dinero < precioArbolBinario) {
			return;
		}
		   g->arbolesBinarios += 1;
		   g->dinero -= precioArbolBinario;
		   System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		   ventanaSecundaria->label1->Text = "$" + cadena;
	   }

	void Form2BotonArbolAVLAccion(System::Object^ sender, System::EventArgs^ e) {
		int precioArbolAVL = g->precioTienda * 350;

		if (g->dinero < precioArbolAVL){
			return;
		}
		   g->arbolesAVL += 1;
		   g->dinero -= precioArbolAVL;
		   System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		   ventanaSecundaria->label1->Text = "$" + cadena;
	   }

	void Form2BotonArbolHeapAccion(System::Object^ sender, System::EventArgs^ e) {
		int precioArbolHeap = g->precioTienda * 130;
		if (g->dinero < precioArbolHeap) {
			return;
		}
		g->arbolesHeap += 1;
		   g->dinero -= precioArbolHeap;
		   System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		   ventanaSecundaria->label1->Text = "$" + cadena;
	   }

	void Form2BotonArbolSplayAccion(System::Object^ sender, System::EventArgs^ e) {
		int precioArbolSplay = g->precioTienda * 600;

		if (g->dinero < precioArbolSplay) {
			return;
		}
		g->arboleSplay += 1;
		   g->dinero -= precioArbolSplay;
		   System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		   ventanaSecundaria->label1->Text = "$" + cadena;
	   }

	void Form2BotonEspantapajarosAccion(System::Object^ sender, System::EventArgs^ e){
		int precioEspantapajaros = g->precioTienda * 100;

		if (g->dinero < precioEspantapajaros || g->cantidadActualEspantapajaros>= 2) {
			return;
		}
		g->espantapajaros += 1;
		g->cantidadActualEspantapajaros++;
		g->dinero -= precioEspantapajaros;
		System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		ventanaSecundaria->label1->Text = "$" + cadena;
	}



	void VenderTodo(System::Object^ sender, System::EventArgs^ e) {
		int dineroSplay = 0;
		int dineroAVL = 0;
		int dineroHeap = 0;
		int dineroBinario = 0;



		for (int i = 0; i < g->ListaSplay->Count; i++) {
			g->ListaSplay[i]->vendidos += g->ListaSplay[i]->contarElementos(g->ListaSplay[i]->raiz);
			dineroSplay += g->ListaSplay[i]->contarElementos(g->ListaSplay[i]->raiz);
			g->ListaSplay[i]->eliminarTodosElementos();
		}


		for (int i = 0; i < g->ListaHEAP->Count; i++) {
			g->ListaHEAP[i]->vendidos += g->ListaHEAP[i]->contarElementos();
			dineroHeap += g->ListaHEAP[i]->contarElementos();
			g->ListaHEAP[i]->eliminarTodosElementos();
		}

		for (int i = 0; i < g->ListaAVL->Count; i++) {
			g->ListaAVL[i]->vendidos += g->ListaAVL[i]->contarElementos(g->ListaAVL[i]->root);
			dineroAVL += g->ListaAVL[i]->contarElementos(g->ListaAVL[i]->root);
			g->ListaAVL[i]->eliminarTodosElementos();
		}

		for (int i = 0; i < g->ListaBinario->Count; i++) {
			g->ListaBinario[i]->vendidos += g->ListaBinario[i]->contarElementos(g->ListaBinario[i]->root);
			dineroBinario += g->ListaBinario[i]->contarElementos(g->ListaBinario[i]->root);
			g->ListaBinario[i]->eliminarTodosElementos();
		}


		dineroBinario = dineroBinario * 2;
		dineroHeap = dineroHeap * 2;
		dineroAVL = dineroAVL * 2;
		dineroSplay = dineroSplay * 2;
		g->dinero += dineroAVL;
		g->dinero += dineroSplay;
		g->dinero += dineroHeap;
		g->dinero += dineroBinario;
		g->puntaje += dineroAVL + dineroSplay + dineroHeap + dineroBinario;

		System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		ventanaSecundaria->label1->Text = "$" + g->dinero.ToString();
		label2->Text = "zzz";

		StreamReader^ lector = gcnew StreamReader(rutaArchivo);


		List<String^>^ listaNombres = gcnew List<String^>();
		List<int>^ listaPuntajes = gcnew List<int>();


		if (lector) {
			String^ linea;


			for (int i = 0; i < 10; i++) {
				linea = lector->ReadLine();
				if (linea == nullptr) {
					break; // Si no hay más líneas en el archivo, sal del bucle
				}

				array<String^>^ tokens = linea->Split(' ');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);
					listaNombres->Add(nombre);
					listaPuntajes->Add(valor);

				}
			}

			lector->Close();
		}

		for (int k = listaNombres->Count - 1; k >= 0; k--) {
			if (listaNombres[k] == g->nombre) {
				listaPuntajes->RemoveAt(k);
				listaNombres->RemoveAt(k);
			}
		}

		bool flag = false;

		for (int i = 0; i < listaPuntajes->Count; i++)
		{
			if (g->puntaje > listaPuntajes[i]) {
				listaPuntajes->Insert(i, g->puntaje);
				listaNombres->Insert(i, g->nombre);
				flag = true;
				break;
			}
		}

		if (!flag) {
			listaNombres->Insert(listaNombres->Count, g->nombre);
			listaPuntajes->Insert(listaPuntajes->Count, g->puntaje);
		}


		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo);
		for (int i = 0; i < listaNombres->Count; i++) {
			escritor->WriteLine(listaNombres[i] + " " + listaPuntajes[i]);
		}
		escritor->Close();

		
	}



	void venderArbolSplay(System::Object^ sender, System::EventArgs^ e) {

		int dineroSplay = 0;
		bool flag = true;
		int t = 0;
		int estaVendidos = 0;
		while (flag == true) {
			for (int i = 0; i < 8; i++)
			{
				
					for (int j = 0; j < 8; j++)
					{
						if (matriz[i, j] == 2 && flag == true)
						{
							for (int o = 0; o < g->ListaSplay->Count; o++) {
								if (g->ListaSplay[o]->x == ventanaArbol->xa && g->ListaSplay[o]->y == ventanaArbol->ya) {
									g->ListaSplay[o]->vendidos += g->ListaSplay[o]->contarElementos(g->ListaSplay[o]->raiz);
									estaVendidos += g->ListaSplay[o]->vendidos;
									dineroSplay += g->ListaSplay[o]->contarElementos(g->ListaSplay[o]->raiz);
									g->ListaSplay[o]->eliminarTodosElementos();
									ventanaArbol->label7->Text = "Vendido!";
									flag = false;
									t++;
									break;

								}


							}

						}
					}	
			}
		}
		
		ventanaArbol->label5->Text = estaVendidos.ToString();
		dineroSplay = dineroSplay * 2;
		g->dinero += dineroSplay;
		ventanaArbol->label3->Text = "0";
		ventanaSecundaria->label1->Text = "$" + g->dinero.ToString();


		g->puntaje += dineroSplay;


		StreamReader^ lector = gcnew StreamReader(rutaArchivo);


		List<String^>^ listaNombres = gcnew List<String^>();
		List<int>^ listaPuntajes = gcnew List<int>();


		if (lector) {
			String^ linea;


			for (int i = 0; i < 10; i++) {
				linea = lector->ReadLine();
				if (linea == nullptr) {
					break; // Si no hay más líneas en el archivo, sal del bucle
				}

				array<String^>^ tokens = linea->Split(' ');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);
					listaNombres->Add(nombre);
					listaPuntajes->Add(valor);

				}
			}

			lector->Close();
		}

		for (int k = listaNombres->Count - 1; k >= 0; k--) {
			if (listaNombres[k] == g->nombre) {
				listaPuntajes->RemoveAt(k);
				listaNombres->RemoveAt(k);
			}
		}

		bool flagSplay = false;

		for (int i = 0; i < listaPuntajes->Count; i++)
		{
			if (g->puntaje > listaPuntajes[i]) {
				listaPuntajes->Insert(i, g->puntaje);
				listaNombres->Insert(i, g->nombre);
				flagSplay = true;
				break;
			}
		}

		if (!flagSplay) {
			listaNombres->Insert(listaNombres->Count, g->nombre);
			listaPuntajes->Insert(listaPuntajes->Count, g->puntaje);
		}


		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo);
		for (int i = 0; i < listaNombres->Count; i++) {
			escritor->WriteLine(listaNombres[i] + " " + listaPuntajes[i]);
		}
		escritor->Close();

	}


	void venderArbolAVL(System::Object^ sender, System::EventArgs^ e) {
		int dineroAVL = 0;
		bool flag = true;
		int estaVendidos = 0;
		while (flag == true) {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				if (matriz[i, j] == 3 && flag == true) {
					for (int o = 0; o < g->ListaAVL->Count; o++) {
						if (g->ListaAVL[o]->x == ventanaArbol->xa && g->ListaAVL[o]->y == ventanaArbol->ya) {
							g->ListaAVL[o]->vendidos += g->ListaAVL[o]->contarElementos(g->ListaAVL[o]->root);
							estaVendidos += g->ListaAVL[o]->vendidos;
							dineroAVL += g->ListaAVL[o]->contarElementos(g->ListaAVL[o]->root);
							g->ListaAVL[o]->eliminarTodosElementos();
							ventanaArbol->label7->Text = "Vendido!";
							flag = false;
							break;
						}
					}
				}
			}
		}

		}
		ventanaArbol->label5->Text = estaVendidos.ToString();
		dineroAVL = dineroAVL * 2;
		g->dinero += dineroAVL;
		ventanaArbol->label3->Text = "0";
		ventanaSecundaria->label1->Text = "$" + g->dinero.ToString();





		g->puntaje += dineroAVL;


		StreamReader^ lector = gcnew StreamReader(rutaArchivo);


		List<String^>^ listaNombres = gcnew List<String^>();
		List<int>^ listaPuntajes = gcnew List<int>();


		if (lector) {
			String^ linea;


			for (int i = 0; i < 10; i++) {
				linea = lector->ReadLine();
				if (linea == nullptr) {
					break; // Si no hay más líneas en el archivo, sal del bucle
				}

				array<String^>^ tokens = linea->Split(' ');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);
					listaNombres->Add(nombre);
					listaPuntajes->Add(valor);

				}
			}

			lector->Close();
		}

		for (int k = listaNombres->Count - 1; k >= 0; k--) {
			if (listaNombres[k] == g->nombre) {
				listaPuntajes->RemoveAt(k);
				listaNombres->RemoveAt(k);
			}
		}

		bool flagAVL = false;

		for (int i = 0; i < listaPuntajes->Count; i++)
		{
			if (g->puntaje > listaPuntajes[i]) {
				listaPuntajes->Insert(i, g->puntaje);
				listaNombres->Insert(i, g->nombre);
				flagAVL = true;
				break;
			}
		}

		if (!flagAVL) {
			listaNombres->Insert(listaNombres->Count, g->nombre);
			listaPuntajes->Insert(listaPuntajes->Count, g->puntaje);
		}


		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo);
		for (int i = 0; i < listaNombres->Count; i++) {
			escritor->WriteLine(listaNombres[i] + " " + listaPuntajes[i]);
		}
		escritor->Close();
	
	
	}


	void venderArbolHeap(System::Object^ sender, System::EventArgs^ e) {
				int dineroHeap = 0;
				bool flag = true;
				int estaVendidos = 0;
				while (flag == true) {
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++) {
							if (matriz[i, j] == 4 && flag == true) {
								for (int o = 0; o < g->ListaHEAP->Count; o++) {
									if (g->ListaHEAP[o]->x == ventanaArbol->xa && g->ListaHEAP[o]->y == ventanaArbol->ya) {
										g->ListaHEAP[o]->vendidos += g->ListaHEAP[o]->contarElementos();
										estaVendidos += g->ListaHEAP[o]->vendidos;
										dineroHeap += g->ListaHEAP[o]->contarElementos();
										g->ListaHEAP[o]->eliminarTodosElementos();
										ventanaArbol->label7->Text = "Vendido!";
										flag = false;
										break;
									}
								}
							}
						}
					}
				}
	
		ventanaArbol->label5->Text = estaVendidos.ToString();
		dineroHeap = dineroHeap * 2;
		g->dinero += dineroHeap;
		ventanaArbol->label3->Text = "0";
		ventanaSecundaria->label1->Text = "$" + g->dinero.ToString();	


		g->puntaje += dineroHeap;

		StreamReader^ lector = gcnew StreamReader(rutaArchivo);


		List<String^>^ listaNombres = gcnew List<String^>();
		List<int>^ listaPuntajes = gcnew List<int>();


		if (lector) {
			String^ linea;


			for (int i = 0; i < 10; i++) {
				linea = lector->ReadLine();
				if (linea == nullptr) {
					break; // Si no hay más líneas en el archivo, sal del bucle
				}

				array<String^>^ tokens = linea->Split(' ');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);
					listaNombres->Add(nombre);
					listaPuntajes->Add(valor);

				}
			}

			lector->Close();
		}

		for (int k = listaNombres->Count - 1; k >= 0; k--) {
			if (listaNombres[k] == g->nombre) {
				listaPuntajes->RemoveAt(k);
				listaNombres->RemoveAt(k);
			}
		}

		bool flagHeap = false;

		for (int i = 0; i < listaPuntajes->Count; i++)
		{
			if (g->puntaje > listaPuntajes[i]) {
				listaPuntajes->Insert(i, g->puntaje);
				listaNombres->Insert(i, g->nombre);
				flagHeap = true;
				break;
			}
		}

		if (!flagHeap) {
			listaNombres->Insert(listaNombres->Count, g->nombre);
			listaPuntajes->Insert(listaPuntajes->Count, g->puntaje);
		}


		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo);
		for (int i = 0; i < listaNombres->Count; i++) {
			escritor->WriteLine(listaNombres[i] + " " + listaPuntajes[i]);
		}
		escritor->Close();






	}
	


	void venderArbolBinario(System::Object^ sender, System::EventArgs^ e) {
				int dineroBinario = 0;
				bool flag = true;
				int estaVendidos = 0;

				while (flag == true) {
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++) {
							if (matriz[i, j] == 1 && flag == true) {
								for (int o = 0; o < g->ListaBinario->Count; o++) {
									if (g->ListaBinario[o]->x == ventanaArbol->xa && g->ListaBinario[o]->y == ventanaArbol->ya) {
										g->ListaBinario[o]->vendidos += g->ListaBinario[o]->contarElementos(g->ListaBinario[o]->root);
										estaVendidos += g->ListaBinario[o]->vendidos;
										dineroBinario += g->ListaBinario[o]->contarElementos(g->ListaBinario[o]->root);
										g->ListaBinario[o]->eliminarTodosElementos();
										ventanaArbol->label7->Text = "Vendido!";
										flag = false;
									}
								}
							}
						}
					}
				}
	
	
		ventanaArbol->label5->Text = estaVendidos.ToString();
		dineroBinario = dineroBinario * 2;
		g->dinero += dineroBinario;
		ventanaArbol->label3->Text = "0";
		ventanaSecundaria->label1->Text = "$" + g->dinero.ToString();




		g->puntaje += dineroBinario;

		StreamReader^ lector = gcnew StreamReader(rutaArchivo);


		List<String^>^ listaNombres = gcnew List<String^>();
		List<int>^ listaPuntajes = gcnew List<int>();


		if (lector) {
			String^ linea;


			for (int i = 0; i < 10; i++) {
				linea = lector->ReadLine();
				if (linea == nullptr) {
					break; // Si no hay más líneas en el archivo, sal del bucle
				}

				array<String^>^ tokens = linea->Split(' ');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);
					listaNombres->Add(nombre);
					listaPuntajes->Add(valor);

				}
			}

			lector->Close();
		}

		for (int k = listaNombres->Count - 1; k >= 0; k--) {
			if (listaNombres[k] == g->nombre) {
				listaPuntajes->RemoveAt(k);
				listaNombres->RemoveAt(k);
			}
		}

		bool flagBinario = false;

		for (int i = 0; i < listaPuntajes->Count; i++)
		{
			if (g->puntaje > listaPuntajes[i]) {
				listaPuntajes->Insert(i, g->puntaje);
				listaNombres->Insert(i, g->nombre);
				flagBinario = true;
				break;
			}
		}

		if (!flagBinario) {
			listaNombres->Insert(listaNombres->Count, g->nombre);
			listaPuntajes->Insert(listaPuntajes->Count, g->puntaje);
		}


		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo);
		for (int i = 0; i < listaNombres->Count; i++) {
			escritor->WriteLine(listaNombres[i] + " " + listaPuntajes[i]);
		}
		escritor->Close();









	}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ventanaSecundaria == nullptr || ventanaSecundaria->IsDisposed) {
		ventanaSecundaria = gcnew Mercado();
		System::String^ cadena = gcnew System::String(std::to_string(g->dinero).c_str());
		ventanaSecundaria->label1->Text = "$" + cadena;
		ventanaSecundaria->botonArbolBinarioClickedEvent += gcnew EventHandler(this, &MyForm::Form2BotonArbolBinarioAccion);
		ventanaSecundaria->button2->Text = "Binario Ordenado $" + (g->precioTienda * 100).ToString();
		ventanaSecundaria->button3->Text = "Heap $" + (g->precioTienda * 130).ToString();
		ventanaSecundaria->button4->Text = "AVL $" + (g->precioTienda * 350).ToString();
		ventanaSecundaria->button5->Text = "Splay $" + (g->precioTienda * 600).ToString();

		ventanaSecundaria->botonAVLClickedEvent += gcnew EventHandler(this, &MyForm::Form2BotonArbolAVLAccion);
		ventanaSecundaria->botonHeapClickedEvent += gcnew EventHandler(this, &MyForm::Form2BotonArbolHeapAccion);
		ventanaSecundaria->botonSplayClickedEvent += gcnew EventHandler(this, &MyForm::Form2BotonArbolSplayAccion);
		ventanaSecundaria->vendeTodosClickedEvent += gcnew EventHandler(this, &MyForm::VenderTodo);
		ventanaSecundaria->botonComprarEspantapajarosClickedEvent += gcnew EventHandler(this, &MyForm::Form2BotonEspantapajarosAccion);
		
	}
	ventanaSecundaria->Show();
}


public: 
	void ventanaConfiguracionAccionBotonBajoTiempoDeCosecha(System::Object^ sender, System::EventArgs^ e){
		g->tiempoDeCosecha = 3;
	}
	void ventanaConfiguracionAccionBotonMedioTiempoDeCosecha(System::Object^ sender, System::EventArgs^ e) {
		g->tiempoDeCosecha = 7;
	}
	void ventanaConfiguracionAccionBotonAltoTiempoDeCosecha(System::Object^ sender, System::EventArgs^ e) {
		g->tiempoDeCosecha = 10;
	}


	void ventanaConfiguracionAccionBotonBajoPrecioTienda(System::Object^ sender, System::EventArgs^ e) {
		g->precioTienda = 1;	
	}
	void ventanaConfiguracionAccionBotonMedioPrecioTienda(System::Object^ sender, System::EventArgs^ e) {
		g->precioTienda = 2;
	}
	void ventanaConfiguracionAccionBotonAltoPrecioTienda(System::Object^ sender, System::EventArgs^ e) {
		g->precioTienda = 3;
	}
	

	void ventanaConfiguracionAccionBotonBajoTiempoPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->tiempoDePlagas = 10;
	}
	void ventanaConfiguracionAccionBotonMedioTiempoPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->tiempoDePlagas = 20;
	}
	void ventanaConfiguracionAccionBotonAltoTiempoPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->tiempoDePlagas = 25;
	}


	void ventanaConfiguracionAccionBotonBajoProbabilidadPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->probabilidadDePlagas = 1;
	}
	void ventanaConfiguracionAccionBotonMedioProbabilidadPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->probabilidadDePlagas = 2;
	}
	void ventanaConfiguracionAccionBotonAltoProbabilidadPlagas(System::Object^ sender, System::EventArgs^ e) {
		g->probabilidadDePlagas = 3;
	}

	
	void ventanaConfiguracionAceptar(System::Object^ sender, System::EventArgs^ e){
		ventanaConfiguracion->Close();
		backgroundWorker1->RunWorkerAsync();
		threadOvejasSplay->Start();
		threadCuervos->Start();
		botonEspantapajaros->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		button5->Enabled = true;
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				buttonGrid[row, col]->Enabled = true;
			}
		}
	}

	void ventanaConfiguracionAceptarNombre(System::Object^ sender, System::EventArgs^ e) {


		String^ nombreTemp = ventanaConfiguracion->textBoxNombre->Text;

		StreamReader^ lector = gcnew StreamReader(rutaArchivo);

		if (lector) {
			String^ linea;

			while ((linea = lector->ReadLine()) != nullptr) {
				array<String^>^ tokens = linea->Split('\t');
				if (tokens->Length >= 2) {
					String^ nombre = tokens[0];
					String^ valorStr = tokens[1];
					int valor = Int32::Parse(valorStr);

					if (nombreTemp == nombre) {
						MessageBox::Show("Nombre ya existe");
						return;
					}
				}
			}
			g->nombre = nombreTemp;

			lector->Close();
		}


	}

	void metodoCuervos() {
		
		while (true) {
			cuervo^ cuervito = gcnew cuervo();
			int row = cuervito->row;
			int col = cuervito->col;


			label2->Text = row.ToString();

			//asdasd

			if (matriz[row, col] != 1 && matriz[row, col] != 2 && matriz[row, col] != 3 && matriz[row, col] != 4 && matriz[row, col] != 5 && matriz[row, col] != 6 && matrizbool[row, col] == false) {

				matriz[row, col] = 8;
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {
							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple;
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}

					}
				}






				/////////// para arboles splay//////////////////////
				if (row + 1 <= 8) {
					if (matriz[row + 1, col] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row + 1 && g->ListaSplay[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaSplay[o]->eliminarPrimerElemento();
										g->ListaSplay[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row + 1, col] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row + 1 && g->ListaAVL[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}
					else if (matriz[row + 1, col] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row + 1 && g->ListaBinario[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}


					else if (matriz[row + 1, col] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row + 1 && g->ListaHEAP[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}


















				}

				if (row - 1 >= 0) {
					if (matriz[row - 1, col] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row - 1 && g->ListaSplay[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaSplay[o]->eliminarPrimerElemento();
										g->ListaSplay[o]->perdidos++;


										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;
											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row - 1, col] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row - 1 && g->ListaAVL[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row - 1, col] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row - 1 && g->ListaBinario[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}

					else if (matriz[row - 1, col] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row - 1 && g->ListaHEAP[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}






				}

				if (col + 1 <= 8) {
					if (matriz[row, col + 1] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row && g->ListaSplay[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaSplay[o]->eliminarPrimerElemento();
										g->ListaSplay[o]->perdidos++;


										con++;
										if (con >= 10) {
											matriz[row, col + 1] = 0;
											c = false;
											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);
									}
									else { c = false; }
								}
							}
						}
					}


					else if (matriz[row, col + 1] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row && g->ListaAVL[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col + 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}




					else if (matriz[row, col + 1] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row && g->ListaBinario[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col + 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}

					else if (matriz[row, col + 1] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row && g->ListaHEAP[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col + 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}










				}

				if (col - 1 >= 0) {
					if (matriz[row, col - 1] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row && g->ListaSplay[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaSplay[o]->eliminarPrimerElemento();
										g->ListaSplay[o]->perdidos++;

										con++;
										if (con >= 5) {
											matriz[row, col - 1] = 0;
											c = false;
											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);
									}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row, col - 1] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row && g->ListaAVL[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col - 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}


					else if (matriz[row, col - 1] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row && g->ListaBinario[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col - 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}

					else if (matriz[row, col - 1] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row && g->ListaHEAP[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 8) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col - 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}


				}







			}



			System::Threading::Thread::Sleep((g->tiempoDePlagas * 1000)+ 3000);

		}

	
	
	
	
	
	}

	void metodoOvejasSplay() {
		
		while (true) {
			oveja^ Ovejita = gcnew oveja();
			int row = Ovejita->row;
			int col = Ovejita->col;

			
			label2->Text = row.ToString();
			
			//asdasd

			if (matriz[row, col] != 1 && matriz[row, col] != 2 && matriz[row, col] != 3 && matriz[row, col] != 4 && matriz[row, col] != 5 && matriz[row, col] != 6 && matrizbool[row, col] == false) {

				matriz[row, col] = 7;
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {
							control->BackColor = System::Drawing::Color::Red;

						}
						else if (matriz[i, j] == 2) {
							control->BackColor = System::Drawing::Color::Black;
						}
						else if (matriz[i, j] == 3) {
							control->BackColor = System::Drawing::Color::Yellow;
						}
						else if (matriz[i, j] == 4) {
							control->BackColor = System::Drawing::Color::Pink;
						}
						else if (matriz[i, j] == 5) {
							control->BackColor = System::Drawing::Color::Cyan;
						}
						else if (matriz[i, j] == 6) {
							control->BackColor = System::Drawing::Color::Brown;
						}
						else if (matriz[i, j] == 7) {
							control->BackColor = System::Drawing::Color::Purple;
						}
						else if (matriz[i, j] == 8) {
							control->BackColor = System::Drawing::Color::Orange;
						}
						else {
							control->BackColor = System::Drawing::Color::Green;
						}

					}
				}






				/////////// para arboles splay//////////////////////
				if (row + 1 <= 8) {
					if (matriz[row + 1, col] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row + 1 && g->ListaSplay[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7){
										g->ListaSplay[o]->eliminarPrimerElemento();
									g->ListaSplay[o]->perdidos++;
									con++;
									if (con >= 10) {
										matriz[row + 1, col] = 0;
										c = false;

										for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
											for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
												Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
												if (matriz[i, j] == 1) {
													control->BackColor = System::Drawing::Color::Red;

												}
												else if (matriz[i, j] == 2) {
													control->BackColor = System::Drawing::Color::Black;
												}
												else if (matriz[i, j] == 3) {
													control->BackColor = System::Drawing::Color::Yellow;
												}
												else if (matriz[i, j] == 4) {
													control->BackColor = System::Drawing::Color::Pink;
												}
												else if (matriz[i, j] == 5) {
													control->BackColor = System::Drawing::Color::Cyan;
												}
												else if (matriz[i, j] == 6) {
													control->BackColor = System::Drawing::Color::Brown;
												}
												else if (matriz[i, j] == 7) {
													control->BackColor = System::Drawing::Color::Purple;
												}
												else if (matriz[i, j] == 8) {
													control->BackColor = System::Drawing::Color::Orange;
												}
												else {
													control->BackColor = System::Drawing::Color::Green;
												}

											}
										}
										break;
									}
									System::Threading::Thread::Sleep(1000);

								}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row + 1, col] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row + 1 && g->ListaAVL[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

					}
					else if (matriz[row + 1, col] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row + 1 && g->ListaBinario[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row + 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}


					else if (matriz[row+1, col ] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row+1 && g->ListaHEAP[o]->y == col ) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row+1, col ] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}


















				}

				if (row - 1 >= 0) {
					if (matriz[row - 1, col] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row - 1 && g->ListaSplay[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7){
										g->ListaSplay[o]->eliminarPrimerElemento();
									g->ListaSplay[o]->perdidos++;


									con++;
									if (con >= 10) {
										matriz[row - 1, col] = 0;
										c = false;
										for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
											for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
												Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
												if (matriz[i, j] == 1) {
													control->BackColor = System::Drawing::Color::Red;

												}
												else if (matriz[i, j] == 2) {
													control->BackColor = System::Drawing::Color::Black;
												}
												else if (matriz[i, j] == 3) {
													control->BackColor = System::Drawing::Color::Yellow;
												}
												else if (matriz[i, j] == 4) {
													control->BackColor = System::Drawing::Color::Pink;
												}
												else if (matriz[i, j] == 5) {
													control->BackColor = System::Drawing::Color::Cyan;
												}
												else if (matriz[i, j] == 6) {
													control->BackColor = System::Drawing::Color::Brown;
												}
												else if (matriz[i, j] == 7) {
													control->BackColor = System::Drawing::Color::Purple;
												}
												else if (matriz[i, j] == 8) {
													control->BackColor = System::Drawing::Color::Orange;
												}
												else {
													control->BackColor = System::Drawing::Color::Green;
												}

											}
										}
										break;
									}
									System::Threading::Thread::Sleep(1000);

								}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row - 1, col] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row - 1 && g->ListaAVL[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row - 1, col] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row - 1 && g->ListaBinario[o]->y == col) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row - 1, col] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}

					else if (matriz[row-1, col ] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row -1&& g->ListaHEAP[o]->y == col ) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row-1, col ] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}






				}

				if (col + 1 <= 8) {
					if (matriz[row, col + 1] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row && g->ListaSplay[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7){
										g->ListaSplay[o]->eliminarPrimerElemento();
									g->ListaSplay[o]->perdidos++;


									con++;
									if (con >= 10) {
										matriz[row, col + 1] = 0;
										c = false;
										for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
											for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
												Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
												if (matriz[i, j] == 1) {
													control->BackColor = System::Drawing::Color::Red;

												}
												else if (matriz[i, j] == 2) {
													control->BackColor = System::Drawing::Color::Black;
												}
												else if (matriz[i, j] == 3) {
													control->BackColor = System::Drawing::Color::Yellow;
												}
												else if (matriz[i, j] == 4) {
													control->BackColor = System::Drawing::Color::Pink;
												}
												else if (matriz[i, j] == 5) {
													control->BackColor = System::Drawing::Color::Cyan;
												}
												else if (matriz[i, j] == 6) {
													control->BackColor = System::Drawing::Color::Brown;
												}
												else if (matriz[i, j] == 7) {
													control->BackColor = System::Drawing::Color::Purple;
												}
												else if (matriz[i, j] == 8) {
													control->BackColor = System::Drawing::Color::Orange;
												}
												else {
													control->BackColor = System::Drawing::Color::Green;
												}

											}
										}
										break;
									}
									System::Threading::Thread::Sleep(1000);
								}
									else { c = false; }
								}
							}
						}
					}


					else if (matriz[row , col+1] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row  && g->ListaAVL[o]->y == col+1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row , col+1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}




					else if (matriz[row , col + 1] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row  && g->ListaBinario[o]->y == col+1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row , col+1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}

					else if (matriz[row, col + 1] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row && g->ListaHEAP[o]->y == col + 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col + 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}










				}

				if (col - 1 >= 0) {
					if (matriz[row, col -1] == 2) {
						for (int o = 0; o < g->ListaSplay->Count; o++) {
							if (g->ListaSplay[o]->x == row && g->ListaSplay[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7){
										g->ListaSplay[o]->eliminarPrimerElemento();
									g->ListaSplay[o]->perdidos++;

									con++;
									if (con >= 5) {
										matriz[row, col - 1] = 0;
										c = false;
										for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
											for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
												Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
												if (matriz[i, j] == 1) {
													control->BackColor = System::Drawing::Color::Red;

												}
												else if (matriz[i, j] == 2) {
													control->BackColor = System::Drawing::Color::Black;
												}
												else if (matriz[i, j] == 3) {
													control->BackColor = System::Drawing::Color::Yellow;
												}
												else if (matriz[i, j] == 4) {
													control->BackColor = System::Drawing::Color::Pink;
												}
												else if (matriz[i, j] == 5) {
													control->BackColor = System::Drawing::Color::Cyan;
												}
												else if (matriz[i, j] == 6) {
													control->BackColor = System::Drawing::Color::Brown;
												}
												else if (matriz[i, j] == 7) {
													control->BackColor = System::Drawing::Color::Purple;
												}
												else if (matriz[i, j] == 8) {
													control->BackColor = System::Drawing::Color::Orange;
												}
												else {
													control->BackColor = System::Drawing::Color::Green;
												}

											}
										}
										break;
									}
									System::Threading::Thread::Sleep(1000);
								}
									else { c = false; }
								}
							}
						}
					}

					else if (matriz[row , col-1] == 3) {
						for (int o = 0; o < g->ListaAVL->Count; o++) {
							if (g->ListaAVL[o]->x == row  && g->ListaAVL[o]->y == col-1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaAVL[o]->EliminarPrimerElemento();
										g->ListaAVL[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row , col-1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}
					}


					else if (matriz[row, col - 1] == 4) {
						for (int o = 0; o < g->ListaBinario->Count; o++) {
							if (g->ListaBinario[o]->x == row && g->ListaBinario[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaBinario[o]->EliminarPrimerElemento();
										g->ListaBinario[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col - 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}

					else if (matriz[row, col - 1] == 5) {
						for (int o = 0; o < g->ListaHEAP->Count; o++) {
							if (g->ListaHEAP[o]->x == row && g->ListaHEAP[o]->y == col - 1) {
								bool c = true;
								int con = 0;
								while (c) {
									if (matriz[row, col] == 7) {
										g->ListaHEAP[o]->EliminarPrimerElemento();
										g->ListaHEAP[o]->perdidos++;
										con++;
										if (con >= 10) {
											matriz[row, col - 1] = 0;
											c = false;

											for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
												for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
													Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
													if (matriz[i, j] == 1) {
														control->BackColor = System::Drawing::Color::Red;

													}
													else if (matriz[i, j] == 2) {
														control->BackColor = System::Drawing::Color::Black;
													}
													else if (matriz[i, j] == 3) {
														control->BackColor = System::Drawing::Color::Yellow;
													}
													else if (matriz[i, j] == 4) {
														control->BackColor = System::Drawing::Color::Pink;
													}
													else if (matriz[i, j] == 5) {
														control->BackColor = System::Drawing::Color::Cyan;
													}
													else if (matriz[i, j] == 6) {
														control->BackColor = System::Drawing::Color::Brown;
													}
													else if (matriz[i, j] == 7) {
														control->BackColor = System::Drawing::Color::Purple;
													}
													else if (matriz[i, j] == 8) {
														control->BackColor = System::Drawing::Color::Orange;
													}
													else {
														control->BackColor = System::Drawing::Color::Green;
													}

												}
											}
											break;
										}
										System::Threading::Thread::Sleep(1000);

									}
									else { c = false; }
								}
							}
						}

						}


				}







			}



			System::Threading::Thread::Sleep(g->tiempoDePlagas * 1000);

		}
	
	
	
	}
	
private: System::Void botonConfiguracion_Click(System::Object^ sender, System::EventArgs^ e) {
	//if (ventanaConfiguracion == nullptr || ventanaConfiguracion->IsDisposed) {
		ventanaConfiguracion = gcnew Configuracion();

		ventanaConfiguracion->botonBajoTiempoDeCosechaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonBajoTiempoDeCosecha);
		ventanaConfiguracion->botonMedioTiempoDeCosechaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonMedioTiempoDeCosecha);
		ventanaConfiguracion->botonAltoTiempoDeCosechaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonAltoTiempoDeCosecha);

		ventanaConfiguracion->botonBajoPreciosTiendaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonBajoPrecioTienda);
		ventanaConfiguracion->botonMedioPreciosTiendaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonMedioPrecioTienda);
		ventanaConfiguracion->botonAltoPreciosTiendaClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonAltoPrecioTienda);

		ventanaConfiguracion->botonBajoTiempoPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonBajoTiempoPlagas);
		ventanaConfiguracion->botonMedioTiempoPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonMedioTiempoPlagas);
		ventanaConfiguracion->botonAltoTiempoPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonAltoTiempoPlagas);

		ventanaConfiguracion->botonBajoProbabilidadPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonBajoProbabilidadPlagas);
		ventanaConfiguracion->botonMedioProbabilidadPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonMedioProbabilidadPlagas);
		ventanaConfiguracion->botonAltoProbabilidadPlagasClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAccionBotonAltoProbabilidadPlagas);

		
		
		ventanaConfiguracion->botonAceptarClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAceptar);
		ventanaConfiguracion->botonAceptarNombreClickedEvent += gcnew EventHandler(this, &MyForm::ventanaConfiguracionAceptarNombre);

	//}
	ventanaConfiguracion->Show();
}



private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	while (!backgroundWorker1->CancellationPending) {
		if (button6->Enabled) {
			button6->Enabled = false;
			ventanaSecundaria->Close();
			System::Threading::Thread::Sleep(5000);
			
		}
		else
		{
			button6->Enabled = true;
			System::Threading::Thread::Sleep(10000);
		}
	}
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	// Acciones después de completar el trabajo en segundo plano
}


private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if(g->ListaSplay[0]->xd == true){
		int x = g->ListaSplay[0]->contarElementos(g->ListaSplay[0]->raiz);
		label2->Text = x.ToString();
	}
	else{
		label2->Text = "no";
	}
	
	
}
	private: System::Void botonEspantapajaros_Click(System::Object^ sender, System::EventArgs^ e) {
		if (g->espantapajaros == 0){
			return;
		}

		int p = 0;
		int u = 0;
		bool flag = false;
		while (flag != true) {
			int h = 0;
			while (h < 8) {
				if (matriz[p, h] == 1) {

					u = h;

					flag = true;
				}
				h++;
			}
			p++;
		}
		p--;

		if (p - 2 >= 0 && matriz[p - 1, u] == 0) {

			matriz[p, u] = 6;
			matriz[p - 2, u] = 1;

			if (p - 1 > 0) {
				matrizbool[p-1, u] = true;
			}
			if (p - 1 >= 0 && u - 1 >= 0) {
			
				matrizbool[p - 1, u - 1] = true;
			}
			if (p - 1 >= 0 && u + 1 < 8) {
				matrizbool[p - 1, u + 1] = true;
			}
			if (u - 1 >= 0) {
				matrizbool[p, u - 1] = true;
			}
			if (u + 1 < 8) {
				matrizbool[p, u + 1] = true;
			}
			if (p + 1 < 8 && u - 1 >= 0) {
				matrizbool[p + 1, u - 1] = true;
			}
			if (p + 1 < 8) {
				matrizbool[p + 1, u] = true;
			}
			if(p + 1 < 8 && u + 1 < 8){
				matrizbool[p + 1, u + 1] = true;
			}
			
			
			g->ListaEspantapajaros->Insert(0, gcnew Espantapajaros());
			g->ListaEspantapajaros[0]->x = p;
			g->ListaEspantapajaros[0]->y = u;
			g->espantapajaros--;
		}
		else if (p + 2 < 8 && matriz[p + 1, u] == 0) {
			matriz[p, u] = 6;
			matriz[p + 2, u] = 1;
			if (p - 1 >= 0) {
				matrizbool[p - 1, u] = true;
			}
			if (p - 1 >= 0 && u - 1 >= 0) {

				matrizbool[p - 1, u - 1] = true;
			}
			if (p - 1 >= 0 && u + 1 < 8) {
				matrizbool[p - 1, u + 1] = true;
			}
			if (u - 1 >= 0) {
				matrizbool[p, u - 1] = true;
			}
			if (u + 1 < 8) {
				matrizbool[p, u + 1] = true;
			}
			if (p + 1 < 8 && u - 1 > 0) {
				matrizbool[p + 1, u - 1] = true;
			}
			if (p + 1 < 8) {
				matrizbool[p + 1, u] = true;
			}
			if (p + 1 < 8 && u + 1 < 8) {
				matrizbool[p + 1, u + 1] = true;
			}




			
			g->ListaEspantapajaros->Insert(0, gcnew Espantapajaros());
			g->ListaEspantapajaros[0]->x = p;
			g->ListaEspantapajaros[0]->y = u;
			g->espantapajaros--;
		}
		else if (u + 2 < 8 && matriz[p, u + 1] == 0) {
			matriz[p, u] = 6;
			matriz[p, u + 2] = 1;
			if (p - 1 >= 0) {
				matrizbool[p - 1, u] = true;
			}
			if (p - 1 >= 0 && u - 1 >= 0) {

				matrizbool[p - 1, u - 1] = true;
			}
			if (p - 1 >= 0 && u + 1 < 8) {
				matrizbool[p - 1, u + 1] = true;
			}
			if (u - 1 >= 0) {
				matrizbool[p, u - 1] = true;
			}
			if (u + 1 < 8) {
				matrizbool[p, u + 1] = true;
			}
			if (p + 1 < 8 && u - 1 > 0) {
				matrizbool[p + 1, u - 1] = true;
			}
			if (p + 1 < 8) {
				matrizbool[p + 1, u] = true;
			}
			if (p + 1 < 8 && u + 1 < 8) {
				matrizbool[p + 1, u + 1] = true;
			}



			
			g->ListaEspantapajaros->Insert(0, gcnew Espantapajaros());
			g->ListaEspantapajaros[0]->x = p;
			g->ListaEspantapajaros[0]->y = u;
			g->espantapajaros--;
		}
		else if (u - 2 >= 0 && matriz[p, u - 1] == 0) {

			matriz[p, u] = 6;
			matriz[p, u - 2] = 1;
			if (p - 1 >= 0) {
				matrizbool[p - 1, u] = true;
			}
			if (p - 1 >= 0 && u - 1 >= 0) {

				matrizbool[p - 1, u - 1] = true;
			}
			if (p - 1 >= 0 && u + 1 < 8) {
				matrizbool[p - 1, u + 1] = true;
			}
			if (u - 1 >= 0) {
				matrizbool[p, u - 1] = true;
			}
			if (u + 1 < 8) {
				matrizbool[p, u + 1] = true;
			}
			if (p + 1 < 8 && u - 1 > 0) {
				matrizbool[p + 1, u - 1] = true;
			}
			if (p + 1 < 8) {
				matrizbool[p + 1, u] = true;
			}
			if (p + 1 < 8 && u + 1 < 8) {
				matrizbool[p + 1, u + 1] = true;
			}




			
			g->ListaEspantapajaros->Insert(0, gcnew Espantapajaros());
			g->ListaEspantapajaros[0]->x = p;
			g->ListaEspantapajaros[0]->y = u;
			g->espantapajaros--;
		}
		else {
			label2->Text = "No se puede poner un espantapájaros aquí";
		}

		for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
			for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
				Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
				if (matriz[i, j] == 1) {
					control->BackColor = System::Drawing::Color::Red;

				}
				else if (matriz[i, j] == 2) {
					control->BackColor = System::Drawing::Color::Black;
				}
				else if (matriz[i, j] == 3) {
					control->BackColor = System::Drawing::Color::Yellow;
				}
				else if (matriz[i, j] == 4) {
					control->BackColor = System::Drawing::Color::Pink;
				}
				else if (matriz[i, j] == 5) {
					control->BackColor = System::Drawing::Color::Cyan;
				}
				else if (matriz[i, j] == 6) {
					control->BackColor = System::Drawing::Color::Brown;
				}
				else if (matriz[i, j] == 7) {
					control->BackColor = System::Drawing::Color::Purple;
				}
				else if (matriz[i, j] == 8) {
					control->BackColor = System::Drawing::Color::Orange;
				}
				else {
					control->BackColor = System::Drawing::Color::Green;
				}
				// Haga algo con el control
			}
		}

	}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaTop10 = gcnew top10Ventana();
	ventanaTop10->textBoxTop10->Height = 200;

	String^ topFinal = "Top 10" + "\r\n";
	int contador = 1;


	StreamReader^ lector = gcnew StreamReader(rutaArchivo);

	if (lector) {
		String^ linea;

		for (int i = 0; i < 10; i++) {
			linea = lector->ReadLine();
			if (linea == nullptr) {
				break; // Si no hay más líneas en el archivo, sal del bucle
			}

			array<String^>^ tokens = linea->Split(' ');
			if (tokens->Length >= 2) {
				String^ nombre = tokens[0];
				String^ valorStr = tokens[1];
				int valor = Int32::Parse(valorStr);

				topFinal += contador + ". " + nombre + " " + valor + "\r\n";
				contador++;
			}
		}

		lector->Close();
	}

	ventanaTop10->textBoxTop10->Text = topFinal;

	ventanaTop10->Show();


}
};
}
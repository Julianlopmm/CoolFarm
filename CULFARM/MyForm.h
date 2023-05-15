#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

		

		
			matriz[5, 5] = 1;
			const int rows = 8;    // Número de filas
			const int cols = 8;    // Número de columnas

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
					else {
						buttonGrid[row, col]->BackColor = System::Drawing::Color::Green;
					}
					buttonGrid[row, col]->Click += gcnew EventHandler(this, &MyForm::Button_Click);

					// Agregar el botón al TableLayoutPanel
					tableLayoutPanel1->Controls->Add(buttonGrid[row, col], col, row);
				}
			}
		

			




			// Crear y configurar los botones

			
			
			

		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
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
		
		System::ComponentModel::Container ^components;

		void Button_Click(Object^ sender, EventArgs^ e)
		{
			// Manejador de eventos para el clic de los botones
			Button^ button = dynamic_cast<Button^>(sender);
			MessageBox::Show("Has hecho clic en: " + button->Text);
		}

		array<Button^, 2>^ buttonGrid;


		cli::array<int, 2>^ matriz = gcnew cli::array<int, 2>(8, 8);
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

				if (p - 1 > 0) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					matriz[p, u] = 0;
					//label2->Text = "holi";
					matriz[p-1, u] = 1;
				}
				else {
					//label2->Text ="No se puede mover";
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {
						
						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {
						
								control->BackColor = System::Drawing::Color::Red;
									
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
				
				
				
				if (u -1 >= 0) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					//label2->Text = String::Format("p: {0} u: {1}", p, u);
					matriz[p, u] = 0;
					//label2->Text = "holi";
					matriz[p , u-1] = 1;
				}
				else {
					//label2->Text = "No se puede mover";
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

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

				

				if (u + 1 <= 7) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					//label2->Text = String::Format("p: {0} u: {1}", p, u);
					matriz[p, u] = 0;
					//label2->Text = "holi";
					matriz[p, u + 1] = 1;
				}
				else {
					//label2->Text = "No se puede mover";
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

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

				

				if (p + 1 <= 8) {
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					//label2->Text = String::Format("p: {0} u: {1}", p, u);
					matriz[p, u] = 0;
					//label2->Text = "holi";
					matriz[p+1 , u] = 1;
				}
				else {
					//label2->Text = "No se puede mover";
					p--;
					label2->Text = String::Format("p: {0} u: {1}", p, u);
					return;
				}
				for (int i = 0; i < tableLayoutPanel1->RowCount; i++) {
					for (int j = 0; j < tableLayoutPanel1->ColumnCount; j++) {

						Control^ control = tableLayoutPanel1->GetControlFromPosition(j, i);
						if (matriz[i, j] == 1) {

							control->BackColor = System::Drawing::Color::Red;

						}

						else {
							control->BackColor = System::Drawing::Color::Green;
						}
						// Haga algo con el control
					}
				}
			
			
			}
			
			
			
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->label2->Location = System::Drawing::Point(734, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 460);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Location = System::Drawing::Point(492, 160);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Form1_KeyDown);
			this->PerformLayout();

		}
#pragma endregion
	
		
	


private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

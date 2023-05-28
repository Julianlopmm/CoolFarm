#pragma once

namespace CULFARM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class Mercado : public System::Windows::Forms::Form
	{
	public:
		Mercado(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mercado()
		{
			if (components)
			{
				delete components;
			}
		}


	public:
		System::EventHandler^ botonArbolBinarioClickedEvent;
		System::EventHandler^ botonHeapClickedEvent;
		System::EventHandler^ botonAVLClickedEvent;
		System::EventHandler^ botonSplayClickedEvent;
		System::EventHandler^ vendeTodosClickedEvent;
		System::EventHandler^ botonComprarEspantapajarosClickedEvent;


	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ vendeT;
	private: System::Windows::Forms::Button^ botonComprarEspantapajaros;
		

	protected:
		void OnbotonArbolBinarioClicked() {
			if (botonArbolBinarioClickedEvent != nullptr) {
				botonArbolBinarioClickedEvent(this, EventArgs::Empty);
			}
		}

		void OnbotonHeapClicked() {
			if (botonHeapClickedEvent != nullptr) {
				botonHeapClickedEvent(this, EventArgs::Empty);
			}
		}

		void OnbotonAVLClicked() {
			if (botonAVLClickedEvent != nullptr) {
				botonAVLClickedEvent(this, EventArgs::Empty);
			}
		}

		void OnbotonSplayClicked() {
			if (botonSplayClickedEvent != nullptr) {
				botonSplayClickedEvent(this, EventArgs::Empty);
			}
		}

		void onVendeTodosClicked() {
			if (vendeTodosClickedEvent != nullptr) {
				vendeTodosClickedEvent(this, EventArgs::Empty);
			}
		}

		void onComprarEspantapajaros() {
			if (botonComprarEspantapajarosClickedEvent != nullptr) {
				botonComprarEspantapajarosClickedEvent(this, EventArgs::Empty);
			}
		}



	public: System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Button^ button2;
			System::Windows::Forms::Button^ button3;
			System::Windows::Forms::Button^ button4;
			System::Windows::Forms::Button^ button5;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->vendeT = (gcnew System::Windows::Forms::Button());
			this->botonComprarEspantapajaros = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(321, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Dinero actual: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(117, 77);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 87);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Binario Ordenado $200";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Mercado::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(240, 77);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(94, 87);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Heap $130";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Mercado::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(117, 170);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(94, 87);
			this->button4->TabIndex = 4;
			this->button4->Text = L"AVL $350";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Mercado::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(240, 170);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(94, 87);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Splay $600";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Mercado::button5_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Mercado::backgroundWorker1_DoWork);
			// 
			// vendeT
			// 
			this->vendeT->Location = System::Drawing::Point(181, 279);
			this->vendeT->Name = L"vendeT";
			this->vendeT->Size = System::Drawing::Size(94, 87);
			this->vendeT->TabIndex = 7;
			this->vendeT->Text = L"Vender Todo";
			this->vendeT->UseVisualStyleBackColor = true;
			this->vendeT->Click += gcnew System::EventHandler(this, &Mercado::vendeT_Click);
			// 
			// botonComprarEspantapajaros
			// 
			this->botonComprarEspantapajaros->Location = System::Drawing::Point(368, 77);
			this->botonComprarEspantapajaros->Name = L"botonComprarEspantapajaros";
			this->botonComprarEspantapajaros->Size = System::Drawing::Size(93, 180);
			this->botonComprarEspantapajaros->TabIndex = 8;
			this->botonComprarEspantapajaros->Text = L"Espantapájaros";
			this->botonComprarEspantapajaros->UseVisualStyleBackColor = true;
			this->botonComprarEspantapajaros->Click += gcnew System::EventHandler(this, &Mercado::botonComprarEspantapajaros_Click);
			// 
			// Mercado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 540);
			this->Controls->Add(this->botonComprarEspantapajaros);
			this->Controls->Add(this->vendeT);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Name = L"Mercado";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}




#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		OnbotonArbolBinarioClicked();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		OnbotonHeapClicked();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		OnbotonAVLClicked();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		OnbotonSplayClicked();
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void vendeT_Click(System::Object^ sender, System::EventArgs^ e) {
		onVendeTodosClicked();
	}
	private: System::Void botonComprarEspantapajaros_Click(System::Object^ sender, System::EventArgs^ e) {
		onComprarEspantapajaros();
	}
};
}
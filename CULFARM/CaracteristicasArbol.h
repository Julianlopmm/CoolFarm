#pragma once

namespace CULFARM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CaracteristicasArbol
	/// </summary>
	public ref class CaracteristicasArbol : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::EventHandler^ botonVenderClickedEvent;
		System::Windows::Forms::Label^ label7;
		int xa;
		int ya;
	public:
		System::Windows::Forms::Label^ label6;
		CaracteristicasArbol(void)
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
		~CaracteristicasArbol()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ARBOL;
	private: System::Windows::Forms::Label^ UBI;
	private: System::Windows::Forms::Label^ CANTFRUTOS;
	private: System::Windows::Forms::Label^ MONTO;
	private: System::Windows::Forms::Label^ VENDIDOS;
	private: System::Windows::Forms::Label^ PERDIDOS;
	private: System::Windows::Forms::Button^ VENDER;








	protected:

		void onBotonVenderClicked() {
			if (botonVenderClickedEvent != nullptr) {
				botonVenderClickedEvent(this, EventArgs::Empty);
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ARBOL = (gcnew System::Windows::Forms::Label());
			this->UBI = (gcnew System::Windows::Forms::Label());
			this->CANTFRUTOS = (gcnew System::Windows::Forms::Label());
			this->MONTO = (gcnew System::Windows::Forms::Label());
			this->VENDIDOS = (gcnew System::Windows::Forms::Label());
			this->PERDIDOS = (gcnew System::Windows::Forms::Label());
			this->VENDER = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 131);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &CaracteristicasArbol::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(150, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(341, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(574, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(722, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 22);
			this->label5->TabIndex = 4;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(864, 131);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 22);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// ARBOL
			// 
			this->ARBOL->AutoSize = true;
			this->ARBOL->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ARBOL->Location = System::Drawing::Point(24, 99);
			this->ARBOL->Name = L"ARBOL";
			this->ARBOL->Size = System::Drawing::Size(84, 26);
			this->ARBOL->TabIndex = 7;
			this->ARBOL->Text = L"ARBOL ";
			this->ARBOL->Click += gcnew System::EventHandler(this, &CaracteristicasArbol::label8_Click);
			// 
			// UBI
			// 
			this->UBI->AutoSize = true;
			this->UBI->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->UBI->Location = System::Drawing::Point(125, 99);
			this->UBI->Name = L"UBI";
			this->UBI->Size = System::Drawing::Size(124, 26);
			this->UBI->TabIndex = 8;
			this->UBI->Text = L"UBICACIÓN";
			// 
			// CANTFRUTOS
			// 
			this->CANTFRUTOS->AutoSize = true;
			this->CANTFRUTOS->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CANTFRUTOS->Location = System::Drawing::Point(266, 99);
			this->CANTFRUTOS->Name = L"CANTFRUTOS";
			this->CANTFRUTOS->Size = System::Drawing::Size(233, 26);
			this->CANTFRUTOS->TabIndex = 9;
			this->CANTFRUTOS->Text = L"CANTIDAD DE FRUTOS";
			// 
			// MONTO
			// 
			this->MONTO->AutoSize = true;
			this->MONTO->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MONTO->Location = System::Drawing::Point(528, 99);
			this->MONTO->Name = L"MONTO";
			this->MONTO->Size = System::Drawing::Size(168, 26);
			this->MONTO->TabIndex = 10;
			this->MONTO->Text = L"MONTO TOTAL ";
			// 
			// VENDIDOS
			// 
			this->VENDIDOS->AutoSize = true;
			this->VENDIDOS->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->VENDIDOS->Location = System::Drawing::Point(702, 99);
			this->VENDIDOS->Name = L"VENDIDOS";
			this->VENDIDOS->Size = System::Drawing::Size(116, 26);
			this->VENDIDOS->TabIndex = 11;
			this->VENDIDOS->Text = L"VENDIDOS";
			// 
			// PERDIDOS
			// 
			this->PERDIDOS->AutoSize = true;
			this->PERDIDOS->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->PERDIDOS->Location = System::Drawing::Point(845, 99);
			this->PERDIDOS->Name = L"PERDIDOS";
			this->PERDIDOS->Size = System::Drawing::Size(111, 26);
			this->PERDIDOS->TabIndex = 12;
			this->PERDIDOS->Text = L"PERDIDOS";
			// 
			// VENDER
			// 
			this->VENDER->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VENDER->Location = System::Drawing::Point(410, 198);
			this->VENDER->Name = L"VENDER";
			this->VENDER->Size = System::Drawing::Size(169, 50);
			this->VENDER->TabIndex = 13;
			this->VENDER->Text = L"VENDER";
			this->VENDER->UseVisualStyleBackColor = true;
			this->VENDER->Click += gcnew System::EventHandler(this, &CaracteristicasArbol::VENDER_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(463, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 26);
			this->label7->TabIndex = 14;
			this->label7->Click += gcnew System::EventHandler(this, &CaracteristicasArbol::label7_Click);
			// 
			// CaracteristicasArbol
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 260);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->VENDER);
			this->Controls->Add(this->PERDIDOS);
			this->Controls->Add(this->VENDIDOS);
			this->Controls->Add(this->MONTO);
			this->Controls->Add(this->CANTFRUTOS);
			this->Controls->Add(this->UBI);
			this->Controls->Add(this->ARBOL);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CaracteristicasArbol";
			this->Text = L"CaracteristicasArbol";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void VENDER_Click(System::Object^ sender, System::EventArgs^ e) {
	onBotonVenderClicked();
}
};
}

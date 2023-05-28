#pragma once


namespace CULFARM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Configuracion
	/// </summary>
	public ref class Configuracion : public System::Windows::Forms::Form
	{
	public:
		Configuracion(void)
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
		~Configuracion()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ label1;
	protected:

	public:
		System::EventHandler^ botonBajoTiempoDeCosechaClickedEvent;
		System::EventHandler^ botonMedioTiempoDeCosechaClickedEvent;
		System::EventHandler^ botonAltoTiempoDeCosechaClickedEvent;

		System::EventHandler^ botonBajoPreciosTiendaClickedEvent;
		System::EventHandler^ botonMedioPreciosTiendaClickedEvent;
		System::EventHandler^ botonAltoPreciosTiendaClickedEvent;

		System::EventHandler^ botonBajoTiempoPlagasClickedEvent;
		System::EventHandler^ botonMedioTiempoPlagasClickedEvent;
		System::EventHandler^ botonAltoTiempoPlagasClickedEvent;

		System::EventHandler^ botonBajoProbabilidadPlagasClickedEvent;
		System::EventHandler^ botonMedioProbabilidadPlagasClickedEvent;
		System::EventHandler^ botonAltoProbabilidadPlagasClickedEvent;


		System::EventHandler^ botonAceptarClickedEvent;
		System::EventHandler^ botonAceptarNombreClickedEvent;

		System::Windows::Forms::TextBox^ textBoxNombre;

		System::Windows::Forms::Button^ botonAceptarNombre;


	public:
	private: System::Windows::Forms::Label^ labelNombre;




	public: System::Windows::Forms::Button^ botonAceptar;
	public:



	protected:
		void onBotonBajoTiempoDeCosechaClicked() {
			if (botonBajoTiempoDeCosechaClickedEvent != nullptr) {
				botonBajoTiempoDeCosechaClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonMedioTiempoDeCosechaClicked() {
			if (botonMedioTiempoDeCosechaClickedEvent != nullptr) {
				botonMedioTiempoDeCosechaClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonAltoTiempoDeCosechaClicked() {
			if (botonAltoTiempoDeCosechaClickedEvent != nullptr) {
				botonAltoTiempoDeCosechaClickedEvent(this, EventArgs::Empty);
			}
		}

		void onBotonBajoPreciosTiendaClicked() {
			if (botonBajoPreciosTiendaClickedEvent != nullptr) {
				botonBajoPreciosTiendaClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonMedioPreciosTiendaClicked() {
			if (botonMedioPreciosTiendaClickedEvent != nullptr) {
				botonMedioPreciosTiendaClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonAltoPreciosTiendaClicked() {
			if (botonAltoPreciosTiendaClickedEvent != nullptr) {
				botonAltoPreciosTiendaClickedEvent(this, EventArgs::Empty);
			}
		}

		void onBotonBajoTiempoPlagasClicked() {
			if (botonBajoTiempoPlagasClickedEvent != nullptr) {
				botonBajoTiempoPlagasClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonMedioTiempoPlagasClicked() {
			if (botonMedioTiempoPlagasClickedEvent != nullptr) {
				botonMedioTiempoPlagasClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonAltoTiempoPlagasClicked() {
			if (botonAltoTiempoPlagasClickedEvent != nullptr) {
				botonAltoTiempoPlagasClickedEvent(this, EventArgs::Empty);
			}
		}

		void onBotonBajoProbabilidadPlagasClicked() {
			if (botonBajoProbabilidadPlagasClickedEvent != nullptr) {
				botonBajoProbabilidadPlagasClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonMedioProbabilidadPlagasClicked() {
			if (botonMedioProbabilidadPlagasClickedEvent != nullptr) {
				botonMedioProbabilidadPlagasClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonAltoProbabilidadPlagasClicked() {
			if (botonAltoProbabilidadPlagasClickedEvent != nullptr) {
				botonAltoProbabilidadPlagasClickedEvent(this, EventArgs::Empty);
			}
		}


		void onBotonAceptarClicked() {
			if (botonAceptarClickedEvent != nullptr) {
				botonAceptarClickedEvent(this, EventArgs::Empty);
			}
		}
		void onBotonAceptarNombreClicked() {
			if (botonAceptarNombreClickedEvent != nullptr) {
				botonAceptarNombreClickedEvent(this, EventArgs::Empty);
			}
		}




	public: System::Windows::Forms::Button^ botonBajoTiempoDeCosecha;
		  System::Windows::Forms::Button^ botonMedioTiempoDeCosecha;
		  System::Windows::Forms::Button^ botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha;
		  System::Windows::Forms::Button^ botonBajoPreciosTienda;
		  System::Windows::Forms::Button^ botonMedioPreciosTienda;
		  System::Windows::Forms::Button^ botonAltoPreciosTienda;
		  System::Windows::Forms::Label^ label2;
		  System::Windows::Forms::Button^ botonBajoTiempoPlagas;
		  System::Windows::Forms::Button^ botonMedioTiempoPlagas;
		  System::Windows::Forms::Button^ botonAltoTiempoPlagas;
		  System::Windows::Forms::Label^ label3;
		  System::Windows::Forms::Button^ botonBajoProbabilidadPlagas;
		  System::Windows::Forms::Button^ botonMedioProbabilidadPlagas;
		  System::Windows::Forms::Button^ botonAltoProbabilidadPlagas;
		  System::Windows::Forms::Label^ label4;

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
			this->botonBajoTiempoDeCosecha = (gcnew System::Windows::Forms::Button());
			this->botonMedioTiempoDeCosecha = (gcnew System::Windows::Forms::Button());
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha = (gcnew System::Windows::Forms::Button());
			this->botonBajoPreciosTienda = (gcnew System::Windows::Forms::Button());
			this->botonMedioPreciosTienda = (gcnew System::Windows::Forms::Button());
			this->botonAltoPreciosTienda = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->botonBajoTiempoPlagas = (gcnew System::Windows::Forms::Button());
			this->botonMedioTiempoPlagas = (gcnew System::Windows::Forms::Button());
			this->botonAltoTiempoPlagas = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->botonBajoProbabilidadPlagas = (gcnew System::Windows::Forms::Button());
			this->botonMedioProbabilidadPlagas = (gcnew System::Windows::Forms::Button());
			this->botonAltoProbabilidadPlagas = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->botonAceptar = (gcnew System::Windows::Forms::Button());
			this->textBoxNombre = (gcnew System::Windows::Forms::TextBox());
			this->labelNombre = (gcnew System::Windows::Forms::Label());
			this->botonAceptarNombre = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(82, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo de cosecha";
			// 
			// botonBajoTiempoDeCosecha
			// 
			this->botonBajoTiempoDeCosecha->Location = System::Drawing::Point(13, 38);
			this->botonBajoTiempoDeCosecha->Name = L"botonBajoTiempoDeCosecha";
			this->botonBajoTiempoDeCosecha->Size = System::Drawing::Size(75, 23);
			this->botonBajoTiempoDeCosecha->TabIndex = 1;
			this->botonBajoTiempoDeCosecha->Text = L"Bajo";
			this->botonBajoTiempoDeCosecha->UseVisualStyleBackColor = true;
			this->botonBajoTiempoDeCosecha->Click += gcnew System::EventHandler(this, &Configuracion::botonBajoTiempoDeCosecha_Click);
			// 
			// botonMedioTiempoDeCosecha
			// 
			this->botonMedioTiempoDeCosecha->Location = System::Drawing::Point(94, 38);
			this->botonMedioTiempoDeCosecha->Name = L"botonMedioTiempoDeCosecha";
			this->botonMedioTiempoDeCosecha->Size = System::Drawing::Size(75, 23);
			this->botonMedioTiempoDeCosecha->TabIndex = 2;
			this->botonMedioTiempoDeCosecha->Text = L"Medio";
			this->botonMedioTiempoDeCosecha->UseVisualStyleBackColor = true;
			this->botonMedioTiempoDeCosecha->Click += gcnew System::EventHandler(this, &Configuracion::botonMedioTiempoDeCosecha_Click);
			// 
			// botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha
			// 
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->Location = System::Drawing::Point(176, 37);
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->Name = L"botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha";
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->Size = System::Drawing::Size(75, 23);
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->TabIndex = 0;
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->Text = L"Alto";
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->UseVisualStyleBackColor = true;
			this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha->Click += gcnew System::EventHandler(this, &Configuracion::botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha_Click);
			// 
			// botonBajoPreciosTienda
			// 
			this->botonBajoPreciosTienda->Location = System::Drawing::Point(13, 94);
			this->botonBajoPreciosTienda->Name = L"botonBajoPreciosTienda";
			this->botonBajoPreciosTienda->Size = System::Drawing::Size(75, 23);
			this->botonBajoPreciosTienda->TabIndex = 3;
			this->botonBajoPreciosTienda->Text = L"Bajo";
			this->botonBajoPreciosTienda->UseVisualStyleBackColor = true;
			this->botonBajoPreciosTienda->Click += gcnew System::EventHandler(this, &Configuracion::botonBajoPreciosTienda_Click);
			// 
			// botonMedioPreciosTienda
			// 
			this->botonMedioPreciosTienda->Location = System::Drawing::Point(94, 94);
			this->botonMedioPreciosTienda->Name = L"botonMedioPreciosTienda";
			this->botonMedioPreciosTienda->Size = System::Drawing::Size(75, 23);
			this->botonMedioPreciosTienda->TabIndex = 6;
			this->botonMedioPreciosTienda->Text = L"Medio";
			this->botonMedioPreciosTienda->UseVisualStyleBackColor = true;
			this->botonMedioPreciosTienda->Click += gcnew System::EventHandler(this, &Configuracion::botonMedioPreciosTienda_Click);
			// 
			// botonAltoPreciosTienda
			// 
			this->botonAltoPreciosTienda->Location = System::Drawing::Point(175, 94);
			this->botonAltoPreciosTienda->Name = L"botonAltoPreciosTienda";
			this->botonAltoPreciosTienda->Size = System::Drawing::Size(75, 23);
			this->botonAltoPreciosTienda->TabIndex = 5;
			this->botonAltoPreciosTienda->Text = L"Alto";
			this->botonAltoPreciosTienda->UseVisualStyleBackColor = true;
			this->botonAltoPreciosTienda->Click += gcnew System::EventHandler(this, &Configuracion::botonAltoPreciosTienda_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(82, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Precios en la tienda";
			// 
			// botonBajoTiempoPlagas
			// 
			this->botonBajoTiempoPlagas->Location = System::Drawing::Point(13, 150);
			this->botonBajoTiempoPlagas->Name = L"botonBajoTiempoPlagas";
			this->botonBajoTiempoPlagas->Size = System::Drawing::Size(75, 23);
			this->botonBajoTiempoPlagas->TabIndex = 7;
			this->botonBajoTiempoPlagas->Text = L"Bajo";
			this->botonBajoTiempoPlagas->UseVisualStyleBackColor = true;
			this->botonBajoTiempoPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonBajoTiempoPlagas_Click);
			// 
			// botonMedioTiempoPlagas
			// 
			this->botonMedioTiempoPlagas->Location = System::Drawing::Point(94, 150);
			this->botonMedioTiempoPlagas->Name = L"botonMedioTiempoPlagas";
			this->botonMedioTiempoPlagas->Size = System::Drawing::Size(75, 23);
			this->botonMedioTiempoPlagas->TabIndex = 10;
			this->botonMedioTiempoPlagas->Text = L"Medio";
			this->botonMedioTiempoPlagas->UseVisualStyleBackColor = true;
			this->botonMedioTiempoPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonMedioTiempoPlagas_Click);
			// 
			// botonAltoTiempoPlagas
			// 
			this->botonAltoTiempoPlagas->Location = System::Drawing::Point(175, 150);
			this->botonAltoTiempoPlagas->Name = L"botonAltoTiempoPlagas";
			this->botonAltoTiempoPlagas->Size = System::Drawing::Size(75, 23);
			this->botonAltoTiempoPlagas->TabIndex = 9;
			this->botonAltoTiempoPlagas->Text = L"Alto";
			this->botonAltoTiempoPlagas->UseVisualStyleBackColor = true;
			this->botonAltoTiempoPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonAltoTiempoPlagas_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(82, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Tiempo de plagas";
			// 
			// botonBajoProbabilidadPlagas
			// 
			this->botonBajoProbabilidadPlagas->Location = System::Drawing::Point(13, 211);
			this->botonBajoProbabilidadPlagas->Name = L"botonBajoProbabilidadPlagas";
			this->botonBajoProbabilidadPlagas->Size = System::Drawing::Size(75, 23);
			this->botonBajoProbabilidadPlagas->TabIndex = 11;
			this->botonBajoProbabilidadPlagas->Text = L"Bajo";
			this->botonBajoProbabilidadPlagas->UseVisualStyleBackColor = true;
			this->botonBajoProbabilidadPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonBajoProbabilidadPlagas_Click);
			// 
			// botonMedioProbabilidadPlagas
			// 
			this->botonMedioProbabilidadPlagas->Location = System::Drawing::Point(94, 211);
			this->botonMedioProbabilidadPlagas->Name = L"botonMedioProbabilidadPlagas";
			this->botonMedioProbabilidadPlagas->Size = System::Drawing::Size(75, 23);
			this->botonMedioProbabilidadPlagas->TabIndex = 14;
			this->botonMedioProbabilidadPlagas->Text = L"Medio";
			this->botonMedioProbabilidadPlagas->UseVisualStyleBackColor = true;
			this->botonMedioProbabilidadPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonMedioProbabilidadPlagas_Click);
			// 
			// botonAltoProbabilidadPlagas
			// 
			this->botonAltoProbabilidadPlagas->Location = System::Drawing::Point(176, 211);
			this->botonAltoProbabilidadPlagas->Name = L"botonAltoProbabilidadPlagas";
			this->botonAltoProbabilidadPlagas->Size = System::Drawing::Size(75, 23);
			this->botonAltoProbabilidadPlagas->TabIndex = 13;
			this->botonAltoProbabilidadPlagas->Text = L"Alto";
			this->botonAltoProbabilidadPlagas->UseVisualStyleBackColor = true;
			this->botonAltoProbabilidadPlagas->Click += gcnew System::EventHandler(this, &Configuracion::botonAltoProbabilidadPlagas_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(82, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Probabilidad de plagas";
			// 
			// botonAceptar
			// 
			this->botonAceptar->Location = System::Drawing::Point(291, 352);
			this->botonAceptar->Name = L"botonAceptar";
			this->botonAceptar->Size = System::Drawing::Size(151, 64);
			this->botonAceptar->TabIndex = 15;
			this->botonAceptar->Text = L"Aceptar";
			this->botonAceptar->UseVisualStyleBackColor = true;
			this->botonAceptar->Click += gcnew System::EventHandler(this, &Configuracion::botonAceptar_Click);
			// 
			// textBoxNombre
			// 
			this->textBoxNombre->Location = System::Drawing::Point(424, 41);
			this->textBoxNombre->Name = L"textBoxNombre";
			this->textBoxNombre->Size = System::Drawing::Size(284, 20);
			this->textBoxNombre->TabIndex = 16;
			// 
			// labelNombre
			// 
			this->labelNombre->AutoSize = true;
			this->labelNombre->Location = System::Drawing::Point(421, 21);
			this->labelNombre->Name = L"labelNombre";
			this->labelNombre->Size = System::Drawing::Size(44, 13);
			this->labelNombre->TabIndex = 17;
			this->labelNombre->Text = L"Nombre";
			// 
			// botonAceptarNombre
			// 
			this->botonAceptarNombre->Location = System::Drawing::Point(424, 78);
			this->botonAceptarNombre->Name = L"botonAceptarNombre";
			this->botonAceptarNombre->Size = System::Drawing::Size(284, 23);
			this->botonAceptarNombre->TabIndex = 18;
			this->botonAceptarNombre->Text = L"Aceptar nombre";
			this->botonAceptarNombre->UseVisualStyleBackColor = true;
			this->botonAceptarNombre->Click += gcnew System::EventHandler(this, &Configuracion::botonAceptarNombre_Click);
			// 
			// Configuracion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 428);
			this->Controls->Add(this->botonAceptarNombre);
			this->Controls->Add(this->labelNombre);
			this->Controls->Add(this->textBoxNombre);
			this->Controls->Add(this->botonAceptar);
			this->Controls->Add(this->botonBajoProbabilidadPlagas);
			this->Controls->Add(this->botonMedioProbabilidadPlagas);
			this->Controls->Add(this->botonAltoProbabilidadPlagas);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->botonBajoTiempoPlagas);
			this->Controls->Add(this->botonMedioTiempoPlagas);
			this->Controls->Add(this->botonAltoTiempoPlagas);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->botonBajoPreciosTienda);
			this->Controls->Add(this->botonMedioPreciosTienda);
			this->Controls->Add(this->botonAltoPreciosTienda);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha);
			this->Controls->Add(this->botonMedioTiempoDeCosecha);
			this->Controls->Add(this->botonBajoTiempoDeCosecha);
			this->Controls->Add(this->label1);
			this->Name = L"Configuracion";
			this->Text = L"Configuracion";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void botonBajoTiempoDeCosecha_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonBajoTiempoDeCosechaClicked();
	}
	private: System::Void botonMedioTiempoDeCosecha_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonMedioTiempoDeCosechaClicked();
	}
	private: System::Void botonBajoTiempoDeCosechabotonAltoTiempoDeCosecha_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAltoTiempoDeCosechaClicked();
	}
	private: System::Void botonBajoPreciosTienda_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonBajoPreciosTiendaClicked();
	}
	private: System::Void botonMedioPreciosTienda_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonMedioPreciosTiendaClicked();
	}
	private: System::Void botonAltoPreciosTienda_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAltoPreciosTiendaClicked();
	}
	private: System::Void botonBajoTiempoPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonBajoTiempoPlagasClicked();
	}
	private: System::Void botonMedioTiempoPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonMedioTiempoPlagasClicked();
	}
	private: System::Void botonAltoTiempoPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAltoTiempoPlagasClicked();
	}
	private: System::Void botonBajoProbabilidadPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonBajoProbabilidadPlagasClicked();
	}
	private: System::Void botonMedioProbabilidadPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonMedioProbabilidadPlagasClicked();
	}
	private: System::Void botonAltoProbabilidadPlagas_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAltoProbabilidadPlagasClicked();
	}
	private: System::Void botonAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAceptarClicked();
	}
	private: System::Void botonAceptarNombre_Click(System::Object^ sender, System::EventArgs^ e) {
		onBotonAceptarNombreClicked();
	}
	};
}


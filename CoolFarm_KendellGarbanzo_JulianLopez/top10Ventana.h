namespace CULFARM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de top10Ventana
	/// </summary>
	public ref class top10Ventana : public System::Windows::Forms::Form
	{
	public:
		top10Ventana(void)
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
		~top10Ventana()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBoxTop10;
	protected:

	protected:

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
			this->textBoxTop10 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxTop10
			// 
			this->textBoxTop10->Location = System::Drawing::Point(12, 12);
			this->textBoxTop10->Multiline = true;
			this->textBoxTop10->Name = L"textBoxTop10";
			this->textBoxTop10->Size = System::Drawing::Size(721, 368);
			this->textBoxTop10->TabIndex = 0;
			this->textBoxTop10->TextChanged += gcnew System::EventHandler(this, &top10Ventana::textBox1_TextChanged);
			// 
			// top10Ventana
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(745, 392);
			this->Controls->Add(this->textBoxTop10);
			this->Name = L"top10Ventana";
			this->Text = L"top10Ventana";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
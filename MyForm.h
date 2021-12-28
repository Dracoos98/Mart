#pragma once
#include "Controladora.h"
namespace Marte {

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
			objcontroladora = new Controladora();
			bmpfondo = gcnew Bitmap("marte.png");
			bmpmeteorito = gcnew Bitmap("meteoritos.png");
			bmpmonigote = gcnew Bitmap("astronauta.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}delete objcontroladora, bmpfondo, bmpmeteorito, bmpmonigote;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
		Bitmap^ bmpfondo;
		Bitmap^ bmpmeteorito;
		Bitmap^ bmpmonigote;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 440);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		bf->Graphics->DrawImage(bmpfondo, 0, 0, (int)bf->Graphics->VisibleClipBounds.Width, (int)bf->Graphics->VisibleClipBounds.Height);
		objcontroladora->Dibujar_Monigote(bf->Graphics, bmpmonigote);
		objcontroladora->Insertar_Meteoritos();
		objcontroladora->Dibujar_Meteoritos(bf->Graphics, bmpmeteorito);
		objcontroladora->Colision();
		
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial Black", 25);
		System::Drawing::SolidBrush^ sb = gcnew System::Drawing::SolidBrush(Color::Black);
		if (objcontroladora->Gano()==true &&objcontroladora->retornar_vidas()>0)
		{
			timer1->Enabled = false;
			bf->Graphics->Clear(Color::White);
			timer1->Enabled = false;
			System::Drawing::Font^ f2 = gcnew System::Drawing::Font("Arial", 40);
			System::Drawing::SolidBrush^ sb2 = gcnew System::Drawing::SolidBrush(Color::DarkGreen);
			bf->Graphics->DrawString("GANASTE", f2, sb2, 40, 40);
		}
		else if (objcontroladora->Perdio() == true)
		{
			timer1->Enabled = false;
			bf->Graphics->Clear(Color::White);

			System::Drawing::Font^ f2 = gcnew System::Drawing::Font("Arial", 40);
			System::Drawing::SolidBrush^ sb2 = gcnew System::Drawing::SolidBrush(Color::DarkRed);
			bf->Graphics->DrawString("PERDISTE", f2, sb2, 40, 40);
		}
		bf->Graphics->DrawString("Vidas: " + objcontroladora->retornar_vidas().ToString() +
			" Tiempo: " + objcontroladora->retornar_tiempo().ToString() +
			" Meteoritos sin colisionar: " + objcontroladora->retornar_meteoritos_s().ToString(), f, sb, 20, 20);
		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objcontroladora->Desplazar_Monigote(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Desplazar_Monigote(direccion::derecha);
		if (e->KeyCode == Keys::Up) objcontroladora->Desplazar_Monigote(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Desplazar_Monigote(direccion::abajo);
	}
	};
}

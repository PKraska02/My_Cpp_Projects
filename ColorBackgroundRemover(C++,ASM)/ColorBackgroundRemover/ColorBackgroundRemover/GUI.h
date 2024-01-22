#pragma once
#include "CPPColorRemoverLIB.h"
#include <Windows.h>
#include <vector>
#include <utility>  
#include <fstream>
namespace ColorBackgroundRemover {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label7;

	private: System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: bool isPipetteActive = false;
	private: int power = 0; 
	private: System::Windows::Forms::ToolStripTextBox^ TextBoxPower;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;


	private: const int powerIncrement = 5;
	System::String^ selectedLanguage = "";
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::Label^ label10;
		   bool isSelecting = false;
		   bool isCutterSelected = false;
		   const int MaxPoints = 32;
		   int pointCounter = 0;
		   array<int>^ xValues = gcnew array<int>(MaxPoints);
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;



		   array<int>^ yValues = gcnew array<int>(MaxPoints);
		   

	//
		   array<System::Drawing::Point>^ CreatePointArray(int numberOfPoints) {
			   array<System::Drawing::Point>^ points = gcnew array<System::Drawing::Point>(numberOfPoints);

			   // Dodaj punkty do tablicy, korzystaj¹c z wczeœniej zapisanych wartoœci x i y
			   for (int i = 0; i < numberOfPoints; ++i) {
				   // SprawdŸ, czy istniej¹ wartoœci x i y dla danego indeksu
				   if (i < pointCounter) {
					   // Ustaw wspó³rzêdne x i y na wczeœniej zapisane wartoœci
					   points[i] = System::Drawing::Point(xValues[i], yValues[i]);
				   }
				   else {
					   // Domyœlne wartoœci, jeœli nie ma wczeœniej zapisanych danych
					   points[i] = System::Drawing::Point(i, i);
				   }
			   }

			   return points;
			}




	//

	System::Drawing::Color GetPixelColor(System::Drawing::Point point) {
			// Get the image from the pictureBox
			 System::Drawing::Bitmap^ bmp = dynamic_cast<System::Drawing::Bitmap^>(pictureBox1->Image);

			 // Check if the image is not null
			 if (bmp != nullptr) {
				// Get the color of the pixel at the specified point
				return bmp->GetPixel(point.X, point.Y);
			 }

		// If the image is null, return a default color
		return System::Drawing::Color::Black;
	}


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->TextBoxPower = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(840, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose language:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"C++", L"ASM" });
			this->comboBox1->Location = System::Drawing::Point(844, 98);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(134, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox1_SelectedIndexChanged);
			// 
			// toolStrip2
			// 
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripButton2,
					this->toolStripSeparator1, this->TextBoxPower, this->toolStripButton1, this->toolStripSeparator2, this->toolStripButton3, this->toolStripSeparator3,
					this->toolStripButton4
			});
			this->toolStrip2->Location = System::Drawing::Point(0, 0);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(1015, 27);
			this->toolStrip2->TabIndex = 3;
			this->toolStrip2->Text = L"toolStrip2";
			this->toolStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &GUI::toolStrip2_ItemClicked);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->AutoSize = false;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(43, 22);
			this->toolStripButton2->Text = L"Pippete";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &GUI::toolStripButton2_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// TextBoxPower
			// 
			this->TextBoxPower->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->TextBoxPower->Name = L"TextBoxPower";
			this->TextBoxPower->Size = System::Drawing::Size(100, 27);
			this->TextBoxPower->Click += gcnew System::EventHandler(this, &GUI::toolStripTextBox1_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->AutoSize = false;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(43, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &GUI::toolStripButton1_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->AutoSize = false;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(43, 22);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &GUI::toolStripButton3_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(24, 24);
			this->toolStripButton4->Text = L"toolStripButton4";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &GUI::toolStripButton4_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(151, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 26);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Decrease \r\npower";
			this->label2->Click += gcnew System::EventHandler(this, &GUI::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(211, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 26);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Increase \r\nPower";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Pipette";
			this->label4->Click += gcnew System::EventHandler(this, &GUI::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(766, 164);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Time C++";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(760, 190);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 20);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Time ASM";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(844, 164);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(145, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GUI::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(844, 190);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(145, 20);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &GUI::textBox2_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(840, 230);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 20);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Threads";
			this->label7->Click += gcnew System::EventHandler(this, &GUI::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(546, 14);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(97, 16);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Pippete Status:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(650, 14);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = L"\"\"\r\n";
			this->label9->Click += gcnew System::EventHandler(this, &GUI::label9_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"7";
			this->openFileDialog1->Title = L"Load Image";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(26, 445);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 35);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Load Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(815, 403);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 57);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Run";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 27);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 477);
			this->splitter1->TabIndex = 19;
			this->splitter1->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(269, 27);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Cutter";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(844, 277);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(145, 20);
			this->textBox3->TabIndex = 21;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &GUI::textBox3_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(613, 354);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &GUI::pictureBox1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(15, 54);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(613, 354);
			this->panel1->TabIndex = 17;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::panel1_Paint);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1015, 504);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->toolStrip2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Handling button click event


#pragma endregion
private: System::Void toolStripProgressBar1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	// This function will be called when the "Increase power" label is clicked
	// Increase the power by the specified increment
	this->power += powerIncrement;

	// Ensure that the power value is within the valid range (0 to 100)
	this->power = Math::Max(0, Math::Min(100, power));

	// Display the current power value in the textBoxPower
	TextBoxPower->Text = power.ToString();
}
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	// This function will be called when the "Decrease power" label is clicked
	// Decrease the power by the specified increment
	this->power -= powerIncrement;

	// Ensure that the power value is within the valid range (0 to 100)
	this->power = Math::Max(0, Math::Min(100, power));

	// Display the current power value in the textBoxPower
	TextBoxPower->Text = power.ToString();
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Pobierz indeks z wybranej opcji w comboBox1
	int selectedIndex = comboBox1->SelectedIndex;

	// Przypisz odpowiedni¹ wartoœæ do zmiennej prywatnej selectedLanguage
	if (selectedIndex == 0) {
		selectedLanguage = "C++";
	}
	else if (selectedIndex == 1) {
		selectedLanguage = "ASM";
	}
}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		// This function will be called when the pictureBox1 is clicked
			// Add your code here to handle the pictureBox1 click
		MouseEventArgs^ me = dynamic_cast<MouseEventArgs^>(e);
		if (isCutterSelected&& pointCounter < MaxPoints) {
			// Get the clicked point
			System::Drawing::Point clickedPoint = me->Location;
			xValues[pointCounter] = clickedPoint.X;
			yValues[pointCounter] = clickedPoint.Y;
			pointCounter++;
			// Use the clickedPoint as needed, for example, display in a MessageBox
			MessageBox::Show(String::Format("Clicked point - X: {0}, Y: {1}", clickedPoint.X, clickedPoint.Y));
		}
		else {
			// Optional: Inform the user that the maximum number of points has been reached
			MessageBox::Show("Maximum number of points reached!");
		}
			// Check if the left mouse button is clicked and the pipette is active
			if (me->Button == System::Windows::Forms::MouseButtons::Left && isPipetteActive) {
				// Get the clicked point
				isCutterSelected = false;
				System::Drawing::Point clickedPoint = me->Location;

				// Get the color of the clicked point
				System::Drawing::Color clickedColor = GetPixelColor(clickedPoint);

				// Convert the color components to string for display

				// TODO PODAÆ WYBRANY KOLOR DO FUNKCJI
				String^ colorInfo = String::Format("R: {0}, G: {1}, B: {2}", clickedColor.R, clickedColor.G, clickedColor.B);

				// Show the color information in a message box
				MessageBox::Show("Pipetted Color: " + colorInfo);

				// Reset the pipette active state to false
				isPipetteActive = false;
				if (isPipetteActive) {
					label9->Text = "Pipette activated";
				}
				else {
					label9->Text = "Pipette deactivated";
				}
			}
		
	}
	private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {

		// Set the pipette active state to true
		isPipetteActive = true;
		// Check the state of the pipette and update the text in textBox3
		if (isPipetteActive) {
			label9->Text = "Pipette activated";
		}
		else {
			label9->Text = "Pipette deactivated";
		}
	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStrip2_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void toolStripTextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.gif;*.png";
	openFileDialog1->Title = "Select an Image File";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Get the selected file name
		String^ selectedFileName = openFileDialog1->FileName;

		// Display the selected image in the PictureBox
		pictureBox1->Image = Image::FromFile(selectedFileName);
	}
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	// Get the Graphics object for drawing
	//Graphics^ g = e->Graphics;

	// Set the color and width of the border
	//Pen^ borderPen = gcnew Pen(Color::Black, 6);

	// Draw a border around the PictureBox
	//g->DrawRectangle(borderPen, pictureBox1->Left - 1, pictureBox1->Top - 1, pictureBox1->Width + 1, pictureBox1->Height + 1);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Drawing::Bitmap^ bmp = dynamic_cast<System::Drawing::Bitmap^>(pictureBox1->Image);

	array<System::Drawing::Point>^ myPointsArray;
	myPointsArray = CreatePointArray(pointCounter);

	const int MaxPoints = 32;
	int xVal[MaxPoints] = { 0 };
	int yVal[MaxPoints] = { 0 };
	for (int i = 0; i < Math::Min(myPointsArray->Length, MaxPoints); ++i) {
		xVal[i] = myPointsArray[i].X;
		yVal[i] = myPointsArray[i].Y;
	}

	if (bmp != nullptr) {
		// Pobierz dane obrazu
		System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height);
		//System::Drawing::Rectangle rect = System::Drawing::Rectangle();
		System::Drawing::Imaging::BitmapData^ bmpData = bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);


		// SprawdŸ wybrany jêzyk i przetwórz obraz odpowiedni¹ funkcj¹
		if (selectedLanguage == "C++") {
			ProcessImageCPP(static_cast<BYTE*>(bmpData->Scan0.ToPointer()), panel1->Width, panel1->Height, this->power,xVal,yVal, pointCounter);

		}
		else if (selectedLanguage == "ASM") {
			//ProcessImageAsm(static_cast<BYTE*>(bmpData->Scan0.ToPointer()), bmp->Width, bmp->Height, this->power);
		}
		else {
			MessageBox::Show("Nieprawid³owy jêzyk wybrany");
		}
		// Odblokuj obszar obrazu
		bmp->UnlockBits(bmpData);

		// Zaktualizuj pictureBox1 po przetworzeniu obrazu
		//pictureBox1->Invalidate();
		pictureBox1->Refresh();
	}
}	

	   bool IsPointInsidePolygon(int x, int y, int xValues[32], int yValues[32], int pointcount)
	   {
		   bool inside = false;

		   for (int i = 0, j = pointcount - 1; i < pointcount; j = i++) {
			   if ((yValues[i] > y) != (yValues[j] > y) &&
				   (x < (xValues[j] - xValues[i]) * (y - yValues[i]) / (yValues[j] - yValues[i]) + xValues[i])) {
				   inside = !inside;
			   }
		   }

		   return inside;
	   }

private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	isCutterSelected = !isCutterSelected;
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};

}


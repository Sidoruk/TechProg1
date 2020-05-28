#pragma once
#include "ClassField.h"

namespace kursgraf1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		int player_turn = 1;
		Game_Field& game_field = Game_Field::getInstance();
		int size_of_field = 0;
		bool opponent_is_server = false;

		int cell_height = 0;
		int cell_width = 0;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBoxMessage;
	private: System::Windows::Forms::RadioButton^ radioButtonServer;
	private: System::Windows::Forms::RadioButton^ radioButtonPeople;
	private: System::Windows::Forms::GroupBox^ groupBoxOpponent;
	private: System::Windows::Forms::TextBox^ textBoxSize;
	private: System::Windows::Forms::Button^ buttonSave;



	private: System::Windows::Forms::PictureBox^ pictureBox1;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->radioButtonServer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPeople = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxOpponent = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->textBoxSize = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBoxOpponent->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(38, 133);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 500);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(631, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->BackColor = System::Drawing::Color::White;
			this->textBoxMessage->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxMessage->Location = System::Drawing::Point(108, 12);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->ReadOnly = true;
			this->textBoxMessage->ShortcutsEnabled = false;
			this->textBoxMessage->Size = System::Drawing::Size(242, 19);
			this->textBoxMessage->TabIndex = 2;
			this->textBoxMessage->Text = L"Enter game parameters:";
			// 
			// radioButtonServer
			// 
			this->radioButtonServer->Location = System::Drawing::Point(108, 19);
			this->radioButtonServer->Name = L"radioButtonServer";
			this->radioButtonServer->Size = System::Drawing::Size(56, 17);
			this->radioButtonServer->TabIndex = 3;
			this->radioButtonServer->TabStop = true;
			this->radioButtonServer->Text = L"Server";
			this->radioButtonServer->UseVisualStyleBackColor = true;
			this->radioButtonServer->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonServer_CheckedChanged);
			// 
			// radioButtonPeople
			// 
			this->radioButtonPeople->AutoSize = true;
			this->radioButtonPeople->Location = System::Drawing::Point(108, 42);
			this->radioButtonPeople->Name = L"radioButtonPeople";
			this->radioButtonPeople->Size = System::Drawing::Size(58, 17);
			this->radioButtonPeople->TabIndex = 4;
			this->radioButtonPeople->TabStop = true;
			this->radioButtonPeople->Text = L"People";
			this->radioButtonPeople->UseVisualStyleBackColor = true;
			this->radioButtonPeople->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonPeople_CheckedChanged);
			// 
			// groupBoxOpponent
			// 
			this->groupBoxOpponent->Controls->Add(this->buttonSave);
			this->groupBoxOpponent->Controls->Add(this->textBoxSize);
			this->groupBoxOpponent->Controls->Add(this->radioButtonPeople);
			this->groupBoxOpponent->Controls->Add(this->radioButtonServer);
			this->groupBoxOpponent->Location = System::Drawing::Point(38, 45);
			this->groupBoxOpponent->Name = L"groupBoxOpponent";
			this->groupBoxOpponent->Size = System::Drawing::Size(541, 82);
			this->groupBoxOpponent->TabIndex = 5;
			this->groupBoxOpponent->TabStop = false;
			this->groupBoxOpponent->Text = L"Opponent";
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(435, 39);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(86, 37);
			this->buttonSave->TabIndex = 6;
			this->buttonSave->Text = L"Save and start";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// textBoxSize
			// 
			this->textBoxSize->Location = System::Drawing::Point(210, 16);
			this->textBoxSize->Name = L"textBoxSize";
			this->textBoxSize->Size = System::Drawing::Size(110, 20);
			this->textBoxSize->TabIndex = 5;
			this->textBoxSize->Text = L"Enter size of board";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(745, 648);
			this->Controls->Add(this->groupBoxOpponent);
			this->Controls->Add(this->textBoxMessage);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game Field";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBoxOpponent->ResumeLayout(false);
			this->groupBoxOpponent->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void radioButtonServer_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButtonPeople_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

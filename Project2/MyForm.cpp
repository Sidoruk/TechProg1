#include "MyForm.h"
#include <Windows.h>
#include "ClassField.h"

using namespace kursgraf1; // Название проекта
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
void main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	kursgraf1::MyForm form; //which form starts first
	Application::Run(% form);

}

System::Void kursgraf1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void kursgraf1::MyForm::radioButtonServer_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	opponent_is_server = true;
}

System::Void kursgraf1::MyForm::radioButtonPeople_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	opponent_is_server = false;
}

System::Void kursgraf1::MyForm::buttonSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	int N;
	try {
		N = System::Convert::ToInt32(textBoxSize->Text);
		if (N <= 0)
			throw 1;
		else {
			size_of_field = N;
			game_field.change_size_of_field(N);
			MyForm::radioButtonPeople->Enabled = false;
			MyForm::radioButtonServer->Enabled = false;
			MyForm::buttonSave->Enabled = false;
			MyForm::textBoxSize->Enabled = false;
			MyForm::pictureBox1->Enabled = true;
			cell_height = int(MyForm::pictureBox1->Height / N);
			cell_width = int(MyForm::pictureBox1->Width / N);

			Graphics^ ris = MyForm::pictureBox1->CreateGraphics();
			for(int i=0; i<size_of_field; i++)
				for (int j = 0; j < size_of_field; j++) {
					ris->FillRectangle(Brushes::Black, i * cell_width, j * cell_height, cell_width, cell_height);
					ris->FillRectangle(Brushes::White, i * cell_width + 1, j * cell_height + 1, cell_width - 2, cell_height - 2);
				}
		}


	}
	catch (...) {
		MessageBox::Show("Can't get size", "Error", MessageBoxButtons::OK);
	}
}

System::Void kursgraf1::MyForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int Curs_X = Cursor->Position.X - MyForm::pictureBox1->Location.X - MyForm::Location.X - 8;
	int Curs_Y = Cursor->Position.Y - MyForm::pictureBox1->Location.Y - MyForm::Location.Y - 30;
	bool cuccessful_set = false;

	int x, y;

	Graphics^ ris = MyForm::pictureBox1->CreateGraphics();
	
	try {
		for (x = 0; x < size_of_field; x++) {
			for (y = 0; y < size_of_field; y++) {
				if ((Curs_X > (x * cell_width)) && (Curs_X < ((x + 1) * cell_width)) && (Curs_Y > (y * cell_height)) && (Curs_Y < ((y + 1) * cell_height))) {
					cuccessful_set = MyForm::game_field.set_cell_value(x, y, 1);
					if (!cuccessful_set)
						throw 1;
					if (player_turn == 1) {
						ris->FillRectangle(Brushes::Red, x * cell_width + (cell_width/2 - 5), y * cell_height + 5, 10, cell_height - 10);
						ris->FillRectangle(Brushes::White, x * cell_width + (cell_width / 2 - 3), y * cell_height + 8, 6, cell_height - 16);
					}
					if (player_turn == 2) {
						ris->FillEllipse(Brushes::Green, x * cell_width + 5, y * cell_height + 5, cell_width - 10, cell_height - 10);
						ris->FillEllipse(Brushes::White, x * cell_width + 8, y * cell_height + 8, cell_width - 16, cell_height - 16);
					}
						
					if (player_turn == 1 && !opponent_is_server)
						player_turn = 2;
					else if (player_turn == 2 && !opponent_is_server)
						player_turn = 1;
					
				}
			}
		}
		if (game_field.is_filled() == false && opponent_is_server)
		{
			game_field.move_of_server(&x, &y);
			ris->FillEllipse(Brushes::Blue, x * cell_width + 5, y * cell_height + 5, cell_width - 10, cell_height - 10);
			ris->FillEllipse(Brushes::White, x * cell_width + 8, y * cell_height + 8, cell_width - 16, cell_height - 16);
		}
	}
	catch (...) {
		MessageBox::Show("Can't write there", "Error", MessageBoxButtons::OK);
	}
	if (game_field.is_filled()) {
		int winner = game_field.count_even_summs();

		if(winner == 1)
			MessageBox::Show("Winner is player 1!!!", "RESULTS", MessageBoxButtons::OK);
		else if(winner == 2)
			MessageBox::Show("Winner is player 2!!!", "RESULTS", MessageBoxButtons::OK);
		else
			MessageBox::Show("DRAW!!!", "RESULTS", MessageBoxButtons::OK);

		Application::Exit();
	}
}
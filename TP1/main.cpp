#include <stdio.h>
#include "Train.h"
#include <iostream>
#include <algorithm>

using namespace std;

struct sort_class {
	bool operator()(TRAIN a, TRAIN b) {
		return (a.number < b.number);
	}
}sort_class_number;

int main(void) {
	cout << "Variant 9" << endl << "Create class TRAIN" << endl << endl;
	int i;
	int j;
	bool found;
	bool equal;
	int num;
	int op = 0;
	TRAIN Trains[8];

	cout << "enter 1 to start working" << endl;
	cin >> i;
	if (i == 1) {
		cout << "firstly enter mass of TRAINs" << endl;
		for (i = 0; i < 8; i++) {
			do {
				cin >> Trains[i];
				equal = false;
				for (j = 0; j < i; j++) {
					if (Trains[j] == Trains[i]) {
						equal = true;
						break;
					}
				}
				if (equal) {
					cout << "Trains have same number, enter again!" << endl;
				}
			} while (equal);
		}

		cout << "Starting sort..." << endl;
		sort(Trains, Trains + 8, sort_class_number);
		cout << "Done!" << endl;
		system("pause");

		do {
			system("cls");
			cout << "choose operations:" << endl << "1 - show" << endl << "2 - sort" << endl << "3 - edit" <<  endl << "4 - search" << endl << "5 - exit" << endl;
			cin >> op;
			switch (op) {
			case 1:
				system("cls");
				cout << "list of TRAINs:" << endl;
				for (i = 0; i < 8; i++)
					cout << Trains[i];
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Starting sort..." << endl;
				sort(Trains, Trains + 8, sort_class_number);
				cout << "Done!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				
				do {
					
						cout << "choose element of mass to edit" << endl;
						cin >> j;
						if (j < 0 || j>7) {
							cout << "incorrect number of element!" << endl;
						}
					} while (j < 0 || j>7);
					do {
						Trains[j].edit();
						equal = false;
						for (i = 0; i <= 7; i++) {
							if ((Trains[j] == Trains[i]) && (i != j)) {
								equal = true;
							}
						}
						if (equal) {
							cout << "Trains have same number, enter again!" << endl;
						}
					} while (equal);
				break;
			case 4:
				system("cls");
				cout << "enter number to search: ";
				cin >> num;
				found = false;
				for (i = 0; i < 8; i++) {
					if (Trains[i].get_number() == num) {
						cout << Trains[i];
						found = true;
					}
				}
				if (!found) {
					cout << "no trains with number " << num << endl;
				}
				system("pause");
				break;
			case 5:
				break;
			default:
				cout << "incorrect operation!" << endl;
				system("pause");
			}
		} while (op != 5);
	}
}
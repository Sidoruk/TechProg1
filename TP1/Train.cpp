#include <stdio.h>
#include <string>
#include "Train.h"
#include <iostream>

using namespace std;

TRAIN::TRAIN() {
	Destination = "---";
	number = -1;
	hour = -1;
	minutes = -1;
}

TRAIN::~TRAIN() {

}

void TRAIN::set_destination() {
	cout << "enter destination: ";
	cin >> Destination;
	cout << endl;
}

void TRAIN::set_number() {
	do {
		cout << "enter number of train: ";
		cin >> number;
		cout << endl;
		if (number < 0)
			cout << "incorrect number!" << endl;
	} while (number < 0);
}

int TRAIN::get_number() {
	return number;
}

void TRAIN::set_hour() {
	do {
		cout << "enter hour: ";
		cin >> hour;
		if (hour < 0 || hour>23)
			cout << "incorrect hour!" << endl;
	} while (hour < 0 || hour>23);
}

void TRAIN::set_minutes() {
	do {
		cout << "enter minutes: ";
		cin >> minutes;
		cout << endl;
		if (minutes < 0 || minutes>59)
			cout << "incorrect minutes!" << endl;
	} while (minutes < 0 || minutes > 59);
}

void TRAIN::edit() {
	set_number();
	set_destination();
	set_hour();
	set_minutes();
}

std::ostream& operator<< (std::ostream& out, const TRAIN& train) {
	out << "Train number " << train.number << ":" << endl << "Destination: " << train.Destination << endl << "Time: " << train.hour << ":" << train.minutes << endl << endl;
	return out;
}

std::istream& operator>> (istream& in, TRAIN& train) {
	train.set_number();
	train.set_destination();
	train.set_hour();
	train.set_minutes();

	return in;
}

bool operator==(const TRAIN& T1, const TRAIN& T2) {
	return (T1.number == T2.number);
}
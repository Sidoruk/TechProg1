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

string TRAIN::get_destination() {
	return Destination;
}

void TRAIN::set_destination() {
	cout << "enter destination: ";
	cin >> Destination;
	cout << endl;
}

int TRAIN::get_number() {
	return number;
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

int TRAIN::get_hour() {
	return hour;
}

void TRAIN::set_hour() {
	do {
		cout << "enter hour: ";
		cin >> hour;
		if (hour < 0 || hour>23)
			cout << "incorrect hour!" << endl;
	} while (hour < 0 || hour>23);
}

int TRAIN::get_minutes() {
	return hour;
}

void TRAIN::set_minutes() {
	do {
		cout << "enter minutes: ";
		cin >> minutes;
		cout << endl;
		if (minutes < 0 || minutes>59)
			cout << "incorrect minutes!" << endl;
	} while (minutes < 0 || minutes>59);
}

std::ostream& operator<< (std::ostream& out, const TRAIN& train) {
	out << "Train number " << train.number << ":" << endl << "Destination: " << train.Destination << endl << "Time: " << train.hour << ":" << train.minutes << endl << endl;
	return out;
}

std::istream& operator>> (istream& in, TRAIN& train) {
	cout << "enter number: ";
	in >> train.number;
	cout << endl << "enter destination: ";
	in >> train.Destination;
	cout << endl << "enter hour: ";
	in >> train.hour;
	cout << "enter minutes: ";
	in >> train.minutes;
	cout << endl;

	return in;
}

TRAIN& TRAIN::operator=(const TRAIN& train) {
	Destination = train.Destination;
	number = train.number;
	hour = train.hour;
	minutes = train.minutes;

	return *this;
}
#include <stdio.h>
#include <string>
#include "Train.h"
#include <iostream>

using namespace std;

TRAIN::TRAIN() {

}

TRAIN::~TRAIN() {

}

string TRAIN::get_destination() {
	return Destination;
}

void TRAIN::set_destination() {
	
}

int TRAIN::get_number() {
	return number;
}

void TRAIN::set_number() {
	
}

int TRAIN::get_hour() {
	return hour;
}

void TRAIN::set_hour() {
	
}

int TRAIN::get_minutes() {
	return hour;
}

void TRAIN::set_minutes() {
	
}

std::ostream& operator<< (std::ostream& out, const TRAIN& train) {
	
}

std::istream& operator>> (istream& in, TRAIN& train) {

	return in;
}

TRAIN& TRAIN::operator=(const TRAIN& train) {

	return *this;
}
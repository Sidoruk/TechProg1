#pragma once
#include <stdio.h>
#include <string>

using namespace std;

class TRAIN {
private:
	string Destination;
	int number;
	int hour;
	int minutes;

public:
	TRAIN();

	string get_destination();
	void set_destination();

	int get_number();
	void set_number();

	int get_hour();
	void set_hour();

	int get_minutes();
	void set_minutes();

	~TRAIN();

	friend std::ostream& operator<< (std::ostream& out, const TRAIN& point);
	friend std::istream& operator>> (istream& cin, TRAIN& obj);
	TRAIN& operator=(const TRAIN& train);
	friend struct sort_class;
};
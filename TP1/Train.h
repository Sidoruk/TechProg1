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

	void set_destination();

	void edit();

	int get_number();
	void set_number();

	void set_hour();

	void set_minutes();

	~TRAIN();

	friend std::ostream& operator<< (std::ostream& out, const TRAIN& point);
	friend std::istream& operator>> (istream& cin, TRAIN& obj);
	friend bool operator==(const TRAIN& T1, const TRAIN& T2);
	friend struct sort_class;
};

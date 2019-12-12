#include <stdio.h>
#include "Train.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int i;
	TRAIN Trains[8];

	for (i = 0; i < 8; i++) {
		cin >> Trains[i];
	}

	for (i = 0; i < 8; i++)
		cout << Trains[i];

	system("pause");

}


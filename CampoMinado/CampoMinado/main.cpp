#include<iostream>

#include "function.h"

#include <array>
using std::array;

using std::string;
using std::cout;
using std::cin;
using std::endl;



int main(int argc, char* argv[]) {

	int aux = 0;

	cin >> aux;

	if (aux == 1) {
		campo_minado_LV1();
	}
	else if (aux == 2) {
		campo_minado_LV2();
	}
	else if (aux == 3) {
		campo_minado_LV3();
	}
	
	return 0;
}
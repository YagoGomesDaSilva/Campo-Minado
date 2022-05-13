#include<iostream>

#include "function.h"

#include <array>
using std::array;

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char* argv[]) {

    char dif = arc_dificuldade(argc, argv);


    if (dif == 'b') {
        campo_minado_LV1();
    }
    else if (dif == 'i') {
        campo_minado_LV2();
    }

    else if (dif == 'a') {
        campo_minado_LV3();
    }

    return 0;
}

#include "function.h"
#include "dif_rec.h"


int main(int argc, char* argv[]) {

    char dif = arc_dificuldade(argc, argv);
    
    if (dif == 'b') {
        
        auto start = steady_clock::now();
        campo_minado_LV1();
        auto end = steady_clock::now();

        auto duracao = end - start;
        cout << endl;
        cout << duration_cast<milliseconds>(duracao).count();

    }

    else if (dif == 'i') {
        campo_minado_LV2();
    }

    else if (dif == 'a') {
        campo_minado_LV3();
    }

   
    return 0;
}

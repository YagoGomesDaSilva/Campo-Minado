#include "function.h"
#include "dif_rec.h"



int main(int argc, char* argv[]) {

    informacoes();

    Record player;
    vector<Record> rec ;

    char dif = arc_dificuldade(rec, argc, argv);

    if (dif == 'b') {
        jogo_1(rec,"records_LV1.txt", player);
    }

    else if (dif == 'i') {
        jogo_2(rec, "records_LV2.txt", player);
    }

    else if (dif == 'a') {
        jogo_3(rec, "records_LV3.txt", player);
    }

    return 0;
}

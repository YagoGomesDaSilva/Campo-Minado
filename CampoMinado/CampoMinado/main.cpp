#include "function.h"
#include "dif_rec.h"
/*
criar uma variavel tempo passando por referencia para dentro da função campo_minado, e diminuir no final da execução
*/

int main(int argc, char* argv[]) {

    Record player;
    char dif = arc_dificuldade(argc, argv);

    void informacoes();

   
    if (dif == 'b') {
        jogo("records_LV1.txt", campo_minado_LV1(), player);
    }

    else if (dif == 'i') {
        jogo("records_LV2.txt", campo_minado_LV2(), player);
    }

    else if (dif == 'a') {
        jogo("records_LV3.txt", campo_minado_LV3(), player);
    }

    return 0;
}

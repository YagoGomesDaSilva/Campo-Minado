#include<iostream>

#include "function.h"

#include <array>
using std::array;

using std::string;
using std::cout;
using std::cin;
using std::endl;

//template<std::size_t SIZE>

int main(int argc, char* argv[]) {

	Ponto ponto;
	Chave game;

	array <array<int, SIZE_1 + 1>, SIZE_1 + 1 > matrizR = {};

	gerar_matriz(matrizR,SIZE_1, SIZE_1);

	gerar_bombas(matrizR,SIZE_1,SIZE_1,BOMBA_1);

	indice_bombas(matrizR, SIZE_1, SIZE_1);
	
	game.game_on = true;
	do {
		
		gerar_campo(matrizR, SIZE_1, SIZE_1, ponto);

		game.comando = true;
		while (game.comando) {

			game.comando = acoes_usuario(matrizR, SIZE_1, SIZE_1, ponto , game);
		}
		
		if (matrizR[ponto.pxU][ponto.pyU] == -1) {
			game.game_on = false;
		}

		system("cls");
	}while (game.game_on);
	
	return 0;
}
#include<iostream>

#include "function.h"

#include <array>
using std::array;

using std::string;
using std::cout;
using std::cin;
using std::endl;





int main(int argc, char* argv[]) {

	Ponto ponto;
	Chave game;

	array <array<int, SIZE_1 + 1>, SIZE_1 + 1 > matrizR = {};

	gerar_matriz(matrizR,SIZE_1, SIZE_1, game);

	gerar_bombas(matrizR,SIZE_1,SIZE_1,BOMBA_1);

	indice_bombas(matrizR, SIZE_1, SIZE_1);
	
	game.game_on = true;
	do {

		
		for (int i = 1; i < SIZE_1 + 1 ; i++) {
			for (int j = 1; j < SIZE_1 + 1; j++) {
				cout << matrizR[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << game.cont;
		cout << endl;
		
		gerar_campo(matrizR, SIZE_1, SIZE_1, ponto);
		
		game.comando = true;
		while (game.comando) {

			game.comando = acoes_usuario(matrizR, SIZE_1, SIZE_1, ponto , game);
		}
		
		printf("\033c");

		game.win = condicao_termino(matrizR, SIZE_1, SIZE_1, ponto, game, BOMBA_1);
		
	}while (game.game_on);

	mensagem_final(game);

	return 0;
}
#include "function.h"


bool campo_minado_LV1() {

	Ponto ponto;
	Chave game;

	array <array<int, SIZE_1 + 1>, SIZE_1 + 1 > arr = {};

	gerar_matriz(arr, SIZE_1, SIZE_1, game);

	gerar_bombas(arr, SIZE_1, SIZE_1, BOMBA_1);

	indice_bombas(arr, SIZE_1, SIZE_1);

	game.game_on = true;
	do {

		/*
		int aux = 0;
		for (int i = 1; i <= SIZE_1; i++) {
			for (int j = 1; j <= SIZE_1; j++) {
				cout << arr[i][j] << " ";
				if (arr[i][j] == -1) {
					aux++;
				}
			}
			cout << endl;
		}

		cout << endl;
		cout << game.cont_band;
		cout << endl;
		cout << game.cont_celula;
		cout << endl;
		cout << game.cont_revel;
		cout << endl;
		cout << aux;
		cout << endl;
		*/

		gerar_campo(arr, SIZE_1, SIZE_1, ponto);

		game.comando = true;
		while (game.comando) {

			game.comando = acoes_usuario(arr, SIZE_1, SIZE_1, ponto, game);
		}

		printf("\033c");

		game.win = condicao_termino(arr, SIZE_1, SIZE_1, ponto, game, BOMBA_1);

	} while (game.game_on);

	mensagem_final(game);

	return game.win;
}

bool campo_minado_LV2() {

	Ponto ponto;
	Chave game;

	array <array<int, SIZE_2 + 1>, SIZE_2 + 1 > arr = {};

	gerar_matriz(arr, SIZE_2, SIZE_2, game);

	gerar_bombas(arr, SIZE_2, SIZE_2, BOMBA_2);

	indice_bombas(arr, SIZE_2, SIZE_2);

	game.game_on = true;
	do {
		/*
		int aux = 0;
		for (int i = 1; i <= SIZE_2; i++) {
			for (int j = 1; j <= SIZE_2; j++) {
				cout << arr[i][j] << " ";
				if (arr[i][j] == -1) {
					aux++;
				}
			}
			cout << endl;
		}

		cout << endl;
		cout << game.cont_band;
		cout << endl;
		cout << game.cont_celula;
		cout << endl;
		cout << game.cont_revel;
		cout << endl;
		cout << aux;
		cout << endl;
		*/
		gerar_campo(arr, SIZE_2, SIZE_2, ponto);

		game.comando = true;
		while (game.comando) {

			game.comando = acoes_usuario(arr, SIZE_2, SIZE_2, ponto, game);
		}

		printf("\033c");

		game.win = condicao_termino(arr, SIZE_2, SIZE_2, ponto, game, BOMBA_2);

	} while (game.game_on);

	mensagem_final(game);

	return game.win;
}

bool campo_minado_LV3() {

	Ponto ponto;
	Chave game;

	array <array<int, SIZE_3C + 1>, SIZE_3C + 1 > arr = {};

	gerar_matriz(arr, SIZE_3L, SIZE_3C, game);

	gerar_bombas(arr, SIZE_3L, SIZE_3C, BOMBA_3);

	indice_bombas(arr, SIZE_3L, SIZE_3C);

	game.game_on = true;
	do {

		/*
		int aux =0;
		for (int i = 1; i <= SIZE_3L; i++) {
			for (int j = 1; j <= SIZE_3C; j++) {
				cout << arr[i][j] << " ";
				if (arr[i][j] == -1) {
					aux++;
				}
			}
			cout << endl;
		}

		cout << endl;
		cout << game.cont_band;
		cout << endl;
		cout << game.cont_celula;
		cout << endl;
		cout << game.cont_revel;
		cout << endl;
		cout << aux;
		cout << endl;
		*/

		gerar_campo(arr, SIZE_3L, SIZE_3C, ponto);

		game.comando = true;
		while (game.comando) {

			game.comando = acoes_usuario(arr, SIZE_3L, SIZE_3C, ponto, game);
		}

		printf("\033c");

		game.win = condicao_termino(arr, SIZE_3L, SIZE_3C, ponto, game, BOMBA_3);

	} while (game.game_on);

	mensagem_final(game);

	return game.win;

}



void mensagem_final(Chave& game) {
	if (game.win == true) {

		cout << "            §_§§       §__§     §§___§                 " << endl;
		cout << "            §___§§§____§___§__§§_____§                 " << endl;
		cout << "            §_____§§§_§____§_§§______§______§§         " << endl;
		cout << "             §_______§§_____§________§__§§§§_§         " << endl;
		cout << "             §_______________________§§§_____§         " << endl;
		cout << "             §______________________________§          " << endl;
		cout << "   §§§§§§_____§_____________________________§          " << endl;
		cout << "    §______§§§_____________________________§           " << endl;
		cout << "    §§_____________________________________§§§         " << endl;
		cout << "     §________________________________________§§§§     " << endl;
		cout << "      §________________________________________ _§§    " << endl;
		cout << "       §_______________________________________§       " << endl;
		cout << "       §§____________________§_______________§§        " << endl;
		cout << "       §_____________§§§§§§§§§_______________§         " << endl;
		cout << "      §_____________§§§§§§§§§§§_______§_______§§       " << endl;
		cout << "    §§____________§§§§§§§§§§§§§§________________§§     " << endl;
		cout << "   §_____________§§§§§§____§§§§§§___§___§_________§§   " << endl;
		cout << "  §_____________§§§§§______§§§§§§____§__§§__________§  " << endl;
		cout << "§§_____________§§§§__§______§§§§§§§__§§__§________§§   " << endl;
		cout << "§_____________§§§§__§§______§§§§§§§__§§§_§§___§§§§     " << endl;
		cout << "______________§§§__§_§§_____§§§§§§§§__§§§_§§__§        " << endl;
		cout << "_____________§§§___§§§_____§§§§§§§§§§_§§§§§§§__§       " << endl;
		cout << "_____________§§____§§§____§§§§§§§§§_§§§§§§§§§___§      " << endl;
		cout << "§§§__________§_____§§§§_§§§§§§        §__§§§§§___§     " << endl;
		cout << "   §§_______§§§____§§_§§§§§§§             §§§§§__§§    " << endl;
		cout << "    §_______§§§§___§_§§§§§  §        §    §§§§§§§§§§§§§" << endl;
		cout << "   §___§____§§§§§__§§§§§§  §      §§§        §__§§§§§§§" << endl;
		cout << "   §___§____§§§§§§§§§§§   §     §§         §_§§_§§§§§§§" << endl;
		cout << "  §____§____§§§§§§§§§§         §§      §§§§§_§§__§§§§§§" << endl;
		cout << " §_____§____§§§§§§§§§         §       §     §§§__§__§§§" << endl;
		cout << " §____§§____§§§§§§§§§                       §§§__§     " << endl;
		cout << "§______§____§§§§§§§§§§§§§                    §§§_§     " << endl;
		cout << "   §§§§_____§§§§§§       §              §§_§§§_§§      " << endl;
		cout << "      §__§__§§§§§§_§§§§§                     §§_§§     " << endl;
		cout << "      §_§§__§§§§§_§§_§§_§                     §§_§§    " << endl;
		cout << "      §_§_§_§§§§§_§_§§§§§                 §§§____§§    " << endl;
		cout << "      §_§_§_§§§§§_§_§§§§                     §____§___ " << endl;
		cout << "     §§§_§§§§§§§_§§§§§§       §     __§§§     _§__§___ " << endl;
		cout << "     §§§__§_§§§§__§§§§      §     §§____     §§§_§§§__ " << endl;
		cout << "      §_§___§_§_§           §     §___§§§     §§__§§§§§" << endl;
		cout << "        §__§§____§             _§§__§§__§     §§§_§§§§§" << endl;
		cout << "          §____§_§§           _§§__§___§      §_§§_§§§§" << endl;
		cout << "         §§_____§_§_§        _§§_§§__§§       §__§§§_§§" << endl;
		cout << "          §_______§_§        __§_§___§        §§__§§§__" << endl;
		cout << "                 §§§         §_§__§§         §§__§§§§__" << endl;
		cout << "                 §_§§_§     §_§_§§           §§_§§§§§__" << endl;
		cout << "                  §§§§§     §§§§     §      §§§§§§§§§__" << endl;
		cout << "                   §§§            §§§      §§§§§§§§§§§_" << endl;
		cout << "                    §§§__§                §§§§§§§§§§§§§" << endl;
		cout << "                     §§§_§               §§§§§§§§§§§§§§" << endl;
		cout << "                      §_§§              §§§§§§§§§§§§§§§" << endl;
		cout << "                        §§§            §§§§§§§§§§§§§§§§" << endl;
		cout << "                          §§§§        §§§§§§§§§§§§§§§§§" << endl;
		cout << "                             §§§§__§§§§§§§             " << endl;

		cout << endl;
		cout << " PARABENS !!! VOCE GANHOU !!! DATTEBAYO!!!";
		cout << endl;
	}

	if (game.win == false) {

		cout << "                       $¶     ¶     ¶¢" << endl;
		cout << "           ¶¶¶¶¶¶¶       ¶¢   ¶   ø¶" << endl;
		cout << "          ¶¶    ø¶¶¶      oø  ø  øo" << endl;
		cout << "          ¶¶       ¶¶¶     1   1    1o" << endl;
		cout << "        ¶¶¶¶¶        ¶¶¶7        1o¶¶¶ø" << endl;
		cout << "       ¶¶¶¶¶¶¶         ¶¶¶¶¶¶¶¶  1" << endl;
		cout << "     ¶¶¶¶¶¶¶¶¶¶¶                  o$¢" << endl;
		cout << "   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶          ¢  1ø   1¶¶" << endl;
		cout << "  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       1$   ¶" << endl;
		cout << " ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      ¶    o¶´" << endl;
		cout << " ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶     ¶¶" << endl;
		cout << "  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ " << endl;
		cout << "   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ " << endl;
		cout << "     ¶¶¶¶¶¶¶¶¶¶¶¶ " << endl;
		cout << "      ¶¶¶¶¶¶¶¶" << endl;

		cout << endl;
		cout << " VOCE FOI EXPLODIDO!!!";
		cout << endl;
	}

}

#ifndef FUNCTION_H

#define FUNCTION_H

#include <iostream>
#include <string>
#include <Windows.h>

#include <array>
using std::array;

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int SIZE_1 = 10;
const int BOMBA_1 = 10;

const int SIZE_2 = 15;
const int BOMBA_2 = 40;

const int SIZE_3L = 15;
const int SIZE_3C = 30;
const int BOMBA_3 = 100;

const int BORDA = NULL;
const int AUX_Z_I = 1000;
const int BANDEIRA = 500;
const int BAND_IN_BOMB= -10;
const int BOMB_IN_GAME = -1;



struct Ponto
{
	int pxB = NULL, pyB = NULL, pxU = NULL, pyU = NULL, aux = NULL;
};

struct Chave
{
	bool game_on = NULL, comando = NULL, win = NULL;
	int cont_band = NULL, cont_celula = NULL, cont_revel = NULL;
};

template<std::size_t SIZE>
void gerar_matriz(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Chave& game) {

	for (int i = 0; i < SIZE_L ; i++) {
		for (int j = 0; j < SIZE_C; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = BORDA;
			}
			else {
				arr[i][j] = 0;
				
			}
			game.cont_celula++;
		}
	}

}

template<std::size_t SIZE>
void gerar_bombas(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, const int BOMBA) {
	//geracao aleatoria das bombas

	srand((unsigned)time(NULL));
	Ponto ponto;

	for (int i = 1; i <= BOMBA; i++) {
		do {

			ponto.pxB = rand() % SIZE_L;
			ponto.pyB = rand() % SIZE_C;

			if(ponto.pxB == 0){
				ponto.pxB++;
			}
			if(ponto.pyB==0){
				ponto.pyB++;
			}

		} while (arr[ponto.pxB][ponto.pyB] == BOMB_IN_GAME);

		arr[ponto.pxB][ponto.pyB] = BOMB_IN_GAME;
	}
}

template<std::size_t SIZE>
void indice_bombas(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C) {
	//numeros ao redor das bombas
	for (int i = 1; i <= SIZE_L ; i++) {
		for (int j = 1; j <= SIZE_C ; j++) {

			if (arr[i][j] == -1) {

				for (int l = -1; l < 2; l++) {
					for (int c = -1; c < 2; c++) {

						if (i + l > SIZE_L - 1 || i + l < 0 || j + c > SIZE_C - 1 || j + c < 0) {
							continue;
						}
						else if (arr[i + l][j + c] == -1) {
							arr[i + l][j + c] = arr[i + l][j + c];
						}
						else
						{
							arr[i + l][j + c] ++;
						}

					}
				}

			}

		}
	}

}
template<std::size_t SIZE>
void revelar_zeros(array <array<int, SIZE>, SIZE>&arr, const int SIZE_L, const int SIZE_C, int x, int y, Chave& game) {

	if (!(x<0 || x > SIZE_L || y<0 || y > SIZE_C || x == 0 || y == 0)) {

		if (arr[x][y] == 0) {

			arr[x][y] = AUX_Z_I;

			revelar_zeros(arr, SIZE_L, SIZE_C, x, y - 1, game);//esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x, y + 1, game);//direita
			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y, game);//baixo
			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y, game);//cima


			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y - 1, game);//diagonal superior esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y + 1, game);// diagonal inferior dierita

			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y - 1, game);//diagonal inferior esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y + 1, game);//diagonal superior direita
			
		}
		else if (arr[x][y] >= 1 && arr[x][y] <= 5) {
			arr[x][y] = arr[x][y] + AUX_Z_I;
		}
	}
}

template<std::size_t SIZE>
void revelar_entorno(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game) {

	for (int l = -1; l < 2; l++) {
		for (int c = -1; c < 2; c++) {

			if (ponto.pxU + l > SIZE_L - 1 || ponto.pxU + l < 0 || ponto.pyU + c > SIZE_C - 1 || ponto.pyU + c < 0) {//se ultrapassar o limite
				continue;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] >= AUX_Z_I && arr[ponto.pxU + l][ponto.pyU + c] <= AUX_Z_I + 5) { //se o local ja foi revelado 
				continue;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] >= BANDEIRA + 1 && arr[ponto.pxU + l][ponto.pyU + c] <= BANDEIRA + 5) { // se tiver bandeira no local de indice 
				continue;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] <= (BAND_IN_BOMB)) { // se tiver bandeira no local da bomba 
				continue;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] == 0) { //se revelar um 0
				arr[ponto.pxU + l][ponto.pyU + c] = arr[ponto.pxU + l][ponto.pyU + c] + AUX_Z_I;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] >= 1 && arr[ponto.pxU + l][ponto.pyU + c] <= 5) { //se revelar um indice
				arr[ponto.pxU + l][ponto.pyU + c] = arr[ponto.pxU + l][ponto.pyU + c] + AUX_Z_I;
			}

			else if (arr[ponto.pxU + l][ponto.pyU + c] = BOMB_IN_GAME) { //se revelar uma bomba
				arr[ponto.pxU][ponto.pyU] = BOMB_IN_GAME;
			}

		}
	}

}

template<std::size_t SIZE>
bool revelar_unidade(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game) {
	do {
	
		cout << endl;
		cout << "Digite o numero da linha: ";
		cin >> ponto.pxU;
		cout << "Digite o numero da coluna: ";
		cin >> ponto.pyU;

		if (ponto.pxU<0 || ponto.pxU > SIZE_L || ponto.pyU<0 || ponto.pyU > SIZE_C || ponto.pxU == 0 || ponto.pyU == 0) {
			cout << endl;
			cout << "Jogada invalida! ";
			cout << endl;
		}
		else {


			if (arr[ponto.pxU][ponto.pyU] == 0) {
				revelar_zeros(arr, SIZE_L, SIZE_C, ponto.pxU, ponto.pyU, game);
			}

			else if (arr[ponto.pxU][ponto.pyU] >= 1 && arr[ponto.pxU][ponto.pyU] <= 5) { // se for um indice
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + AUX_Z_I;
			}

			else if (arr[ponto.pxU][ponto.pyU] >= BANDEIRA + 1 && arr[ponto.pxU][ponto.pyU] <= BANDEIRA + 5) { //bandeira no local dos indices
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + BANDEIRA;
			}

			else if (arr[ponto.pxU][ponto.pyU] <= (BAND_IN_BOMB)) { //bandeira no local da bomba
				arr[ponto.pxU][ponto.pyU] = BOMB_IN_GAME;
			}
			
			else if (arr[ponto.pxU][ponto.pyU] >= AUX_Z_I + 1 && arr[ponto.pxU][ponto.pyU] <= AUX_Z_I + 5){//se o local ja foi revelado 				
				revelar_entorno(arr, SIZE_L, SIZE_C, ponto, game);
			}
			
			return game.comando = false;
		}

	} while (true);
}

template<std::size_t SIZE>
bool manipular_bandeira(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game) {
	do {

		cout << endl;
		cout << "Digite o numero da linha: ";
		cin >> ponto.pxU;
		cout << "Digite o numero da coluna: ";
		cin >> ponto.pyU;

		if (ponto.pxU<0 || ponto.pxU > SIZE_L || ponto.pyU<0 || ponto.pyU > SIZE_C || ponto.pxU == 0 || ponto.pyU == 0) {
			cout << endl;
			cout << "Jogada invalida! ";
			cout << endl;
		}
		else if (arr[ponto.pxU][ponto.pyU] >= AUX_Z_I) {
			cout << endl;
			cout << "Local ja revelado! ";
			cout << endl;
		}
		else if (arr[ponto.pxU][ponto.pyU] == 0) {
			cout << endl;
			cout << "Local seguro! ";
			cout << endl;
			Sleep(2000);
			return game.comando = false;
		}
		else {

			//POR BANDEIRA
			if (arr[ponto.pxU][ponto.pyU] >= 1 && arr[ponto.pxU][ponto.pyU] <= 5) {
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + BANDEIRA;
			}
			else if (arr[ponto.pxU][ponto.pyU] == BOMB_IN_GAME) {
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + (BAND_IN_BOMB);
				ponto.pxU = NULL;
				ponto.pyU = NULL;
			}
			//RETIRAR BANDEIRA
			else if (arr[ponto.pxU][ponto.pyU] >= BANDEIRA + 1 && arr[ponto.pxU][ponto.pyU] <= BANDEIRA + 5) {
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] - BANDEIRA;
			}
			else if (arr[ponto.pxU][ponto.pyU] < (BAND_IN_BOMB)) {
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] - (BAND_IN_BOMB);
				ponto.pxU = NULL;
				ponto.pyU = NULL;
			}

			return game.comando = false;
		}

	} while (true);
}

template<std::size_t SIZE>
bool acoes_usuario(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game) {

	do {

		cout << endl;
		cout << "Escolha uma opcao: "<<endl;
		cout << "Revelar uninadade = 0 // Manipular bandeira = 1: ";
		cin >> ponto.aux;
		if (!(ponto.aux == 0 || ponto.aux == 1)) {
			cout << endl;
			cout << "Opcao invalida! ";
			cout << endl;
		}
		else {
			if(ponto.aux == 0){
				return revelar_unidade(arr,  SIZE_L, SIZE_C,  ponto,  game);
			}
			else if (ponto.aux == 1) {
				return manipular_bandeira(arr, SIZE_L, SIZE_C, ponto, game);
			}
		}

	} while (true);
}

template<std::size_t SIZE>
void gerar_campo(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto) {
	//inicio geracao do campo
	for (int l = 1; l <= SIZE_L ; l++) {

		if (l == 1) {
			cout << "  ";

			for (int num = 1; num <= SIZE_C ; num++) {//geração dos numeros em cima da matriz
				if (num >= 10) {
					cout << num << " ";
				}
				else {
					cout << " " << num << " ";
				}
			}
			//geraçao  dos numeros à esquerda da matiz
			cout << endl;
			if (l >= 10) {
				cout << l << " ";
			}
			else {
				cout << " " << l << " ";
			}
		}

		else if (l >= 10) {
			cout << l << " ";
		}
		else {

			cout << " " << l << " ";
		}

		for (int c = 1; c <= SIZE_C ; c++) {

			if (arr[l][c] == BOMB_IN_GAME) {//escondendo as bombas
				cout << "X  ";
			}

			else if (arr[l][c] >= AUX_Z_I + 1 && arr[l][c] <= AUX_Z_I + 5) {//impressao dos locais de indice das bombas ja escolhidos pelo usuario			
				cout << arr[l][c] % AUX_Z_I << "  ";
			}
			
			else if (arr[l][c] == AUX_Z_I) {//caso seja 0 o local permanece 0
					cout << "0  ";
			}

			else if (arr[l][c] >= BANDEIRA + 1 && arr[l][c] <= BANDEIRA + 5) {//bandeira no local dos indices
				cout << "B  ";
			}

			else if (arr[l][c] < (BAND_IN_BOMB)) {//bandeira no local da bomba
				cout << "B  ";
			}

			else {
				cout << "X  ";
			}

		}

		cout << endl;
	}
}


template<std::size_t SIZE>
bool condicao_termino(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game, const int BOMBA) {

	game.cont_band = 0;
	game.cont_revel= 0;
	for (int i = 1; i <= SIZE_L; i++) {
		for (int j = 1; j <= SIZE_C; j++) {

			if (arr[i][j] >= AUX_Z_I) {
				game.cont_revel++;
			}

			if (arr[i][j] == (BAND_IN_BOMB) + (BOMB_IN_GAME)) { // CONTA QUANTAS BANDEIRAS FORAM POSICIONADAS NAS BOMBAS
				game.cont_band++;
			}
			else if (arr[i][j] >= BANDEIRA + 1 && arr[i][j] <= BANDEIRA + 5) {
				game.cont_band--;
			}

		}
	}

	if ((game.cont_celula == game.cont_revel + BOMBA) && (game.cont_band == BOMBA)) { // Condicao de vitoria 
		game.game_on = false;
		return true;
	}

	else if (arr[ponto.pxU][ponto.pyU] == BOMB_IN_GAME  || arr[ponto.pxU][ponto.pyU] == (BAND_IN_BOMB)+(BOMB_IN_GAME)) { // conticao de derrota 
		game.game_on = false;
		return false;
	}

}

void mensagem_final(Chave& game);

bool campo_minado_LV1();

bool campo_minado_LV2();

bool campo_minado_LV3();

#endif
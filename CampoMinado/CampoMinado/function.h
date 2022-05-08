#ifndef FUNCTION_H

#define FUNCTION_H

#include<iostream>
#include <string>

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

struct Ponto
{
	int pxB = NULL, pyB = NULL, pxU = NULL, pyU = NULL, aux = NULL;
};

struct Chave
{
	bool game_on = NULL, comando = NULL, bandeira = NULL;
};

template<std::size_t SIZE>
void gerar_matriz(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C) {

	for (int i = 0; i < SIZE_L; i++) {
		for (int j = 0; j < SIZE_C; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = BORDA;
			}
			else {
				arr[i][j] = 0;
			}

		}
	}

}

template<std::size_t SIZE>
void gerar_bombas(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, const int BOMBA) {
	//geracao aleatoria das bombas
	srand((unsigned)time(NULL));
	Ponto ponto;
	for (int i = 1; i < BOMBA + 1; i++) {
		do {

			ponto.pxB = rand() % SIZE_L;
			ponto.pyB = rand() % SIZE_C;

		} while (arr[ponto.pxB][ponto.pyB] == -1);

		arr[ponto.pxB][ponto.pyB] = -1;
	}
}

template<std::size_t SIZE>
void indice_bombas(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C) {
	//numeros ao redor das bombas
	for (int i = 1; i < SIZE_L + 1; i++) {
		for (int j = 1; j < SIZE_C + 1; j++) {

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
void revelar_zeros(array <array<int, SIZE>, SIZE>&arr, const int SIZE_L, const int SIZE_C, int x, int y) {

	if (!(x<0 || x > SIZE_L || y<0 || y > SIZE_C || x == 0 || y == 0)) {

		if (arr[x][y] == 0) {

			arr[x][y] = 2000;

			revelar_zeros(arr, SIZE_L, SIZE_C, x, y - 1);//esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x, y + 1);//direita
			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y);//baixo
			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y);//cima


			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y - 1);//diagonal superior esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y + 1);// diagonal inferior dierita

			revelar_zeros(arr, SIZE_L, SIZE_C, x + 1, y - 1);//diagonal inferior esquerda
			revelar_zeros(arr, SIZE_L, SIZE_C, x - 1, y + 1);//diagonal superior direita
			
		}
		else if (arr[x][y] >= 1 && arr[x][y] <= 5) {
			arr[x][y] = arr[x][y] + 1000;
		}
	}
}

template<std::size_t SIZE>
bool acoes_usuario(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto, Chave& game) {

	cout << endl;
	cout << "Digite o numero da linha: ";
	cin >> ponto.pxU;
	cout << "Digite o numero da coluna: ";
	cin >> ponto.pyU;

	if (ponto.pxU<0 || ponto.pxU > SIZE_L || ponto.pyU<0 || ponto.pyU > SIZE_C || ponto.pxU == 0 || ponto.pyU == 0) {
		cout << endl;
		cout << "Jogada invalida! ";
	}
	else {

		game.bandeira = true;
		cout << endl;
		cout << "Posicionar ou remover bandeira ? ( SIM = 1 // NAO = Qualquer numero )";
		cin >> ponto.aux;
		if (ponto.aux == 1) {

			do {

				if ((arr[ponto.pxU][ponto.pyU] == 2000)||((arr[ponto.pxU][ponto.pyU] > 1000 && arr[ponto.pxU][ponto.pyU] <= 1000 + 5))) {
					cout << endl;
					cout << "Jogada invalida! ";
					game.bandeira = false;
				}
				else {

					do {
						cout << endl;
						cout << "Remover bandeira = 0 // Posicionar bandeira = 1 ?";
						cin >> ponto.aux;

						if (ponto.aux != 0 || ponto.aux != 1) {
							cout << endl;
							cout << "Jogada invalida! ";
							game.bandeira = false;
						}
						else {

							if (ponto.aux = 1) {

								if ( (arr[ponto.pxU][ponto.pyU] > 1000 + 500 && arr[ponto.pxU][ponto.pyU] <= 1000 + 505 )||( arr[ponto.pxU][ponto.pyU] < (-10)) ){
									cout << endl;
									cout << "Posicionamento invalido! ";
								}
								else {

									if (arr[ponto.pxU][ponto.pyU] == -1) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + (-10);
									}
									else if (arr[ponto.pxU][ponto.pyU] >= 1 && arr[ponto.pxU][ponto.pyU] <= 5) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + 1000 + 500;
									}
									else if (arr[ponto.pxU][ponto.pyU] == 0) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + 500;
									}
								}

							}
							else {

								if ( (arr[ponto.pxU][ponto.pyU] > 1000 && arr[ponto.pxU][ponto.pyU] <= 1000 + 5) || (arr[ponto.pxU][ponto.pyU] < - 1) ) {
										cout << endl;
										cout << "Remoção invalida! ";
								}

								else {

									if (arr[ponto.pxU][ponto.pyU] == -1) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + (+10);
									}
									else if (arr[ponto.pxU][ponto.pyU] >= 1 && arr[ponto.pxU][ponto.pyU] <= 5) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] - 1000 - 500;
									}
									else if (arr[ponto.pxU][ponto.pyU] == 500) {
										arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] - 500;
									}
								}


							}


						}

					} while (game.bandeira);

				}
			
			} while (game.bandeira);
			
		}
		else {

			if (arr[ponto.pxU][ponto.pyU] == 0) {
				revelar_zeros(arr, SIZE_L, SIZE_C, ponto.pxU, ponto.pyU);
			}
			else if (arr[ponto.pxU][ponto.pyU] >= 1 && arr[ponto.pxU][ponto.pyU] <= 5) {
				arr[ponto.pxU][ponto.pyU] = arr[ponto.pxU][ponto.pyU] + 1000;
			}

		}

		return game.comando = false;
	}

}

template<std::size_t SIZE>
void gerar_campo(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C, Ponto& ponto) {
	//inicio geracao do campo
	for (int l = 1; l < SIZE_L + 1; l++) {

		if (l == 1) {
			cout << "   ";

			for (int num = 1; num < SIZE_L + 1; num++) {//geração dos numeros em cima da matriz
				cout << num << " ";
			}
			//geraçao  dos numeros à esquerda da matiz
			cout << endl;
			cout << " " << l << " ";
		}

		else if (l == 10) {
			cout << l << " ";
		}
		else {
			cout << " " << l << " ";
		}

		for (int c = 1; c < SIZE_C + 1; c++) {

			if (arr[l][c] == -1) {//escondendo as bombas
				cout << "X ";
			}
			else if ((arr[l][c] > 1000 && arr[l][c] <+ 1000 + 5) && (arr[l][c] < 2000)) {//impressao dos locais de indice das bombas ja escolhidos pelo usuario
				
				cout << arr[l][c] % 1000 << " ";
				
			}
			
			else if ((arr[l][c] > 1000 + 500 && arr[l][c] < +1000 + 500+ 5) && (arr[l][c] < (-10)) ){//impressao dos bandeiras

				cout << "B" << " ";
				
			}
			
			else if (arr[l][c] == 2000) {//caso seja 0 o local permanece 0
					cout << "0 ";
			}

			else {
				cout << "X ";
			}
			

		}

		cout << endl;
	}
}
#endif
#ifndef FUNCTION_H

#define FUNCTION_H

#include<iostream>
#include<Windows.h>
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

struct Ponto
{
	int pxB = NULL, pyB = NULL, pxU = NULL, pyU = NULL;
};

struct Chave
{
	bool game_on = NULL, comando = NULL;
};

template<std::size_t SIZE>
void gerar_matriz(array <array<int, SIZE>, SIZE>& arr, const int SIZE_L, const int SIZE_C) {

	for (int i = 1; i < SIZE_L; i++) {
		for (int j = 1; j < SIZE_C; j++) {

			arr[i][j] = 0;

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

		if (arr[ponto.pxU][ponto.pyU] == 0) {
			arr[ponto.pxU][ponto.pyU] = 5000;
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
			else if (arr[l][c] > 1000) {//impressao dos locais de bombas ja escolhidos pelo usuario

				cout << arr[l][c] % 1000 << " ";
			}
			else if (l == ponto.pxU && c == ponto.pyU) {//impressao do local escolhido pelo usuario

				cout << arr[l][c] << " ";
				arr[l][c] = arr[l][c] + 1000;//garantre a impressao dos locais escolhidos pelo usuario
			}
			else {

				if (arr[l][c] == 5000) {//caso seja 0 o local permanece 0
					cout << "0 ";
				}
				else {
					cout << "X ";
				}
			}

		}

		cout << endl;
	}
}

#endif
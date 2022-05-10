#include <iostream>
using namespace std;

int main() {

	int arr[11][11], win = 0, n_unidades = 0;
	int arr2[16][16], win2 = 0, n_unidades2 = 0;
	int arr3[16][31], win3 = 0, n_unidades3 = 0;

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = 1;
				win++;
				n_unidades++;
			}
			else {
				arr[i][j] = 0;
				n_unidades++;
			}

		}
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	cout << win;
	cout << endl;
	cout << n_unidades;
	cout << endl;
	cout << endl;

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = 1;
				win2++;
				n_unidades2++;
			}
			else {
				arr[i][j] = 0;
				n_unidades2++;
			}

		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	cout << win2;
	cout << endl;
	cout << n_unidades2;
	cout << endl;
	cout << endl;
	///////////////////////////////////////////////
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 31; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = 1;
				win3++;
				n_unidades3++;
			}
			else {
				arr[i][j] = 0;
				n_unidades3++;
			}

		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 31; j++) {
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}


	cout << endl;
	cout << win3;

	cout << endl;
	cout << n_unidades3;
	cout << endl;
	cout << endl;


	return 0;
}
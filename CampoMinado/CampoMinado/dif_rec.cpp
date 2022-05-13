#include "dif_rec.h"

char arc_dificuldade(int& argc, char* argv[]) {

	std::ifstream dificuldade{};
	dificuldade.open("dificuldade.txt", std::ios::app);

	char dif;
	dif = dificuldade.get();

	for (int i = 0; i < argc; i++) {

		if (strcmp(argv[i], "-h") == 0) {
			cout << "BEM VINDO AO CAMPO MINADO" << endl;
			cout << "REGRAS \n ---------" << endl;
			cout << "COMO JOGAR \n ---------" << endl;

		}
		else if (strcmp(argv[i], "-d") == 0) {
			cout << "SELECIONE NOVA DIFICULDADE \n __________ \n b = Fácil \n i = Intermediário \n a = Avançado" << endl;
			remove("dificuldade.txt");
			std::ofstream dificuldade;
			dificuldade.open("dificuldade.txt", std::ios::out);
			char dif;
			cin >> dif;
			dificuldade << dif << endl;
			dificuldade.close();
		}
	}

	return dif;
}

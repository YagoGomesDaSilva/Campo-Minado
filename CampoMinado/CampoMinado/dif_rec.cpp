#include "dif_rec.h"

void sort(vector<Record>& rec) {
	for (int k = 0; k < rec.size(); k++) {
		int pos = 0;
		for (int i = k + 1; i < rec.size(); i++) {
			if (rec[i].milliseconds < rec[pos].milliseconds) {
				pos = i;
			}
		}
		Record tmp = rec[pos];
		rec[pos] = rec[k];
		rec[k] = tmp;
	}
}

std::ostream& operator<<(std::ostream& os, Record const& player) {
	return os << '{' << player.nome << ',' << player.milliseconds / 1000.0 << '}';
}

std::ostream& operator<<(std::ostream& os, vector<Record>& vet) {
	os << '<' << std::endl << '\t';
	if (vet.size() > 0) {
		os << vet[0];
	}
	for (int i = 1; i < vet.size(); i++) {
		os << ',' << std::endl << '\t' << vet[i];
	}
	os << std::endl << '>';
	return os;
}


void write_records(vector<Record>& rec, string& file_name) {

	std::ofstream file;
	file.open(file_name,std::ios::app);
	if (file.is_open()) {
		file << rec.size() << std::endl;
		for (Record r : rec) {
			file << r.nome << std::endl;
			file << r.milliseconds << std::endl;
		}
		file.close();
	}
}

void read_records(std::vector<Record>& rec,string file_name) {

	std::ifstream record;
	record.open(file_name.c_str());
	if (record.is_open()) {
		rec.clear();
		int size;
		record >> size;
		record.ignore();
		for (int i = 0; i < size; i++) {
			Record r;
			std::getline(record, r.nome);
			record >> r.milliseconds;
			record.ignore();
			rec.push_back(r);
		}
		record.close();
	}
}

void jogo_1(vector<Record>& rec,string FILE, Record& player) {


	auto start = high_resolution_clock::now();
	bool win = campo_minado_LV1();
	auto end = high_resolution_clock::now();

	auto duracao = end - start;

	//cout << endl;
	//cout << duration_cast<milliseconds>(duracao).count();

	if (win == true) {

		cout << endl;
		cout << "Digite seu nome: ";
		cin >> player.nome;
		player.milliseconds = duration_cast<milliseconds>(duracao).count();

		rec.push_back({ player.nome, player.milliseconds });

		sort(rec);

		write_records(rec, FILE);

		rec.clear();
	}
}

void jogo_2(vector<Record>& rec, string FILE, Record& player) {


	auto start = high_resolution_clock::now();
	bool win = campo_minado_LV2();
	auto end = high_resolution_clock::now();

	auto duracao = end - start;
	cout << endl;
	cout << duration_cast<milliseconds>(duracao).count();

	if (win == true) {

		cout << endl;
		cout << "Digite seu nome: ";
		cin >> player.nome;
		player.milliseconds = duration_cast<milliseconds>(duracao).count();

		rec.push_back({ player.nome, player.milliseconds });

		sort(rec);

		write_records(rec, FILE);

		rec.clear();
	}
}

void jogo_3(vector<Record>& rec, string FILE, Record& player) {


	auto start = high_resolution_clock::now();
	bool win = campo_minado_LV3();
	auto end = high_resolution_clock::now();

	auto duracao = end - start;
	cout << endl;
	cout << duration_cast<milliseconds>(duracao).count();

	if (win == true) {

		cout << endl;
		cout << "Digite seu nome: ";
		cin >> player.nome;
		player.milliseconds = duration_cast<milliseconds>(duracao).count();

		rec.push_back({ player.nome, player.milliseconds });

		sort(rec);

		write_records(rec, FILE);

		rec.clear();
	}
}


void informacoes() {
	cout << "            BEM VINDO AO CAMPO MINADO                 " << endl;
	cout << "            *-*-*-*-*-*-*-*-*-*-*-*-*                 " << endl;
	cout << "       -h para Informações         " << endl;
	cout << "       -r para Imprimir records (Imprime somente do nível selecionado)         " << endl;
	cout << "       -d Mudar a dificuldade         " << endl;
	cout << "                                                       " << endl;
	cout << "                 *-*-*-*-*-*-*-*          " << endl;
	cout << "                  Sobre o Jogo           " << endl;
	cout << "                 *-*-*-*-*-*-*-*         " << endl;
	cout << "     1º Se uma mina for revelada: Você perde.     " << endl;
	cout << "     2º Um número indica a quantidade de minas ao redor do próprio número.   " << endl;
	cout << "     3º Você vence se revelar todas as células que não contêm minas.       " << endl;
	cout << "     4º Ao inserir a bandeira você presume que o local tem uma bomba.        " << endl;
	cout << "     5º Se a quantidade de bandeiras marcadas for igual ao número, ao selecionar o número são reveladas as casas ao redor.        " << endl;
	cout << "                                                        " << endl;
	cout << "                 *-*-*-*-*-*-*    " << endl;
	cout << "                  Como Jogar   " << endl;
	cout << "                 *-*-*-*-*-*-* " << endl;
	cout << "                                                       " << endl;
	cout << "            Manipular Bandeira = 1 " << endl;
	cout << "            Revelar Unidade = 0      " << endl;
	cout << "            Insira a Linha.   " << endl;
	cout << "            Insira a Coluna.   " << endl;
	cout << endl;
	cout << endl;
}

char arc_dificuldade(vector<Record>& rec, int& argc, char* argv[]) {

	std::ifstream dificuldade{};
	dificuldade.open("dificuldade.txt", std::ios::app);

	char dif;
	dif = dificuldade.get();

	for (int i = 0; i < argc; i++) {

		if (strcmp(argv[i], "-h") == 0) {
			informacoes();
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

		else if (strcmp(argv[i], "-r") == 0) {

			if (dif == 'b') {
				string FILE = "records_LV1.txt";
				read_records(rec, FILE);
			}

			else if (dif == 'i') {
				string FILE = "records_LV2.txt";
				read_records(rec, FILE);
			}

			else if (dif == 'a') {
				string FILE = "records_LV3.txt";
				read_records(rec, FILE);
			}


		}

	}

	return dif;
}

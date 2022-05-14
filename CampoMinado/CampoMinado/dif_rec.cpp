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
	string line;
	std::ifstream ajuda;
	ajuda.open("help.txt");

	if (ajuda.is_open()) {
		while (getline(ajuda, line, '\n')) {
			cout << line << '\n';
		}
	}
	else {
		cout << "ERRO. \n";
	}
}

char arc_dificuldade(vector<Record>& rec, int& argc, char* argv[]) {

	std::ifstream dificuldade{};
	dificuldade.open("dificuldade.txt", std::ios::app);

	char dif;
	dif = dificuldade.get();

	for (int i = 0; i < argc; i++) {

		if (strcmp(argv[i], "-h") == 0) {
			void informacoes();
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
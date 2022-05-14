#ifndef DIF_REC
#define DIF_REC

#include<iostream>
#include<algorithm>

#include <vector>
using std::vector;

#include <cstring>
#include <fstream>
#include <string>
#include <sstream>

#include <chrono>
using namespace std::chrono;

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Record {
	string nome;
	int milliseconds;
};


void sort(vector<Record>& rec);

std::ostream& operator<<(std::ostream& os, Record const& player);

std::ostream& operator<<(std::ostream& os, vector<Record>& vet);

void write_records(vector<Record>& rec, string& file_name);

void read_records(string file_name);

void informacoes();

void jogo(string FILE, bool campo_minado, Record& player);

char arc_dificuldade(int& argc, char* argv[]);

#endif
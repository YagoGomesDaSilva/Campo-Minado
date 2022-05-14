#ifndef DIF_REC
#define DIF_REC

#include "function.h"

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


std::ostream& operator<<(std::ostream& os, Record const& player);

std::ostream& operator<<(std::ostream& os, vector<Record>& vet);

void informacoes();

void read_records(vector<Record>& rec, string file_name);

void sort(vector<Record>& rec);

void write_records(vector<Record>& rec, string& file_name);

void jogo_1(vector<Record>& rec, string FILE, Record& player);

void jogo_2(vector<Record>& rec, string FILE, Record& player);

void jogo_3(vector<Record>& rec, string FILE, Record& player);

char arc_dificuldade(vector<Record>& rec, int& argc, char* argv[]);

#endif
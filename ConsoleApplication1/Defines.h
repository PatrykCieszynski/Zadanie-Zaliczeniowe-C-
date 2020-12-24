#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


#ifdef _MSC_VER
#define KOMPILATOR_CPP_VISUAL
#endif


class osoba {
public:
	string imie, nazwisko;
	int wiek;
	osoba(string pimie, string pnazwisko, int pwiek) :
		imie(pimie), nazwisko(pnazwisko), wiek(pwiek) {};
};

vector <osoba> ludzie;
const static osoba tabOsoC[] = { {"Dorota", "Nowak", 23},
		{"Damian", "Nowak", 23},
		{"Anna", "Kowalska", 20},
		{"Adam", "Kowalski", 20}
};

#include "Defines.h"


void ListRecords() {
	cout << "\n\nLista osob:\n";
	for (int i = 0; i < ludzie.size(); i++)
	{
		cout << endl;
		cout << "Imię: " << ludzie[i].imie << endl;
		cout << "Nazwisko: " << ludzie[i].nazwisko << endl;
		cout << "Wiek: " << ludzie[i].wiek << endl;
	}
	cout << endl;
};


void AddRecord() {
	cout << "Podaj imie: ";
	string imie;
	cin >> imie;
	cout << "Nazwisko: ";
	string nazwisko;
	cin >> nazwisko;
	cout << "Wiek: ";
	int wiek;
	cin >> wiek;
	ludzie.push_back(osoba(imie, nazwisko, wiek));
}


void ReadFromFile() {
	fstream Records;
	Records.open("Records.txt", ios::in);
	if (!Records) {
		cout << "Nie ma takiego pliku";
	}
	else {
		string s,imie,nazwisko;
		int i=0,wiek;
		while (getline(Records, s)) {
			if (i == 0) {
				imie = s;
			}
			if (i == 1) {
				nazwisko = s;
			}
			if (i == 2) {
				wiek = stoi(s);
				ludzie.push_back(osoba(imie, nazwisko, wiek));
				i -= 3;
			}
			i++;
		}
	}
	Records.close();
}


void WriteToFile() {
	fstream Records;
	Records.open("Records.txt", ios::out);
	if (!Records) {
		cout << "\nWystapil blad!\n";
	}
	else {
		cout << "\nPlik utworzony pomyslne!\n";
		for (auto const& x : ludzie)
		{
			Records << x.imie << endl;
			Records << x.nazwisko << endl;
			Records << x.wiek << endl;
		}
		Records.close();
	}
}


int main()
{
	setlocale(LC_ALL, "polish");
	for (const auto& oso : tabOsoC)
		ludzie.push_back(oso);
	do {
		cout <<
			"1. Wypisanie bazy\n"
			"2. Dodanie elementu do bazy\n"
			"3. Skasowanie bazy\n"
			"4. Wczytanie z pliku (oprogramować \"serializację\" kolekcji)\n"
			"5. Zapisanie do pliku (oprogramować \"serializację\" kolekcji)\n"
			"0. Koniec\n";
		string txt;
		cin >> txt;
		if (txt.empty() || txt[0] == '0') exit(0);
		switch (txt[0]) {
		case '1': {
			ListRecords();
			break;
		}
		case '2': {
			AddRecord();
			break;
		}
		case '3': {
			ludzie.clear();
			break;
		}
		case '4': {
			ReadFromFile();
			break;
		}
		case '5': {
			WriteToFile();
			break;
		}
		default:
			break;
		}
	} while (true);
}
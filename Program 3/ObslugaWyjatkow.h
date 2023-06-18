#pragma once
#include <vector>
#include <fstream>


class ObslugaWyjatkow
{
private:
	std::vector <int> rejestr;
public:
	ObslugaWyjatkow();
	~ObslugaWyjatkow();
	int CzyPlikDziala(std::fstream *plik);
	int CzyPoprawneTypy(char typ);
	int CzyDzieleniePrzezZero(double liczba);
	int CzyPoprawnaLiczbaWiersziKolumn(int liczba, int ilosc);
	int ZwrocWartoscRejestru(int ktory) {
		return rejestr[ktory-1];
	}
};


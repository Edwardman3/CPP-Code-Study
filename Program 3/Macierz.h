#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ObslugaWyjatkow.h"

template <typename X>
class Macierz
{
	int ile_wierszy;
	int dlugosc_wiersza;
	ObslugaWyjatkow* wyjatki;
	std::vector <X> dane;
	std::vector <X*> wiersze;
	std::vector <char> etykiety;
 public:
	Macierz(std::fstream *_plik,int _tryb,ObslugaWyjatkow *_wyjatki);
	void operator=(const Macierz<X>& other_) = delete;
	Macierz(const Macierz<X>& other_) = delete;
	void zeruj();
	void pokaz() ;
	int getIleWierszy() { return ile_wierszy; }
	X& element(int i, int j)
	{
		return wiersze[i][j];
	}
	X& wolny(int i)
	{
		return wiersze[i][dlugosc_wiersza - 1];
	}
	void WczytajZPliku(std::fstream *plik);
	void ZamienWiersze(int ktory);
	void ZamienKolumny(int ktore);
	void WczytajZPlikuStrumienZnakow(std::fstream *plik);
	void UstawIleWierszyiDlugosc();
	void pokazWynik();
};

template <typename X>
Macierz<X>::Macierz(std::fstream *_plik, int _tryb, ObslugaWyjatkow *_wyjatki)
{
	wyjatki = _wyjatki;
	if (_tryb == 1)
	{
		WczytajZPliku(_plik);
	}
	else
	{
		WczytajZPlikuStrumienZnakow(_plik);
	}
}

template <typename X>
void Macierz<X>::zeruj()
{
	for (int i = 0; i < ile_wierszy*dlugosc_wiersza; ++i)
	{
		dane[i] = 0;
	}
}

template <typename X>
void Macierz<X>::pokaz()
{
	using std::cout;
	using std::endl;
	using std::setw;
	using std::fixed;
	using std::setprecision;
	for (int i = 0; i < ile_wierszy; ++i)
	{
		for (int j = 0; j < dlugosc_wiersza - 1; ++j)
		{
			cout << setw(8) << setprecision(4) << fixed << wiersze[i][j];
		}
		cout << "  |" << setw(8) << setprecision(4) << wiersze[i][dlugosc_wiersza - 1] << endl;
	}
}

template <typename X>
void Macierz<X>::pokazWynik()
{
	int i = 0;
	using std::cout;
	using std::endl;
	using std::setw;
	using std::fixed;
	using std::setprecision;
	while ( i < ile_wierszy)
	{
		cout << setw(8) << setprecision(4) << fixed << etykiety[i];
		cout << "  = " << setw(8) << setprecision(4) << wiersze[i][dlugosc_wiersza - 1] << endl;
		i++;
	}
}

template <typename X>
void Macierz<X>::WczytajZPliku(std::fstream *plik)
{
	X bufor;	
	while (plik->eof() == false)
	{
		(*(plik)) >> bufor;
		dane.push_back(bufor);
	}
	UstawIleWierszyiDlugosc();
}

template <typename X>
void Macierz<X> ::UstawIleWierszyiDlugosc()
{
	int licznik = 0;
	ile_wierszy = ((-1 + (int)sqrt(1 + 4 * dane.size())) / 2);
	dlugosc_wiersza = ile_wierszy + 1;
	if (wyjatki->CzyPoprawnaLiczbaWiersziKolumn(dane.size(), ile_wierszy) == 1)
	{
		while (licznik < ile_wierszy)
		{
			wiersze.push_back(&dane[licznik * (dlugosc_wiersza)]);
			licznik++;
		}
	}
}

template <typename X>
void Macierz<X>::ZamienWiersze(int ktory)
{
	X* temp;
	std::cout << "Przed zmiana" << std::endl;
	pokaz();
	if (ktory + 1 == ile_wierszy )
	{
		temp = wiersze[ktory];
		wiersze[ktory] = wiersze[0];
		wiersze[0] = temp;
	}
	else
	{
		temp = wiersze[ktory];
		wiersze[ktory] = wiersze[ktory + 1];
		wiersze[ktory + 1] = temp;
	}
	std::cout << std::endl;
	pokaz();
	std::cout << "Po zmianie" << std::endl;
}

template <typename X>
void Macierz<X>::ZamienKolumny(int ktore)
{
	X temp;
	if (ktore + 2 != dlugosc_wiersza)
	{
		std::cout << "Przed zmiana kolumn" << std::endl;
		pokaz();
		for (int i = 0; i < dlugosc_wiersza; i++)
		{
			temp = wiersze[i][ktore];
			wiersze[i][ktore] = wiersze[i][ktore + 1];
			wiersze[i][ktore + 1] = temp;
		}
		std::cout << std::endl;
		pokaz();
		std::cout << "Po zmianie kolumn "<< std::endl;
	}
}

template <typename X>
void Macierz<X>::WczytajZPlikuStrumienZnakow(std::fstream *plik)
{
	char znak1 = 'q';
	X liczba1 = 0.0;
	std::string source;
	std::getline((*(plik)), source);
	while ((*(plik)).eof() == false)
	{
		std::getline((*(plik)), source);
		while (source.find(' ') <= source.length() && source.find(' ')>=0)
		{
			source.erase(source.find(' '),1);
		}
		while (source.find('*') <= source.length() && source.find('*') >= 0)
		{
			source.erase(source.find('*'), 1);
		}
		std::stringstream s;
		s << source;
		while (s.eof()==false)
		{	
			s >> liczba1 >> znak1;
			if (s.fail()==true)
			{
				s.clear();
				s >> znak1 >> liczba1;
				dane.push_back(liczba1);
			}
			else
			{
				dane.push_back(liczba1);
				etykiety.push_back(znak1);
			}
		}
	}
	UstawIleWierszyiDlugosc();
}
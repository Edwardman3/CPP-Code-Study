#include <iomanip>
#include <iostream>
#include <fstream>
#include "Macierz.h"
#include <string>

template <typename X>
Macierz<X>::Macierz()
{
	WczytajZPliku();
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
void Macierz<X>::WczytajZPliku()
{
	std::fstream plik;
	int licznik =0 ;
	char typ;
	X bufor;
	plik.open("Macierz_5.txt", std::ios::in);
	try
	{
		if (plik.good() == false)
		{
			std::string blad ="BLAD OTWARCIA PLIKU";
			throw blad;
		}
		else
		{
			plik >> typ;
			while (plik.eof() == false)
			{
				plik >> bufor;
				dane.push_back(bufor);
			}
			ile_wierszy = (-1 + sqrt(1 + 4 * dane.size())) / 2;
			dlugosc_wiersza = ile_wierszy + 1;
			while (licznik < ile_wierszy)
			{
				wiersze.push_back(&dane[licznik * (dlugosc_wiersza)]);
				licznik++;
			}
		}
	}
	catch (std::string blad)
	{
		std::cout << blad << std::endl;
	}
}

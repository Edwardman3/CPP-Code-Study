#include <iostream>
#include "Macierz.h"
#include "Solver.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include "ObslugaWyjatkow.h"


int main() 
{
	std::fstream plik;
	std::string nazwa;
	ObslugaWyjatkow wyjatki;
	char typ='A';
	std::cout << "Podaj nazwe pliku wraz z rozszerzeniem ktory chcesz utworzyc: ";
	std::cin >> nazwa;
	plik.open(nazwa, std::ios::in);
	if (wyjatki.CzyPlikDziala(&plik) == 1)
	{
		plik >> typ;
		if (wyjatki.CzyPoprawneTypy(typ) == 1)
		{
			if (typ == 'F')
			{
				if (nazwa[0] == 'm')
				{
					Macierz <float> m(&plik, 1, &wyjatki);
					if (wyjatki.ZwrocWartoscRejestru(4) == 1)
					{
						m.pokaz();
						std::cout << std::endl;
						Solver <float> s(m);
						s.rozwiaz();
						m.pokaz();
					}
				}
				else
				{

					Macierz <float> m(&plik, 0, &wyjatki);
					if (wyjatki.ZwrocWartoscRejestru(4) == 1)
					{
						m.pokaz();
						std::cout << std::endl;
						Solver <float> s(m);
						s.rozwiaz();
						m.pokazWynik();
					}
				}
			}
			else
			{
				if (nazwa[0] == 'm')
				{
					Macierz <double> m(&plik, 1, &wyjatki);
					if (wyjatki.ZwrocWartoscRejestru(4) == 1)
					{
						m.pokaz();
						std::cout << std::endl;
						Solver <double> s(m);
						s.rozwiaz();
						m.pokaz();
					}
				}
				else
				{

					Macierz <double> m(&plik, 0, &wyjatki);
					if (wyjatki.ZwrocWartoscRejestru(4) == 1)
					{
						m.pokaz();
						std::cout << std::endl;
						Solver <double> s(m);
						s.rozwiaz();
						m.pokazWynik();
					}
				}
			}
			plik.close();
		}
	}
	
	std::cin.get();
	std::cin.get();
	return 0;
}

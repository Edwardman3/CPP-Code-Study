#pragma once
#include "Macierz.h"
template <typename X>
class Solver 
{
  Macierz<X>& mat;
  const int n;

  void skalujWiersz(int ktory, X skala);
  void addWiersze(int ktory, int do_ktorego, X skala = 1.0);

 public:
  Solver(Macierz<X>& mat_) : mat(mat_), n(mat.getIleWierszy()) {}

  void rozwiaz();
};

template <typename X>
void Solver<X>::skalujWiersz(int ktory, X skala) {
	// mnozy kazdy element wiersza przez skalar
	for (int i = 0; i < n + 1; ++i) {
		mat.element(ktory, i) *= skala;
	}
}

template <typename X>
void Solver<X>::addWiersze(int ktory, int do_ktorego, X skala) 
{
	// dodaje pierwszy rzad do drugiego, mnozac wczesniej jego wartosci przez skalar
	for (int i = 0; i < n + 1; ++i) {
		mat.element(do_ktorego, i) += skala * mat.element(ktory, i);
	}
}

template <typename X>
void Solver<X>::rozwiaz() 
{
	int licznik=1;
	// rozwiazuj kazda kolumne z osobna
	for (int i = 0; i < n; ++i) 
	{
		// znormalizuj dany wiersz (na diagonalnej musza byc same 1)
		X pierwszy = mat.element(i, i);
		while (pierwszy == 0.0)
		{
			mat.ZamienWiersze(i);
			pierwszy = mat.element(i, i);
			licznik++;
			if (licznik == 3)
			{
				licznik = 1;
				mat.ZamienKolumny(i);
			}
		}
		skalujWiersz(i, (X)1.0 / pierwszy);
		// uzyj i-tego wiersza do wyeliminowania wszystkich pozostalych
		for (int j = 0; j < n; ++j) 
		{
			if (i == j) continue; // nie wyeliminuj siebie
								  // przemnoz wiersz przez te wartosc, by wyeliminowac element na i-tym miejscu
			X skala = (X)-1.0 * mat.element(j, i);
			addWiersze(i, j, skala);
		}
	}
}


#include "Solver.h"

void Solver::skalujWiersz(int ktory, double skala) {
  // mnozy kazdy element wiersza przez skalar
  for (int i = 0; i < n + 1; ++i) {
    mat.element(ktory, i) *= skala;
  }
}


void Solver::addWiersze(int ktory, int do_ktorego, double skala) {
  // dodaje pierwszy rzad do drugiego, mnozac wczesniej jego wartosci przez skalar
  for (int i = 0; i < n + 1; ++i) {
    mat.element(do_ktorego, i) += skala * mat.element(ktory, i);
  }
}


void Solver::rozwiaz() {
  // rozwiazuj kazda kolumne z osobna
  for (int i = 0; i < n; ++i) {
    // znormalizuj dany wiersz (na diagonalnej musza byc same 1)
    double pierwszy = mat.element(i, i);
    skalujWiersz(i, 1.0 / pierwszy);
    // uzyj i-tego wiersza do wyeliminowania wszystkich pozostalych
    for (int j = 0; j < n; ++j) {
      if (i == j) continue; // nie wyeliminuj siebie
      // przemnoz wiersz przez te wartosc, by wyeliminowac element na i-tym miejscu
      double skala = -1.0 * mat.element(j, i);
      addWiersze(i, j, skala);
    }
  }
}

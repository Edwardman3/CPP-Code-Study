#pragma once
#include "Karta.h"
#include "Gracz.h"



class Kasyno
{
private:
	Karta talia[52];
	Gracz *gracze;
	int ile_kart;
	int ile_graczy;
	int ile_botow;
	bool koniec_gry;
public:
	Kasyno();
	~Kasyno();
	void WypiszTalie();
	void Graj();
	void TasujTalie();
	Karta * Kasyno::dajKarte();
	bool CzyToKoniecGry();
	void KtoryWygral();
	void WyczyscStol();
	friend std::ofstream& operator<< (std::ofstream& _wyjscie, Karta &_wypisywana);
	void ZapiszWynik();
};


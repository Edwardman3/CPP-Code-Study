#pragma once
#include <iostream>
#include "Czas.h"

class Obrabiarka
{
private:
	Czas *czasy;
	Czas czasProcesow;
	int dlugoscTablicy;
	
public:
	Obrabiarka();
	Obrabiarka(const Obrabiarka &_skopiowany);
	~Obrabiarka();
	int zwrocdlugosc();
	void dodajCzas(int _sekundy, int _minuty=0, int _godziny=0);
	void dodajCzas();
	void wypisz();
	void wypiszCzasProcesow();
	Czas & operator[](int _wybrany);
	Obrabiarka &operator=(const Obrabiarka &_przypisywany);
	void stworzKopienpierwszych(Obrabiarka _kopiowana);
	void stworzKopieCzasu(Obrabiarka _kopiowana, int _sekundy, int _minuty = 0 , int godziny = 0);
};


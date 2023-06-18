#pragma once
#include "Karta.h"
#include <string>
#include <string.h>

class Gracz
{
protected:
	std::string nazwa;
	int punkty;
	bool czy_gra;
private:
	Karta *reka[10];
	int ile_kart_w_rece;
public:
	Gracz();
	~Gracz();
	void UstawImie();
	void DodajPunkty(int _nowy);
	void ZwiekszLiczbeKart();
	void PokazReke();
	void wezKarte(Karta * _karta);
	bool CzyGraczGraDalej();
	std::string ZwrocNazwe();
	virtual void WybierzCzyGrasz(); //klasa virtualna
	int ZwrocPunkty();
	void StopGra();
	void Reset();
	Karta  operator[](int _ktora);
	int ZwrocIloscKart();
};


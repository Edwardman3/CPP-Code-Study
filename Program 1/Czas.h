#pragma once
#include <iostream>

class Czas
{
private:
	int sekundy;
	int minuty;
	int godziny;
	void sprawdzSekundy();
	void sprawdzMinuty();
	int zabezpieczenieDanych(int _nowe);
public:
	Czas(int _sekundy = 0, int _minuty = 0, int _godziny = 0);
	int zwrocsekundy();
	int zwrocminuty();
	int zwrocgodziny();
	void wypiszCzas();
	void ustawSekundy(int _sekundy);
	void ustawSekundy();
	void ustawMinuty(int _minuty);
	void ustawMinuty();
	void ustawGodziny(int _godziny);
	void ustawGodziny();
	void wypiszSekundy();
	void wypiszMinuty();
	void wypiszGodziny();
	void ustawCzas(int _sekundy = 0, int _minuty = 0, int _godziny = 0);
	Czas operator+(Czas _nowy);
	Czas operator+(int _nowy);
	friend std::ostream & operator<< (std::ostream &wyjscie,  Czas &_wypisywany);
	bool operator==(Czas _czassprawdzany);
	bool operator!=(Czas _czassprawdzany);
	bool operator<(Czas _czassprawdzany);
	bool operator>(Czas _czassprawdzany);
	bool operator<=(Czas _czassprawdzany);
	bool operator>=(Czas _czassprawdzany);
};
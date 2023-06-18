#include "Czas.h"
#include <iostream>




void Czas::sprawdzSekundy()
{
	if (sekundy >= 60)
	{
		minuty = minuty + sekundy / 60;
		sekundy = sekundy % 60;
	}
}

void Czas::sprawdzMinuty()
{
	if (minuty >= 60)
	{	
		godziny = godziny + minuty / 60;
		minuty = minuty % 60;
	}
}

int Czas::zabezpieczenieDanych(int _nowe)
{
	while (_nowe < 0)
	{
		std::cout << "Wartosc jest mniejsza od 0 Podaj jeszcze raz" << std::endl;
		std::cin >> _nowe;
	}
	return _nowe;
}

Czas::Czas(int _sekundy, int _minuty, int _godziny)
{
	_sekundy=zabezpieczenieDanych(_sekundy);
	sekundy = _sekundy;
	_minuty=zabezpieczenieDanych(_minuty);
	minuty = _minuty;
	_godziny = zabezpieczenieDanych(_godziny);
	godziny = _godziny;
	sprawdzSekundy();
	sprawdzMinuty();
}

int Czas::zwrocsekundy()
{
	return sekundy;
}

int Czas::zwrocminuty()
{
	return minuty;
}

int Czas::zwrocgodziny()
{
	return godziny;
}

void Czas::wypiszCzas()
{
	std::cout << "Sekundy: " << sekundy << " Minuty: " << minuty << " Godziny: " << godziny << std::endl;
}

void Czas::ustawSekundy(int _sekundy)
{
	_sekundy = zabezpieczenieDanych(_sekundy);
	sekundy = sekundy +_sekundy;
	sprawdzSekundy();
}

void Czas::ustawSekundy()
{
	int sekundytmp;
	std::cin >> sekundytmp;
	sekundytmp = zabezpieczenieDanych(sekundytmp);
	sekundy = sekundytmp;
	sprawdzSekundy();
}

void Czas::ustawMinuty(int _minuty)
{
	_minuty = zabezpieczenieDanych(_minuty);
	minuty = minuty + _minuty;
	sprawdzMinuty();
}

void Czas::ustawMinuty()
{
	int minutytmp;
	std::cin >> minutytmp;
	minutytmp = zabezpieczenieDanych(minutytmp);
	minuty = minutytmp;
	sprawdzMinuty();
}

void Czas::ustawGodziny(int _godziny)
{
	_godziny = zabezpieczenieDanych(_godziny);
	godziny = godziny +_godziny;
}

void Czas::ustawGodziny()
{
	int godzinytmp;
	std::cin >> godzinytmp;
	godzinytmp = zabezpieczenieDanych(godzinytmp);
	godziny = godzinytmp;
}

void Czas::wypiszSekundy()
{
	std::cout << sekundy << std::endl;
}

void Czas::wypiszMinuty()
{
	std::cout << minuty << std::endl;
}

void Czas::wypiszGodziny()
{
	std::cout << godziny << std::endl;
}

void Czas::ustawCzas(int _sekundy, int _minuty, int _godziny)
{
	sekundy = _sekundy;
	minuty = _minuty;
	godziny = _godziny;
	sprawdzSekundy();
	sprawdzMinuty();
}

Czas Czas::operator+(Czas _nowy)
{
	Czas temp;
	temp.sekundy = sekundy + _nowy.sekundy;
	if (temp.sekundy >= 60)
	{
		temp.minuty = temp.minuty + (temp.sekundy / 60);
		temp.sekundy = temp.sekundy % 60;
	}
	temp.minuty = temp.minuty + minuty + _nowy.minuty;
	if (temp.minuty >= 60)
	{
		temp.godziny = temp.godziny + (temp.minuty / 60);
		temp.minuty = temp.minuty % 60;
	}
	temp.godziny = temp.godziny + godziny + _nowy.godziny;
	return temp;
}

Czas Czas::operator+(int _nowy)
{
	Czas temp;
	temp.sekundy = sekundy + _nowy;
	if (temp.sekundy >= 60)
	{
		temp.minuty = temp.minuty + (temp.sekundy / 60);
		temp.sekundy = temp.sekundy % 60;
	}
	temp.minuty = temp.minuty + minuty ;
	if (temp.minuty >= 60)
	{
		temp.godziny = temp.godziny + (temp.minuty / 60);
		temp.minuty = temp.minuty % 60;
	}
	temp.godziny = temp.godziny + godziny ;
	return temp;
}

std::ostream & operator<< (std::ostream &wyjscie,  Czas &_wypisywany)
{
		wyjscie << "Sekundy: ";
		std::cout.width(2);
		wyjscie <<std::right << _wypisywany.zwrocsekundy();
		wyjscie << " Minuty: ";
		std::cout.width(2);
		wyjscie << std::right << _wypisywany.zwrocminuty();	
		wyjscie <<  " Godziny: ";
		std::cout.width(2);
		wyjscie << std::right << _wypisywany.zwrocgodziny();
		
	return	wyjscie; 
}

bool Czas::operator==(Czas _czassprawdzany)
{
	if ((sekundy == _czassprawdzany.sekundy) && (minuty == _czassprawdzany.minuty) && (godziny == _czassprawdzany.godziny))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Czas::operator!=(Czas _czassprawdzany)
{
	if (!((sekundy == _czassprawdzany.sekundy) && (minuty == _czassprawdzany.minuty) && (godziny == _czassprawdzany.godziny)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Czas::operator<(Czas _czassprawdzany)
{
	if (godziny < _czassprawdzany.godziny)
	{
		return true;
	}
	else
	{
		if ((godziny == _czassprawdzany.godziny) && (minuty < _czassprawdzany.minuty))
		{
			return true;
		}
		else
		{
			if ((godziny == _czassprawdzany.godziny) && (minuty == _czassprawdzany.minuty) && sekundy < _czassprawdzany.sekundy)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Czas::operator>(Czas _czassprawdzany)
{
	if (!(*this < _czassprawdzany))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Czas::operator<=(Czas _czassprawdzany)
{
	if ((*this < _czassprawdzany) || (*this == _czassprawdzany))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Czas::operator>=(Czas _czassprawdzany)
{
	if ((*this > _czassprawdzany) || (*this == _czassprawdzany))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#include "Obrabiarka.h"

Obrabiarka::Obrabiarka()
	:czasy(nullptr)
	,dlugoscTablicy(0)
	,czasProcesow(0,0,0)
{
}

Obrabiarka::Obrabiarka(const Obrabiarka &_skopiowany)
{
	int licznik = 0;
	dlugoscTablicy = _skopiowany.dlugoscTablicy;
	czasProcesow = _skopiowany.czasProcesow;
	czasy = new Czas[dlugoscTablicy];
	while (licznik < dlugoscTablicy)
	{
		*(czasy + licznik) = *(_skopiowany.czasy + licznik);
		licznik++;
	}
}

Obrabiarka::~Obrabiarka()
{
	delete[] czasy;
}

int Obrabiarka::zwrocdlugosc()
{
	return dlugoscTablicy;
}

Obrabiarka & Obrabiarka::operator=(const Obrabiarka &_przypisywany)
{
	int licznik = 0;
	if (&_przypisywany == this)
	{
		return *this;
	}
	else
	{
		delete[] czasy;
		dlugoscTablicy = _przypisywany.dlugoscTablicy;
		czasy = new Czas[_przypisywany.dlugoscTablicy];
		while (licznik < dlugoscTablicy)
		{
			*(czasy + licznik) = *(_przypisywany.czasy + licznik);
			licznik++;
		}
		
		return *this;
	}
}

Czas & Obrabiarka::operator[](int _wybrany)
{
	if (_wybrany <= 0 || _wybrany > dlugoscTablicy)
	{
		return *czasy;
	}
	else
	{
		return *(czasy + _wybrany - 1);
	}
	
}

void Obrabiarka::dodajCzas(int _sekundy, int _minuty , int _godziny)
{
	Czas nowyCzas;
	Czas *czasowaTablica = nullptr;
	int licznik = 0;
	nowyCzas.ustawSekundy(_sekundy);
	nowyCzas.ustawMinuty(_minuty);
	nowyCzas.ustawGodziny(_godziny);
	dlugoscTablicy++;
	czasowaTablica = new Czas[dlugoscTablicy];
	while (licznik < (dlugoscTablicy - 1))
	{
		*(czasowaTablica + licznik) = *(czasy + licznik);
		licznik++;
	}
	*(czasowaTablica + licznik) = nowyCzas;
	delete[] czasy;
	czasy = new Czas[dlugoscTablicy];
	licznik = 0;
	while (licznik < dlugoscTablicy)
	{
		*(czasy + licznik) = *(czasowaTablica + licznik);
		licznik++;
	}
	delete[] czasowaTablica;
	czasProcesow = czasProcesow + nowyCzas;
}

void Obrabiarka::dodajCzas()
{
	Czas nowyCzas;
	Czas *czasowaTablica = nullptr;
	int licznik = 0;
	std::cout << "Podaj ilosc sekund: ";
	nowyCzas.ustawSekundy();
	std::cout << "Podaj ilosc minut: ";
	nowyCzas.ustawMinuty();
	std::cout << "Podaj ilosc godzin: ";
	nowyCzas.ustawGodziny();
	dlugoscTablicy++;
	czasowaTablica = new Czas[dlugoscTablicy];
	while (licznik < (dlugoscTablicy-1))
	{
		*(czasowaTablica + licznik) = *(czasy + licznik);
		licznik++;
	}
	*(czasowaTablica + licznik) = nowyCzas;
	delete[] czasy;
	czasy = new Czas[dlugoscTablicy];
	licznik = 0;
	while (licznik < dlugoscTablicy)
	{
		*(czasy + licznik) = *(czasowaTablica + licznik);
		licznik++;
	}
	delete[] czasowaTablica;
	czasProcesow = czasProcesow + nowyCzas;
}

void Obrabiarka::wypisz()
{
	int licznik = 0;
	while (licznik < dlugoscTablicy)
	{
		std::cout <<std::left<< (*(czasy + licznik)) << std::endl;
		licznik++;
	}
}

void Obrabiarka::wypiszCzasProcesow()
{
	std::cout << "Czas procesow: " << std::endl;
	std::cout << czasProcesow << std::endl;
}

void Obrabiarka::stworzKopienpierwszych(Obrabiarka _kopiowana)
{
	int ilosc = 0, licznik = 0;
	puts("Podaj ilosc czasow do skopiowania:");
	while (!(std::cin >> ilosc) || ilosc <= 0 || ilosc > _kopiowana.dlugoscTablicy)
	{
		puts("Wprowadz wartosc jeszcze raz!");
	}
	(*this).dlugoscTablicy = ilosc;
	(*this).czasy = new Czas[(*this).dlugoscTablicy];
	while (licznik < (*this).dlugoscTablicy)
	{
		*((*this).czasy + licznik) = *(_kopiowana.czasy + licznik);
		(*this).czasProcesow = (*this).czasProcesow + *((*this).czasy + licznik);
		licznik++;
	}
}

void Obrabiarka::stworzKopieCzasu(Obrabiarka _kopiowana, int _sekundy, int _minuty, int _godziny)
{
	Czas granica(_sekundy, _minuty, _godziny);
	Czas tmp(0, 0, 0);
	int licznik = 0;
	while (tmp <= granica)
	{
		tmp = tmp + *(_kopiowana.czasy + licznik);
		licznik++;
	}
	(*this).dlugoscTablicy = licznik-1;
	licznik = 0;
	(*this).czasy = new Czas[(*this).dlugoscTablicy];
	while (licznik < (*this).dlugoscTablicy)
	{
		*((*this).czasy + licznik) = *(_kopiowana.czasy + licznik);
		(*this).czasProcesow = (*this).czasProcesow + *((*this).czasy + licznik);
		licznik++;
	}
}
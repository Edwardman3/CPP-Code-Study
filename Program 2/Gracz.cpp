#include "Gracz.h"



Gracz::Gracz()
	:czy_gra(true)
	,punkty(0)
	,ile_kart_w_rece(0)
{
	for (int i = 0; i < 10; i++)
	{
		*(reka+i) = nullptr;
	}
}

Gracz::~Gracz()
{
}

void Gracz::UstawImie()
{
	while (true)
	{
		std::cin >> nazwa; 
		if (std::cin.fail() == true || nazwa.length() > 20)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Podaj nazwe gracza jeszcze raz (do 20 znakow): ";
		}
		else break;
	}
}

void Gracz::DodajPunkty(int _nowy)
{
	punkty = punkty + _nowy;
}

void Gracz::ZwiekszLiczbeKart()
{
	ile_kart_w_rece++;
	if (ile_kart_w_rece == 10)
	{
		czy_gra = false;
	}
}

void Gracz::PokazReke()
{
	int licznik = 0;
	std::cout << nazwa << std::endl;
	while (licznik < ile_kart_w_rece)
	{
		reka[licznik]->wypisz();
		std::cout << " ";
		licznik++;
	}
	std::cout << "" << std::endl;
	std::cout << "Punkty: " << punkty << std::endl;
}

void Gracz::wezKarte(Karta * _karta)
{
	if (_karta != nullptr)
	{
		reka[ile_kart_w_rece] = _karta;
		ZwiekszLiczbeKart();
		DodajPunkty(_karta->getWartosc());
	}
	else
	{
		std::cout << "Brak kart w talii, pora spasowac" << std::endl;
	}
}

bool Gracz::CzyGraczGraDalej()
{
	return czy_gra;
}

std::string Gracz::ZwrocNazwe()
{
	return nazwa;
}

void Gracz::WybierzCzyGrasz()
{
	int wybor;
	while (true)
	{
		std::cout << nazwa << "Czy chcesz spasowac? 1. TAK 2. Nie" << std::endl;
		std::cin >> wybor;
		if (std::cin.fail() == true || wybor < 1 || wybor > 2)
		{
			std::cout << "Z³y wybor" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	if (wybor == 1)
	{
		czy_gra = false;
	}
}

int Gracz::ZwrocPunkty()
{
	return punkty;
}

void Gracz::StopGra()
{
	czy_gra = false;
}

void Gracz::Reset()
{
	int licznik = 0;
	czy_gra = true;
	punkty = 0;
	while (licznik<ile_kart_w_rece)
	{
		reka[licznik] = nullptr;
		licznik++;
	}
	ile_kart_w_rece = 0;
}

Karta  Gracz::operator[](int _ktora)
{
	return *reka[_ktora];
}

int Gracz::ZwrocIloscKart()
{
	return ile_kart_w_rece;
}
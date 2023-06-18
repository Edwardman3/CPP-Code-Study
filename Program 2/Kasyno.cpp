#include "Kasyno.h"
#include <time.h>
#include "Karta.h"
#include <fstream>#include <iomanip>

Kasyno::Kasyno()
	:ile_kart(52)
	,koniec_gry(false)
{
	int licznik1 = 0;
	int licznik2 = 0;
	int licznik3 = 0;
	while (true)
	{
		std::cout << "Podaj liczbe graczy (od 1 do 3):" << std::endl;
		std::cin >> ile_graczy;
		if (std::cin.fail() == true || ile_graczy < 1 || ile_graczy >3)
		{
			std::cout << "Podaj wartosc z podanego zakresu" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	while (true)
	{
		std::cout << "Podaj liczbe botow(od 1 do 3):" << std::endl;
		std::cin >> ile_botow;
		if (std::cin.fail() == true || ile_botow < 1 || ile_botow >4)
		{
			std::cout << "Podaj wartosc z podanego zakresu" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	gracze = new Gracz[ile_graczy + ile_botow]; //zmiana
	while (licznik1 < ile_graczy)
	{
		std::cout << "Podaj nazwe gracza numer " << licznik1 + 1 << " (do 20 znakow): ";
		gracze[licznik1].UstawImie();
		licznik1++;
	}
	while (licznik1 < (ile_graczy + ile_botow)) //zmiana
	{
		gracze[]
		std::cout << "Podaj poziom odwagi dla " <<  << " (do 20 znakow): ";
		gracze[licznik1].UstawImie();
		licznik1++;
	}
	licznik1 = 0;
	while (licznik1 < 4)
	{
		while (licznik2 < 13)
		{
			talia[licznik3].setKolor(licznik1);
			talia[licznik3].setWartosc(licznik2);
			licznik2++;
			licznik3++;
		}
		licznik2 = 0;
		licznik1++;
	}
}

Kasyno::~Kasyno()
{
	delete[] gracze;
}

void Kasyno::WypiszTalie()
{
	int licznik = 0;
	while (licznik < 52)
	{
		talia[licznik].wypisz();
		licznik++;
		if (licznik % 13 == 0)
		{
			std::cout << "" <<std::endl;
		}
		else
		{
			std::cout << " ";
		}
	}
}

void Kasyno::Graj()
{
	int grasz_dalej = 1;
	int licznik = 0;
	int wybor = 0;
	TasujTalie();
	while (grasz_dalej == 1)
	{
		WypiszTalie();
		licznik = 0;
		wybor = 0;
		while (licznik < ile_graczy)
		{
			gracze[licznik].wezKarte(dajKarte());
			gracze[licznik].wezKarte(dajKarte());
			licznik++;
		}
		koniec_gry = false;
		while (koniec_gry == false)
		{
			licznik = 0;
			while (licznik < ile_graczy)
			{
				gracze[licznik].PokazReke();
				licznik++;
			}
			licznik = 0;
			while (licznik < ile_graczy)
			{
				if (gracze[licznik].CzyGraczGraDalej() == true)
				{
					gracze[licznik].WybierzCzyGrasz();
				}
				if (gracze[licznik].CzyGraczGraDalej() == true)
				{
					gracze[licznik].wezKarte(dajKarte());
				}
				if (gracze[licznik].ZwrocPunkty() >= 21)
				{
					gracze[licznik].StopGra();
				}
				licznik++;
			}
			system("cls");
			if (CzyToKoniecGry() == true)
			{
				koniec_gry = true;
				std::cout << "KONIEC GRY" << std::endl;
				licznik = 0;
				while (licznik < ile_graczy)
				{
					gracze[licznik].PokazReke();
					licznik++;
				}
				KtoryWygral();
				ZapiszWynik();
				while (true)
				{
					std::cout << "Czy chcesz zagrac jeszcze raz? 1. TAK 2. NIE" << std::endl;
					std::cin >> grasz_dalej;
					if (std::cin.fail() == true || grasz_dalej <=0 || grasz_dalej >=3)
					{
						std::cout << "Z³y wybor" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
					}
					else break;
				}
				if (grasz_dalej == 1)
				{
					WyczyscStol();
				}
			}
		}
	}
}

void Zamiana(Karta *a , Karta *b)
{
	Karta tymczasowa;
	tymczasowa = *a;
	*a = *b;
	*b = tymczasowa;
}

void Kasyno::TasujTalie()
{
	int licznik = 0;
	srand(time(NULL));
	while (licznik <100)
	{
		Zamiana(&talia[rand() % 52], &talia[rand() % 52]);
		licznik++;
	}
}

Karta * Kasyno::dajKarte()
{
	if (ile_kart != 0)
	{
		ile_kart--;
		return &talia[ile_kart];
	}
	else
	{
		return nullptr;
	}
}

bool Kasyno::CzyToKoniecGry()
{
	int licznik = 0;
	while (licznik<ile_graczy)
	{
		if (gracze[licznik].CzyGraczGraDalej()==true)
		{
			return false;
		}
		licznik++;
	}
	return true;
}

void Kasyno::KtoryWygral()
{
	int licznik1 = 21;
	int licznik2 = 0;
	bool zwyciesca = false;
	while (zwyciesca == false && licznik1 >0)
	{
		while (licznik2<ile_graczy)
		{
			if (gracze[licznik2].ZwrocPunkty() == licznik1)
			{
				zwyciesca = true;
				std::cout << "Wygral!  " << std::endl;
				std::cout << "Gracz: " << gracze[licznik2].ZwrocNazwe() << " z " << licznik1 << " punktami" << std::endl;
			}
			licznik2++;
		}
		licznik2 = 0;
		licznik1--;
	}
	if (zwyciesca == false)
	{
		std::cout << "Wszyscy przegrali :( " << std::endl;
	}
}

void Kasyno::WyczyscStol()
{
	int licznik = 0;
	TasujTalie();
	ile_kart = 52;
	while (licznik < ile_graczy)
	{
		gracze[licznik].Reset();
		licznik++;
	}
}
void Kasyno::ZapiszWynik(){	int licznik1 = 0;	int licznik2 = 0;	std::ofstream plik;	plik.open("LOG.txt", std::ofstream::app);	plik << std::endl; 	plik.width(20);	plik << "NOWA GRA" << std::endl;	plik << std::endl;	while (licznik1 < ile_graczy)	{		plik << gracze[licznik1].ZwrocNazwe();		plik.width(20 - gracze[licznik1].ZwrocNazwe().length());		while (licznik2 < gracze[licznik1].ZwrocIloscKart())		{			plik << gracze[licznik1][licznik2];			plik.width(1);			licznik2++;		}		plik.width(40 - licznik2 * 3);		licznik2 = 0;		plik << gracze[licznik1].ZwrocPunkty() << std::endl;		licznik1++;	}	plik << std::endl;	plik.width(20);	plik << "KONIEC GRY" << std::endl;	plik << std::endl;	plik.close();}std::ofstream& operator<< (std::ofstream& _wyjscie, Karta &_wypisywana){	_wyjscie << (char)_wypisywana.getFigura() << (char)_wypisywana.getKolor() << " ";	return _wyjscie;}
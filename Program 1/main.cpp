#include <iostream>
#include "Czas.h"
#include "Obrabiarka.h"
#include <time.h>
#include <conio.h>
#include <Windows.h>

#pragma warning(disable:4996)

int main(void)
{
	Obrabiarka frezarka;
	Obrabiarka frezarkaKopiaN;
	Obrabiarka frezarkaKopiaCzas;
	char wybor;
	int sekundy=-1;
	int minuty=-1;
	int godziny=-1;
	int warunek_koczacy=1;
	srand(time(NULL));
	while (warunek_koczacy == 1)
	{
		sekundy = -1;
		minuty = -1;
		godziny = -1;
		std::cout << "__________________________________________" << std::endl;
	
		std::cout << "MENU:" << std::endl;

		std::cout <<  "1. Generuj 5 czasow" << std::endl;
	
		std::cout <<  "2. Dodaj czas" << std::endl;
		
		std::cout <<  "3. Wypisz wszytskie czasy i czas procesu" << std::endl;
		
		std::cout <<  "4. Wypisz wskazany czas" << std::endl;
		
		std::cout <<  "5. Utworz kopie n - pierwszych i wypisz" << std::endl;
		
		std::cout <<  "6. Utworz kopie do czasu o... i wypisz" << std::endl;
		
		std::cout <<  "7. Zamknij " << std::endl;

		wybor = getch();					// wybor=getchar() ale trzeba dac enter

		switch (wybor)
		{
		case '1':
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				frezarka.dodajCzas(rand() % 100, rand() % 100, rand() % 2);
			}
			std::cout << "Ustawiono 5 czasow" << std::endl;
			break;
		case '2':
			system("cls");
			while (sekundy < 0)
			{
				std::cout << "sekundy: ";
				std::cin >> sekundy;
			}
			while (minuty < 0)
			{
				std::cout << "minuty: ";
				std::cin >> minuty;
			}
			while (godziny < 0)
			{
				std::cout << "godziny: ";
				std::cin >> godziny;
			}
			frezarka.dodajCzas(sekundy,minuty ,godziny );
			std::cout << "dodano " << std::endl;
			break;
		case '3':
			system("cls");
			frezarka.wypisz();
			frezarka.wypiszCzasProcesow();
			break;
		case '4':

			system("cls");
			while (sekundy<1 || sekundy > frezarka.zwrocdlugosc())
			{
				std::cout << "Podaj ktory: " << std::endl;
				std::cin >> sekundy;
			}
			std::cout << frezarka[sekundy] << std::endl;
			break;
		case '5':
			system("cls");
			frezarkaKopiaN.stworzKopienpierwszych(frezarka);
			frezarkaKopiaN.wypisz();
			frezarkaKopiaN.wypiszCzasProcesow();
			break;
		case '6':
			system("cls");
			while (sekundy < 0)
			{
				std::cout << "sekundy: ";
				std::cin >> sekundy;
			}
			while (minuty < 0)
			{
				std::cout << "minuty: ";
				std::cin >> minuty;
			}
			while (godziny < 0)
			{
				std::cout << "godziny: ";
				std::cin >> godziny;
			}
			frezarkaKopiaCzas.stworzKopieCzasu(frezarka, sekundy, minuty, godziny);
			frezarkaKopiaCzas.wypisz();
			frezarkaKopiaCzas.wypiszCzasProcesow();
			break;
		case '7':
			warunek_koczacy = 0;
			system("cls");
			break;
		default:
			std::cout << "bledny wybor" << std::endl;
			system("cls");
			break;
		}
	}
	return 0;
}
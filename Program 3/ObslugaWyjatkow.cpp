#include "ObslugaWyjatkow.h"
#include <iostream>
#include <string>
#include <fstream>


ObslugaWyjatkow::ObslugaWyjatkow()
{
	rejestr.assign(4, 1);
}

ObslugaWyjatkow::~ObslugaWyjatkow()
{
}

int ObslugaWyjatkow::CzyPlikDziala(std::fstream *plik)
{
	try
	{
		if (plik->good() == false)
		{
			std::string blad = "BLAD OTWARCIA PLIKU";
			throw blad;
		}
	}
	catch (std::string blad)
	{
		std::cout << blad <<std:: endl;
		rejestr[0] = 0;
		
	}
	return rejestr[0];
}

int ObslugaWyjatkow::CzyPoprawneTypy(char typ)
{
	try
	{
		if (typ != 'F' && typ != 'D')
		{
			std::string blad = "BLAD TYPU DANYCH";
			throw blad;
		}

	}
	catch (std::string blad)
	{
		std::cout << blad << std::endl;
		rejestr[1] = 0;
		
	}
	return rejestr[1];
}

int ObslugaWyjatkow::CzyDzieleniePrzezZero(double liczba)
{
	try
	{
		if (liczba > 0.0 && liczba < 0.0)
		{
			std::string blad = "DZIELENIE PRZEZ ZERO";
			throw blad;
		}

	}
	catch (std::string blad)
	{
		std::cout << blad << std::endl;
		rejestr[2] = 0;
		
	}
	return rejestr[2];
}

int ObslugaWyjatkow::CzyPoprawnaLiczbaWiersziKolumn(int liczba, int ilosc)
{
	try
	{
		if (liczba != ilosc*(ilosc + 1))
		{
			std::string blad = "ILOSC WPROWADZONYCH DANYCH JEST NIEPOPRAWNA SPRAWDZ PLIK";
			throw blad;
		}
	}
	catch (std::string blad)
	{
		std::cout << blad << std::endl;
		rejestr[3] = 0;
	}
	return rejestr[3];
}
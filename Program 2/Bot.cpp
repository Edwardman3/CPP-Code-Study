#include "Bot.h"



Bot::Bot()
	:odwaga(0)
{
}


Bot::~Bot()
{

}

void Bot::UstawOdwage()
{
	int wybor;
	while (true)
	{
		std::cout << "Opcje do wyboru :| 1. ryzykujacy | 2. normalny | 3. zachowawczy |  Wybor:" << std::endl;
		std::cin >> wybor;
		if (std::cin.fail() == true || wybor < 1 || wybor >3)
		{
			std::cout << "Podaj wartosc z podanego zakresu od 1 do 3" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	if (wybor == 1)
	{
		odwaga = 19;
	}
	else
	{
		if (wybor == 2)
		{
			odwaga = 17;
		}
		else
		{
			odwaga = 15;
		}
	}
}

int Bot::ZwrocOdwage()
{
	return odwaga;
}

void Bot::NadajNazwe(int _ktory)
{
	nazwa = "Bot " + char(_ktory);
}

void Bot::WybierzCzyGrasz()
{
	if (odwaga <= punkty)
	{
		czy_gra = false;
	}
}
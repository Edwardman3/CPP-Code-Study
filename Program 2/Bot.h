#pragma once
#include "Gracz.h"


class Bot : public Gracz
{
private:
	int odwaga;
public:
	Bot();
	~Bot();
	void UstawOdwage();
	int ZwrocOdwage();
	void NadajNazwe(int _ktory);
	void WybierzCzyGrasz();
};


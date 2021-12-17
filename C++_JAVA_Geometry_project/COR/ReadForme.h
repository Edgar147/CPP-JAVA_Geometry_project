#pragma once
#include"../Forme/Forme.h"
//class abstrait qui traite les formes dans le COR
class ReadForme
{
public:
	ReadForme();
	virtual~ReadForme();
	//chargement de la forme
	virtual Forme * Lires(char * ch)const = 0;
};

ReadForme::ReadForme()
{
}

ReadForme::~ReadForme()
{
}
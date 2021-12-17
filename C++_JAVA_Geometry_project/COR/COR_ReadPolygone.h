#pragma once
#include"COR_Reads.h"
//Traitement de polygonn dans le COR
class COR_ReadPolygone:public COR_Reads
{
public:

	COR_ReadPolygone(ReadForme * c = NULL) :COR_Reads(c) {}
	~COR_ReadPolygone(){}
	Forme * Lire(char * ch)const;
private:

};
//Transfomation  d'une table de double vers  polygone
Forme * PolygoneDouble(double * d)
{
	Polygone * p = new Polygone();
	int i = 4;
	for(int nb = 0;nb < (int)d[3];nb ++)
	{
		p->add(new Vecteur2D(d[i], d[i + 1]));
		i =i + 2;
	}
	return p;
}
inline Forme * COR_ReadPolygone::Lire(char * ch) const
{
	if (ch[0] == '3')
	{
		cout << ch;
		return CaracForme(ch, PolygoneDouble);
	}
	return NULL;
}


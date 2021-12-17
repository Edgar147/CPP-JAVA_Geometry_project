#pragma once
#include"COR_Reads.h"
//Traitement de cercle dans le COR
class COR_ReadCercle :public COR_Reads
{
public:
	COR_ReadCercle(ReadForme * c = NULL) :COR_Reads(c) {}

	~COR_ReadCercle(){}

	Forme * Lire(char * ch)const;
};
//Transfomer une table de double a cercle
Forme * CercleDouble(double * d)
{
	//Creation cercle avec 3 param
	return new Cercle(Vecteur2D(d[3], d[4]), d[5]);
}
inline Forme * COR_ReadCercle::Lire(char * ch) const
{
	if (ch[0] == '2')
		return CaracForme(ch, CercleDouble);
	return NULL;
}

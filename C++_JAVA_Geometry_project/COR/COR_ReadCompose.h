#pragma once
#include"COR_Reads.h"
#include"COR_ReadCercle.h"
#include"COR_ReadPolygone.h"
#include"COR_ReadSegment.h"
//Traitement de Compose dans COR
class COR_ReadCompose :public COR_Reads
{
public:
	COR_ReadCompose(ReadForme * c = NULL) :COR_Reads(c) {}

	~COR_ReadCompose() {};

	Forme * Lire(char * ch)const;
private:

};
//De table double->> compose
Forme * ComposeDouble(double * d)
{
	return new Compose();
}
inline Forme * COR_ReadCompose::Lire(char * ch) const
{//???????????????????????????????????????????????????????????????????
	if (ch[0] == '4')
		return CaracForme(ch, ComposeDouble);
	return NULL;
}
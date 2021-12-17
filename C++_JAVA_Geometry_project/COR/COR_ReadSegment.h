#pragma once
#include"COR_Reads.h"
//Traitement de  segment dans le COR
class COR_ReadSegment

	:public COR_Reads

{
public:
	COR_ReadSegment(ReadForme * c = NULL):COR_Reads(c) {}
	~COR_ReadSegment() {}
	Forme * Lire(char * ch)const;
private:

};
//Transfomer une table de double a segment
Forme * SegmentDouble(double * d)
{
	return new Segment(Vecteur2D(d[3], d[4]), Vecteur2D(d[5],d[6]));
}

inline Forme * COR_ReadSegment::Lire(char * ch) const
{

	if (ch[0] == '1')
	{
		return CaracForme(ch, SegmentDouble);
		
	}

	return NULL;
}

#pragma once

#include"Chargeur.h"

#include"../Forme/Compose.h"
#include"../Forme/Segment.h"
#include"../Forme/Cercle.h"
#include"../Forme/Polygone.h"
#include"../Forme/Forme.h"

#include<fstream>
#include<stdio.h>
using namespace std;

//Traitement des formes

class COR_Reads :public ReadForme
{
	ReadForme * suivante;
public:
	COR_Reads(ReadForme * c = NULL) {
		suivante = c;
	}

	virtual ~COR_Reads() { free(suivante); };

	virtual Forme * Lires(char * ch)const;

	//Traitement de type de forme

	virtual Forme * Lire(char * ch)const = 0;
};

inline Forme * COR_Reads::Lires(char * ch) const
{
	Forme * f = Lire(ch);
	if (f != NULL){
		return f;
	}
	if (suivante == NULL){
		
		return NULL;
	}

	return suivante->Lires(ch);
}



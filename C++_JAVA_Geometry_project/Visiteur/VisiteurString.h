#pragma once
#include "Visiteur.h"
#include "../Forme/Forme.h"
#include<fstream>
using namespace std;
//On visite et on sauvegarde dans un fichier .txt

class VisiteurString :
	public Visiteur
{
	char * c;
public:
	VisiteurString() {};
	~VisiteurString() {};

	template <class T>
	void Ecrire(const T * t)const
	{
		ofstream OutFile(c, ios::app);

		OutFile << t->toString() << endl;
		OutFile.close();

	}
		
	void visite(Segment * t)const;
	void visite(Cercle * t)const;
	void visite(Polygone * t)const;
	void visite(Compose * t)const;

};

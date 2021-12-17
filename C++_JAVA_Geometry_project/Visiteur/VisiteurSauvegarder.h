#pragma once
#include<fstream>
#include "Visiteur.h"
using namespace std;
class VisiteurSauvegarder :
	public Visiteur
{
	string adress;
public:
	VisiteurSauvegarder(string a):adress(a) {};

	~VisiteurSauvegarder() {};

	void Garder(string s)const;

	void visite(Compose *)const;
	void visite(Cercle *)const;
	void visite(Segment *)const;
	void visite(Polygone *)const;
};
//Sauvegarde  dans le ficher qui se trouve à l'adresse

inline void VisiteurSauvegarder::Garder(string s)const
{
	ofstream OutFile(adress.c_str(),ios::app);
	OutFile << s <<endl;
	OutFile.close();
}
//retouner string x,y pour un vecteur????????????????????????????
string garderVecteur(Vecteur2D v);



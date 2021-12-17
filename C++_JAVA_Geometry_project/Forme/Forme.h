#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<sstream>

#include "Erreur.h"
#include<vector>
#include"Vecteur2D.h"
using namespace std;
class Visiteur;
/*
Class Forme:3 Données :
	Type(int):1.Segment ,2.Cercle, 3.Polyfone, 4.Compose

	DejaAppartenant(bool):True si forme  deja appartieny a un groupe
	Couleur(int): 0.Balck, 1.Blue, 2.Red ,3.Green, 4.Yellow,5.Cyan 
*/
class Forme
{
	int Type;
	int Couleur;
	bool DejaAppartenant = false;
public:
//Valeurs des couleurs
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;
//Valeurs des types
	static const int SEGMENT = 1;
	static const int CERCLE= 2;
	static const int POLYGONE = 3;
	static const int COMPOSE = 4;
	//Par defaut il va être construit par la couleur black
	Forme(int type, int couleur = BLACK) :Type(type) { 
		setCouleur(couleur); 
		}

	virtual ~Forme() {};

	virtual void setCouleur(int couleur);
	int getCouleur() { return Couleur; }

	int getType() { return Type; }
	void DejaApp() { DejaAppartenant = true; }
	void Non_App() { DejaAppartenant = false; }

	int getApp()const { return DejaAppartenant; }

	virtual void add(Forme * f) {};
	virtual string toString()const;
	friend ostream & operator << (ostream & os, const Forme & f);
	
	operator string() const;

	//Calcul de la surface de forme
	virtual double Aire()const = 0;

	//Acceptation des visiteurs
	virtual void accepte(const Visiteur * visiteur) = 0;

};
inline ostream & operator << (ostream & os, const Forme & f)
{
	os << f.toString();
	return os;
}
inline Forme::operator string() const
{
	ostringstream  os;
	
	os << this->toString();
	return os.str();
}

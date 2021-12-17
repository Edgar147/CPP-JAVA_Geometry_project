#pragma once
#include "Forme.h"
#include "../Visiteur/Visiteur.h"
using namespace std;

//Class des composes avec un vecteur
class Compose:
	public Forme
{
public:
	//Vector des membres
	vector<Forme *> VectFormes;
	Compose(int Couleur = 1):Forme(COMPOSE,Couleur){}
	~Compose() {};


	//ajouter une forme dans le compose
	void add(Forme * f)
	{
		f -> DejaApp();

		f->setCouleur(getCouleur());
		VectFormes.push_back(f);
	}
	void setCouleur(int couleur);

	string toString()const;

	friend ostream & operator << (ostream & os, const Compose & c);
	operator string() const;

	double Aire()const;
	void accepte(const Visiteur * visiteur);

};
inline ostream & operator << (ostream & os, const Compose & c)
{
	os << c.toString();

	return os;
}

inline Compose::operator string() const
{
	ostringstream  os;
	os << this->toString();
	return os.str();
}
//ON calcule la surface
inline double Compose::Aire() const
{
	double s = 0.0;
	for (int i = 0;i < (int)VectFormes.size();i++)
	
		s += VectFormes[i]->Aire();
	return s;
}


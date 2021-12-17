#pragma once
#include "Forme.h"
#include<math.h>
#include "../Visiteur/Visiteur.h"
using namespace std;

//Representation de Classe polygone avec des vectors
class Polygone :
	public Forme
{
public:
	vector<Vecteur2D *> Vector_Points;
	Polygone() :Forme(POLYGONE) {}
	~Polygone() {};
//ajout d'un point
	void add(Vecteur2D * v)
	{
		Vector_Points.push_back(v);
	}


	void add(double x,double y)
	{
		Vecteur2D * v =new Vecteur2D(x, y);

		Vector_Points.push_back(v);

	}



	string toString()const;
	void accepte(const Visiteur * visiteur);

	friend ostream & operator << (ostream & os, const Polygone & c);
	operator string() const;
	double Aire()const;
};
inline ostream & operator << (ostream & os, const Polygone & c)
{
	os << c.toString();
	return os;
}
inline Polygone::operator string() const
{
	ostringstream  os;
	os << this->toString();
	return os.str();
}

inline string Polygone::toString() const
{
	string s = Forme::toString();
	s += ",Points = ";

	for (int i = 0;i < (int)Vector_Points.size();i++)
		s += string(*Vector_Points[i]);
		
	return s + "]";
}

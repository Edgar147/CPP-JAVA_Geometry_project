#include "Cercle.h"
string Cercle::toString() const
{
	return Forme::toString() + ",Center = " +string(Center) + ",Rayon = " + to_string(Rayon) + "]";
}


void Cercle::accepte(const Visiteur * visiteur)
{
	visiteur->visite(this);
}

ostream & operator<<(ostream & os, const Cercle & c)
{
	os << c.toString();

	return os;
}

//On calcule la surface de cercle
double Cercle::Aire() const
{
	return Rayon * Rayon * 3.14;
}

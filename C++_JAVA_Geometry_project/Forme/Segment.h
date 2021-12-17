#pragma once
#include "Forme.h"
#include "../Visiteur/Visiteur.h"
using namespace std;
//Class de representation de segment, avec 2 vectors
class Segment :
	public Forme
{
	Vecteur2D Debut;
	Vecteur2D Fin;
public:
	Segment(Vecteur2D d, Vecteur2D f) :Forme(SEGMENT), Debut(d), Fin(f) {}

	~Segment();

	Segment(double x1, double y1, double x2, double y2):Forme(SEGMENT)
	{
		Debut = Vecteur2D(x1, y1);
		Fin = Vecteur2D(x2, y2);
	}

	Vecteur2D getDebut()const {
		 return Debut;
		  }
	Vecteur2D getFin()const { 
		return Fin; 
		}

	void setDebut(Vecteur2D d) { 
		Debut = d;
		 }
	void setFin(Vecteur2D d) { 
		Fin = d;
		 }

	string toString()const;
	void accepte(const Visiteur * visiteur);

	friend ostream & operator << (ostream & os, const Segment & c);
	operator string() const;
	//Calcul de l'aire de segment, qui est toujours 0
	double Aire()const { return 0.0; }
};
inline ostream & operator << (ostream & os, const Segment & c)
{
	os << c.toString();
	return os;
}

inline Segment::~Segment() { };

inline string Segment::toString() const
{
	return Forme::toString() + ",Debut = " + string(Debut) + ",Fin = " +string(Fin) + "]";
}


inline Segment::operator string() const
{
	ostringstream  os;
	os << this->toString();
	
	return os.str();
}

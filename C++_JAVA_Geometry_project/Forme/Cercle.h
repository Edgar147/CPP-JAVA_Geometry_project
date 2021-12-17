#pragma once
#include "Forme.h"
#include "../Visiteur/Visiteur.h"
using namespace std;
/*Class Cercle
Avec deux champs Center(Vecteur2D) et Rayon(Double)
*/
//Classe Cercle avec Center(Vecteur2D) et Rayon(Double)
class Cercle :
	public Forme
{
	Vecteur2D  Center;
	double Rayon;
public:
	Cercle(Vecteur2D Center, double rayon);

	Cercle(double y ,double x, double rayon);

	~Cercle() {};

	string toString()const;

	void accepte(const Visiteur * visiteur);

	friend extern ostream & operator << (ostream & os, const Cercle & c);


	double Aire()const;

	operator string() const;

	//Setter et Getter

	void setCenter(Vecteur2D v) {
		 Center = v; 
		 }
	Vecteur2D getCenter() const{
		 return Center; 
		 }
	void setRayon(double r) { 
		Rayon = r;
		 }
	double getRayon() const{ 
		return Rayon; 
		}
};

inline Cercle::operator string() const
{
	ostringstream  os;
	os << this->toString();
	return os.str();
}
//rayon->r
inline Cercle::Cercle(Vecteur2D Center, double rayon) :Forme(CERCLE)
{
	this->Center = Center;
	if (rayon <= 0)
		throw Erreur("Le rayon est negatif");

	this->Rayon = rayon;
}

inline Cercle::Cercle(double x, double y, double rayon) :Forme(CERCLE)
{
	if (rayon <= 0)
		throw Erreur("Le rayon est negatif");
	this->Rayon = rayon;
	
	Center = Vecteur2D(x, y);
}
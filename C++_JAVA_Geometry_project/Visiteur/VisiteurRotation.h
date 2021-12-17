#pragma once
#include "Visiteur.h"

//Visite et rotation avec un radian
class VisiteurRotation :
	public Visiteur
{
	double r1;//////////////////////?????????????
public:
	VisiteurRotation(double r2) :r1(r2) {}

	~VisiteurRotation(){}

	Vecteur2D Rotation_Vecteur(const double angle, Vecteur2D  v)const;

	void visite(Compose *)const;
	void visite(Cercle *)const;
	void visite(Segment *)const;
	void visite(Polygone *)const;
};

//Rotation sur vecteur
inline Vecteur2D VisiteurRotation::Rotation_Vecteur(const double angle, Vecteur2D  v)const
{
	if (v.getX() == v.getY() == 0)
		return v;
	double x = v.getX() * cos(angle) - v.getY() * sin(angle);
	double y = v.getX() * sin(angle) + v.getY() * cos(angle);
	v = Vecteur2D(x, y);
	return v;
}


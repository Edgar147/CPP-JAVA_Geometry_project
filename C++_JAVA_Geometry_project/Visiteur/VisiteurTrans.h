#pragma once
#include "Visiteur.h"
/*
Visiter et faire translation a une forme avec un Vecteur2D
*/
class VisiteurTrans :
	public Visiteur
{
	Vecteur2D v;
public:
	VisiteurTrans(double x1, double y1):v(x1,y1) {};
	~VisiteurTrans() {};
	

	void visite(Segment *)const;
	void visite(Cercle *)const;
	void visite(Polygone *)const;
	void visite(Compose *)const;

};


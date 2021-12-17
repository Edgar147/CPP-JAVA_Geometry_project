#pragma once
#include "Visiteur.h"

class VisiteurHomotethie :
	public Visiteur
{
	double f;
public:
	VisiteurHomotethie(double f1) :f(f1) {}
	~VisiteurHomotethie(){}

	void visite(Compose *)const;
	void visite(Cercle *)const;
	void visite(Segment *)const;
	void visite(Polygone *)const;
};




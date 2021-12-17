#include "Polygone.h"


void Polygone::accepte(const Visiteur * visiteur)
{
	visiteur->visite(this);
}

//Calcul de la surface
double Polygone::Aire() const
{
	double a, b, c;
	double result = 0;
	double p;
	for (int i = 2; i < (int)Vector_Points.size(); i++)
	{
		a = sqrt(pow(Vector_Points[i - 1]->x - Vector_Points[0]->x, 2.0) + pow(Vector_Points[i - 1]->y - Vector_Points[0]->y, 2.0));
		b = sqrt(pow(Vector_Points[i]->x - Vector_Points[i - 1]->x, 2.0) + pow(Vector_Points[i]->y - Vector_Points[i - 1]->y, 2.0));
		c = sqrt(pow(Vector_Points[i]->x - Vector_Points[0]->x, 2.0) + pow(Vector_Points[i]->y - Vector_Points[0]->y, 2.0));
		p = (a + b + c) / 2;
		
		result += sqrt(p*(p - a)*(p - b)*(p - c));
	}
	return result;
}
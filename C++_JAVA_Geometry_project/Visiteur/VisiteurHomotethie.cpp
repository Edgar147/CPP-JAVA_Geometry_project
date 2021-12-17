#include "VisiteurHomotethie.h"

//Deplacement de composé
void VisiteurHomotethie::visite(Compose * c) const
{
	for (int i = 0; i < (int)c->VectFormes.size(); i++)
	{
		c->VectFormes[i]->accepte(this);
	}
}

//Deplacement de cercle
void VisiteurHomotethie::visite(Cercle * c) const
{
	c->setCenter(c->getCenter() * f);
	c->setRayon(c->getRayon() * f);
}

//Deplacement de segment
void VisiteurHomotethie::visite(Segment * s) const
{
	s->setDebut(s->getDebut() * f);

	s->setFin(s->getFin() * f);
}


//Deplacement de polygone
void VisiteurHomotethie::visite(Polygone * c) const
{
	for (int i = 0; i < (int)c->Vector_Points.size(); i++)
	{
		*(c->Vector_Points[i]) = *(c->Vector_Points[i]) * f;
	}
}

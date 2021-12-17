#include "VisiteurTrans.h"




//Deplacement d'une segment
void VisiteurTrans::visite(Segment * s) const
{
	s->setDebut(s->getDebut() + v);
	s->setFin(s->getFin() + v);
}


//Deplacement de cercle
void VisiteurTrans::visite(Cercle * c) const
{
	c->setCenter(c->getCenter() + v);
}


//Deplacement de polygone
void VisiteurTrans::visite(Polygone * c) const
{
	for (int i = 0;i < (int)c->Vector_Points.size();i++)
	{

		*(c->Vector_Points[i]) += v;
	}
}


//Deplacement de composé
void VisiteurTrans::visite(Compose * c) const
{
	for (int i = 0;i < (int)c->VectFormes.size();i++)
	{
		c->VectFormes[i]->accepte(this);
	}

}



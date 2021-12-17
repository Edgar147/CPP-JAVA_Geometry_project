#include "VisiteurRotation.h"
//rotation sur forme composé
void VisiteurRotation::visite(Compose * c) const
{
	for (int i = 0;i < (int)c->VectFormes.size();i++)
	{
		c->VectFormes[i]->accepte(this);
	}
}


//Rotation sur cercle
void VisiteurRotation::visite(Cercle * c) const
{
	c->setCenter(Rotation_Vecteur(r1, c->getCenter()));
}

//rotation sur un segment
void VisiteurRotation::visite(Segment * c) const
{
	c->setDebut(Rotation_Vecteur(r1, c->getDebut()));
	c->setFin(Rotation_Vecteur(r1, c->getFin()));
}

//rotation sur un polygone
void VisiteurRotation::visite(Polygone * c) const
{
	for (int i = 0;i < (int)c->Vector_Points.size();i++)
	{
		
		//*(c->Vector_Points[i]) = Rotation_Vecteur(r1, *(c->Vector_Points[i]));
		
	}
}
#include "VisiteurSauvegarder.h"
//Sauvegarde d'une forme
string garderForme(Forme * f)
{
	return to_string(f->getType()) + "," + to_string(f->getCouleur()) + "," + to_string(f->getApp()) + ",";
}
//Soveguarde du forme composé
void VisiteurSauvegarder::visite(Compose * c) const
{
	string s = garderForme(c) + to_string((c->VectFormes.size()));
	Garder(s);

	for (int i = 0;i < (int)c->VectFormes.size();i++)
		c->VectFormes[i]->accepte(this);
}

//Sauvegarde d'un cercle
void VisiteurSauvegarder::visite(Cercle * c) const
{
	string s = garderForme(c) + garderVecteur(c->getCenter()) + "," + to_string(c->getRayon());
	Garder(s);
}

//Sauvegarde d'un segment
void VisiteurSauvegarder::visite(Segment * c) const
{
	string s = garderForme(c)  + garderVecteur(c->getDebut()) + "," + garderVecteur(c->getFin());
	Garder(s);
}


//Sauvegarde d'un polygone
void VisiteurSauvegarder::visite(Polygone * c) const
{
	string s = garderForme(c) + to_string(c->Vector_Points.size());

	for (int i = 0;i < (int)c->Vector_Points.size();i++)
		s += "," + garderVecteur(*c->Vector_Points[i]);
		
	Garder(s);
}

string garderVecteur(Vecteur2D v)
{
	return to_string(v.getX()) + "," + to_string(v.getY());
}
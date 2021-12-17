#include "Compose.h"

void Compose::setCouleur(int couleur)
{
	for (int i = 0;i < (int)VectFormes.size();i++)
	{
		VectFormes[i]->setCouleur(couleur);
	}
}

string Compose::toString() const
{
	string s = string("[Compose=");
	for (int i = 0;i < (int)VectFormes.size();i++)
		s += string(*VectFormes[i]);
	return s + "]";
	
}

void Compose::accepte(const Visiteur * visiteur)
{
	visiteur->visite(this);
}


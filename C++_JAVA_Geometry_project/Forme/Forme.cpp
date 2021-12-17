#include "Forme.h"


void Forme::setCouleur(int couleur)
{
	if (couleur < 0 || couleur > 5)
		throw Erreur("La  couleur n'existe pas");
		
	Couleur = couleur;
}

string Forme::toString() const
{
	return string("[Forme:Type=")+to_string(Type)+",DejaAppartenant="+ to_string(DejaAppartenant)
			+ ",Couleur=" + to_string(Couleur);
}

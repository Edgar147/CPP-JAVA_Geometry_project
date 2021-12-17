#include "VisiteurDessine.h"
#include "VisiteurSauvegarder.h"
void VisiteurDessine ::DessineForme(Forme * f,string & s)const
{
	string r = to_string(f->getType()) + "," + to_string(f->getCouleur()) + "," + to_string(f->getApp()) + ",";
	r += s + "\r\n";
	cd->consRequeteEnvoi(r);
}

VisiteurDessine::VisiteurDessine()
{
	string adresseServeur;
	int portServeurDessin;
	cout << "Saisissez l'adresse du Serveur" << endl;
	cin >> adresseServeur;
	cout << "Saisissez le port du serveur" << endl;
	cin >> portServeurDessin;
	cd = new Client_Dessin(adresseServeur, portServeurDessin);

	string titre;
	int Ox, Oy, largeur, hauteur;

	cout << "Saisissez le titre de la fenetre de dessin" << endl;
	cin >> titre;
	cout << "Saisissez l'abcisse d origine de la fenetre de dessin" << endl;
	cin >> Ox;
	cout << "Saisissez l'ordonnee d origine de la fenetre de dessin" << endl;
	cin >> Oy;
	cout << "Saisissez largeur de la fenetre de dessin" << endl;
	cin >> largeur;
	cout << "Saisissez la hauteur de la fenetre de dessin" << endl;
	cin >> hauteur;

	cd->ouvreFenetreGraphique(titre, Ox, Oy, largeur, hauteur);

}
void VisiteurDessine::visite(Compose * c) const
{
	for (int i = 0;i < (int)c->VectFormes.size();i++)
		c->VectFormes[i]->accepte(this);
}

void VisiteurDessine::visite(Cercle * c) const
{
	string s = garderVecteur(c->getCenter()) + "," + to_string(c->getRayon());

	DessineForme(c, s);
}

void VisiteurDessine::visite(Segment * c) const
{
	string s = garderVecteur(c->getDebut()) + "," + garderVecteur(c->getFin());
	DessineForme(c, s);
}

void VisiteurDessine::visite(Polygone * c) const
{
	string s = to_string(c->Vector_Points.size());

	for (int i = 0;i < (int)c->Vector_Points.size();i++)
		s += "," + garderVecteur(*c->Vector_Points[i]);
		
	DessineForme(c, s);
}

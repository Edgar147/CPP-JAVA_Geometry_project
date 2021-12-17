#pragma once
#include "Visiteur.h"
#include"Client_Dessin.h"
#include "VisiteurSauvegarder.h"

//ON visite et envoie des informations des formes vers serveur avec une requete
class VisiteurDessine :
	public Visiteur
{
	Client_Dessin * cd;
public:
	VisiteurDessine();
	~VisiteurDessine() {  };

	//Dessiner compose
	void visite(Compose *)const;

	//Dessiner Cercle 
	void visite(Cercle *)const;

	//Dessiner Segment
	void visite(Segment *)const;

	//Dessiner Polygone
	void visite(Polygone *)const;
	
	//Construction et envoie de requete
	void DessineForme(Forme * f,string & s)const;
};



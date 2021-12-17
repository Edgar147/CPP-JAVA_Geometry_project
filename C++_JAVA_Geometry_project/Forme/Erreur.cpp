/**
mise en oeuvre de la classe Erreur
*/
using namespace std;

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Erreur.h"

//int Erreur::LONGUEURMESSAGE(50);

Erreur::Erreur()
{
	strcpy_s(this->message, "Erreur !");
}


Erreur::Erreur(const char * messageErreur)
{
	strcpy_s(this->message, "Erreur : ");
	int l = strlen(messageErreur);
	static int n = LONGUEURMESSAGE - 9;
	if (l <= n) strcat_s(this->message, messageErreur);
	else
	{
		strncat_s(this->message, messageErreur, n);
		this->message[LONGUEURMESSAGE] = '\0';
	}
}

Erreur::operator string() const
{
	return string(this->message);
}

ostream & operator << (ostream & os, const Erreur & erreur)
{
	os << (string)erreur;
	return os;
}

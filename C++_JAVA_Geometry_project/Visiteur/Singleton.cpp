#include <iostream>
#include "../Forme/Erreur.h"
#include "Singleton.h"

using namespace std;

/* static */ Singleton * Singleton::instanceUnique = NULL;

/* static */ Singleton * Singleton::getInstance()
{
	if (!instanceUnique)
		instanceUnique = new Singleton;

	return instanceUnique;
}

Singleton::Singleton(void)
{
	int r;

	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert ?indiquer la version de la librairie ?utiliser : 1 pour winsock et 2 pour winsock2

	/* en cas de succee, wsaData a initialisee et l'appel a renvoy?la valeur 0 */

	if (r)
		throw Erreur("L'initialisation a echou?");

	cout << "initialisation winsock effectuee" << endl;
}


Singleton::~Singleton(void)
{
	WSACleanup();
	cout << "liberation des ressources de la winsock effectuee" << endl;
}
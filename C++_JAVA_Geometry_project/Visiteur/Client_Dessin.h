#pragma once

#include <WinSock2.h>
#include <string>

using namespace std;

/**
 * creer un client TCP/IP vers un serveur JAVA de dessin
 */
class Client_Dessin
{
	SOCKET sock;			// informations concernant le socket ?creer : famille d'adresses acceptees, mode connect?ou non, protocole 
	SOCKADDR_IN sockaddr;	// informations concernant le serveur avec lequel on va communiquer

public:
	Client_Dessin(const string & adresseServeurDessin = "", const int portServeurDessin = 0);
	~Client_Dessin();
	void consRequeteEnvoi(const string reauete);
	void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);
};


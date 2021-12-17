
#pragma warning(disable : 4996)


#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../Forme/Erreur.h"
#include "Singleton.h"
#include "Client_Dessin.h"


using namespace std;

/**
 * cree un client TCP/IP vers un serveur de dessin
 *
 * envoie 3 requetes possibles :
 *
 * ouvrir une fenetre graphique
 * tracer un segment
 * tracer un cercle
 *
 * protocole : Chaque requete est codee sous forme d'une seule String se terminant par le caractere fin de ligne.
 * Sur la ligne, 2 parametres constutifs sont separe par ", ".
 *
 * */

Client_Dessin::Client_Dessin(const string & adresseServeurDessin, const int portServeurDessin)
{
	Singleton::getInstance();	// initialisation de la DLL : effectuee une seule fois


	//----------------------// création socket \\------------------------------------------------------------------------------------------------------------------------------------
	int xx;
	int r;
	int familleAdresses = AF_INET;		    // IPv4
	int typeSocket = SOCK_STREAM;           // mode connect?TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
											// pour les valeurs des parametres : cf. fct socket dans la doc sur winsock

	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la creetion du socket a echoue: code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyees par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket de dessin cree" << endl;

	//------------------------------// création du representant du serveur \\--------------------------------------------------------------------------------------------------------

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

	//--------------// connexion du client au serveur \\-----------------------------------------------------------------------------------------------------------------------------

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																	// Le code d'erreur peut etre obtenu par un appel ?WSAGetLastError()
	xx= sockaddr.sin_addr.s_addr;
	if (r == SOCKET_ERROR)
		throw Erreur("La connexion au serveur de dessin a echoue");
	cout << "connexion au serveur de dessin reussie" << endl;
}

Client_Dessin::~Client_Dessin()
{
	int r = shutdown(sock, SD_BOTH);						// on coupe la connexion pour l'envoi et la reption
															// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel ?WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a echoue");


	r = closesocket(sock);									// renvoie une valeur non nulle en cas d'echec. Le code d'erreur peut être obtenu par un appel ?WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a echoue");

	cout << "arrêt normal du client" << endl;
}
void Client_Dessin::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
	ostringstream oss;
	oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";
	consRequeteEnvoi(oss.str());
}

void Client_Dessin::consRequeteEnvoi(const string requete )
{
	
	int r = send(sock, requete.c_str(), (int)requete.length(), 0); //------------------ envoi de la requtee au serveur ------------------------------------------------------------------

	if (r == SOCKET_ERROR)
		throw Erreur("echec de l'envoi de la requete d'ouverture de fenetre graphique");
	cout << "requete envoye:"<<requete << endl;
}

//const ostringstream Client_Dessin::tracerCercle
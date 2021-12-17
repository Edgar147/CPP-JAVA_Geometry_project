#pragma once

#include <WinSock2.h>

/**
	Singleton contenant l'initialisation de la librairie winsock2.
	Assure que la DLL de la winsock est initialisee une unique fois
*/
class Singleton
{
	WSADATA wsaData;	//  structure contenant les donnees de la librairie winsock ?initialiser. represente la DLL.
	Singleton(void);

	static Singleton * instanceUnique;

public:
	static Singleton * getInstance();
	~Singleton(void);
};


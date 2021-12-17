#pragma once
/**
classe Erreur
*/
#ifndef ERREUR
#define ERREUR

using namespace std;

#include <string>
#include <iostream>

class Erreur
{
public:
	const static int LONGUEURMESSAGE = 100;
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	Erreur(const char * messageErreur);


	inline static void testeEgalite(int m, int n, const char * message);

	/**
	 * v�rifie que a <= b
	 * lance une exception si a > b
	 *
	 * */
	inline static void testePlusPetitOuEgal(const int a, const int b, const char * message);

	/**
	 * lance une exception si x n'est pas dans [a,b]
	 * */
	inline static void testeAppartient(int a, int x, int b, const char * message);

	/**
	 * lance une exception si d est vide
	 * */

	inline static void testeNonVide(const void *d, const char * message);

	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);

inline void Erreur::testeEgalite(int m, int n, const char * message)
{
#ifdef DEBUG
	if (m != n) throw Erreur(message);
#endif
}


/**
 * v�rifie que a <= b
 * lance une exception si a > b
 *
 * */
inline /*static*/ void Erreur::testePlusPetitOuEgal(const int a, const int b, const char * message)
{
#ifdef DEBUG
	if (a > b) throw Erreur(message);
#endif
}



/**
 * lance une exception si x n'est pas dans [a,b]
 * */
inline /*static*/ void Erreur::testeAppartient(int a, int x, int b, const char * message)
{
	Erreur::testePlusPetitOuEgal(a, x, message);
	Erreur::testePlusPetitOuEgal(x, b, message);
}

/*{
#ifdef DEBUG
if ( !(  a <= x && x <= b ) ) throw Erreur(message);
#endif
}*/

/**
 * lance une exception si d est vide
 * */

inline /*static*/ void Erreur::testeNonVide(const void *d, const char * message)
{
#ifdef DEBUG
	if (!d) throw Erreur(message);
#endif
}



#endif



#pragma once
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

class Vecteur2D
{
public:
	double x, y;

	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* DONNEES : s respectant le format "(  nombre r��el, nombre r��el)"
	*
	* */
	inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline void operator += (const Vecteur2D & u);
	inline const Vecteur2D operator * (const double & a) const;
	/**
	* - unaire (c'est-��- dire oppos�� d'un vecteur)
	* */
	inline const Vecteur2D operator - () const;

	double getX()const { return x; }
	double getY()const { return y; }

	operator string() const;

};


inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u * a; }

//------------ impl��mentation des fonctions inline ----------------------

inline  Vecteur2D::Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

inline Vecteur2D::Vecteur2D(const char * s)
{
#pragma warning(disable : 4996)
	char fen[20];
	int i;
	int j;
	for (i = 1;i < (int)strlen(s);i++)
	{
		if (s[i] == ',')
		{
			strncpy_s(fen, s + 1, i - 1);
			fen[i] = '\0';
			x = strtod(fen, NULL);
			j = i;
		}
	}
	for (i;i < (int)strlen(s);i++)
	{
		if (s[i] == ')')
		{
			strncpy_s(fen, s + j, i - j);
			fen[i - j + 1] = '\0';
			y = strtod(fen, NULL);
		}
	}
}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

inline void Vecteur2D::operator += (const Vecteur2D & u)
{
	this->x = x + u.x;
	this->y = y + u.y;
}
inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

inline Vecteur2D::operator string() const
{
	ostringstream  os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

inline ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << (string)u;
	return os;
}
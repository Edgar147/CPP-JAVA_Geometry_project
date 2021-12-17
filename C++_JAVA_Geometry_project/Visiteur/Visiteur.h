#pragma once
#include<iostream>
#include<math.h>

#include"../Forme/Segment.h"
#include"../Forme/Cercle.h"
#include"../Forme/Polygone.h"
#include"../Forme/Compose.h"
using namespace std;
class Forme;
class Compose;
class Cercle;
class Segment;
class Polygone;
class Visiteur
{
public:
	Visiteur() {};
	virtual ~Visiteur() {};


	
	virtual void visite(Segment *)const = 0;
	virtual void visite(Cercle *)const = 0;
	virtual void visite(Polygone *)const = 0;
	virtual void visite(Compose *)const=0;
};


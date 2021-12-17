#include "VisiteurString.h"


void VisiteurString::visite(Segment * t) const
{
	Ecrire(t);
}



void VisiteurString::visite(Cercle * t) const
{
	Ecrire(t);
}


void VisiteurString::visite(Polygone * t) const
{
	Ecrire(t);
}

void VisiteurString::visite(Compose * t) const
{
	Ecrire(t);
}

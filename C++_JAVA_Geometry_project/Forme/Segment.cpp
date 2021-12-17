#include "Segment.h"


void Segment::accepte(const Visiteur * visiteur)
{
	visiteur->visite(this);
}



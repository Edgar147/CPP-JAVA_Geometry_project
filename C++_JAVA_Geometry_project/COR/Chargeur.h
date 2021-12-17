#pragma once
#include"ReadForme.h"
#include"../Forme/Compose.h"
#include<fstream>
//Cela charge  à partir d'un fichier
class Chargeur
{

	const char * adresse;
	ReadForme * rd;

	

public:
		Chargeur(ReadForme * f1,const char * a):rd(f1),adresse(a){}
	
	//On construie une vector qui contient les formes composés
		vector<Forme *> v_Compos(vector<Forme *> v, int * composes, int n);
	
	//On charge les formes à partir d'un fichier rd
		vector<Forme *> Charger();

};

//De chaine de carac a double
double * CaracDouble(char * ch);

//On crée une forme avec z
Forme * CaracForme(char * ch, Forme *(*f)(double * d));

//De string à chaine
char * StringChar(const string & aux);


double * CaracDouble(char * chaine)
{
	double * d = (double *)malloc(sizeof(double)*BUFSIZ);
	int n = 0;
	if (chaine == NULL)
		throw Erreur("Chaine null, essayez autre chose");

	char * aux = (char *)malloc(sizeof(char)*BUFSIZ);
	
	const char * s = ",";

	//On resultpère les chaines ,divisées par ,
	aux = strtok(chaine, s);

	while (aux != NULL)
	{
		d[n] = atof(aux); //de chaine à double(int)
		n++;
		aux = strtok(NULL, s);
	}
	return d;
}


Forme * CaracForme(char * chaine, Forme *(*f)(double * d))
{
	double * d;
	d = CaracDouble(chaine);

	Forme * c = f(d);

	c->setCouleur((int)d[1]);

	if ((int)d[2] == 1){

		c->DejaApp();
	}
	return c;
}

char * StringChar(const string & aux)
{
	int lng = aux.size();

	char * ch= (char *)malloc((lng + 1) * sizeof(char));

	aux.copy(ch, lng, 0);
	ch[lng + 1] = '\0';
	return ch;
}

vector<Forme *>Chargeur::v_Compos(vector<Forme *> v, int * composes, int n)
{
	vector<Forme *> result;
	Compose * c = NULL;
	int i;
	//on copie jusqu'à la dernière compose
	for (i = composes[n - 2];i < composes[n - 1]+ composes[n - 2];i++)

		result.push_back(v[i]);

	//on construie encore le compose

	c = new Compose();
	for (int j = 0;j < composes[n - 2];j++)
	{
		i++;
		c->add(v[i]);
	}
	result.push_back(c);
	i++;
	//copy les restes
	for (i;i < (int)v.size();i++)
		result.push_back(v[i] );
	n =n - 2;
	if (n > 0)
		return v_Compos(result, composes, n);
	return result;
}
vector<Forme *> Chargeur::Charger()
{
	vector<Forme *> v;
	int * composes = (int*)malloc(sizeof(int)*BUFSIZ);

	ifstream readFile(adresse);
	int nbComposes = 0;

	string aux;
	string aux1 = ".";

	readFile >> aux;

	while (aux != aux1)
	{
		char * ch = StringChar(aux);

		aux1 = aux.data();

		char ch1 = ch[6];
		Forme * f = rd->Lires(ch);

		if (f->getType() == Forme::COMPOSE)
		{
			composes[nbComposes] = (int)v.size();
			double * d = CaracDouble(&ch1);

			composes[nbComposes + 1] = (int)d[0];
			nbComposes = nbComposes + 2;
		}
		if (f != NULL)
		{
			v.push_back(f);
		}

		readFile >> aux;
	}
	readFile.close();

	
	if (nbComposes == 0)
		return v;
	return v_Compos(v, composes, nbComposes);
}

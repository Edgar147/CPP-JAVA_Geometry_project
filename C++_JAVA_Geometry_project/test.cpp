
#include <stdio.h>
#include <stdlib.h>
#include "Visiteur/VisiteurDessine.h"
#include"Visiteur/VisiteurString.h"
#include"Visiteur/VisiteurRotation.h"
#include"Visiteur/VisiteurTrans.h"
#include"Visiteur/VisiteurSauveGarder.h"
#include"Visiteur/VisiteurHomotethie.h"
#include"Visiteur/VisiteurDessine.h"
#include"COR/COR_ReadCompose.h"
#pragma comment(lib, "ws2_32.lib") 
using namespace std;

int main()
{
	double a, k;
	k = 80;
	a = 80;
	Polygone *R1 = new Polygone();
	R1->add(a+k*1, -1*k+a);
	R1->add(a+k*5, -1*k+a);
	R1->add(a+k*5, 1*k+a);
	R1->add(a+k*1, 1*k+a);
	R1->setCouleur(4);


	Polygone * T1 = new Polygone();
	T1->add(a+k*6, -1*k+a);
	T1->add(a+k*8, 0*k+a);
	T1->add(a+k*6, 1*k+a);
	T1->setCouleur(4);




	Cercle * C1 = new Cercle(a+k*11, a+k*2, 2*k);
	C1->setCouleur(4);


	Compose G1 = Compose(Forme::RED);
	G1.add(R1);
	G1.add(T1);
	G1.add(C1);
	
	VisiteurTrans * vt = new VisiteurTrans(150, 150);
	G1.accepte(vt);

	
	VisiteurRotation * vr = new VisiteurRotation(2);
	G1.accepte(vr);


	

	cout << G1 << "Aire =" << G1.Aire() << endl;


	fstream file("text/mabellefigure1.txt", ios::out);
	file.close();
	VisiteurSauvegarder v = VisiteurSauvegarder("text/mabellefigure1.txt");
	G1.accepte(&v);

	char * aux = (char *)malloc(sizeof(char)*BUFSIZ);
	COR_ReadCercle * Corc = new COR_ReadCercle();
	COR_ReadPolygone * Corp = new COR_ReadPolygone(Corc);
	COR_ReadSegment * Cors = new COR_ReadSegment(Corp);
	COR_ReadCompose * Coro = new COR_ReadCompose(Cors);
	Chargeur * cg = new Chargeur(Coro, "text/mabellefigure1.txt");
	vector<Forme *> vf = cg->Charger();
	









	Compose G2 = Compose(Forme::RED);










	//Chargeur * cg = new Chargeur( "text/Info.txt");


	/*
	Cercle * c = new Cercle(100, 100, 30);

	VisiteurTrans * vt = new VisiteurTrans(150, 300);
	c->accepte(vt);
	*/



	/*
	Segment * s = new Segment(0, 0, 300, 300);
	Polygone * p = new Polygone();
	p->add(0, 0);
	p->add(110,201);
	p->add(201, 100);
	p->add(200, 200);
	Compose cp1 = Compose(Forme::RED);
	Compose cp2 = Compose(Forme::BLUE);
	cp1.add(c);
	cp2.add(p);
	cp2.add(&cp1);
	*/
/*
	//Test aire
	cout << *c <<"Aire :"<<c->Aire()<< endl;
	cp1.add(c);
	cout << cp1 << "Aire :"<<cp1.Aire()<<endl;
	cp2.add(p);
	cp2.add(&cp1);
	cout << cp2<< "Aire :" << cp2.Aire() << endl;
	cout << p->toString() << " Aire:" << p->Aire();
	*/
	/*
	//TestCOR
	fstream file("text/Info.txt", ios::out);
	file.close();
	VisiteurSauvegarder v = VisiteurSauvegarder("text/Info.txt");
	cp1.accepte(&v);
	char * aux = (char *)malloc(sizeof(char)*BUFSIZ);
	COR_ReadCercle * Corc = new COR_ReadCercle();
	COR_ReadPolygone * Corp = new COR_ReadPolygone(Corc);
	COR_ReadSegment * Cors = new COR_ReadSegment(Corp);
	COR_ReadCompose * Coro = new COR_ReadCompose(Cors);
	Chargeur * cg = new Chargeur(Coro, "text/Info.txt");
	vector<Forme *> vf = cg->Charger();
	for (int i = 0;i < (int)vf.size();i++)
	{
		cout << endl<< i<<"." << *vf[i] << endl;
	}
	*/
	/*
	//Test Visiteur
	VisiteurRotation * vr = new VisiteurRotation(3.14);

	VisiteurTrans * vt = new VisiteurTrans(1, 1);

	VisiteurHomotethie * vh = new VisiteurHomotethie(2);

	cp2.accepte(vr);
	cout << cp2 << endl;

	cout << *c << endl;
	c->accepte(vh);
	cout << *c << endl;
	*/





	VisiteurDessine * vd = new VisiteurDessine();
	//vd->visite(c);
	//vd->visite(&cp2);
	//cp2.accepte(vd);
	vd->visite(&G1);
	cout << "Test fini" << endl;
	system("pause");
}

/*
C'est une classe qui est la "base" de toutes les autres classes qui peuvent dessiner  à 
partir d'une requete en utilisant le tableau des doubles
*/
abstract public class Dessin 
{

		//On effectuera le dessin à partir de la requete de la forme demandée
		abstract void dessiner( double[] d, CadreDessin cadreDessin);
}

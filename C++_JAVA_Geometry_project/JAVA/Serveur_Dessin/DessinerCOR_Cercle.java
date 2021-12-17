

//Ce classe aide à dessiner un cercle  avec les données requise.

public class DessinerCOR_Cercle extends DessinCOR
{
	private static final int CERCLE = 2;

	DessinerCOR_Cercle(DessinCOR dessinSuiv)
	{	super(dessinSuiv); }
	
	/**
	 * methode qui tente de dessiner un cercle si la requete est compatible au format de cercle
	 * @return 1 si il a pu dessiner le cercle et 0 sinon 
	 */
	//Ce method dessine un cercle ,si la requete est compatible au format requise pour cercle.
	//retourne 1 si dessiner ok, 0 sinon
	int dessiner1(double[] d, CadreDessin cadreDessin)
	{
		if ((int)d[0] == CERCLE)
		{
			cadreDessin.graphics.drawOval((int)d[3]-(int)d[5], (int)d[4]-(int)d[5], 2*(int)d[5], 2*(int)d[5]);
			return 1;
		}
		else
			return 0;
	}
}


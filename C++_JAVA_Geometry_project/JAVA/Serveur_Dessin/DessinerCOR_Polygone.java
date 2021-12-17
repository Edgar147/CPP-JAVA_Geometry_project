
 /*
 Le classe est pour dessiner le cercle, en utilisant les données de requete, avec 2 tableaux de x et y.
 */
public class DessinerCOR_Polygone extends DessinCOR 	
{

	private static final int POLYGONE = 3;

	DessinerCOR_Polygone(DessinCOR dessinSuiv)
	{	super(dessinSuiv); }
	

	//Methode pour dessiner polygone si requete ok pour polygone,retourne 1 si le dessin est ok, 0 sinon
	int dessiner1(double[] d, CadreDessin cadreDessin)
	{
		if ((int)d[0] == POLYGONE)
		{		
			int x[] = new int[(int)d[3]], y[] =new int[(int)d[3]];
			
			for(int i = 4, j = 0; j < d[3]; i += 2, j += 1)
			{
				System.out.println("continue");

				x[j] = (int)d[i];
				y[j] = (int)d[i+1];
			}

			cadreDessin.graphics.drawPolygon(x, y, (int)d[3]);
			return 1;
		}
		else 
		
			return 0;
	}
}

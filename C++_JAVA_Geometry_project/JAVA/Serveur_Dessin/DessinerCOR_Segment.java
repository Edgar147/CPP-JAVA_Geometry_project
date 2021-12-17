import java.awt.Color;


//Classe pour dessiner un segment
public class DessinerCOR_Segment extends DessinCOR
{
	public static final int SEGMENT = 1;

	DessinerCOR_Segment(DessinCOR dessinSuiv)
	{	super(dessinSuiv); }
	

	 //Methode qui doit dessiner un segment si la requete est du bon format, 
	 //si dessiner ok retourne 1, sinon 0
	int dessiner1(double[] d, CadreDessin cadreDessin)
	{
		if ((int)d[0] == SEGMENT)
		{
			cadreDessin.graphics.drawLine((int)d[3], (int)d[4], (int)d[5], (int)d[6]);
			cadreDessin.graphics.setColor(Color.black);
			return 1;
		}
		else 
			return 0;
	}
}


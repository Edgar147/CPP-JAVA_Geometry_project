
//Dessin utilisant COR
public abstract class DessinCOR extends Dessin
{
	protected DessinCOR dessinSuiv;

	
	DessinCOR (DessinCOR dessinSuiv)
	{	
		this.dessinSuiv = dessinSuiv; 

	}
	
	void dessiner( double[] d, CadreDessin cadreDessin)
	{
		if(this.dessiner1(d, cadreDessin) == 0 && dessinSuiv != null) 	//on essaye de dessiner
				this.dessinSuiv.dessiner(d, cadreDessin);
	}
	
	abstract int dessiner1(double[] d, CadreDessin cadreDessin);
}


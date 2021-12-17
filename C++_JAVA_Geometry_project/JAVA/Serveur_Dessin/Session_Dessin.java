/**
 * represente la session de dessin entreprise par un client distant.
 * 
 * Effectue principalement les operations suivantes :
 * 
 * ouvre une fenetre awt (Frame) pour dessiner dessus (les coordonn閑s de la fenetre sont indiqu閑s par le client).
 * puis execute sur la fenetre ouverte tous les ordres de tracee du client distant.
 * 
 * fonctionne dans un thread sera du thread principal.
 * 
 * */
import java.net.Socket;
import java.awt.Color;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;


public class Session_Dessin extends Thread
{
	Socket socket;                  // pour dialoguer avec le client distant. Peut-on se passer de cet attribut ?
	BufferedReader fluxEntrant;     // flux entrant pour recevoir les requetes du client
	CadreDessin responsableDessin;
	/**
	 * @param socket: permettant de lier le serveur a un des clients utilisant le soket
	 * 
	 * Cette classe lit les requetes arrivant dans le membre fluxEntrant
	 * 1. execute une instruction recue pour afficher une fenetre de dessin
	 * 2. execute une instruction recue de dessin de forme
	 * 
	 * Elle se charge de formater la requete afin que la chaine de responsabilite l'ecume et en retire toutes information susceptible d'engager le dessin d'une forme
	 * 
	 * 
	 * @throws IOException 
	 * 
	 * */
	public Session_Dessin(Socket socket) throws IOException
	{
		this.socket = socket;
		this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
	}
	
	@Override
	public void run()
	{
	String requete;
	
	try
	    {    
			Color[] colors = {Color.black,Color.blue,Color.red,Color.green,Color.yellow,Color.cyan};
		    requete = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonnees Ox, Oy, largeur et hauteur de la fenetre, les arguments sont separe des ","
		    System.out.println("requtee recue : " + requete);
	 	    String titre;
	 	    int Ox, Oy, largeur, hauteur;
	 	    
	 	    String argu[] = requete.split(",");
	 	    titre = argu[0].trim();
		    Ox = Integer.parseInt(argu[1].trim());         // redondance de code detiminer pour 8 lignes !!!! cf. lignes suivantes
	 	    Oy = Integer.parseInt(argu[2].trim());
	 	    largeur = Integer.parseInt(argu[3].trim());
		    hauteur = Integer.parseInt(argu[4].trim());
		    
		    responsableDessin = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
		    
		    while(true)
		    {
		    	 	requete = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonnees Ox, Oy, largeur et hauteur de la fenetre, les arguments sont separe  par des ","
				    System.out.println("requtee recue : " + requete);
		 	        DessinCOR Segment, Cercle, Polygone;
		 	        
		 	        Segment = new DessinerCOR_Segment(null);
		 	        Polygone = new DessinerCOR_Polygone(Segment);
		 	        Cercle = new DessinerCOR_Cercle(Polygone);
		 	        Dessin dessinateur = Cercle;	//constuire COR
		 	        
			 	    	String argument[] = requete.split(",");  
			 	    	int l2 = argument.length;
			 	    	double di = Double.parseDouble(argument[3]);
			 	    	System.out.println("voilà");
			 	       System.out.println(di);

				 	    double[] d = new double[(int)di + 10];
				 	    
			 		    for(int j = 0; j < l2; j += 1)	
			 		    	{d[j]= Double.parseDouble(argument[j]);System.out.println(d[j]);}
			 		    
					    responsableDessin.graphics.setColor(colors[(int)d[1]]);			 		    
			 	        dessinateur.dessiner(d, responsableDessin);
			 	      
			 	  //  }

			 	       responsableDessin.getBufferStrategy().show();		    	
		   }
	    }
	catch (SocketException e)
	    {
	    System.out.println("session de dessin termine par le client");
	    }
	catch (NumberFormatException e)
	    {
	    e.printStackTrace();
	    }
	catch (IOException e)
	    {
	    e.printStackTrace();
	    }
	catch (InterruptedException e)
    {
    e.printStackTrace();
    }
	}

}



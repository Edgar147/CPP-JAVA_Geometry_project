import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/*

 	Classe qui test les fonctionnalite du serveur de dessin:
	-	en attente de connexion au client
 	-	recoit les requetes soumises
 	-	affiche le dessin demande
 
 On crée un port pour connecter le socket cree par le client, pour communiquer avec les requetes
 On compte le nombre de client connecte au serveur
 On initie une session de dessin (classe session_dessin) 

 */

public class Main {

public static void main(String[] args)
{
int portServeur = 8080;   
try
    {

    @SuppressWarnings("resource")

	ServerSocket serveurDessin = new ServerSocket(portServeur);
    
    System.out.println("Serveur de dessin est pret : "+serveurDessin);
    
    int nbClients;
    
    nbClients = 0;
    
    while(true)
        {
        System.out.println("Serveur de dessin  attente le prochain client");

        Socket socket = serveurDessin.accept();

        ++nbClients;
        System.out.println("Nouveau client connecte = " + nbClients);
        Session_Dessin sessionDessin = new Session_Dessin(socket);                //session de dessin du nouveau client
       
        sessionDessin.start();                                                  // On travaille dans un thread separé en parall de fonctionnement serveurDessin
        }
    }
catch (IOException e)
    {
    
    System.err.println("Le serveur ne peut pas contacter le port ou la connexion sur ce port est interrompu \n Voir ici : "+e);
    }
}

}

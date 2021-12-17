//package clientserveurdessin.serveur.maladroit;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.Dimension;


/**
 * destine a recevoir des dessins realise en Active-Rendering
 * 
 * paint() est desactive
 * 
 * pourrait etre ameliore par l'utilisation d'un Canvas : Panel specialis pour le dessin
 * pourrait etre ameliore par l'utilisation de coordonnes relatives plutot que des coordonnes en pixels
 * */
public class CadreDessin extends Frame
{

private static final long serialVersionUID = 1L;

public Graphics graphics;      // Variable des manipulations de dessin

/*
   titre: le titre de la fenetre
   ox: abscisse  de bord gauche de la fenêtre
   oy: ordonne   de bord superieur de la fenetre
   largeur: largeur de la fenetre
   hauteur: hauteur de la fenetre
  
  l'unité est le pixel
  
 */

public CadreDessin(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
{
	super(titre);
//Parametres de la fenêtre

	Toolkit tk = Toolkit.getDefaultToolkit();
	
	int largeurF, hauteurF; // largeur Fenêtre, hauteur Fenêtre
	
	Dimension taille = tk.getScreenSize(); // La dimensions de l'ecran
	
	largeurF = (int) taille.getWidth();
	hauteurF = (int) taille.getHeight();
	
	int bordGauche, bordSuperieur, l, h ;
	
	bordSuperieur = Math.max(0, oy);
	bordGauche = Math.max(0, ox);


	l = Math.min(largeur, largeurF - bordGauche);
	h = Math.min(hauteur, hauteurF - bordSuperieur);

	this.setBounds(bordGauche, bordSuperieur, l, h);
	//this.setBounds(0, 350, l, h);


	//???????
	
	this.setVisible(true);
	
	//------------------------- initialisation de l'active rendering -----------------------
	
	this.setIgnoreRepaint(true);
	
	int nbBuffers = 1;

	this.createBufferStrategy(nbBuffers);
	Thread.sleep(50);   // il faut attendre un minimum de 50 ms pour que le buffer soit opeationnel
	this.graphics = this.getBufferStrategy().getDrawGraphics();
}

}

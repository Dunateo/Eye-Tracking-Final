#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "imageSF.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1080
#define HauteurFenetre 960
#define NB_ATTITUDE1 7
typedef DonneesImageRGB *tabImagee[NB_ATTITUDE1];
typedef struct sprite{
	int n;
	int numAtti[NB_ATTITUDE1];
}sprite;

typedef struct pt{
	float x,y;
}pt;

// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);

	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);

	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();

	return 0;
}



/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;

	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}

}
void initialisationVoiture(tabImagee voiture){
  int i;
	char numero[NB_ATTITUDE1];
  char nomFichier[25];
  for(i=0; i<NB_ATTITUDE1; i++){
		strcpy(nomFichier, "v");
    sprintf(numero,"%d",(i+1));
    strcat(nomFichier,numero);
    strcat(nomFichier, ".bmp");
    voiture[i]=lisBMPRGB(nomFichier);
}
}

void hitBox(float *x,float *i)
{
		if((*x)*220>906)
		{
			*x=*x-0.2;
		}
		if((*x)*220+93<63)
		{
			*x=*x+0.2;
		}
		if((*i)*220>960-108)
		{
			*i=*i-0.2;
		}
		if((*i)*220+72<960-937)
		{
			*i=*i+0.2;
		}
}
void afficheEtat(int etatTour)
{
	couleurCourante(40,40,40);
	epaisseurDeTrait(2);
	afficheChaine("ALPHA",15,18,960-75);
	couleurCourante(255,255,255);
	afficheChaine("LAPE : ",15, 235,960-75);
	afficheChaine("LIVES : ",15, 709,960-75);
}
	

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	static tabImagee voiture;

	/* On va aussi animer une balle traversant l'ecran */
	static int xBalle;
	static int yBalle;
	static int vxBalle = 7;
	static int vyBalle = -7;
	static couleur magenta;
	static float i = (960-263)/220;
	static float x = 480/220;
	static int z = 2;
	static int etatTour = 0;


	switch (evenement)
	{
		case Initialisation:
			xBalle = largeurFenetre()*valeurAleatoire();
			yBalle = hauteurFenetre()*valeurAleatoire();
			image = lisBMPRGB("Circuit.bmp");
			initialisationVoiture(voiture);

  		magenta.r = 255;
  		magenta.v = 0;
  		magenta.b = 255;
			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;

		case Temporisation:
			// On met a jour les coordonnees de la balle
			xBalle += vxBalle;
			yBalle += vyBalle;

			// On fait rebondir la balle si necessaire
			if (xBalle < 0 || xBalle >= largeurFenetre())
				vxBalle = -vxBalle;
			if (yBalle < 0 || yBalle >= hauteurFenetre())
				vyBalle = -vyBalle;
				
			hitBox(&x,&i);
			if(x*220==511 && i*220>960-322  && i*220<960-186)
			{
				etatTour=etatTour+1;
				printf("etatTour = %d\n",etatTour);
			}



			// Les coordonnees de la balle ayant eventuellement change,
			// il faut redessiner la fenetre :
			rafraichisFenetre();
			break;

		case Affichage:

		
			ecrisImage(0,0, image->largeurImage, image->hauteurImage, image->donneesRGB);
			afficheEtat(etatTour);
			ecrisImageSansFond(x*220,i*220, voiture[z]->largeurImage, voiture[z]->hauteurImage, voiture[z]->donneesRGB, magenta);







			break;

		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'p': /* Pour sortir quelque peu proprement du programme */
				case 'P':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 's':
				case 'S':
					// Configure le systeme pour ne plus generer de message Temporisation
					i=i-0.2;
					z = 4;
					lanceBoucleEvenements();

				case 'z':
				case 'Z':
						// Configure le systeme pour ne plus generer de message Temporisation
					i=i+0.2;
					z = 0;
					lanceBoucleEvenements();

					case 'q':
					case 'Q':
						// Configure le systeme pour ne plus generer de message Temporisation
						x=x-0.2;
						z = 6;
						lanceBoucleEvenements();

						case 'd':
						case 'D':
							// Configure le systeme pour ne plus generer de message Temporisation
							x=x+0.2;
							z = 2;
							lanceBoucleEvenements();


					break;
					
			}
			break;

		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				// Si le bouton gauche de la souris est appuye, faire repartir
				// la balle de la souris
				xBalle = abscisseSouris();
				yBalle = ordonneeSouris();
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;

		case Souris: // Si la souris est deplacee
			break;

		case Inactivite: // Quand aucun message n'est disponible
			break;

		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			if (xBalle >= largeurFenetre())
				xBalle = largeurFenetre()-1;
			if (yBalle >= hauteurFenetre())
				yBalle = hauteurFenetre()-1;
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

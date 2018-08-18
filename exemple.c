#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "structures.h"
#include "gereMath.h"
#include "fichier.h"
#include "affichage.h"
#include "calcul.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1080
#define HauteurFenetre 960

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


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas

//Initialisation du pictionnary
	static chaine nomFichier;
	static float time;
	static float times;
	static int incre;
	static int nbline;
	static int r,g,b;
	static int drawstate;
	static pt *T2;
	static float *TTime;
	static lgtLine Pict;
	static setP Card;
	static int ir = 0;

//Initialisation de l'association
	static int C1=0;   //Colors for buttons
	static int C2=255;
	static int C3=255;
	static int T1=255;
	static int T2a=0;
	static int T3=0;

	static int etatLvl = 1; //states for all levels
	static int pairEmain = 30; //number of pairs
	static int etatCompt = 0; // state for the count
	static float timea = 0;   //value of the time
	static int etatPair = 0;   //wich pair is chose
	static int etatClic = 0;   //O no clic 1 ever clicked
	static int etatCache = 0;  //state for hidden the crad
	static int etatPoly = 0;   //state to start the calculus of the polynome
	//static int etatTremb = 0; (not used)
	static int j = 0;  //number of point during the tracking
	static int i = 0;
	static pt *T;		//stack all the point of tracking
	static poly p;		//stack the polynome of each mouvement
	static float tremb = 0;		//score of the tremor
	static int incorect = 0;	//numbers of pairs incorrect
	static chaine nomFichierLvl1;  //files for each levels
	static chaine nomFichierLvl2;
	static chaine nomFichierLvl3;

	static chaine nomFichierTremb;  //file for the tremor
	static chaine nomT;		//name of the tremor
	//Lvl 1
	static carte A11;
	static carte A21;
	static carte B11;
	static carte B21;
	static carte C11;
	static carte C21;
	static carte D11;
	static carte D21;
	static carte E11;
	static carte E21;
	static carte F11;
	static carte F21;
	static carte G11;
	static carte G21;
	static carte H11;
	static carte H21;
	static carte I11;
	static carte I21;
	static carte J11;
	static carte J21;
	//Lvl 2
	static carte A12;
	static carte A22;
	static carte B12;
	static carte B22;
	static carte C12;
	static carte C22;
	static carte D12;
	static carte D22;
	static carte E12;
	static carte E22;
	static carte F12;
	static carte F22;
	static carte G12;
	static carte G22;
	static carte H12;
	static carte H22;
	static carte I12;
	static carte I22;
	static carte J12;
	static carte J22;
	//Lvl 3
	static carte A13;
	static carte A23;
	static carte B13;
	static carte B23;
	static carte C13;
	static carte C23;
	static carte D13;
	static carte D23;
	static carte E13;
	static carte E23;
	static carte F13;
	static carte F23;
	static carte G13;
	static carte G23;
	static carte H13;
	static carte H23;
	static carte I13;
	static carte I23;
	static carte J13;
	static carte J23;

//Initialisation du mémory
	static DonneesImageRGB *image = NULL ;
	static int increm = 0;
	//static pt point;
	static btn quit, nextTurn;
	static set game;
	static turn turn;
	static int scoreP1, scoreP2;
	static pair duo;
	static pt *T2m;
	static float temps = 0;
	static char tempus[10];
	static DonneesImageRGB *zero = NULL ;
	static DonneesImageRGB *un = NULL ;
	static DonneesImageRGB *deux = NULL ;
	static DonneesImageRGB *trois = NULL ;
	static DonneesImageRGB *quatre = NULL ;
	static DonneesImageRGB *cinq = NULL ;
	static DonneesImageRGB *six = NULL ;
	static DonneesImageRGB *sept = NULL ;
	static DonneesImageRGB *huit = NULL ;
	static DonneesImageRGB *neuf = NULL ;
	static DonneesImageRGB *mini = NULL ;
	static char pair[100];
	static float delay;
//initialisation Big Project
	static int etatmenu = 0 ;
	static btn pictionnary, association, calibrage, memory, settings, reye, leye;
	static DonneesImageRGB *menuu = NULL ;
//init du traitement d'image
	static unsigned char *GL;
	static unsigned char *GX;
	static unsigned char *GY;
	static unsigned char *GXY;
	static int matriceGrad[LarImg][HauImg];
	static int matriceRad[LarImg][HauImg][Ray];
	static int i1=0;
	static int j1=0;
	static jointure join;
	static int hj;

//init script
	static int etatcam;
	static int nb;
	static DonneesImageRGB *Vid = NULL;
	static DonneesImageRGB *VidNB = NULL;

	static FILE*Center;
	static FILE*f;

	switch (evenement)
	{
		case Initialisation:
		//init pictionnary
			incre = 0;
			strcpy(nomFichier,"Fichiers/card.txt");
			Card = readingcard(nomFichier);
			initialisationCardP(&Card);
			Pict.TL = (float *)malloc(sizeof(float)*(incre+1));
			Pict.Time = (float *)malloc(sizeof(float)*(incre+1));
		//init association
		initialiseLvl1(&A11,&A21,&B11,&B21,&C11,&C21,&D11,&D21,&E11,&E21,&F11,&F21,&G11,&G21,&H11,&H21,&I11,&I21,&J11,&J21); //initialise all cards for all levels
		initialiseLvl2(&A12,&A22,&B12,&B22,&C12,&C22,&D12,&D22,&E12,&E22,&F12,&F22,&G12,&G22,&H12,&H22,&I12,&I22,&J12,&J22);
		initialiseLvl3(&A13,&A23,&B13,&B23,&C13,&C23,&D13,&D23,&E13,&E23,&F13,&F23,&G13,&G23,&H13,&H23,&I13,&I23,&J13,&J23);

		activeGestionDeplacementPassifSouris();

		A11.img = lisBMPRGB("images/carré rouge.bmp");  //initialise all pictures for all levels
		A21.img = lisBMPRGB("images/carré bleu.bmp");
		B11.img = lisBMPRGB("images/rectangle rouge.bmp");
		B21.img = lisBMPRGB("images/rectangle bleu.bmp");
		C11.img = lisBMPRGB("images/triangle rouge.bmp");
		C21.img = lisBMPRGB("images/triangle bleu.bmp");
		D11.img = lisBMPRGB("images/rond rouge.bmp");
		D21.img = lisBMPRGB("images/rond bleu.bmp");
		E11.img = lisBMPRGB("images/flèche rouge.bmp");
		E21.img = lisBMPRGB("images/flèche bleu.bmp");
		F11.img = lisBMPRGB("images/croix bleu.bmp");
		F21.img = lisBMPRGB("images/croix rouge.bmp");
		G11.img = lisBMPRGB("images/étoile bleu.bmp");
		G21.img = lisBMPRGB("images/étoile rouge.bmp");
		H11.img = lisBMPRGB("images/coeur rouge.bmp");
		H21.img = lisBMPRGB("images/coeur bleu.bmp");
		I11.img = lisBMPRGB("images/plus bleu.bmp");
		I21.img = lisBMPRGB("images/plus rouge.bmp");
		J11.img = lisBMPRGB("images/pentagone rouge.bmp");
		J21.img = lisBMPRGB("images/pentagone bleu.bmp");

		A12.img = lisBMPRGB("images/a.bmp");
		A22.img = lisBMPRGB("images/1.bmp");
		B12.img = lisBMPRGB("images/b.bmp");
		B22.img = lisBMPRGB("images/2.bmp");
		C12.img = lisBMPRGB("images/3.bmp");
		C22.img = lisBMPRGB("images/c.bmp");
		D12.img = lisBMPRGB("images/d.bmp");
		D22.img = lisBMPRGB("images/4.bmp");
		E12.img = lisBMPRGB("images/5.bmp");
		E22.img = lisBMPRGB("images/e.bmp");
		F12.img = lisBMPRGB("images/6.bmp");
		F22.img = lisBMPRGB("images/f.bmp");
		G12.img = lisBMPRGB("images/7.bmp");
		G22.img = lisBMPRGB("images/g.bmp");
		H12.img = lisBMPRGB("images/h.bmp");
		H22.img = lisBMPRGB("images/8.bmp");
		I12.img = lisBMPRGB("images/9.bmp");
		I22.img = lisBMPRGB("images/i.bmp");
		J12.img = lisBMPRGB("images/j.bmp");
		J22.img = lisBMPRGB("images/10.bmp");

		A13.img = lisBMPRGB("images/route.bmp");
		A23.img = lisBMPRGB("images/voiture.bmp");
		B13.img = lisBMPRGB("images/abeille.bmp");
		B23.img = lisBMPRGB("images/miel.bmp");
		C13.img = lisBMPRGB("images/brosse.bmp");
		C23.img = lisBMPRGB("images/cheveux.bmp");
		D13.img = lisBMPRGB("images/clé.bmp");
		D23.img = lisBMPRGB("images/porte.bmp");
		E13.img = lisBMPRGB("images/aéroport.bmp");
		E23.img = lisBMPRGB("images/avion.bmp");
		F13.img = lisBMPRGB("images/nuages.bmp");
		F23.img = lisBMPRGB("images/pluie.bmp");
		G13.img = lisBMPRGB("images/infirmière.bmp");
		G23.img = lisBMPRGB("images/seringue.bmp");
		H13.img = lisBMPRGB("images/pinceau.bmp");
		H23.img = lisBMPRGB("images/tableau.bmp");
		I13.img = lisBMPRGB("images/bouquet.bmp");
		I23.img = lisBMPRGB("images/fleur.bmp");
		J13.img = lisBMPRGB("images/cheval.bmp");
		J23.img = lisBMPRGB("images/fer.bmp");
		sprintf(nomFichierLvl1,"Fichiers/carteLvl1.txt");
		sprintf(nomFichierLvl2,"Fichiers/carteLvl2.txt");
		sprintf(nomFichierLvl3,"Fichiers/carteLvl3.txt");
		sprintf(nomFichierTremb,"Fichiers/temor.txt");

		saveCarteLvl(&A11,&A21,&B11,&B21,&C11,&C21,&D11,&D21,&E11,&E21,&F11,&F21,&G11,&G21,&H11,&H21,&I11,&I21,&J11,&J21,nomFichierLvl1); //save cards in files
		saveCarteLvl(&A12,&A22,&B12,&B22,&C12,&C22,&D12,&D22,&E12,&E22,&F12,&F22,&G12,&G22,&H12,&H22,&I12,&I22,&J12,&J22,nomFichierLvl2);
		saveCarteLvl(&A13,&A23,&B13,&B23,&C13,&C23,&D13,&D23,&E13,&E23,&F13,&F23,&G13,&G23,&H13,&H23,&I13,&I23,&J13,&J23,nomFichierLvl3);

	//init memory
		zero = lisBMPRGB("images/deathstroke.bmp");
		un = lisBMPRGB("images/hulk.bmp");
		deux = lisBMPRGB("images/thor.bmp");
		trois = lisBMPRGB("images/iron-man.bmp");
		quatre = lisBMPRGB("images/wolverine.bmp");
		cinq = lisBMPRGB("images/deadpool.bmp");
		six = lisBMPRGB("images/magneto.bmp");
		sept = lisBMPRGB("images/batman.bmp");
		huit = lisBMPRGB("images/the-joker.bmp");
		neuf = lisBMPRGB("images/captain-america.bmp");
		mini = lisBMPRGB("images/memory-logo-mini.bmp");

		initializeTurn(&turn);
		initializeSet(&game);
		distributionCard(&game);

		// init menu
		pictionnary = initializeBtnPictionnary();
		memory = initializeBtnMemory();
		association = initializeBtnAssociation();
		settings = initializeBtnSettings();
		reye = initializeReye();
		leye = initializeLeye();
		menuu = lisBMPRGB("images/MenuBig.bmp");



		//init connexion
		etatcam = 0;
		etatTxt();

		//init files
		Center=fopen("Fichiers/EyesCenter.txt","wt");



			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;

		case Temporisation:
//when there is no game
		if(etatmenu == 0){

				etatcam = 0;
				etatTxt();







		}
//pictionnary
		if(etatmenu == 1){
			time = time+20;
			times = timeInSeconds( time);
			numbersLines(incre, &nbline );
			lengthLine(incre, &T2, &Pict);
			timeLine(&Pict, &TTime);
			selectCard(&Card);
			//connexion avec le raspi et traitement d'image
			camera(&etatcam);
			NbImg(&nb,&etatcam);
			recupImage(nb,Vid,VidNB, &etatcam, &GL, &GX ,&GY ,&GXY,matriceGrad,matriceRad,&join,Center);
			if(etatcam == 4){
				fclose(Center);
				f = fopen("Fichiers/EyesCenter.txt","rt");//fichier des barycenteres
				etatcam = 5;
			}
			gereJeuLoading(&etatcam,&hj);

			if(time >= 63000){
				ir = ir + 1;
			}

		}
//association
		if(etatmenu == 2){
			//connexion avec le raspi et traitement d'image
			camera(&etatcam);
			NbImg(&nb,&etatcam);
			recupImage(nb,Vid,VidNB, &etatcam, &GL, &GX ,&GY ,&GXY,matriceGrad,matriceRad,&join,Center);
			if(etatcam == 4){
				fclose(Center);
				f = fopen("Fichiers/EyesCenter.txt","rt");//fichier des barycenteres
				etatcam = 5;
			}
			gereJeuLoading(&etatcam,&hj);
				if(etatLvl == 1)//hidden the pairs when theire right
				{
					gereCache(etatCache,&A11,&A21,&B11,&B21,&C11,&C21,&D11,&D21,&E11,&E21,&F11,&F21,&G11,&G21,&H11,&H21,&I11,&I21,&J11,&J21);

				}
				if(etatLvl == 2)
				{
					gereCache(etatCache,&A12,&A22,&B12,&B22,&C12,&C22,&D12,&D22,&E12,&E22,&F12,&F22,&G12,&G22,&H12,&H22,&I12,&I22,&J12,&J22);

				}
				if(etatLvl == 3)
				{
					gereCache(etatCache,&A13,&A23,&B13,&B23,&C13,&C23,&D13,&D23,&E13,&E23,&F13,&F23,&G13,&G23,&H13,&H23,&I13,&I23,&J13,&J23);

				}
				if(etatCompt == 1) //timer
				{
					timea=timea+0.020;
				}
				rafraichisFenetre();
				if(etatClic == 1) //stack mouvement of the mouse
				{
					deplacementSouris(&T,j,etatClic);
					j=j+1;
					etatPoly=1;
					printf("j=%d\n",j);


				}
				if(etatClic == 0 && etatPoly == 1 && i<j)//calcul the polynome
				{
					equationPoly(&p,T,j);
					scoreTramblement(T,p,&tremb,j,i);
					i++;
					printf("i=%d\n",i);
					printf("j=%d\n",j);
					//etatPoly=0;

				}
				if(etatPoly == 1 && i==j) //free all point of the mouse
				{
					free(T);
					T=NULL;
					nomTremblement(tremb,nomT);  //name the tremor
					sauveTremb(tremb,incorect,nomT,nomFichierTremb,timea); //save tremor in a file
					j=0;  //reinitialise
					i=0;
					etatPoly=0;
					printf("etatpoly=%d\n",etatPoly);
				}

		}
//memory
		if(etatmenu == 3){
			//connexion avec le raspi et traitement d'image
			camera(&etatcam);
			NbImg(&nb,&etatcam);
			recupImage(nb,Vid,VidNB, &etatcam, &GL, &GX ,&GY ,&GXY,matriceGrad,matriceRad,&join,Center);
			if(etatcam == 4){
				fclose(Center);
				f = fopen("Fichiers/EyesCenter.txt","rt");//fichier des barycenteres
				etatcam = 5;
			}
			gereJeuLoading(&etatcam,&hj);

			temps += 1;
			increm +=1;
			sprintf(tempus, "%f", temps);

			allocationT(increm, &T2m);

			timeBetweenClicks(&temps, &turn, &delay);
			//printf("delai : %f\n", delay);

			//printf("temps : %f\n", temps);
			initializeCardsGraphic(&game);
			initializeTurnBtn(&nextTurn);
			manageSetClicked(&game);
			managePickedCards(&game, &duo);
			validationPair(&game, &duo, &turn);

			manageTurnButton(&nextTurn, &turn);
			//printf("turn : %d\n", turn.player);
			//printf("A(%d;%d) B(%d;%d)\n", nextTurn.x1, nextTurn.y1, nextTurn.x2, nextTurn.y2);
			//printf("(batman).player (%d;%d)\n", game.E.player, game.K.player);

			//calculusScore(&duo, &scoreP1, &scoreP2);
			calculusScore(&game, &scoreP1, &scoreP2, pair);
			//printf("score 1 = %d score 2 = %d\n", scoreP1, scoreP2);
			//printf("clicks %d\n", turn.clicks);

			initializeButtonQuit(&quit);
			manageClicking(&turn);

		}
//calibration
		if(etatmenu == 4){

		}

			// il faut redessiner la fenetre :
			rafraichisFenetre();
			break;

		case Affichage:


			if(etatmenu == 0){
				// On part d'un fond d'ecran blanc
				effaceFenetre (10, 10, 255);
				displayMenu(pictionnary, association, calibrage, memory, settings, quit, reye, leye);
				ecrisImage(0,0, menuu->largeurImage, menuu->hauteurImage, menuu->donneesRGB);


			}
//pictionnary
			if(etatmenu == 1){
				// On part d'un fond d'ecran blanc
					effaceFenetre (255, 255, 255);
					displayBackgroundP(times);
				displayCardsP(Card);

					if( time>=3000){
					drawingP( r, g,  b,  drawstate, incre, &T2);
				}
				if(time >= 63000){
					drawsPts(incre, &T2,ir,nb);
					system("pkill exemple");
					affichePtsEye(f);
					afficheReturnMenuEnd();
				}

			}
//assos
			if(etatmenu == 2){

				// On part d'un fond d'ecran blanc
				effaceFenetre (50, 50, 150);  //show the background
				afficheFondIMG();
				afficheFondBTN();
				afficheNiveau(C1,C2,C3,T1,T2a,T3);
				afficheBTN();
				afficheTime(timea);
				affichepairEmain(pairEmain);
				afficheIncorect(incorect);
				if(etatLvl == 1)//show all cards of each levels
				{
					afficheCartePair(A11,A21);
					afficheCartePair(B11,B21);
					afficheCartePair(C11,C21);
					afficheCartePair(D11,D21);
					afficheCartePair(E11,E21);
					afficheCartePair(F11,F21);
					afficheCartePair(G11,G21);
					afficheCartePair(H11,H21);
					afficheCartePair(I11,I21);
					afficheCartePair(J11,J21);
				}
				if(etatLvl == 2)
				{
					afficheCartePair(A12,A22);
					afficheCartePair(B12,B22);
					afficheCartePair(C12,C22);
					afficheCartePair(D12,D22);
					afficheCartePair(E12,E22);
					afficheCartePair(F12,F22);
					afficheCartePair(G12,G22);
					afficheCartePair(H12,H22);
					afficheCartePair(I12,I22);
					afficheCartePair(J12,J22);
				}
				if(etatLvl == 3)
				{
					afficheCartePair(A13,A23);
					afficheCartePair(B13,B23);
					afficheCartePair(C13,C23);
					afficheCartePair(D13,D23);
					afficheCartePair(E13,E23);
					afficheCartePair(F13,F23);
					afficheCartePair(G13,G23);
					afficheCartePair(H13,H23);
					afficheCartePair(I13,I23);
					afficheCartePair(J13,J23);
				}
				if(pairEmain == 0) //show completed and the tremor when the game is ended
				{
					etatCompt=0;
					couleurCourante(0,0,0);
					epaisseurDeTrait(3);
					afficheChaine("COMPLETE",20,largeurFenetre()/2,hauteurFenetre()/2);
					afficheChaine("TREMOR : ",20,largeurFenetre()/2,375*hauteurFenetre()/800);
					afficheChaine(nomT,20,625*largeurFenetre()/1000,375*hauteurFenetre()/800);
				}

			}
//memory
			if(etatmenu == 3){
				// On part d'un fond d'ecran blanc
				effaceFenetre (255, 255, 255);
				traceButtonQuit(quit);
				manageButtonQuit(quit, game, &T2m, increm, pair);

				couleurCourante(255, 0, 0);
				epaisseurDeTrait(5);
				displaySet(game, &turn, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf, mini);
				drawLeftPanel(&turn);
				drawNextTurnBtn(&nextTurn, &turn);
				drawScore(&scoreP1, &scoreP2, &turn);

				displayCard(&(duo.a), &turn, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
				displayCard(&(duo.b), &turn, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
				if (image != NULL) // Si l'image a pu etre lue
				{
					// On affiche l'image
					ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
				}

			}
//calibr
			if(etatmenu == 4){
				// On part d'un fond d'ecran blanc
				effaceFenetre (255, 255, 255);

			}





			break;

		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
				if(etatmenu == 0){

					termineBoucleEvenements();
				}
				if(etatmenu == 1){
					ordinateLine(&Pict);
					averageLine(&Pict);
					timeGlobal(&Pict);
					savePlayerComportement("Fichiers/GameSave.txt", &T2,incre,nbline,&Pict,Card);
					free(Card.A.name);
				 	free(Card.B.name);
				 	free(Card.C.name);
				 	free(Card.D.name);
				 	free(Card.E.name);
					free(T2);
					free(TTime);
					free(Pict.Time);
					free(Pict.TL);
					Pict.Time = NULL;
					Pict.TL = NULL;
					T2 = NULL;
					TTime = NULL;
					fclose(f);
					termineBoucleEvenements();
				}
				if(etatmenu == 2){
					termineBoucleEvenements();
				}
				if(etatmenu == 3){
					libereDonneesImageRGB(&image);
					termineBoucleEvenements();
				}
				if(etatmenu == 4){
					termineBoucleEvenements();
				}


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

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;

		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			if(etatmenu == 0){
				manageMenu(&etatmenu, pictionnary, memory, association, settings, quit);
				manageBtnQUIT(&quit);
			}
			if(etatmenu == 1){
				if(time <= 3000){
			returnCardP(&Card);
		}
				if(etatBoutonSouris() == GaucheAppuye && time>=63000 && abscisseSouris()>=(largeurFenetre()*530)/1080 && ordonneeSouris()>=(hauteurFenetre()*470)/960 && abscisseSouris()<=(largeurFenetre()*750)/1080 && ordonneeSouris()<=(hauteurFenetre()*520)/960)
				{
					ordinateLine(&Pict);
					averageLine(&Pict);
					timeGlobal(&Pict);
					savePlayerComportement("Fichiers/GameSave.txt", &T2,incre,nbline,&Pict,Card);
					free(Card.A.name);
				 	free(Card.B.name);
				 	free(Card.C.name);
				 	free(Card.D.name);
				 	free(Card.E.name);
					free(T2);
					free(TTime);
					free(Pict.Time);
					free(Pict.TL);
					Pict.Time = NULL;
					Pict.TL = NULL;
					T2 = NULL;
					TTime = NULL;
					time=0;
					etatmenu=0;
				}
				if(etatBoutonSouris() == GaucheAppuye && time>=63000 && abscisseSouris()>=(largeurFenetre()*530)/1080 && ordonneeSouris()>=(hauteurFenetre()*400)/960 && abscisseSouris()<=(largeurFenetre()*750)/1080 && ordonneeSouris()<=(hauteurFenetre()*450)/960)
				{
					ordinateLine(&Pict);
					averageLine(&Pict);
					timeGlobal(&Pict);
					savePlayerComportement("Fichiers/GameSave.txt", &T2,incre,nbline,&Pict,Card);
					free(Card.A.name);
				 	free(Card.B.name);
				 	free(Card.C.name);
				 	free(Card.D.name);
				 	free(Card.E.name);
					free(T2);
					free(TTime);
					free(Pict.Time);
					free(Pict.TL);
					Pict.Time = NULL;
					Pict.TL = NULL;
					T2 = NULL;
					TTime = NULL;
					termineBoucleEvenements();
				}

			if(time <=63000 && time>=3000){

				Card.A.state = 0;
				Card.B.state = 0;
				Card.C.state = 0;
				Card.D.state = 0;
				Card.E.state = 0;
				selectColor(&r,&g,&b);
				drawPoints(&drawstate, &incre);
				saveMouse(incre, &T2, drawstate);
				saveTime(incre, &TTime, drawstate, times);
			}

			}
			if(etatmenu == 2){
				if (etatBoutonSouris() == GaucheAppuye)
				{
					printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
					gereClicLvl(&C1,&C2,&C3,&T1,&T2a,&T3,&etatLvl,&etatCache); //clics of buttons
					gereClicLeave();
					gereCompt(&etatCompt);
					gereClicReset(&timea,&etatCompt,&etatCache,&pairEmain,&etatClic,&incorect);
					gereClicReturnMenu(&time,&etatCompt,&etatCache,&pairEmain,&etatClic,&incorect,&etatmenu);

					if(etatLvl==1)  //clics of cards
					{
						gereClicCarte(A11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(A21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J11,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J21,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
					}
					else if(etatLvl==2)
					{
						gereClicCarte(A12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(A22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J12,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J22,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
					}
					else if(etatLvl==3)
					{
						gereClicCarte(A13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(A23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(B23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(C23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(D23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(E23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(F23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(G23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(H23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(I23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J13,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
						gereClicCarte(J23,&etatPair,&etatClic,&etatCache,&pairEmain,&incorect);
					}

			}
		}
			if(etatmenu == 3){

			}
			if(etatmenu == 4){

			}

			break;

		case Souris: // Si la souris est deplacee
			break;

		case Inactivite: // Quand aucun message n'est disponible
			break;

		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe

			break;
	}
}

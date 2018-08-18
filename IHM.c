#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "structures.h"
#include "gereMath.h"

void afficheFondIMG(void) //show the background for images
{
	couleurCourante(255,255,255);
	rectangle(200*largeurFenetre()/1000,10*hauteurFenetre()/800,980*largeurFenetre()/1000,790*hauteurFenetre()/800);
}

void afficheFondBTN(void) //show the background for buttons
{
	couleurCourante(100,100,100);
	rectangle(10*largeurFenetre()/1000,10*hauteurFenetre()/800,190*largeurFenetre()/1000,790*hauteurFenetre()/800);
}

void afficheNiveau(int C1,int C2,int C3, int T1, int T2, int T3) //show the Levels selector button
{
	couleurCourante(255,255,255);
	epaisseurDeTrait(2);
	afficheChaine("LEVEL",15,65*largeurFenetre()/1000,775*hauteurFenetre()/800);
	couleurCourante(C1,C1,C1);
	rectangle(20*largeurFenetre()/1000,765*hauteurFenetre()/800,180*largeurFenetre()/1000,735*hauteurFenetre()/800);
	couleurCourante(C2,C2,C2);
	rectangle(20*largeurFenetre()/1000,725*hauteurFenetre()/800,180*largeurFenetre()/1000,695*hauteurFenetre()/800);
	couleurCourante(C3,C3,C3);
	rectangle(20*largeurFenetre()/1000,685*hauteurFenetre()/800,180*largeurFenetre()/1000,655*hauteurFenetre()/800);
	couleurCourante(T1,T1,T1);
	afficheChaine("LEVEL 1",12,35*largeurFenetre()/1000,745*hauteurFenetre()/800);
	couleurCourante(T2,T2,T2);
	afficheChaine("LEVEL 2",12,35*largeurFenetre()/1000,705*hauteurFenetre()/800);
	couleurCourante(T3,T3,T3);
	afficheChaine("LEVEL 3",12,35*largeurFenetre()/1000,665*hauteurFenetre()/800);
}

void afficheBTN(void)  //show the reset, return to menu and leave button
{
	couleurCourante(255,255,255);
	rectangle(20*largeurFenetre()/1000,20*hauteurFenetre()/800,180*largeurFenetre()/1000,50*hauteurFenetre()/800);
	rectangle(20*largeurFenetre()/1000,60*hauteurFenetre()/800,180*largeurFenetre()/1000,90*hauteurFenetre()/800);
	rectangle(20*largeurFenetre()/1000,100*hauteurFenetre()/800,180*largeurFenetre()/1000,130*hauteurFenetre()/800);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("LEAVE",12,35*largeurFenetre()/1000,30*hauteurFenetre()/800);
	afficheChaine("RETURN MENU",12,35*largeurFenetre()/1000,70*hauteurFenetre()/800);
	afficheChaine("RESET",12,35*largeurFenetre()/1000,110*hauteurFenetre()/800);


}

void afficheTime(float time) //show the time
{
	char T[20];
	sprintf(T,"%f",time);
	couleurCourante(255,255,255);
	epaisseurDeTrait(2);
	afficheChaine("TIME",15,65*largeurFenetre()/1000,625*hauteurFenetre()/800);
	afficheChaine(T,12,50*largeurFenetre()/1000,600*hauteurFenetre()/800);
}

void affichepairEmain(int pairEmain) //show pairs remainings
{
	char T[20];
	sprintf(T,"%d",pairEmain);
	couleurCourante(255,255,255);
	epaisseurDeTrait(2);
	afficheChaine("PAIRS REMAINING",15,30*largeurFenetre()/1000,550*hauteurFenetre()/800);
	afficheChaine(T,12,70*largeurFenetre()/1000,525*hauteurFenetre()/800);
}


void afficheCartePair(carte C1, carte C2) //general fonction to show two cards
{
	if (C1.img != NULL)
	{
		ecrisImage(C1.pos.x,C1.pos.y, C1.img->largeurImage, C1.img->hauteurImage, C1.img->donneesRGB);
	}if (C2.img != NULL)
	{
		ecrisImage(C2.pos.x,C2.pos.y, C2.img->largeurImage, C2.img->hauteurImage, C2.img->donneesRGB);
	}
}

void afficheIncorect(int incorect) //show the numbers of incorrect pairs
{
	char T[20];
	sprintf(T,"%d",incorect);
	couleurCourante(255,255,255);
	epaisseurDeTrait(2);
	afficheChaine("PAIRS INCORECT",15,30*largeurFenetre()/1000,475*hauteurFenetre()/800);
	afficheChaine(T,12,70*largeurFenetre()/1000,450*hauteurFenetre()/800);
}

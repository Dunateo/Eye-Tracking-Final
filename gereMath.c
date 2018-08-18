#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "structures.h"
#include "gereMath.h"


void gereClicLvl(int *C1, int *C2, int *C3, int *T1, int *T2, int *T3, int *etatLvl, int *etatCache)  //manage the clic on levels button and change the color
{
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()<=765*hauteurFenetre()/800 && abscisseSouris()<=180*largeurFenetre()/1000 && ordonneeSouris()>=735*hauteurFenetre()/800)
	{
		*C1=0;
		*C2=255;
		*C3=255;
		*T1=255;
		*T2=0;
		*T3=0;
		*etatLvl=1;
		*etatCache=0;
		printf("%d\n",*etatLvl);
	}else if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()<=725*hauteurFenetre()/800 && abscisseSouris()<=180*largeurFenetre()/1000 && ordonneeSouris()>=695*hauteurFenetre()/800)
	{
		*C1=255;
		*C2=0;
		*C3=255;
		*T1=0;
		*T2=255;
		*T3=0;
		*etatLvl=2;
		*etatCache=0;
		printf("%d\n",*etatLvl);
	}else if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()<=685*hauteurFenetre()/800 && abscisseSouris()<=180*largeurFenetre()/1000 && ordonneeSouris()>=655*hauteurFenetre()/800)
	{
		*C1=255;
		*C2=255;
		*C3=0;
		*T1=0;
		*T2=0;
		*T3=255;
		*etatLvl=3;
		*etatCache=0;
		printf("%d\n",*etatLvl);
	}
}

void gereClicLeave(void) // manage the clic to quit
{
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()>=20*hauteurFenetre()/800 && abscisseSouris()<= 180*largeurFenetre()/1000 && ordonneeSouris()<=50*hauteurFenetre()/800)
	{
		termineBoucleEvenements();
	}
}

void gereClicReset(float *time, int *etatCompt, int *etatCache, int *pairEmain, int *etatClic,int *incorect) //manage the clic to reset
{
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()>=100*hauteurFenetre()/800 && abscisseSouris()<=180*largeurFenetre()/1000 && ordonneeSouris()<=130*hauteurFenetre()/800)
	{
		*time=0;
		*etatCompt=0;
		*etatCache=0;
		*etatClic=0;
		*pairEmain=30;
		*incorect=0;
		lanceBoucleEvenements();
	}
}

void gereClicReturnMenu(float *time, int *etatCompt, int *etatCache, int *pairEmain, int *etatClic,int *incorect, int *etatmenu) //manage the clic to return menu
{
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=20*largeurFenetre()/1000 && ordonneeSouris()>=60*hauteurFenetre()/800 && abscisseSouris()<=180*largeurFenetre()/1000 && ordonneeSouris()<=90*hauteurFenetre()/800)
	{
		printf("ça clique\n");
		*time=0;
		*etatCompt=0;
		*etatCache=0;
		*etatClic=0;
		*pairEmain=30;
		*incorect=0;
		*etatmenu=0;
		lanceBoucleEvenements();
		
	}
}


void gereCompt(int *etatCompt) //when you clic on the images background the timer starts
{
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=200*largeurFenetre()/1000 && ordonneeSouris()>=10*hauteurFenetre()/800 && abscisseSouris()<=980*largeurFenetre()/1000 && ordonneeSouris()<=790*hauteurFenetre()/800)
	{
		*etatCompt=1;
	}
}

void gereClicCarte(carte c, int *etatPair, int *etatClic, int *etatCache, int *pairEmain, int *incorect)//general function to manage the clic on a card
{
	if(*etatClic == 0 && etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=c.pos.x && ordonneeSouris()>=c.pos.y && abscisseSouris()<=(c.pos.x)+100 && ordonneeSouris()<=(c.pos.y)+100)
	{
		*etatClic=1;
		*etatPair=c.num;
	}else if(*etatClic == 1 && etatBoutonSouris() == GaucheAppuye && abscisseSouris()>=c.pos.x && ordonneeSouris()>=c.pos.y && abscisseSouris()<=(c.pos.x)+100 && ordonneeSouris()<=(c.pos.y)+100)
	{
		if(*etatPair>100)
		{
			if(*etatPair == c.num+100)
			{
				*etatClic=0;
				*etatCache=c.num;
				*pairEmain=*pairEmain-1;
			}else if(*etatPair != c.num+100)
			{
				*incorect = *incorect+1;
				*etatClic=0;
			}
		}else if(*etatPair<100)
		{
			if(*etatPair == c.num-100)
			{
				*etatClic=0;
				*etatCache=c.num-100;
				*pairEmain=*pairEmain-1;
			}else if(*etatPair != c.num-100)
			{
				*incorect = *incorect+1;
				*etatClic=0;
			}
		}
	}
}

void initialiseLvl3(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2)
{
	E1->num=5;
	E1->pos.x=(200+145)*largeurFenetre()/1000;
	E1->pos.y=(20+106)*hauteurFenetre()/800;               //initialise all positions of cards for the level 3

	J1->num=10;
	J1->pos.x=(200+145+145)*largeurFenetre()/1000;
	J1->pos.y=(20+106)*hauteurFenetre()/800;

	E2->num=105;
	E2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	E2->pos.y=(20+106)*hauteurFenetre()/800;

	J2->num=110;
	J2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	J2->pos.y=(20+106)*hauteurFenetre()/800;


	I1->num=9;
	I1->pos.x=(200+145)*largeurFenetre()/1000;
	I1->pos.y=(20+106+106)*hauteurFenetre()/800;

	C1->num=3;
	C1->pos.x=(200+145+145)*largeurFenetre()/1000;
	C1->pos.y=(20+106+106)*hauteurFenetre()/800;

	D1->num=4;
	D1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	D1->pos.y=(20+106+106)*hauteurFenetre()/800;

	I2->num=109;
	I2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	I2->pos.y=(20+106+106)*hauteurFenetre()/800;


	A1->num=1;
	A1->pos.x=(200+145)*largeurFenetre()/1000;
	A1->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	F1->num=6;
	F1->pos.x=(200+145+145)*largeurFenetre()/1000;
	F1->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	C2->num=103;
	C2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	C2->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	G1->num=7;
	G1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	G1->pos.y=(20+106+106+106)*hauteurFenetre()/800;


	A2->num=101;
	A2->pos.x=(200+145)*largeurFenetre()/1000;
	A2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	D2->num=104;
	D2->pos.x=(200+145+145)*largeurFenetre()/1000;
	D2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	H1->num=8;
	H1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	H1->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	B1->num=2;
	B1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	B1->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;


	B2->num=102;
	B2->pos.x=(200+145)*largeurFenetre()/1000;
	B2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	F2->num=106;
	F2->pos.x=(200+145+145)*largeurFenetre()/1000;
	F2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	G2->num=107;
	G2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	G2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	H2->num=108;
	H2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	H2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;
}

void initialiseLvl2(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2)
{
	D1->num=4;
	D1->pos.x=(200+145)*largeurFenetre()/1000;
	D1->pos.y=(20+106)*hauteurFenetre()/800;                //initialise all positions of cards for the level 2

	C1->num=3;
	C1->pos.x=(200+145+145)*largeurFenetre()/1000;
	C1->pos.y=(20+106)*hauteurFenetre()/800;

	B1->num=2;
	B1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	B1->pos.y=(20+106)*hauteurFenetre()/800;

	A1->num=1;
	A1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	A1->pos.y=(20+106)*hauteurFenetre()/800;


	H1->num=8;
	H1->pos.x=(200+145)*largeurFenetre()/1000;
	H1->pos.y=(20+106+106)*hauteurFenetre()/800;

	G1->num=7;
	G1->pos.x=(200+145+145)*largeurFenetre()/1000;
	G1->pos.y=(20+106+106)*hauteurFenetre()/800;

	F1->num=6;
	F1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	F1->pos.y=(20+106+106)*hauteurFenetre()/800;

	E1->num=5;
	E1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	E1->pos.y=(20+106+106)*hauteurFenetre()/800;


	B2->num=102;
	B2->pos.x=(200+145)*largeurFenetre()/1000;
	B2->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	A2->num=101;
	A2->pos.x=(200+145+145)*largeurFenetre()/1000;
	A2->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	J1->num=10;
	J1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	J1->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	I1->num=9;
	I1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	I1->pos.y=(20+106+106+106)*hauteurFenetre()/800;


	F2->num=106;
	F2->pos.x=(200+145)*largeurFenetre()/1000;
	F2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	E2->num=105;
	E2->pos.x=(200+145+145)*largeurFenetre()/1000;
	E2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	D2->num=104;
	D2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	D2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	C2->num=103;
	C2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	C2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;


	J2->num=110;
	J2->pos.x=(200+145)*largeurFenetre()/1000;
	J2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	I2->num=109;
	I2->pos.x=(200+145+145)*largeurFenetre()/1000;
	I2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	H2->num=108;
	H2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	H2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	G2->num=107;
	G2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	G2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;
}

void initialiseLvl1(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2)
{
	A1->num=1;
	A1->pos.x=(200+145)*largeurFenetre()/1000;
	A1->pos.y=(20+106)*hauteurFenetre()/800;                         //initialise all positions of cards for the level 1

	B1->num=2;
	B1->pos.x=(200+145+145)*largeurFenetre()/1000;
	B1->pos.y=(20+106)*hauteurFenetre()/800;

	C1->num=3;
	C1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	C1->pos.y=(20+106)*hauteurFenetre()/800;

	D1->num=4;
	D1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	D1->pos.y=(20+106)*hauteurFenetre()/800;


	E1->num=5;
	E1->pos.x=(200+145)*largeurFenetre()/1000;
	E1->pos.y=(20+106+106)*hauteurFenetre()/800;

	F1->num=6;
	F1->pos.x=(200+145+145)*largeurFenetre()/1000;
	F1->pos.y=(20+106+106)*hauteurFenetre()/800;

	G1->num=7;
	G1->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	G1->pos.y=(20+106+106)*hauteurFenetre()/800;

	H1->num=8;
	H1->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	H1->pos.y=(20+106+106)*hauteurFenetre()/800;


	I1->num=9;
	I1->pos.x=(200+145)*largeurFenetre()/1000;
	I1->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	J1->num=10;
	J1->pos.x=(200+145+145)*largeurFenetre()/1000;
	J1->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	A2->num=101;
	A2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	A2->pos.y=(20+106+106+106)*hauteurFenetre()/800;

	B2->num=102;
	B2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	B2->pos.y=(20+106+106+106)*hauteurFenetre()/800;


	C2->num=103;
	C2->pos.x=(200+145)*largeurFenetre()/1000;
	C2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	D2->num=104;
	D2->pos.x=(200+145+145)*largeurFenetre()/1000;
	D2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	E2->num=105;
	E2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	E2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;

	F2->num=106;
	F2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	F2->pos.y=(20+106+106+106+106)*hauteurFenetre()/800;


	G2->num=107;
	G2->pos.x=(200+145)*largeurFenetre()/1000;
	G2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	H2->num=108;
	H2->pos.x=(200+145+145)*largeurFenetre()/1000;
	H2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	I2->num=109;
	I2->pos.x=(200+145+145+145)*largeurFenetre()/1000;
	I2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

	J2->num=110;
	J2->pos.x=(200+145+145+145+145)*largeurFenetre()/1000;
	J2->pos.y=(20+106+106+106+106+106)*hauteurFenetre()/800;

}

void gereCache(int etatCache, carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2)
{
	if(etatCache == A1->num)
	{                                                    //general function to manage the hidden of cards in a level
		A1->img=NULL;
		A2->img=NULL;
	}
	if(etatCache == B1->num)
	{
		B1->img=NULL;
		B2->img=NULL;
	}
	if(etatCache == C1->num)
	{
		C1->img=NULL;
		C2->img=NULL;
	}
	if(etatCache == D1->num)
	{
		D1->img=NULL;
		D2->img=NULL;
	}
	if(etatCache == E1->num)
	{
		E1->img=NULL;
		E2->img=NULL;
	}
	if(etatCache == F1->num)
	{
		F1->img=NULL;
		F2->img=NULL;
	}
	if(etatCache == G1->num)
	{
		G1->img=NULL;
		G2->img=NULL;
	}
	if(etatCache == H1->num)
	{
		H1->img=NULL;
		H2->img=NULL;
	}
	if(etatCache == I1->num)
	{
		I1->img=NULL;
		I2->img=NULL;
	}
	if(etatCache == J1->num)
	{
		J1->img=NULL;
		J2->img=NULL;
	}
}

void deplacementSouris(pt **T, int j, int etatClic)    //function for the mouse tracking
{
	  if (etatClic == 1)
	  {

			if( j == 0)
			{

				(*T) = (pt *)malloc(sizeof(pt)*(j+1));
				(*T)[j].x = abscisseSouris();
				(*T)[j].y = ordonneeSouris();

			}
			else
			{

				pt * T1;
				T1 = (pt *)realloc(*T, sizeof(pt)*(j+1));

				if(T1 != NULL)
				{
					*T = T1;
				}

			(*T)[j].x = abscisseSouris();
			(*T)[j].y = ordonneeSouris();   //erreur
			printf("x=%f et y=%f\n",(*T)[j].x,(*T)[j].y);

		}
	}

}

void equationPoly(poly *p, pt *T, int j)      //general function to calcul all polynomes (interpolation lineaire)
{
	if((T[0].x)<(T[j-1].x))
	{
		printf("x0=%f y0 =%f xj=%f yj=%f\n",T[0].x,T[0].y,T[j-1].x,T[j-1].y);
		p->a=(T[j-1].y-T[0].y)/(T[j-1].x-T[0].x);
		p->b=T[j-1].y-(p->a*T[j-1].x);
	}else if((T[0].x)>(T[j-1].x))
	{
		printf("x0=%f y0 =%f xj=%f yj=%f\n",T[0].x,T[0].y,T[j-1].x,T[j-1].y);
		p->a=(T[0].y-T[j-1].y)/(T[0].x-T[j-1].x);
		p->b=T[j-1].y-(p->a*T[j-1].x);
	}
	printf("Poly : %fx + %f = y\n",p->a,p->b);
}

void scoreTramblement(pt *T,poly p, float *tremb, int j,int i) //calcul teh score of the tremor
{
	float y;

	y=p.a*T[i].x+p.b;
	if(y>T[i].y)
	{
		*tremb=*tremb+(y-T[i].y);
	}else if(y<T[i].y)
	{
		*tremb=*tremb+(T[i].y-y);
	}


	printf("tremb=%f\n",*tremb);
}

void nomTremblement(float tremb, chaine nomT)    //name the tremor with the score
{
	if(tremb<10000)
	{
		sprintf(nomT,"No tremor");
	}else if(tremb>10000 && tremb<40000)
	{
		sprintf(nomT,"Little tremor");
	}else if(tremb>40000 && tremb<70000)
	{
		sprintf(nomT,"Middle tremor");
	}else if(tremb>70000)
	{
		sprintf(nomT,"Big tremor");
	}
	printf("Tremor : %s\n",nomT);
}

void saveCarteLvl(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2, chaine nomFichier)
{
	FILE*f;
	f=fopen(nomFichier,"wt");   //save all position of each pairs une a file
	if(f==NULL) return;
	fprintf(f,"Position pairs 1 (%f,%f)\n",A1->pos.x,A1->pos.y);
	fprintf(f,"Position pairs 1 (%f,%f)\n",A2->pos.x,A2->pos.y);
	fprintf(f,"Position pairs 2 (%f,%f)\n",B1->pos.x,B1->pos.y);
	fprintf(f,"Position pairs 2 (%f,%f)\n",B2->pos.x,B2->pos.y);
	fprintf(f,"Position pairs 3 (%f,%f)\n",C1->pos.x,C1->pos.y);
	fprintf(f,"Position pairs 3 (%f,%f)\n",C2->pos.x,C2->pos.y);
	fprintf(f,"Position pairs 4 (%f,%f)\n",D1->pos.x,D1->pos.y);
	fprintf(f,"Position pairs 4 (%f,%f)\n",D2->pos.x,D2->pos.y);
	fprintf(f,"Position pairs 5 (%f,%f)\n",E1->pos.x,E1->pos.y);
	fprintf(f,"Position pairs 5 (%f,%f)\n",E2->pos.x,E2->pos.y);
	fprintf(f,"Position pairs 6 (%f,%f)\n",F1->pos.x,F1->pos.y);
	fprintf(f,"Position pairs 6 (%f,%f)\n",F2->pos.x,F2->pos.y);
	fprintf(f,"Position pairs 7 (%f,%f)\n",G1->pos.x,G1->pos.y);
	fprintf(f,"Position pairs 7 (%f,%f)\n",G2->pos.x,G2->pos.y);
	fprintf(f,"Position pairs 8 (%f,%f)\n",H1->pos.x,H1->pos.y);
	fprintf(f,"Position pairs 8 (%f,%f)\n",H2->pos.x,H2->pos.y);
	fprintf(f,"Position pairs 9 (%f,%f)\n",I1->pos.x,I1->pos.y);
	fprintf(f,"Position pairs 9 (%f,%f)\n",I2->pos.x,I2->pos.y);
	fprintf(f,"Position pairs 10 (%f,%f)\n",J1->pos.x,J1->pos.y);
	fprintf(f,"Position pairs 10 (%f,%f)\n",J2->pos.x,J2->pos.y);
	fclose(f);

}

void sauveTremb(float tremb,int incorect, chaine nomT, chaine nomFichier,float time)
{
	FILE*f;                  //save the tremor, the tremor score and the incorrects try in a file
	f=fopen(nomFichier,"wt");
	if(f==NULL) return;
	fprintf(f,"Incorrects try : %d\n",incorect);
	printf("Tremor fichier : %s\n",nomT);
	fprintf(f,"Tremor state : %s\n",nomT);
	fprintf(f,"Tremor score : %f\n",tremb);
	fprintf(f,"Time (s) : %f\n",time);
	fclose(f);
}

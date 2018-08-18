#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BmpLib.h"
#include "GfxLib.h"
#include "structures.h"


//function to read the card
setP readingcard(chaine nomFichier){
  FILE *f;
  setP In;
  char transition[100];
  char transition2[100];
  char transition3[100];
  char transition4[100];
  char transition5[100];
	f=fopen(nomFichier,"rt");
	if(f == NULL)
		printf("fichier non ouvert les guys\n");
	printf("fichier ouvert les guys\n");

  //take the first card
	fscanf(f,"card1: %s\n",transition);
  In.A.count = strlen(transition);
  In.A.name = (char *)malloc(sizeof(char)*(In.A.count));
  if( In.A.name != NULL){
   strcpy(In.A.name,transition);

   In.A.player = 1;
 }
 else{
   In.A.name = NULL;
   In.A.player = 0;
 }

  printf("%s\n", In.A.name );

  //take the second card
	fscanf(f,"card2: %s\n",transition2);
  In.B.count = strlen(transition2);
  In.B.name = (char *)malloc(sizeof(char)*(In.B.count));
  if( In.B.name != NULL){

   strcpy(In.B.name,transition2);
   In.B.player = 1;
 }

  printf("%s\n", In.B.name );

  //card3
  fscanf(f,"card3: %s\n",transition3);
  In.C.count = strlen(transition3);
  In.C.name = (char *)malloc(sizeof(char)*(In.C.count));
  if( In.C.name != NULL){

   strcpy(In.C.name,transition3);
   In.C.player = 1;
 }
 printf("%s\n", In.C.name );

 //card4
	fscanf(f,"card4: %s\n",transition4);
  In.D.count = strlen(transition4);
  In.D.name = (char *)malloc(sizeof(char)*(In.D.count));
  if( In.D.name != NULL){
   strcpy(In.D.name,transition4);
   In.D.player = 1;
 }
 printf("%s\n", In.D.name );

 //card5
  fscanf(f,"card5: %s\n",transition5);
  In.E.count= strlen(transition5);
  In.E.name = (char *)malloc(sizeof(char)*(In.E.count));
  if( In.E.name != NULL){
   strcpy(In.E.name,transition5);
   In.E.player = 1;
 }
 else{
   In.E.name = NULL;
   In.E.player = 0;
 }
 printf("%s\n", In.E.name );


	fclose(f);

  return In;

}

//save all the player comportements in a texte file
void savePlayerComportement(chaine nomFichier, pt **T2,int incre,int nbline, lgtLine *Pict, setP Card){
    FILE *f;
  	f=fopen(nomFichier,"wt");
  	if(f == NULL)
  		return;
    fprintf(f, "Player saveGame:\n");
    fprintf(f, "\nThe words were:\n\n" );
    fprintf(f, "-%s\n",Card.A.name );
    fprintf(f, "-%s\n",Card.B.name );
    fprintf(f, "-%s\n",Card.C.name );
    fprintf(f, "-%s\n",Card.D.name );
    fprintf(f, "-%s\n",Card.E.name );
    //choosen card
    if(Card.chs == 1){
      fprintf(f, "\nHe choose: %s\n", Card.A.name);
    }
    if(Card.chs == 2){
      fprintf(f, "\nHe choose: %s\n", Card.B.name);
    }
    if(Card.chs == 3){
      fprintf(f, "\nHe choose: %s\n", Card.C.name);
    }
    if(Card.chs == 4){
      fprintf(f, "\nHe choose: %s\n", Card.D.name);
    }
    if(Card.chs == 5){
      fprintf(f, "\nHe choose: %s\n", Card.E.name);
    }



    fprintf(f, "\nHere we have the draw trajectory:\n");

  for (int i = 0; i < incre; i++) {

    fprintf(f, "point[%d]:(%.2f;%.2f)\n", i,(*T2)[i].x,(*T2)[i].y );

  }
  fprintf(f, "\nWe have %d lines:\n\n",nbline);
  fprintf(f, "length of each line:\n");

  for(int j = 0; j<Pict->nb-1; j++){

    fprintf(f, "line[%d]:(%.2f)px in (%.2f)s\n", j+1,Pict->TL[j],Pict->Time[j] );
  }

  fprintf(f, "\n And the average of all the lines is %.2f px\n", Pict->moy );
  fprintf(f, "\n And the minimum of all the lines is %.2f px\n", Pict->min );
  fprintf(f, "\n And the maximum of all the lines is %.2f px\n", Pict->max );
  fprintf(f, "\n And the time to draw  all the lines is %.2f s\n", Pict->glob );

  fclose(f);

}

//initialisation of the position for each card and their numbers
void initialisationCardP(setP *Card){

if(Card->A.player == 1){
  Card->A.id = 1;
  Card->A.state = 0;
  Card->A.x1 =largeurFenetre()/12;
  Card->A.y1 =31*hauteurFenetre()/37;
}
if(Card->B.player == 1){
  Card->B.id = 2;
  Card->B.state = 0;
  Card->B.x1 =largeurFenetre()/12;
  Card->B.y1 =27*hauteurFenetre()/37;
}
if(Card->C.player == 1){
  Card->C.id = 3;
  Card->C.state = 0;
  Card->C.x1 =largeurFenetre()/12;
  Card->C.y1 =23*hauteurFenetre()/37;
}
if(Card->D.player == 1){
  Card->D.id = 4;
  Card->D.state = 0;
  Card->D.x1 =largeurFenetre()/12;
  Card->D.y1 =19*hauteurFenetre()/37;

}
if(Card->E.player == 1){
  Card->E.id = 5;
  Card->E.state = 0;
  Card->E.x1 =largeurFenetre()/12;
  Card->E.y1 =15*hauteurFenetre()/37;

}

}
//return int card
void selectCard(setP *Card){

  if(Card->A.state == 1 && Card->B.state == 0 && Card->C.state == 0 && Card->D.state == 0 && Card->E.state == 0){

    Card->chs = 1;

  }


  if(Card->A.state == 0 && Card->B.state == 1 && Card->C.state == 0 && Card->D.state == 0 && Card->E.state == 0){


  Card->chs = 2;
}

  if(Card->A.state == 0 && Card->B.state == 0 && Card->C.state == 1 && Card->D.state == 0 && Card->E.state == 0){

    Card->chs = 3;
}



  if(Card->A.state == 0 && Card->B.state == 0 && Card->C.state == 0 && Card->D.state == 1 && Card->E.state == 0){

  Card->chs = 4;
}



  if(Card->A.state == 0 && Card->B.state == 0 && Card->C.state == 0 && Card->D.state == 0 && Card->E.state == 1){

  Card->chs = 5;
}
}

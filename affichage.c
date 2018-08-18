#include <stdlib.h>
#include <stdio.h>
#include "GfxLib.h"
#include "BmpLib.h"
#include "structures.h"
#include "affichage.h"

void displayBackgroundP(float times){

  char cardtxt[15] = "Select a card:";
  char draw[11] = "Draw here:";
  char time[6] = "Time:";
  char count[5];
  char Ttime[6] = "63.00";
  char palette[12] = "Draw Color:";

  //display the background in the left high corner
  couleurCourante(67, 53, 52);
  rectangle(0,1*hauteurFenetre()/3,1*largeurFenetre()/3,3*hauteurFenetre()/3);

  //separatory
  couleurCourante(102,102,102);
  rectangle(0,2*hauteurFenetre()/7,1*largeurFenetre()/3,3*hauteurFenetre()/7);

  //display the background in the left bottom corner
  couleurCourante(179,179,179);
  rectangle(0,0,1*largeurFenetre()/3,1*hauteurFenetre()/3);

  //display the 5 cards emplacements
  couleurCourante(0,255,255);
  rectangle(0,15*hauteurFenetre()/18,1*largeurFenetre()/3,16*hauteurFenetre()/18);
  couleurCourante(255,0,0);
  rectangle(0,13*hauteurFenetre()/18,1*largeurFenetre()/3,14*hauteurFenetre()/18);
  couleurCourante(255,215,0);
  rectangle(0,11*hauteurFenetre()/18,1*largeurFenetre()/3,12*hauteurFenetre()/18);
  couleurCourante(154,205,50);
  rectangle(0,9*hauteurFenetre()/18,1*largeurFenetre()/3,10*hauteurFenetre()/18);
  couleurCourante(148,0,211);
  rectangle(0,7*hauteurFenetre()/18,1*largeurFenetre()/3,8*hauteurFenetre()/18);

  //display the text in left high corner
  couleurCourante(255,255,255);
  epaisseurDeTrait(2);
  afficheChaine(cardtxt, 30,(1/2)*largeurFenetre()/3 ,17*hauteurFenetre()/18);

  //display the text in right high corner
  couleurCourante(0,0,0);
  epaisseurDeTrait(2);
  afficheChaine(draw, 30,2*largeurFenetre()/3 ,17*hauteurFenetre()/18);

  //display time
  couleurCourante(255,255,255);
  epaisseurDeTrait(2);
  afficheChaine(time, 20, largeurFenetre()/12,2*hauteurFenetre()/7);
  if(times <= 63.00){
    sprintf(count, "%.2f", times);
    epaisseurDeTrait(2);
    afficheChaine(count, 20, 2*largeurFenetre()/12,2*hauteurFenetre()/7);
  }
  else{
    epaisseurDeTrait(2);
    afficheChaine(Ttime, 20, 2*largeurFenetre()/12,2*hauteurFenetre()/7);

  }


  //display color
  couleurCourante(255,0,0);//red
  rectangle(0,0,1*largeurFenetre()/6,1*hauteurFenetre()/18);
  couleurCourante(139,58,98);//black
  rectangle(0,1*hauteurFenetre()/18,1*largeurFenetre()/6,2*hauteurFenetre()/18);
  couleurCourante(0,0,0);//hot pink
  rectangle(0,2*hauteurFenetre()/18,1*largeurFenetre()/6,3*hauteurFenetre()/18);
  couleurCourante(0,0,255);//blue
  rectangle(1*largeurFenetre()/6,0,2*largeurFenetre()/6,1*hauteurFenetre()/18);
  couleurCourante(102,205,0);//green
  rectangle(1*largeurFenetre()/6,1*hauteurFenetre()/18,2*largeurFenetre()/6,2*hauteurFenetre()/18);
  couleurCourante(238,238,0);//yellow
  rectangle(1*largeurFenetre()/6,2*hauteurFenetre()/18,2*largeurFenetre()/6,3*hauteurFenetre()/18);

  //separatory 2
  couleurCourante(102,102,102);
  rectangle(0,3*hauteurFenetre()/18,2*largeurFenetre()/6,4*hauteurFenetre()/18);

  //display the text in the low corner
  couleurCourante(255,255,255);
  epaisseurDeTrait(2);
  afficheChaine(palette, 25,1*largeurFenetre()/12 ,3*hauteurFenetre()/18);
}

void displayCardsP(setP Card){
  char rt[16] = "Return the card";
  //char *b = (char *)malloc(sizeof(char)*A->count);
  //b = "Mint";

  //display the text for card1
  if(Card.A.state == 1 && Card.B.state == 0 && Card.C.state == 0 && Card.D.state == 0 && Card.E.state == 0){

    couleurCourante(255,255,255);
    afficheChaine(Card.A.name, 20,largeurFenetre()/12,31*hauteurFenetre()/37);
    Card.chs = 1;

  }
  else{
    couleurCourante(255,255,255);
    epaisseurDeTrait(2);
    afficheChaine(rt, 20,largeurFenetre()/12,31*hauteurFenetre()/37);
  }

  //display the text for card2
  if(Card.A.state == 0 && Card.B.state == 1 && Card.C.state == 0 && Card.D.state == 0 && Card.E.state == 0){

  couleurCourante(255,255,255);
  afficheChaine(Card.B.name, 30,largeurFenetre()/12,27*hauteurFenetre()/37);
  Card.chs = 2;
}
  else{
  couleurCourante(255,255,255);
  epaisseurDeTrait(2);
  afficheChaine(rt, 20,largeurFenetre()/12,27*hauteurFenetre()/37);
}

  //display the text for card3
  if(Card.A.state == 0 && Card.B.state == 0 && Card.C.state == 1 && Card.D.state == 0 && Card.E.state == 0){
    couleurCourante(255,255,255);
    afficheChaine(Card.C.name, 30,largeurFenetre()/12,23*hauteurFenetre()/37);
    Card.chs = 3;
}
  else{
  couleurCourante(255,255,255);
  epaisseurDeTrait(2);
  afficheChaine(rt, 20,largeurFenetre()/12,23*hauteurFenetre()/37);
}

  //display the text for card4
  if(Card.A.state == 0 && Card.B.state == 0 && Card.C.state == 0 && Card.D.state == 1 && Card.E.state == 0){
  couleurCourante(255,255,255);
  afficheChaine(Card.D.name, 30,largeurFenetre()/12,19*hauteurFenetre()/37);
  Card.chs = 4;
}
  else{
    couleurCourante(255,255,255);
    epaisseurDeTrait(2);
    afficheChaine(rt, 20,largeurFenetre()/12,19*hauteurFenetre()/37);
}

  //display the text for card5
  if(Card.A.state == 0 && Card.B.state == 0 && Card.C.state == 0 && Card.D.state == 0 && Card.E.state == 1){
  couleurCourante(255,255,255);
  afficheChaine(Card.E.name, 30,largeurFenetre()/12,15*hauteurFenetre()/37);
  Card.chs = 5;
}
  else{
    couleurCourante(255,255,255);
    epaisseurDeTrait(2);
    afficheChaine(rt, 20,largeurFenetre()/12,15*hauteurFenetre()/37);
}
}

//draw the drawPoints
void drawingP(int r,int g, int b, int drawstate, int incre, pt **T2) {



      for (int i = 1; i < incre; i++) {
        couleurCourante(r,g,b);
        epaisseurDeTrait(5);
        ligne((*T2)[i].x,(*T2)[i].y,(*T2)[i+1].x,(*T2)[i+1].y );

      }



}
void drawsPts(int incre, pt **T2, int ir, int nb){


  char g[14] = "It's Finish !";
  char q[17] = "Press q to quit!";

//display game
  couleurCourante(168,128,242);
  epaisseurDeTrait(2);
  afficheChaine(g, 40,4*largeurFenetre()/6,31*hauteurFenetre()/37);
  afficheChaine(q, 40,4*largeurFenetre()/6,29*hauteurFenetre()/37);

//display points trajectory
  for (int i = 0; i < incre; i++) {
    couleurCourante(168,128,242);
    epaisseurDeTrait(10);
    point((*T2)[i].x,(*T2)[i].y );

  }

  //replay the trajectory
  if(ir < incre){
    couleurCourante(158,85,85);
    epaisseurDeTrait(8);
    ligne((*T2)[ir].x,(*T2)[ir].y,(*T2)[ir+1].x,(*T2)[ir+1].y );

  }




}

void affichePtsEye(FILE *f){
  pt Eye1, Eye2;

  fscanf(f,"eye1(%f,%f) eye2(%f,%f)\n",&(Eye1.x),&(Eye1.y),&(Eye2.x),&(Eye2.y) );
    couleurCourante(250,0,0);
    epaisseurDeTrait(20);
    point(Eye1.x,Eye1.y);
    point(Eye2.x,Eye2.y);
    //in
    couleurCourante(0,0,0);
    epaisseurDeTrait(10);
    point(Eye1.x,Eye1.y);
    point(Eye2.x,Eye2.y);

}

void afficheReturnMenuEnd()
{
	couleurCourante(67,53,52);
	rectangle((largeurFenetre()*530)/1080,(hauteurFenetre()*470)/960,(largeurFenetre()*750)/1080,(hauteurFenetre()*520)/960);
	rectangle((largeurFenetre()*530)/1080,(hauteurFenetre()*400)/960,(largeurFenetre()*750)/1080,(hauteurFenetre()*450)/960);
	couleurCourante(255,255,255);
	epaisseurDeTrait(3);
	afficheChaine("MENU",15,(largeurFenetre()*620)/1080,(hauteurFenetre()*490)/960);
	afficheChaine("QUIT",15,(largeurFenetre()*620)/1080,(hauteurFenetre()*420)/960);
}

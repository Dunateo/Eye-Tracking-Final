#include <stdlib.h>
#include <stdio.h>
#include "GfxLib.h"
#include "BmpLib.h"
#include "structures.h"


//return the card
void returnCardP(setP *Card){
  if (etatBoutonSouris() == GaucheAppuye){
    //check box card1
    if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/3 && ordonneeSouris()>=15*hauteurFenetre()/18 && ordonneeSouris()<=16*hauteurFenetre()/18){
      Card->A.state = 1;

  }
    else{
      Card->A.state = 0;
  }
  //check box card2
  if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/3 && ordonneeSouris()>=13*hauteurFenetre()/18 && ordonneeSouris()<=14*hauteurFenetre()/18){
    Card->B.state = 1;

}
  else{
    Card->B.state = 0;
}
//check box card3
  if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/3 && ordonneeSouris()>=11*hauteurFenetre()/18 && ordonneeSouris()<=12*hauteurFenetre()/18){
    Card->C.state = 1;

}
  else{
    Card->C.state = 0;
}
  //check box card4
  if(abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/3 && ordonneeSouris()>=9*hauteurFenetre()/18 && ordonneeSouris()<=10*hauteurFenetre()/18){
    Card->D.state = 1;

}
  else{
    Card->D.state = 0;
}
  //check box card5
  if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/3 && ordonneeSouris()>=7*hauteurFenetre()/18 && ordonneeSouris()<= 8*hauteurFenetre()/18){
    Card->E.state = 1;

}
  else{
    Card->E.state = 0;
}

}
}


//give a number for r,g,b
void selectColor(int *r,int *g,int *b){
  if (etatBoutonSouris() == GaucheAppuye){

    if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/6 && ordonneeSouris()>=0 && ordonneeSouris()<=1*hauteurFenetre()/18){
      *r = 255;
      *g = 0;
      *b = 0;

  }
  if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/6 && ordonneeSouris()>=1*hauteurFenetre()/18 && ordonneeSouris()<=2*hauteurFenetre()/18){
    *r = 139;
    *g = 58;
    *b = 98;

  }
  if( abscisseSouris()>=0 && abscisseSouris()<=1*largeurFenetre()/6 && ordonneeSouris()>=2*hauteurFenetre()/18 && ordonneeSouris()<=3*hauteurFenetre()/18){
    *r = 0;
    *g = 0;
    *b = 0;

}
if( abscisseSouris()>=1*largeurFenetre()/6 && abscisseSouris()<=2*largeurFenetre()/6 && ordonneeSouris()>=0 && ordonneeSouris()<=1*hauteurFenetre()/18){
  *r = 0;
  *g = 0;
  *b = 255;

}
if( abscisseSouris()>=1*largeurFenetre()/6 && abscisseSouris()<=2*largeurFenetre()/6 && ordonneeSouris()>=1*hauteurFenetre()/18 && ordonneeSouris()<=2*hauteurFenetre()/18){
  *r = 102;
  *g = 205;
  *b = 0;

}
if( abscisseSouris()>=1*largeurFenetre()/6 && abscisseSouris()<=2*largeurFenetre()/6 && ordonneeSouris()>=2*hauteurFenetre()/18 && ordonneeSouris()<=3*hauteurFenetre()/18){
  *r = 238;
  *g = 238;
  *b = 0;

}

  }

}

//drawing state
void drawPoints(int *drawstate, int *incre){
  if (etatBoutonSouris() == GaucheAppuye){


    if( abscisseSouris()>=1*largeurFenetre()/3 && abscisseSouris()<=3*largeurFenetre()/3 && ordonneeSouris()>=0 && ordonneeSouris()<=3*hauteurFenetre()/3){

      *drawstate = 1;
      *incre = *incre +1;

    }
    else{
      *drawstate = 0;
    }

  }

}


//save all the points of the draw
void saveMouse(int incre, pt **T2, int drawstate){


  if (etatBoutonSouris() == GaucheAppuye && drawstate == 1){

  if( incre == 0){

    (*T2) = (pt *)malloc(sizeof(pt)*(incre+1));
    (*T2)[incre].x = abscisseSouris();
    (*T2)[incre].y = ordonneeSouris();
    //if there is no pt in T2 we init it
  }
  else{

    pt * T1;
    T1 = (pt *)realloc(*T2, sizeof(pt)*(incre+1));

    if(T1 != NULL){
      *T2 = T1;
    }

    (*T2)[incre].x = abscisseSouris();
    (*T2)[incre].y = ordonneeSouris();

  }
}
}

//save the time for each points
void saveTime(int incre, float **T2, int drawstate, float times){

  if (etatBoutonSouris() == GaucheAppuye && drawstate == 1){

  if( incre == 0){

    (*T2) = (float *)malloc(sizeof(float)*(incre+1));
    (*T2)[incre] = times;
    //if there is no pt in T2 we init it
  }
  else{

    float * T1;
    T1 = (float *)realloc(*T2, sizeof(float)*(incre+1));

    if(T1 != NULL){
      *T2 = T1;

    }

    (*T2)[incre] = times;

  }
}
}

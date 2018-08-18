#include <stdlib.h>
#include <stdio.h>
#include "BmpLib.h"
#include "GfxLib.h"
#include "structures.h"
#include <string.h>

void printCoordinates(pt a){
  activeGestionDeplacementPassifSouris();
  demandeTemporisation(20);
  printf("pt(%f;%f)\n", a.x, a.y);
  epaisseurDeTrait(30);
  couleurCourante(255, 255, 0);
  point(a.x, a.y);
}

void allocationT(int incre, pt **T2){
  activeGestionDeplacementPassifSouris();

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


void printCard(card x){
  printf("Card #%d : (%d;%d)(%d;%d)\tstate = %d\tcount = %d\tplayer = %d\n", x.id, x.x1, x.y1, x.x2, x.y2, x.state, x.count, x.player);
  return;
}


///*
void sauveTab(chaine test, pt TabCoordinates[], int nbpt){
  FILE*f;
  int i;
  f=fopen(test, "wt");
  if (test == NULL) return;
  for (i = 0; i < nbpt; i++) {
    fprintf(f, "(%f;%f)\n", TabCoordinates[i].x, TabCoordinates[i].y);
  }
  fclose(f);
  return;
}

void chargeTab(chaine test, pt TabCoordinates[], int nbpt){
  FILE*f;
  int i;
  f=fopen(test, "rt");
  if (f == NULL) return;
  for (i = 0; i < nbpt; i++) {
    fscanf(f, "(%f;%f)\n", &(TabCoordinates[i]).x, &(TabCoordinates[i]).y);
  }
  fclose(f);
  return;
}

void manageClicking(turn *t){
  if (etatBoutonSouris() == GaucheAppuye) {
    t->clicks +=1;
  }
}

void manageTurnButton(btn *s, turn *t){
  if (etatBoutonSouris() == GaucheAppuye && t->player == 1 && abscisseSouris() >= s->x1 && abscisseSouris() <= s->x2 && ordonneeSouris() >= s->y1 && ordonneeSouris() <= s->y2) {
    t->player =2;
  }
  else if (etatBoutonSouris() == GaucheAppuye && t->player == 2 && abscisseSouris() >= s->x1 && abscisseSouris() <= s->x2 && ordonneeSouris() >= s->y1 && ordonneeSouris() <= s->y2) {
    t->player =1;
  }
}

void distributionCard(set *g){
  //1st row
  g->A.img = 2;
  g->B.img = 4;
  g->C.img = 0;
  g->D.img = 8;
  g->E.img = 7;

  //2nd row
  g->F.img = 1;
  g->G.img = 6;
  g->H.img = 3;
  g->I.img = 9;
  g->J.img = 9;

  //3rd row
  g->K.img = 7;
  g->L.img = 4;
  g->M.img = 2;
  g->N.img = 1;
  g->O.img = 5;

  //4th row
  g->P.img = 6;
  g->Q.img = 0;
  g->R.img = 3;
  g->S.img = 5;
  g->T.img = 8;
}

void managePickedCards(set *g, pair *duo){

  duo->a.id =-1;
  duo->b.id =-1;


  /*------------------
  -------1st row------
  ------------------*/
  if (g->A.state == 1 && duo->a.id == -1 && g->A.player == 0) {
    duo->a = g->A;
  }else if (g->A.state == 1 && duo->a.id != -1 && g->A.player == 0) {
    duo->b = g->A;
  }

  if (g->B.state == 1 && duo->a.id == -1 && g->B.player == 0) {
    duo->a = g->B;
  }else if (g->B.state == 1 && duo->a.id != -1 && g->B.player == 0) {
    duo->b = g->B;
  }

  if (g->C.state == 1 && duo->a.id == -1 && g->C.player == 0) {
    duo->a = g->C;
  }else if (g->C.state == 1 && duo->a.id != -1 && g->C.player == 0) {
    duo->b = g->C;
  }

  if (g->D.state == 1 && duo->a.id == -1 && g->D.player == 0) {
    duo->a = g->D;
  }else if (g->D.state == 1 && duo->a.id != -1 && g->D.player == 0) {
    duo->b = g->D;
  }

  if (g->E.state == 1 && duo->a.id == -1 && g->E.player == 0) {
    duo->a = g->E;
  }else if (g->E.state == 1 && duo->a.id != -1 && g->E.player == 0) {
    duo->b = g->E;
  }


  /*------------------
  -------2nd row------
  ------------------*/
  if (g->F.state == 1 && duo->a.id == -1 && g->F.player == 0) {
    duo->a = g->F;
  }else if (g->F.state == 1 && duo->a.id != -1 && g->F.player == 0) {
    duo->b = g->F;
  }
  if (g->G.state == 1 && duo->a.id == -1 && g->G.player == 0) {
    duo->a = g->G;
  }else if (g->G.state == 1 && duo->a.id != -1 && g->G.player == 0) {
    duo->b = g->G;
  }

  if (g->H.state == 1 && duo->a.id == -1 && g->H.player == 0) {
    duo->a = g->H;
  }else if (g->H.state == 1 && duo->a.id != -1 && g->H.player == 0) {
    duo->b = g->H;
  }

  if (g->I.state == 1 && duo->a.id == -1 && g->I.player == 0) {
    duo->a = g->I;
  }else if (g->I.state == 1 && duo->a.id != -1 && g->I.player == 0) {
    duo->b = g->I;
  }

  if (g->J.state == 1 && duo->a.id == -1 && g->J.player == 0) {
    duo->a = g->J;
  }else if (g->J.state == 1 && duo->a.id != -1 && g->J.player == 0) {
    duo->b = g->J;
  }


  /*------------------
  -------3rd row------
  ------------------*/
  if (g->K.state == 1 && duo->a.id == -1 && g->K.player == 0) {
    duo->a = g->K;
  }else if (g->K.state == 1 && duo->a.id != -1 && g->K.player == 0) {
    duo->b = g->K;
  }

  if (g->L.state == 1 && duo->a.id == -1 && g->L.player == 0) {
    duo->a = g->L;
  }else if (g->L.state == 1 && duo->a.id != -1 && g->L.player == 0) {
    duo->b = g->L;
  }

  if (g->M.state == 1 && duo->a.id == -1 && g->M.player == 0) {
    duo->a = g->M;
  }else if (g->M.state == 1 && duo->a.id != -1 && g->M.player == 0) {
    duo->b = g->M;
  }

  if (g->N.state == 1 && duo->a.id == -1 && g->N.player == 0) {
    duo->a = g->N;
  }else if (g->N.state == 1 && duo->a.id != -1 && g->N.player == 0) {
    duo->b = g->N;
  }

  if (g->O.state == 1 && duo->a.id == -1 && g->O.player == 0) {
    duo->a = g->O;
  }else if (g->O.state == 1 && duo->a.id != -1 && g->O.player == 0) {
    duo->b = g->O;
  }


  /*------------------
  -------4th row------
  ------------------*/
  if (g->P.state == 1 && duo->a.id == -1 && g->P.player == 0) {
    duo->a = g->P;
  }else if (g->P.state == 1 && duo->a.id != -1 && g->P.player == 0) {
    duo->b = g->P;
  }

  if (g->Q.state == 1 && duo->a.id == -1 && g->Q.player == 0) {
    duo->a = g->Q;
  }else if (g->Q.state == 1 && duo->a.id != -1 && g->Q.player == 0) {
    duo->b = g->Q;
  }

  if (g->R.state == 1 && duo->a.id == -1 && g->R.player == 0) {
    duo->a = g->R;
  }else if (g->R.state == 1 && duo->a.id != -1 && g->R.player == 0) {
    duo->b = g->R;
  }

  if (g->S.state == 1 && duo->a.id == -1 && g->S.player == 0) {
    duo->a = g->S;
  }else if (g->S.state == 1 && duo->a.id != -1 && g->S.player == 0) {
    duo->b = g->S;
  }

  if (g->T.state == 1 && duo->a.id == -1 && g->T.player == 0) {
    duo->a = g->T;
  }else if (g->T.state == 1 && duo->a.id != -1 && g->T.player == 0) {
    duo->b = g->T;
  }

  printf("pair selected : (%d;%d)\n", duo->a.id, duo->b.id);
}

void validationPair(set *g, pair *duo, turn *t){

  //si le joueur 1 a une bonne paire
  if (duo->a.img == duo->b.img && t->player == 1) {

    //1st row
    if (duo->a.id == g->A.id) {
      g->A.player = 1;
    }
    if (duo->a.id == g->B.id) {
      g->B.player = 1;
    }
    if (duo->a.id == g->C.id) {
      g->C.player = 1;
    }
    if (duo->a.id == g->D.id) {
      g->D.player = 1;
    }
    if (duo->a.id == g->E.id) {
      g->E.player = 1;
    }

    //2nd row

    if (duo->a.id == g->F.id) {
      g->F.player = 1;
    }
    if (duo->a.id == g->G.id) {
      g->G.player = 1;
    }
    if (duo->a.id == g->H.id) {
      g->H.player = 1;
    }
    if (duo->a.id == g->I.id) {
      g->I.player = 1;
    }
    if (duo->a.id == g->J.id) {
      g->J.player = 1;
    }

    //3rd row
    if (duo->a.id == g->K.id) {
      g->K.player = 1;
    }
    if (duo->a.id == g->L.id) {
      g->L.player = 1;
    }
    if (duo->a.id == g->M.id) {
      g->M.player = 1;
    }
    if (duo->a.id == g->N.id) {
      g->N.player = 1;
    }
    if (duo->a.id == g->O.id) {
      g->O.player = 1;
    }

    //4th row
    if (duo->a.id == g->P.id) {
      g->P.player = 1;
    }
    if (duo->a.id == g->Q.id) {
      g->Q.player = 1;
    }
    if (duo->a.id == g->R.id) {
      g->R.player = 1;
    }
    if (duo->a.id == g->S.id) {
      g->S.player = 1;
    }
    if (duo->a.id == g->T.id) {
      g->T.player = 1;
    }
  }

  //si le joueur 2 a une bonne paire
  if (duo->a.img == duo->b.img && t->player == 2) {

    //1st row
    if (duo->a.id == g->A.id) {
      g->A.player = 2;
    }
    if (duo->a.id == g->B.id) {
      g->B.player = 2;
    }
    if (duo->a.id == g->C.id) {
      g->C.player = 2;
    }
    if (duo->a.id == g->D.id) {
      g->D.player = 2;
    }
    if (duo->a.id == g->E.id) {
      g->E.player = 2;
    }

    //2nd row

    if (duo->a.id == g->F.id) {
      g->F.player = 2;
    }
    if (duo->a.id == g->G.id) {
      g->G.player = 2;
    }
    if (duo->a.id == g->H.id) {
      g->H.player = 2;
    }
    if (duo->a.id == g->I.id) {
      g->I.player = 2;
    }
    if (duo->a.id == g->J.id) {
      g->J.player = 2;
    }

    //3rd row
    if (duo->a.id == g->K.id) {
      g->K.player = 2;
    }
    if (duo->a.id == g->L.id) {
      g->L.player = 2;
    }
    if (duo->a.id == g->M.id) {
      g->M.player = 2;
    }
    if (duo->a.id == g->N.id) {
      g->N.player = 2;
    }
    if (duo->a.id == g->O.id) {
      g->O.player = 2;
    }

    //4th row
    if (duo->a.id == g->P.id) {
      g->P.player = 2;
    }
    if (duo->a.id == g->Q.id) {
      g->Q.player = 2;
    }
    if (duo->a.id == g->R.id) {
      g->R.player = 2;
    }
    if (duo->a.id == g->S.id) {
      g->S.player = 2;
    }
    if (duo->a.id == g->T.id) {
      g->T.player = 2;
    }
  }
}



void saveSet(chaine save, set g){
  FILE*f;
  f=fopen(save, "wt");
  if (save == NULL)
  return;
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.A.id, g.A.img, g.A.x1, g.A.y1, g.A.x2, g.A.y2, g.A.state, g.A.count, g.A.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.B.id, g.B.img, g.B.x1, g.B.y1, g.B.x2, g.B.y2, g.B.state, g.B.count, g.B.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.C.id, g.C.img, g.C.x1, g.C.y1, g.C.x2, g.C.y2, g.C.state, g.C.count, g.C.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.D.id, g.D.img, g.D.x1, g.D.y1, g.D.x2, g.D.y2, g.D.state, g.D.count, g.D.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.E.id, g.E.img, g.E.x1, g.E.y1, g.E.x2, g.E.y2, g.E.state, g.E.count, g.E.player);

  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.F.id, g.F.img, g.F.x1, g.F.y1, g.F.x2, g.F.y2, g.F.state, g.F.count, g.F.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.G.id, g.G.img, g.G.x1, g.G.y1, g.G.x2, g.G.y2, g.G.state, g.G.count, g.G.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.H.id, g.H.img, g.H.x1, g.H.y1, g.H.x2, g.H.y2, g.H.state, g.H.count, g.H.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.I.id, g.I.img, g.I.x1, g.I.y1, g.I.x2, g.I.y2, g.I.state, g.I.count, g.I.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.J.id, g.J.img, g.J.x1, g.J.y1, g.J.x2, g.J.y2, g.J.state, g.J.count, g.J.player);

  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.K.id, g.K.img, g.K.x1, g.K.y1, g.K.x2, g.K.y2, g.K.state, g.K.count, g.K.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.L.id, g.L.img, g.L.x1, g.L.y1, g.L.x2, g.L.y2, g.L.state, g.L.count, g.L.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.M.id, g.M.img, g.M.x1, g.M.y1, g.M.x2, g.M.y2, g.M.state, g.M.count, g.M.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.N.id, g.N.img, g.N.x1, g.N.y1, g.N.x2, g.N.y2, g.N.state, g.N.count, g.N.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.O.id, g.O.img, g.O.x1, g.O.y1, g.O.x2, g.O.y2, g.O.state, g.O.count, g.O.player);

  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.P.id, g.P.img, g.P.x1, g.P.y1, g.P.x2, g.P.y2, g.P.state, g.P.count, g.P.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.Q.id, g.Q.img, g.Q.x1, g.Q.y1, g.Q.x2, g.Q.y2, g.Q.state, g.Q.count, g.Q.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.R.id, g.R.img, g.R.x1, g.R.y1, g.R.x2, g.R.y2, g.R.state, g.R.count, g.R.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.S.id, g.S.img, g.S.x1, g.S.y1, g.S.x2, g.S.y2, g.S.state, g.S.count, g.S.player);
  fprintf(f, "id = %d\nimg = %d\nA(%d;%d)\nB(%d;%d)\nstate = %d\ncount = %d\nplayer = %d\n\n", g.T.id, g.T.img, g.T.x1, g.T.y1, g.T.x2, g.T.y2, g.T.state, g.T.count, g.T.player);
  fclose(f);
  return;
}

void saveCoordMouse(chaine nom, pt *T2, int incre){

  FILE*f;
  int i;
  f=fopen(nom, "wt");
  if (nom == NULL)
  return;
  else{
    for (i = 0; i < incre; i++) {
      fprintf(f, "pt %d : (%f;%f)\n", i, (T2[i].x), (T2[i].y));
    }
  }

  fclose(f);
  return;
}

void savePair(chaine nom, char pair[100]){
  FILE*f;
  f=fopen(nom, "wt");
  if(nom == NULL)
  return;
  else{
    fprintf(f, "%s", pair);
  }
}


void calculusScore(set *g, int *score1, int *score2, char pair[100]){
  int a1 = 0;
  int b1 = 0;
  int c1 = 0;
  int d1 = 0;
  int e1 = 0;
  int f1 = 0;
  int g1 = 0;
  int h1 = 0;
  int i1 = 0;
  int o1 = 0;

  int a2 = 0;
  int b2 = 0;
  int c2 = 0;
  int d2 = 0;
  int e2 = 0;
  int f2 = 0;
  int g2 = 0;
  int h2 = 0;
  int i2 = 0;
  int o2 = 0;

  sprintf(pair, "Paired Card :\n");
  if (g->A.player == 1 && g->M.player == 1){
    a1 = 1;
    strcat(pair, "2 paired\n");
  }
  else if (g->A.player == 2 && g->M.player == 2){
    a2 = 1;
    strcat(pair, "2 paired\n");
  }

  if (g->B.player == 1 && g->L.player == 1){
    b1 = 1;
    strcat(pair, "4 paired\n");
  }
  else if (g->B.player == 2 && g->L.player == 2){
    b2 = 1;
    strcat(pair, "4 paired\n");
  }

  if (g->C.player == 1 && g->Q.player == 1){
    c1 = 1;
    strcat(pair, "0 paired\n");
  }
  else if (g->C.player == 2 && g->Q.player == 2){
    c2 = 1;
    strcat(pair, "0 paired\n");
  }

  if (g->D.player == 1 && g->T.player == 1){
    d1 = 1;
    strcat(pair, "8 paired\n");
  }
  else if (g->D.player == 2 && g->T.player == 2){
    d2 = 1;
    strcat(pair, "8 paired\n");
  }

  if (g->E.player == 1 && g->K.player == 1){
    e1 = 1;
    strcat(pair, "7 paired\n");
  }
  else if (g->E.player == 2 && g->K.player == 2){
    e2 = 1;
    strcat(pair, "7 paired\n");
  }

  if (g->F.player == 1 && g->N.player == 1){
    f1 = 1;
    strcat(pair, "1 paired\n");
  }
  else if (g->F.player == 2 && g->N.player == 2){
    f2 = 1;
    strcat(pair, "1 paired\n");
  }

  if (g->G.player == 1 && g->P.player == 1){
    g1 = 1;
    strcat(pair, "6 paired\n");
  }
  else if (g->G.player == 2 && g->P.player == 2){
    g2 = 1;
    strcat(pair, "6 paired\n");
  }

  if (g->H.player == 1 && g->R.player == 1){
    h1 = 1;
    strcat(pair, "3 paired\n");
  }
  else if (g->H.player == 2 && g->R.player == 2){
    h2 = 1;
    strcat(pair, "3 paired\n");
  }

  if (g->I.player == 1 && g->J.player == 1){
    i1 = 1;
    strcat(pair, "9 paired\n");
  }
  else if (g->I.player == 2 && g->J.player == 2){
    i2 = 1;
    strcat(pair, "9 paired\n");
  }
  /*
  if (g->J.player == 1)score1 += 1;
  else if (g->J.player == 2)score2 += 1;

  if (g->K.player == 1)score1 += 1;
  else if (g->K.player == 2)score2 += 1;

  if (g->L.player == 1)score1 += 1;
  else if (g->L.player == 2)score2 += 1;

  if (g->M.player == 1)score1 += 1;
  else if (g->M.player == 2)score2 += 1;

  if (g->N.player == 1)score1 += 1;
  else if (g->N.player == 2)score2 += 1;
  */
  if (g->O.player == 1 && g->S.player == 1){
    o1 = 1;
    strcat(pair, "5 paired\n");
  }
  else if (g->O.player == 2 && g->S.player == 2){
    o2 = 1;
    strcat(pair, "5 paired\n");
  }

  *score1 = a1 + b1 + c1 + d1 + e1 + f1 + g1 + h1 + i1 + o1;
  *score2 = a2 + b2 + c2 + d2 + e2 + f2 + g2 + h2 + i2 + o2;
  /*
  if (g->P.player == 1)score1 += 1;
  else if (g->P.player == 2)score2 += 1;

  if (g->Q.player == 1)score1 += 1;
  else if (g->Q.player == 2)score2 += 1;

  if (g->R.player == 1)score1 += 1;
  else if (g->R.player == 2)score2 += 1;

  if (g->S.player == 1)score1 += 1;
  else if (g->S.player == 2)score2 += 1;

  if (g->T.player == 1)score1 += 1;
  else if (g->T.player == 2)score2 += 1;
  */
}
/*
void calculusScore(pair *duo, int *score1, int *score2){
*score2 = 3;
if (duo->a.player == 1 && duo->b.player == 1) {
score1 += 1;
}else if (duo->a.player == 2 && duo->b.player == 2) {
score2 = score2 + 1;
}
}
*/

void timeBetweenClicks(float *timer, turn *t, float *timePair){
  float Tint1, Tint2;
  if (t->clicks%2 == 0 && etatBoutonSouris() == GaucheRelache && abscisseSouris() >= 7*largeurFenetre()/27) {
    Tint1 = *timer;
    t->clicks += 2;
  }
  if (t->clicks%2 == 1 && etatBoutonSouris() == GaucheRelache && abscisseSouris() >= 7*largeurFenetre()/27) {
    Tint2 = *timer;
    t->clicks = 2;
  }
  *timePair = Tint2 - Tint1; //delay between clicks
}

btn initializeBtnPictionnary(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

   x.x1 = 370*largeurFenetre()/1080;
  x.y1 = (960-550)*hauteurFenetre()/960;
  x.x2 = 760*largeurFenetre()/1080;
  x.y2 =(960-500)*hauteurFenetre()/960 ;

  return x;
}

btn initializeBtnMemory(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

  x.x1 = 420*largeurFenetre()/1080;
  x.y1 = (960-370)*hauteurFenetre()/960;
  x.x2 = 670*largeurFenetre()/1080;
  x.y2 =(960-330)*hauteurFenetre()/960 ;

  return x;
}

btn initializeBtnAssociation(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

  x.x1 = 370*largeurFenetre()/1080;
  x.y1 = (960-750)*hauteurFenetre()/960;
  x.x2 = 760*largeurFenetre()/1080;
  x.y2 =(960-700)*hauteurFenetre()/960 ;

  return x;
}

btn initializeBtnSettings(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

  x.x2 = largeurFenetre()-10;
  x.x1 = x.x2 - largeurFenetre()/8;
  x.y1 = 10;
  x.y2 = x.y1 + hauteurFenetre()/8;

  return x;
}

btn initializeReye(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

  x.x1 = 5*largeurFenetre()/8+20;
  x.y1 = hauteurFenetre() - 2*hauteurFenetre()/8;
  x.x2 = largeurFenetre() - 30;
  x.y2 = hauteurFenetre() - 30;


  return x;
}

btn initializeLeye(void){
  btn x;

  x.r = 150;
  x.g = 150;
  x.b = 150;

  x.x1 = 2*largeurFenetre()/8+20;
  x.y1 = hauteurFenetre() - 2*hauteurFenetre()/8;
  x.x2 = largeurFenetre() - (30+3*largeurFenetre()/8);
  x.y2 = hauteurFenetre() - 30;


  return x;
}

void displayMenu(btn pictionnary, btn association, btn calibrage, btn memory, btn settings, btn quit, btn reye, btn leye){

  int dyp = pictionnary.y2-pictionnary.y1;
  int dym = memory.y2-memory.y1;
  int dya = association.y2-association.y1;

  effaceFenetre(200,200,200);
  epaisseurDeTrait(2);


  traceButton(pictionnary);
  couleurCourante(50, 50, 50);
  afficheChaine("Pictionnary", 50, pictionnary.x1+tailleChaine("Pictionnary", 50)/2, pictionnary.y1+dyp/2-50/2);

  traceButton(memory);
  couleurCourante(50, 50, 50);
  afficheChaine("Memory", 50, memory.x1+tailleChaine("Memory   ", 50)/2, memory.y1+dym/2-50/2);

  traceButton(association);
  couleurCourante(50,50,50);
  afficheChaine("Association", 50, association.x1+tailleChaine("Association", 50)/2, association.y1+dya/2-50/2);

  initializeButtonQuit(&quit);
  traceButtonQuit(quit);

  traceButton(settings);

  traceButton(reye);
  couleurCourante(50, 50, 50);
  afficheChaine("Right Eye", 30, reye.x1+30, reye.y1+30);

  traceButton(leye);
  couleurCourante(50, 50, 50);
  afficheChaine("Left Eye", 30, leye.x1+30, leye.y1+30);
}

void manageBtnQUIT(btn * q){
  if (etatBoutonSouris() == GaucheAppuye && abscisseSouris() >= q->x1 - 10 && abscisseSouris() <= q->x1 + 10 && ordonneeSouris() >= q->y1 - 10 && ordonneeSouris() <= q->y1 + 10) {
    termineBoucleEvenements();
  }
}



void manageMenu(int * etatmenu, btn pictionnary, btn memory, btn association, btn settings, btn quit){

  if (etatBoutonSouris()==GaucheRelache && abscisseSouris() >= pictionnary.x1 && abscisseSouris() <= pictionnary.x2 && ordonneeSouris() >= pictionnary.y1 && ordonneeSouris() <= pictionnary.y2) {
    *etatmenu = 1;
  }
  if (etatBoutonSouris()==GaucheRelache && abscisseSouris() >= association.x1 && abscisseSouris() <= association.x2 && ordonneeSouris() >= association.y1 && ordonneeSouris() <= association.y2) {
    *etatmenu = 2;
  }
  if (etatBoutonSouris()==GaucheRelache && abscisseSouris() >= memory.x1 && abscisseSouris() <= memory.x2 && ordonneeSouris() >= memory.y1 && ordonneeSouris() <= memory.y2) {
    *etatmenu = 3;
  }
  if (etatBoutonSouris()==GaucheRelache && abscisseSouris() >= settings.x1 && abscisseSouris() <= settings.x2 && ordonneeSouris() >= settings.y1 && ordonneeSouris() <= settings.y2) {
    *etatmenu = 4;
  }
  manageBtnQUIT(&quit);
}

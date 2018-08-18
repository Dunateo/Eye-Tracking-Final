#include <stdlib.h>
#include <stdio.h>
#include "GfxLib.h"
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "structures.h"
#include <string.h>


void traceButton(btn a){
  couleurCourante(a.r, a.g, a.g);
  epaisseurDeTrait(2);
  rectangle(a.x1, a.y1, a.x2, a.y2);

  //borders
  epaisseurDeTrait(5);
  couleurCourante(a.r-50,	a.g-50,	a.b-50);
  ligne(a.x1, a.y1-2, a.x1, a.y2+2);  //|
  ligne(a.x1, a.y2, a.x2+2, a.y2);    // -
  ligne(a.x2, a.y2, a.x2, a.y1);      //  |
  ligne(a.x2+2, a.y1, a.x1, a.y1);    // _
}

void traceButtonQuit(btn a){
  couleurCourante(a.r, a.g, a.b);
  epaisseurDeTrait(25);
  point(a.x1, a.y1);
  couleurCourante(255, 255, 255);
  epaisseurDeTrait(5);
  ligne(a.x1 - 5, a.y1 - 5, a.x2 + 5, a.y2 + 5);
  ligne(a.x1 - 5, a.y1 + 5, a.x2 + 5, a.y2 - 5);
}

void manageButtonQuit(btn q, set g, pt **T, int incre, char pair[100]){
  if (etatBoutonSouris() == GaucheAppuye && abscisseSouris() >= q.x1 - 10 && abscisseSouris() <= q.x1 + 10 && ordonneeSouris() >= q.y1 - 10 && ordonneeSouris() <= q.y1 + 10) {
    saveSet("save", g);
    saveCoordMouse("saveMouse", *T, incre);
    savePair("savePair", pair);
    termineBoucleEvenements();
  }
}




void flipDownCard(card *x, turn *t){
  //x = (card *)malloc(sizeof(card));
  if (x->player == 0 && t->clicks == 0) {
    x->state = 0;
  }
  //free(x);
}

/*
void hideAllUnpaired(turn *t, card A, card B, card C, card D, card E, card F, card G, card H, card I, card J, card K, card L, card M, card N, card O, card P, card Q, card R, card S, card T){
hideUnpaired(&A, t);
hideUnpaired(&B, t);
hideUnpaired(&C, t);
hideUnpaired(&D, t);
hideUnpaired(&E, t);
hideUnpaired(&F, t);
hideUnpaired(&G, t);
hideUnpaired(&H, t);
hideUnpaired(&I, t);
hideUnpaired(&J, t);
hideUnpaired(&K, t);
hideUnpaired(&L, t);
hideUnpaired(&M, t);
hideUnpaired(&N, t);
hideUnpaired(&O, t);
hideUnpaired(&P, t);
hideUnpaired(&Q, t);
hideUnpaired(&R, t);
hideUnpaired(&S, t);
hideUnpaired(&T, t);
}
*/

void initializeImg(DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf){

  zero = lisBMPRGB("home.bmp");
  //un = lisBMPRGB("hulk.bmp");
  deux = lisBMPRGB("picture.bmp");
  trois = lisBMPRGB("iron-man.bmp");
  quatre = lisBMPRGB("wolverine.bmp");
  cinq = lisBMPRGB("deadpool.bmp");
  six = lisBMPRGB("magneto.bmp");
  sept = lisBMPRGB("batman.bmp");
  huit = lisBMPRGB("the-joker.bmp");
  neuf = lisBMPRGB("captain-america.bmp");
}

void displayCard(card *x, turn *t, DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf){


  flipDownCard(x, t);

  //hidden card
  if (x->state == 0) {
    couleurCourante(146, 39, 143);
    epaisseurDeTrait(1);
    rectangle(x->x1, x->y1, x->x2, x->y2);

    //borders
    epaisseurDeTrait(5);
    couleurCourante(81,	21,	79);
    ligne(x->x1, x->y1-2, x->x1, x->y2+2);  //|
    ligne(x->x1, x->y2, x->x2+2, x->y2);    // -
    ligne(x->x2, x->y2, x->x2, x->y1);      //  |
    ligne(x->x2+2, x->y1, x->x1, x->y1);    // _
  }

  else if (x->state == 1){

    //player 1's pair
    if (x->state == 1 && x->player == 1) {
      //display corresponding picture
      //borders are blue
      epaisseurDeTrait(5);
      couleurCourante(0, 0, 255);
      ligne(x->x1, x->y1-2, x->x1, x->y2+2);  //|
      ligne(x->x1, x->y2, x->x2+2, x->y2);    // -
      ligne(x->x2, x->y2, x->x2, x->y1);      //  |
      ligne(x->x2+2, x->y1, x->x1, x->y1);    // _
    }

    //player 2's pair
    else if (x->state == 1 && x->player == 2) {
      //display corresponding picture
      //borders are red
      epaisseurDeTrait(5);
      couleurCourante(255, 0, 0);
      ligne(x->x1, x->y1-2, x->x1, x->y2+2);  //|
      ligne(x->x1, x->y2, x->x2+2, x->y2);    // -
      ligne(x->x2, x->y2, x->x2, x->y1);      //  |
      ligne(x->x2+2, x->y1, x->x1, x->y1);    // _
    }

    else if (x->state == 1) {
      //display corresponding

      epaisseurDeTrait(1);
      couleurCourante(255,165,0);
      rectangle(x->x1, x->y1, x->x2, x->y2);

      //borders are black
      epaisseurDeTrait(5);
      couleurCourante(0, 0, 0);
      ligne(x->x1, x->y1-2, x->x1, x->y2+2);  //|
      ligne(x->x1, x->y2, x->x2+2, x->y2);    // -
      ligne(x->x2, x->y2, x->x2, x->y1);      //  |
      ligne(x->x2+2, x->y1, x->x1, x->y1);    // _
    }
  }

  if (largeurFenetre() >= 600 && hauteurFenetre() >= 600 && x->state == 1) {
    if (zero != NULL && x->img == 0)
    {
      ecrisImage(x->x1, x->y1, zero->largeurImage, zero->hauteurImage, zero->donneesRGB);
    }
    if (un != NULL && x->img == 1)
    {
      ecrisImage(x->x1, x->y1, un->largeurImage, un->hauteurImage, un->donneesRGB);
    }
    if (deux != NULL && x->img == 2)
    {
      ecrisImage(x->x1, x->y1, deux->largeurImage, deux->hauteurImage, deux->donneesRGB);
    }
    if (trois != NULL && x->img == 3)
    {
      ecrisImage(x->x1, x->y1, trois->largeurImage, trois->hauteurImage, trois->donneesRGB);
    }
    if (quatre != NULL && x->img == 4)
    {
      ecrisImage(x->x1, x->y1, quatre->largeurImage, quatre->hauteurImage, quatre->donneesRGB);
    }
    if (cinq != NULL && x->img == 5)
    {
      ecrisImage(x->x1, x->y1, cinq->largeurImage, cinq->hauteurImage, cinq->donneesRGB);
    }
    if (six != NULL && x->img == 6)
    {
      ecrisImage(x->x1, x->y1, six->largeurImage, six->hauteurImage, six->donneesRGB);
    }
    if (sept != NULL && x->img == 7)
    {
      ecrisImage(x->x1, x->y1, sept->largeurImage, sept->hauteurImage, sept->donneesRGB);
    }
    if (huit != NULL && x->img == 8)
    {
      ecrisImage(x->x1, x->y1, huit->largeurImage, huit->hauteurImage, huit->donneesRGB);
    }
    if (neuf != NULL && x->img == 9)
    {
      ecrisImage(x->x1, x->y1, neuf->largeurImage, neuf->hauteurImage, neuf->donneesRGB);
    }
  }
}
void displaySet(set g, turn *t, DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf, DonneesImageRGB *mini){
  //image->largeurImage = 841;
  //image->hauteurImage = 199;
  displayCard(&(g.A), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.B), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.C), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.D), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.E), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.F), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.G), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.H), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.I), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.J), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.K), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.L), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.M), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.N), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.O), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.P), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.Q), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.R), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.S), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);
  displayCard(&(g.T), t, zero, un, deux, trois, quatre, cinq, six, sept, huit, neuf);


  if (mini != NULL && largeurFenetre() >= 600 && hauteurFenetre() >= 600) // Si l'image a pu etre lue
  {
    ecrisImage(17*largeurFenetre()/27 - (mini->largeurImage)/2, 21*hauteurFenetre()/23 - mini->hauteurImage/2, mini->largeurImage, mini->hauteurImage, mini->donneesRGB);
  }
}

card manageCardClicked(card x){
  if (etatBoutonSouris() == GaucheAppuye && abscisseSouris() >= x.x1 && abscisseSouris() <= x.x2 && ordonneeSouris() >= x.y1 && ordonneeSouris() <= x.y2) {
    x.count += 1;
    if (x.state == 0) {
      x.state = 1;
    }else x.state = 0;
  }
  return x;
}

void manageSetClicked(set *g){
  g->A = manageCardClicked(g->A);
  g->B = manageCardClicked(g->B);
  g->C = manageCardClicked(g->C);
  g->D = manageCardClicked(g->D);
  g->E = manageCardClicked(g->E);
  g->F = manageCardClicked(g->F);
  g->G = manageCardClicked(g->G);
  g->H = manageCardClicked(g->H);
  g->I = manageCardClicked(g->I);
  g->J = manageCardClicked(g->J);
  g->K = manageCardClicked(g->K);
  g->L = manageCardClicked(g->L);
  g->M = manageCardClicked(g->M);
  g->N = manageCardClicked(g->N);
  g->O = manageCardClicked(g->O);
  g->P = manageCardClicked(g->P);
  g->Q = manageCardClicked(g->Q);
  g->R = manageCardClicked(g->R);
  g->S = manageCardClicked(g->S);
  g->T = manageCardClicked(g->T);
}



void initializeButtonQuit(btn *q){
  q->r = 255;
  q->b = q->g = 0;
  q->x1 = q->x2 = largeurFenetre() - 20;
  q->y1 = q->y2 = hauteurFenetre() - 20;
}

// 1st row
card initializeCardA(void){
  card a;

  a.id = 1;

  a.state = 0;
  a.count = 0;
  a.player = 0;

  return a;
}

card initializeCardB(card a){
  card b;

  b.id = a.id + 1;

  b.state = a.state;
  b.count = a.count;
  b.player = a.player;

  return b;
}

card initializeCardC(card b){
  card c;

  c.id = b.id + 1;

  c.state = b.state;
  c.count = b.count;
  c.player = b.player;

  return c;
}

card initializeCardD(card c){
  card d;

  d.id = c.id + 1;
  d.state = c.state;
  d.count = c.count;
  d.player = c.player;

  return d;
}

card initializeCardE(card d){
  card e;

  e.id = d.id + 1;

  e.state = d.state;
  e.count = d.count;
  e.player = d.player;

  return e;
}


// 2nd row
card initializeCardF(void){
  card f;

  f.id = 6;

  f.state = 0;
  f.count = 0;
  f.player = 0;

  return f;
}

card initializeCardG(card f){
  card g;

  g.id = 7;

  g.state = f.state;
  g.count = f.count;
  g.player = f.player;

  return g;
}

card initializeCardH(card g){
  card h;

  h.id = 8;

  h.state = g.state;
  h.count = g.count;
  h.player = g.player;

  return h;
}

card initializeCardI(card h){
  card i;

  i.id = 9;

  i.state = h.state;
  i.count = h.count;
  i.player = h.player;

  return i;
}

card initializeCardJ(card i){
  card j;

  j.id = 10;

  j.state = i.state;
  j.count = i.count;
  j.player = i.player;

  return j;
}


// 3rd row
card initializeCardK(void){
  card k;

  k.id = 11;

  k.state = 0;
  k.count = 0;
  k.player = 0;

  return k;
}

card initializeCardL(card k){
  card l;

  l.id = k.id + 1;

  l.state = k.state;
  l.count = k.count;
  l.player = k.player;

  return l;
}

card initializeCardM(card l){
  card m;

  m.id = l.id + 1;

  m.state = l.state;
  m.count = l.count;
  m.player = l.player;

  return m;
}

card initializeCardN(card m){
  card n;

  n.id = m.id + 1;

  n.state = m.state;
  n.count = m.count;
  n.player = m.player;

  return n;
}

card initializeCardO(card n){
  card o;

  o.id = n.id + 1;

  o.state = n.state;
  o.count = n.count;
  o.player = n.player;

  return o;
}


// 4th row
card initializeCardP(void){
  card p;

  p.id = 16;

  p.state = 0;
  p.count = 0;
  p.player = 0;

  return p;
}

card initializeCardQ(card p){
  card q;

  q.id = p.id + 1;

  q.state = p.state;
  q.count = p.count;
  q.player = p.player;

  return q;
}

card initializeCardR(card q){
  card r;

  r.id = q.id + 1;

  r.state = q.state;
  r.count = q.count;
  r.player = q.player;

  return r;
}

card initializeCardS(card r){
  card s;

  s.id = r.id + 1;

  s.state = r.state;
  s.count = r.count;
  s.player = r.player;

  return s;
}

card initializeCardT(card s){
  card t;

  t.id = s.id + 1;

  t.state = s.state;
  t.count = s.count;
  t.player = s.player;

  return t;
}

void initializeSet(set *g){

  //1st row
  g->A = initializeCardA();
  g->B = initializeCardB(g->A);
  g->C = initializeCardC(g->B);
  g->D = initializeCardD(g->C);
  g->E = initializeCardE(g->D);

  //2nd row
  g->F = initializeCardF();
  g->G = initializeCardG(g->F);
  g->H = initializeCardH(g->G);
  g->I = initializeCardI(g->H);
  g->J = initializeCardJ(g->I);

  //3rd row
  g->K = initializeCardK();
  g->L = initializeCardL(g->K);
  g->M = initializeCardM(g->L);
  g->N = initializeCardN(g->M);
  g->O = initializeCardO(g->N);

  //4th row
  g->P = initializeCardP();
  g->Q = initializeCardQ(g->P);
  g->R = initializeCardR(g->Q);
  g->S = initializeCardS(g->R);
  g->T = initializeCardT(g->S);


  g->A.img = -1;
  g->B.img = -1;
  g->C.img = -1;
  g->D.img = -1;
  g->E.img = -1;

  g->F.img = -1;
  g->G.img = -1;
  g->H.img = -1;
  g->I.img = -1;
  g->J.img = -1;

  g->K.img = -1;
  g->L.img = -1;
  g->M.img = -1;
  g->N.img = -1;
  g->O.img = -1;

  g->P.img = -1;
  g->Q.img = -1;
  g->R.img = -1;
  g->S.img = -1;
  g->T.img = -1;
}

void initializeCardsGraphic(set *g){

  g->A.x1 = 8 * largeurFenetre() / 27;
  g->A.y1 = 16 * hauteurFenetre() / 23;
  g->A.x2 = g->A.x1 + 2 * largeurFenetre() / 27;
  g->A.y2 = g->A.y1 + 3 * hauteurFenetre() / 23;

  g->B.x1 = g->A.x1 + 4*largeurFenetre() / 27;
  g->B.y1 = g->A.y1;
  g->B.x2 = g->A.x2 + 4*largeurFenetre() / 27;
  g->B.y2 = g->A.y2;

  g->C.x1 = g->B.x1 + 4*largeurFenetre() / 27;
  g->C.y1 = g->B.y1;
  g->C.x2 = g->B.x2 + 4*largeurFenetre() / 27;
  g->C.y2 = g->B.y2;

  g->D.x1 = g->C.x1 + 4*largeurFenetre() / 27;
  g->D.y1 = g->C.y1;
  g->D.x2 = g->C.x2 + 4*largeurFenetre() / 27;
  g->D.y2 = g->C.y2;

  g->E.x1 = g->D.x1 + 4*largeurFenetre() / 27;
  g->E.y1 = g->D.y1;
  g->E.x2 = g->D.x2 + 4*largeurFenetre() / 27;
  g->E.y2 = g->D.y2;

  g->F.x1 = 8*largeurFenetre() / 27;
  g->F.y1 = 11*hauteurFenetre() / 23;
  g->F.x2 = g->F.x1 + 2*largeurFenetre() / 27;
  g->F.y2 = g->F.y1 + 3*hauteurFenetre() / 23;

  g->G.x1 = g->F.x1 + 4*largeurFenetre() / 27;
  g->G.y1 = g->F.y1;
  g->G.x2 = g->F.x2 + 4*largeurFenetre() / 27;
  g->G.y2 = g->F.y2;

  g->H.x1 = g->G.x1 + 4*largeurFenetre() / 27;
  g->H.y1 = g->G.y1;
  g->H.x2 = g->G.x2 + 4*largeurFenetre() / 27;
  g->H.y2 = g->G.y2;

  g->I.x1 = g->H.x1 + 4*largeurFenetre() / 27;
  g->I.y1 = g->H.y1;
  g->I.x2 = g->H.x2 + 4*largeurFenetre() / 27;
  g->I.y2 = g->H.y2;

  g->J.x1 = g->I.x1 + 4*largeurFenetre() / 27;
  g->J.y1 = g->I.y1;
  g->J.x2 = g->I.x2 + 4*largeurFenetre() / 27;
  g->J.y2 = g->I.y2;

  g->K.x1 = 8*largeurFenetre() / 27;
  g->K.y1 = 6*hauteurFenetre() / 23;
  g->K.x2 = g->K.x1 + 2*largeurFenetre() / 27;
  g->K.y2 = g->K.y1 + 3*hauteurFenetre() / 23;

  g->L.x1 = g->K.x1 + 4*largeurFenetre() / 27;
  g->L.y1 = g->K.y1;
  g->L.x2 = g->K.x2 + 4*largeurFenetre() / 27;
  g->L.y2 = g->K.y2;

  g->M.x1 = g->L.x1 + 4*largeurFenetre() / 27;
  g->M.y1 = g->L.y1;
  g->M.x2 = g->L.x2 + 4*largeurFenetre() / 27;
  g->M.y2 = g->L.y2;

  g->N.x1 = g->M.x1 + 4*largeurFenetre() / 27;
  g->N.y1 = g->M.y1;
  g->N.x2 = g->M.x2 + 4*largeurFenetre() / 27;
  g->N.y2 = g->M.y2;

  g->O.x1 = g->N.x1 + 4*largeurFenetre() / 27;
  g->O.y1 = g->N.y1;
  g->O.x2 = g->N.x2 + 4*largeurFenetre() / 27;
  g->O.y2 = g->N.y2;

  g->P.x1 = 8*largeurFenetre() / 27;
  g->P.y1 = 1*hauteurFenetre() / 23;
  g->P.x2 = g->P.x1 + 2*largeurFenetre() / 27;
  g->P.y2 = g->P.y1 + 3*hauteurFenetre() / 23;

  g->Q.x1 = g->P.x1 + 4*largeurFenetre() / 27;
  g->Q.y1 = g->P.y1;
  g->Q.x2 = g->P.x2 + 4*largeurFenetre() / 27;
  g->Q.y2 = g->P.y2;

  g->R.x1 = g->Q.x1 + 4*largeurFenetre() / 27;
  g->R.y1 = g->Q.y1;
  g->R.x2 = g->Q.x2 + 4*largeurFenetre() / 27;
  g->R.y2 = g->Q.y2;

  g->S.x1 = g->R.x1 + 4*largeurFenetre() / 27;
  g->S.y1 = g->R.y1;
  g->S.x2 = g->R.x2 + 4*largeurFenetre() / 27;
  g->S.y2 = g->R.y2;

  g->T.x1 = g->S.x1 + 4*largeurFenetre() / 27;
  g->T.y1 = g->S.y1;
  g->T.x2 = g->S.x2 + 4*largeurFenetre() / 27;
  g->T.y2 = g->S.y2;
}

void initializeTurn(turn *t){

  t->clicks = 0;
  t->player = 1;
}



void drawLeftPanel(turn *t){
  //blue left panel
  if (t->player == 1) {

    couleurCourante(leftPanelColor1R, leftPanelColor1V, leftPanelColor1B);
    epaisseurDeTrait(2);
    rectangle(0, 0, 7*largeurFenetre() / 27, hauteurFenetre());

    couleurCourante(leftPanelColor1R-40, leftPanelColor1V-40, leftPanelColor1B-40);
    epaisseurDeTrait(5);
    ligne(7*largeurFenetre() / 27, 0, 7*largeurFenetre() / 27, hauteurFenetre());
  }

  //red left panel
  else if (t->player == 2) {

    couleurCourante(leftPanelColor2R, leftPanelColor2V, leftPanelColor2B);
    epaisseurDeTrait(2);
    rectangle(0, 0, 7*largeurFenetre() / 27, hauteurFenetre());

    couleurCourante(leftPanelColor2R-40, leftPanelColor2V-40, leftPanelColor2B-40);
    epaisseurDeTrait(5);
    ligne(7*largeurFenetre() / 27, 0, 7*largeurFenetre() / 27, hauteurFenetre());
  }
  else {

    couleurCourante(255, 165, 0);
    epaisseurDeTrait(2);
    rectangle(0, 0, 7*largeurFenetre() / 27, hauteurFenetre());

    couleurCourante(255-40, 165-40, 0-40);
    epaisseurDeTrait(5);
    ligne(7*largeurFenetre() / 27, 0, 7*largeurFenetre() / 27, hauteurFenetre());

  }
}

void initializeTurnBtn(btn *t){
  t->r = 171 ;
  t->g = 170 ;
  t->b = 178 ;
  t->x1 = largeurFenetre() / 27 ;
  t->y1 = 1 * hauteurFenetre() /23 ;
  t->x2 = (t->x1) * 6;
  t->y2 = (t->y1) + (1 * largeurFenetre() / 23);
}

void drawNextTurnBtn(btn *t, turn *turn){
  int dx = t->x2 - t->x1;
  int dy = t->y2 - t->y1;
  epaisseurDeTrait(2);
  couleurCourante(t->r, t->g, t->b);
  rectangle(t->x1, t->y1, t->x2, t->y2);

  couleurCourante(0, 0, 0);
  epaisseurDeTrait(3);
  afficheChaine("Next Turn", largeurFenetre()/40, (t->x1+dx/2)/2, (t->y1 + dy/4));

  epaisseurDeTrait(5);

  if (turn->player == 1) {
    couleurCourante(leftPanelColor1R-40, leftPanelColor1V-40, leftPanelColor1B-40);
    ligne(t->x1, t->y1-2, t->x1, t->y2+2);  //|
    ligne(t->x1, t->y2, t->x2+2, t->y2);    // -
    ligne(t->x2, t->y2, t->x2, t->y1);      //  |
    ligne(t->x2+2, t->y1, t->x1, t->y1);    // _
  }else if (turn->player == 2) {
    couleurCourante(leftPanelColor2R-40, leftPanelColor2V-40, leftPanelColor2B-40);
    ligne(t->x1, t->y1-2, t->x1, t->y2+2);  //|
    ligne(t->x1, t->y2, t->x2+2, t->y2);    // -
    ligne(t->x2, t->y2, t->x2, t->y1);      //  |
    ligne(t->x2+2, t->y1, t->x1, t->y1);    // _
  }
}

void drawP1Score(int *score1, turn *turn){
  char s[20];
  char temp[2];
  int x1 = largeurFenetre() / 27;
  int y1 = 10*hauteurFenetre() / 23;
  int x2 = 6*largeurFenetre() / 27;
  int y2 = 12*hauteurFenetre() / 23;
  sprintf(s, "Score Player 1 : ");
  sprintf(temp, "%d", *score1);
  strcat(s, temp);

  couleurCourante(171, 170, 178);
  epaisseurDeTrait(3);
  rectangle(x1, y1, x2, y2);
  couleurCourante(0, 0, 0);
  afficheChaine(s, largeurFenetre()/65, largeurFenetre() / 27 + largeurFenetre()/200, 10*hauteurFenetre() / 23 + hauteurFenetre()/(23*2));

  epaisseurDeTrait(5);

  if (turn->player == 1) {
    couleurCourante(leftPanelColor1R-40, leftPanelColor1V-40, leftPanelColor1B-40);
    ligne(x1, y1-2, x1, y2+2);  //|
    ligne(x1, y2, x2+2, y2);    // -
    ligne(x2, y2, x2, y1);      //  |
    ligne(x2+2, y1, x1, y1);    // _
  }else if (turn->player == 2) {
    couleurCourante(leftPanelColor2R-40, leftPanelColor2V-40, leftPanelColor2B-40);
    ligne(x1, y1-2, x1, y2+2);  //|
    ligne(x1, y2, x2+2, y2);    // -
    ligne(x2, y2, x2, y1);      //  |
    ligne(x2+2, y1, x1, y1);    // _
  }

}

void drawP2Score(int *score2, turn *turn){
  char s2[20];
  char temp2[2];
  int x1 = largeurFenetre() / 27;
  int y1 = 13*hauteurFenetre() / 23;
  int x2 = 6*largeurFenetre() / 27;
  int y2 = 15*hauteurFenetre() / 23;
  sprintf(s2, "Score Player 2 : ");
  sprintf(temp2, "%d", *score2);
  strcat(s2, temp2);

  couleurCourante(171, 170, 178);
  epaisseurDeTrait(3);
  rectangle(x1, y1, x2, y2);
  couleurCourante(0, 0, 0);
  afficheChaine(s2, largeurFenetre()/65, largeurFenetre() / 27 + largeurFenetre()/200, 13*hauteurFenetre() / 23 + hauteurFenetre()/(23*2));

  epaisseurDeTrait(5);

  if (turn->player == 1) {
    couleurCourante(leftPanelColor1R-40, leftPanelColor1V-40, leftPanelColor1B-40);
    ligne(x1, y1-2, x1, y2+2);  //|
    ligne(x1, y2, x2+2, y2);    // -
    ligne(x2, y2, x2, y1);      //  |
    ligne(x2+2, y1, x1, y1);    // _
  }else if (turn->player == 2) {
    couleurCourante(leftPanelColor2R-40, leftPanelColor2V-40, leftPanelColor2B-40);
    ligne(x1, y1-2, x1, y2+2);  //|
    ligne(x1, y2, x2+2, y2);    // -
    ligne(x2, y2, x2, y1);      //  |
    ligne(x2+2, y1, x1, y1);    // _
  }
}

void drawScore(int *scoreP1, int *scoreP2, turn *t){
  drawP1Score(scoreP1, t);
  drawP2Score(scoreP2, t);
}

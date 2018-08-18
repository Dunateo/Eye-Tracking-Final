//blue left panel
#define leftPanelColor1R 20
#define leftPanelColor1V 20
#define leftPanelColor1B 150
//red left panel
#define leftPanelColor2R 150
#define leftPanelColor2V 20
#define leftPanelColor2B 20
//Barycentre needed constantes
#define LarImg 500
#define HauImg 300 //for all images
#define JOINT 2     //2eyes
#define MAXPIXJOINT 48000000//many px/img
//For radon
#define Ray 46

typedef char chaine[50];

typedef struct pt{
  float x, y; //cartesian cordinates
}pt;

typedef struct btn{
  int r, g, b; // color
  int x1,y1,x2,y2; //cordinates
}btn;

typedef struct lgtLine{
  float min,max,moy,glob;
  int nb;
  float *TL,*Time;

}lgtLine;

typedef struct symbol{
  char name; // associated with the img
}symbol;

typedef struct carte{
	pt pos;
	int num;
	DonneesImageRGB *img;
}carte;

typedef struct card{
  int id; // number of the card in the set
  int img; // -1 at first then 0 to 9 (to be paired)
  int x1,y1,x2,y2; //graphic of the card
  int state; //0 or 1, displayed or hidden
  int count; // nb of times clicked
  int player; // 0 for unpaired, 1 paired by player 1 and 2 paired by player 2
  char *name;//name of the card

}card;

typedef struct setP{
  card A, B, C, D, E;
  int chs;
}setP;

typedef struct set{
  card A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T;
}set;

typedef struct name{
  char *A,*B,*C,*D,*E;
  int lt1,lt2,lt3,lt4,lt5;
}name;
typedef struct poly{
	float a,b;
}poly;

typedef struct turn{
  int clicks; //0, 1 or 2 then turn is over
  int player; //1 or 2 ( for each player )
}turn;

typedef struct pair{
  card a, b;
}pair;

//radon and barycentre

typedef struct equCercle{
	int Xc;
	int r;
	int Yc1, Yc2;
}equCercle;

typedef struct info{

	pt position[MAXPIXJOINT]; // y puis x
	int nb;
	pt centre;
}info;

typedef struct jointure{
	info j[JOINT];
}jointure;

/*---------------------------------------
------------------GLOBAL-----------------
---------------------------------------*/
void mouseTracking(int *TabPt);
void analyseMouseTracking(int *TabPtAnalysed);
void printCoordinates(pt a);
void printCard(card x);
void sauveTab(chaine test, pt *TabCoordinates, int nbpt);
void chargeTab(chaine test, pt *TabCoordinates, int nbpt);
void allocationT(int incre, pt **T2);
/*---------------------------------------
----------------GRAPHIQUE----------------
---------------------------------------*/
void traceButton(btn A);
void initializeButtonQuit(btn *q);
void traceInterface(btn A, btn B, btn C);
void traceButtonQuit(btn A);
void manageButtonQuit(btn QUIT, set game, pt **T, int incre, char pair[100]);
void drawLeftPanel(turn *t);

void displayMenu(btn pictionnary, btn association, btn calibrage, btn memory, btn settings, btn quit, btn reye, btn leye);
btn initializeBtnPictionnary(void);
btn initializeBtnMemory(void);
btn initializeBtnAssociation(void);
btn initializeBtnSettings(void);
btn initializeReye();
btn initializeLeye();

void manageBtnQUIT(btn * quit);

void manageMenu(int * etatmenu, btn pictionnary, btn memory, btn association, btn settings, btn quit);

/*---------------------------------------
-----------------MEMORY------------------
---------------------------------------*/
//card fromm A to T are the 20 cards on the set
//card fromm A to T are the 20 cards on the set
void displayCards(card A, card B, card C, card D, card E, card F, card G, card H, card I, card J, card K, card L, card M, card N, card O, card P, card Q, card R, card S, card T);
//void calculusScore(pair *duo, int *score1, int *score2);
void calculusScore(set *g, int *score1, int *score2, char pair[100]);
void saveGame(chaine save, set game); // save the set in a binary file
void loadGame(chaine save); // load the previous set of cards in a binary file

card initializeCardA(void);
card initializeCardB(card a);
card initializeCardC(card b);
card initializeCardD(card c);
card initializeCardE(card d);
card initializeCardF(void);
card initializeCardG(card f);
card initializeCardH(card g);
card initializeCardI(card h);
card initializeCardJ(card i);
card initializeCardK(void);
card initializeCardL(card k);
card initializeCardM(card l);
card initializeCardN(card m);
card initializeCardO(card n);
card initializeCardP(void);
card initializeCardQ(card p);
card initializeCardR(card q);
card initializeCardS(card r);
card initializeCardT(card s);

void initializeSet(set *g);

void initializeTurn(turn *t);
void initializeTurnBtn(btn *t);
void drawNextTurnBtn(btn *t, turn *turn);

void distributionCard(set *g);

void initializeImg(DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf);

void displayCard(card *x, turn *t, DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf);
void displaySet(set g, turn *t, DonneesImageRGB *zero, DonneesImageRGB *un, DonneesImageRGB *deux, DonneesImageRGB *trois, DonneesImageRGB *quatre, DonneesImageRGB *cinq, DonneesImageRGB *six, DonneesImageRGB *sept, DonneesImageRGB *huit, DonneesImageRGB *neuf, DonneesImageRGB *mini);
void flipDownCard(card *x, turn *t);
void initializeCardsGraphic(set *g);

card manageCardClicked(card x);
void manageSetClicked(set *g);

void manageClicking(turn *t);
void manageTurnButton(btn *s, turn *t);



void saveCoordinates(pt *TabCoordinates, int *nbpt, pt x);

void drawP1Score(int *score1, turn *t);
void drawP2Score(int *score2, turn *t);
void drawScore(int *scoreP1, int *scoreP2, turn *t);


void managePickedCards(set *g, pair *duo);
void validationPair(set *g, pair *duo, turn *t);

void saveSet(chaine save, set g);
void saveCoordMouse(chaine nom, pt *T2, int incre);
void savePair(chaine nom, char pair[100]);

void timeBetweenClicks(float *timer, turn *t, float *timePair);


/*---------------------------------------
-----------------PICTIONNARY-------------
---------------------------------------*/

void editorGraphics(pt souris,btn editor);
void loadCards(chaine save, setP game);
int drawCount(int ligne, int time);
/*---------------------------------------
-----------------Association-------------
---------------------------------------*/
void afficheFondIMG(void);
void afficheFondBTN(void);
void afficheNiveau(int C1,int C2,int C3, int T1, int T2, int T3);
void afficheBTN(void);
void afficheTime(float time);
void afficheCartePair(carte C1, carte C2);
void affichepairEmain(int pairEmain);
void afficheIncorect(int incorect);

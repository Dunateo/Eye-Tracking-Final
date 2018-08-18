typedef char chaine[50];

typedef struct pt{
  float x, y; //cartesian cordinates
}pt;


typedef struct symbol{
  chaine name; // associated with the img
}symbol;

typedef struct card{
  int id; // number of the card in the set
  int x1, y1, x2, y2; //graphic of the card
  int state; //0 or 1, displayed or hidden
  int count; // nb of times clicked
  int player; // 0 for unpaired, 1 paired by player 1 and 2 paired by player 2
}card;

typedef struct set{
  card A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T;
}set;

typedef struct poly{
	float a,b;
}poly;

typedef struct carte{
	pt pos;
	int num;
	DonneesImageRGB *img;
}carte;


void afficheFondIMG(void);
void afficheFondBTN(void);
void afficheNiveau(int C1,int C2,int C3, int T1, int T2, int T3);
void afficheBTN(void);
void afficheTime(float time);
void afficheCartePair(carte C1, carte C2);
void affichepairEmain(int pairEmain);
void afficheIncorect(int incorect);

void gereClicLvl(int *C1, int *C2, int *C3, int *T1, int *T2, int *T3, int *etatLvl, int *etatCache);
void gereClicLeave(void);
void gereCompt(int *etatCompt);
void gereClicReset(float *time, int *etatCompt, int *etatCache, int *pairEmain, int *etatClic, int *incorect);
void gereClicReturnMenu(float *time, int *etatCompt, int *etatCache, int *pairEmain, int *etatClic,int *incorect, int *etatmenu);
void gereClicCarte(carte c, int *etatPair, int *etatClic, int *etatCache, int *pairEmain, int *incorect);
void initialiseLvl1(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2);
void initialiseLvl2(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2);
void initialiseLvl3(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2);
void gereCache(int etatCache, carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2);
void deplacementSouris(pt **T, int j, int etatClic);
void equationPoly(poly *p, pt *T, int j);
void scoreTramblement(pt *T,poly p, float *tremb, int j,int i);
void nomTremblement(float tremb,chaine nomT);
void saveCarteLvl(carte *A1,carte *A2, carte *B1,carte *B2,carte *C1,carte *C2, carte *D1,carte *D2,carte *E1,carte *E2,carte *F1,carte *F2,carte *G1,carte *G2,carte *H1,carte *H2,carte *I1,carte *I2,carte *J1,carte *J2, chaine nomFichier);
void sauveTremb(float tremb,int incorect, chaine nomT, chaine nomFichier,float time);


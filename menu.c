#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "structures.h"
#include "gereMath.h"
#include "fichier.h"
#include "affichage.h"
#include "calcul.h"

btn initializeChoicePictionnary(void){
  btn p;

  p.r = 10;
  p.g = 10;
  p.b = 10;

  p.x1 = largeurFenetre()/8;
  p.y1 = 8*hauteurFenetre()/20;
  p.x2 = p.x1 + 4*largeurFenetre()/8;
  p.y2 = p.y1 + 3*hauteurFenetre()/8;

  return p;
}

void displayMenu(btn pictionnary, btn association, btn calibrage, btn memory, btn settings){

  traceButton(pictionnary);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GfxLib.h"
#include "imageSF.h"

static int *BVR2ARVB_sansFond(int largeur, int hauteur, const unsigned char *donnees, couleur fond)
{
	const unsigned char *ptrDonnees;
	unsigned char *pixels = (unsigned char*)malloc(largeur*hauteur*sizeof(int));
	unsigned char *ptrPixel;
	int index;
	
	ptrPixel = pixels;
	ptrDonnees = donnees;
	for
		(index = largeur*hauteur; index != 0; --index) /* On parcourt tous les
														pixels de l'image */
	{
		ptrPixel[0] = ptrDonnees[0];
		ptrPixel[1] = ptrDonnees[1];
		ptrPixel[2] = ptrDonnees[2];
		if (ptrDonnees[0] == fond.b && ptrDonnees[1] == fond.v && ptrDonnees[2] == fond.r)
			ptrPixel[3] = 0x000;
		else
			ptrPixel[3] = 0x0FF;
		ptrDonnees += 3; /* On passe a la premiere composante du pixel suivant */
		ptrPixel += 4; /* On passe au pixel suivant */
	}
	return (int*)pixels;
}

// Ecris dans la fenetre une image BVR couvrant largeur*hauteur et demarrant en (x, y) */
void ecrisImageSansFond(int x, int y, int largeur, int hauteur, const unsigned char *donnees, couleur fond)
{
	int *pixels = BVR2ARVB_sansFond(largeur, hauteur, donnees, fond);
	ecrisImageARVB(x, y, largeur, hauteur, pixels);
	free(pixels);
}

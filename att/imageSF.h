typedef struct couleur{
	unsigned char r, v, b;
	} couleur;
	
void ecrisImageSansFond(int x, int y, int largeur, int hauteur, const unsigned char *donnees, couleur fond);
// permet d'afficher une image en rendant la couleur fond transparente

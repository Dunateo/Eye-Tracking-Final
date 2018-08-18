#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "BmpLib.h"
#include "structures.h"
#include "calcul.h"

//calculus of time in seconds
float timeInSeconds(float time){
  float inter;

   inter = (time * 0.02)/20;

  return inter;
}

//calculus the numbers of line in the draw
void numbersLines(int incre, int *nbline ){

    int testing = incre + 1; //because it goes to 0 at n so we have n+1 points

    if(testing == 1){
      nbline = 0;

    }
    else{
      *nbline = (testing - 2);//because 2 points are 1 line so n points it n-1 ligne
    }

}

//calculus length of line
void lengthLine(int incre, pt **T2, lgtLine *Pict){

  pt entre;

  Pict->TL = (float *)realloc(Pict->TL, sizeof(float)*(incre+1));//we rellocate mémory for more line

  if(Pict->TL != NULL){



    for (int j = 0; j < incre-1; j++) {

      entre.x = (((*T2)[j+2].x)-((*T2)[j+1].x))*(((*T2)[j+2].x)-((*T2)[j+1].x));
      entre.y = (((*T2)[j+2].y)-((*T2)[j+1].y))*(((*T2)[j+2].y)-((*T2)[j+1].y));

      Pict->TL[j] = sqrt(entre.x + entre.y);


    }


  }

  Pict->nb = incre;


}

//calculus the average of all the line
void averageLine(lgtLine *Pict){

  float inter = 0.0, g = 0.0;

  for (int i = 0; i < Pict->nb-1 ; i++) {

    inter = Pict->TL[i]+g;
    g = inter;

  }


  Pict->moy = inter / (Pict->nb-1); //calculus of all the length


}

//ordinate the differents lengthLine
void ordinateLine(lgtLine *Pict){

    int i,j,c;

    float tab[Pict->nb] ;
    //in order to have all the line ordinate in a tab
    for (int h = 0; h < Pict->nb; h++) {
      tab[h] = Pict->TL[h];
    }

    for(j=1;j<Pict->nb-1;j++) // pour faire l'operation N fois
      for(i=0;i<Pict->nb-2;i++)
        if ( Pict->TL[i] > Pict->TL[i+1] ) {
                c = Pict->TL[i];
                tab[i] = Pict->TL[i+1];
                tab[i+1] = c;
        }


  Pict->min = tab[0];
  Pict->max = tab[Pict->nb-2];
}

//save the time for each line
void timeLine(lgtLine *Pict, float **T2){



    Pict->Time = (float *)realloc(Pict->Time, sizeof(float)*(Pict->nb+1));

    if(Pict->Time != NULL){

    for (int i = 0; i < Pict->nb-1; i++) {

      Pict->Time[i] = (*T2)[i+2] - (*T2)[i+1];

    }

  }

}

//calcul the time for all the drawing
void timeGlobal(lgtLine *Pict){

  float inter=0.0,g = 0.0;

  for (int i = 0; i < Pict->nb-1; i++) {

    inter = Pict->Time[i] +g;
    g = inter;

  }

  Pict->glob = inter;

}

//modification de l'image en noir et blanc
void pixels(DonneesImageRGB *image, DonneesImageRGB *imageNB){
  int nbP;
  int gris;
	nbP = (image->largeurImage) * (image->hauteurImage) * 3;
  imageNB->largeurImage = image->largeurImage;
  imageNB->hauteurImage = image->hauteurImage;

  for (int i = 0; i < nbP; i = i+3) {
     gris = 0.2125 * (image->donneesRGB[i+2]) + 0.7154 *  (image->donneesRGB[i+1]) + 0.0721 * (image->donneesRGB[i]);
     imageNB->donneesRGB[i] = gris;
     imageNB->donneesRGB[i+1] = gris;
     imageNB->donneesRGB[i+2] = gris;
  }

}
//gradient function and radon function
void createMatrice(DonneesImageRGB *imageNB, unsigned char **GL, unsigned char **GX ,unsigned char **GY ,unsigned char **GXY, int matriceGrad[LarImg][HauImg], int matriceRad[LarImg][HauImg][Ray], jointure *j){
	int i = 0;
	int t = 0;
	int D =0;
	int B;
	j->j[0].nb = 0;
	j->j[1].nb = 0;
	GL = (unsigned char **)malloc((imageNB->largeurImage) * sizeof(unsigned char*) );
	GX = (unsigned char **)malloc((imageNB->largeurImage) * sizeof(unsigned char*) );
	GY = (unsigned char **)malloc((imageNB->largeurImage) * sizeof(unsigned char*) );
	GXY = (unsigned char **)malloc((imageNB->largeurImage) * sizeof(unsigned char*) );

	for(int h = 0; h<(imageNB->largeurImage); h++){

		GL[h] = (unsigned char *)malloc(sizeof(unsigned char)* (imageNB->hauteurImage));
		GX[h] = (unsigned char *)malloc(sizeof(unsigned char)* (imageNB->hauteurImage));
		GY[h] = (unsigned char *)malloc(sizeof(unsigned char)* (imageNB->hauteurImage));
		GXY[h] = (unsigned char *)malloc(sizeof(unsigned char)* (imageNB->hauteurImage));
	}

	for(int y = 0; y < (imageNB->hauteurImage); y++){
		for (int x = 0; x <(imageNB->largeurImage); x++) {
			GL[x][y] = imageNB->donneesRGB[i];
			i = i+3;
		}
	}
	for (int g = 0; g < (imageNB->hauteurImage); g++) {
		//GX[0][g] = 0;
		//GY[0][g] = 0;
		GXY[0][g] = 0;
	}

	for (int h = 0; h < (imageNB->largeurImage); h++) {
		//GX[h][0] = 0;
		//GY[h][0] = 0;
		GXY[h][0] = 0;
	}

	for (int y1 = 0; y1 < (imageNB->hauteurImage); y1++) {
	 	for (int x1 = 0; x1 < (imageNB->largeurImage); x1++) {
			if(y1 != 0 && x1 != 0){
			GX[x1][y1] = abs(GL[x1][y1] - GL[x1][y1-1]);
			GY[x1][y1] = abs(GL[x1][y1] - GL[x1-1][y1]);
			GXY[x1][y1] = sqrt((GX[x1][y1])*(GX[x1][y1])+(GY[x1][y1])*(GY[x1][y1]));
		}
		if(GXY[x1][y1]>0)
		{
			imageNB->donneesRGB[t]=255;
			imageNB->donneesRGB[t+1]=255;
			imageNB->donneesRGB[t+2]=255;
			matriceGrad[x1][y1]=1;

			matriceRad[x1][y1][45]=0;
			//printf("Grad= %d Rad=%d en x=%d y=%d\n",matriceGrad[x1][y1],matriceRad[x1][y1], x1, y1);

		}else{
			imageNB->donneesRGB[t]=0;
			imageNB->donneesRGB[t+1]=0;
			imageNB->donneesRGB[t+2]=0;
			matriceGrad[x1][y1]=0;
			matriceRad[x1][y1][45]=0;

      if(x1>=0 && x1<250)
			{
				j->j[0].position[D].x=x1;
				j->j[0].position[D].y=y1;
				j->j[0].nb = j->j[0].nb+1;
				D++;
				//printf("pc1= (%f,%f) nb=%d\n",j->j[0].position[D].x=x1,j->j[0].position[D].y=y1,j->j[0].nb = j->j[0].nb);
			}else{
				j->j[1].position[B].x=x1;
				j->j[1].position[B].y=y1;
				j->j[1].nb = j->j[1].nb+1;
				B++;
				//printf("pc1= (%f,%f) nb=%d\n",j->j[1].position[D].x=x1,j->j[1].position[D].y=y1,j->j[1].nb = j->j[1].nb);
			}


			//printf("Grad= %d Rad=%d en %d\n",matriceGrad[x1][y1],matriceRad[x1][y1], x1);
		}
		t=t+3;
	 	}

	}
	//printf("rad1= %d\n",matriceGrad[243][101]);
	pointRadon(matriceGrad,matriceRad);//si radon ne marche pas utiliser : barCentre(j);
	//pointRadon(matriceGrad,matriceRad);
}

//launch the connexion with the pi
void connexion(){

	system("chmod +x connexion.sh&");
	system("/media/sf_Partage/T5/Big-Projectmg/connexion.sh&");


}

//launch the copiying of the doc on raspberry
void enregistrement(){
	system("chmod +x enregistrement.sh&");
	system("/media/sf_Partage/T5/Big-Projectmg/enregistrement.sh&");

}

//delete the etat.txt in order to do it well
  void etatTxt(){
    system("rm -rf /media/sf_Partage/T5/Big-Projectmg/Fichiers/etat.txt");
    system("rm -rf /media/sf_Partage/T5/Big-Projectmg/Fichiers/etat2.txt");
  }

//function to record the eye
void camera(int *etatcam){
  char nomFichier[19] = "Fichiers/etat.txt";

  if(*(etatcam) == 0){
    connexion();
    *(etatcam) = 1;
  }

  if(fopen(nomFichier, "rt") != NULL && *(etatcam) == 1 ){
    enregistrement();
    *(etatcam) = 2;

  }

}

//get the numbers of pictures in Vid
void NbImg (int *nb, int *etatcam)
{
    char nomFichier[19] = "Fichiers/etat2.txt";
    FILE *f = NULL;
    char c;

    if(fopen(nomFichier, "rt") != NULL && *(etatcam) == 2){

    system("ls /media/sf_Partage/T5/Big-Projectmg/Vid -A > /media/sf_Partage/T5/Big-Projectmg/Vid/pictures.txt");

    f = fopen("/media/sf_Partage/T5/Big-Projectmg/Vid/pictures.txt","rt");

    if(f != NULL)
    {
        while((c = fgetc(f)) != EOF)
        {
            if(c == '\n')
            {
                (*nb)++;
            }
        }

        (*nb) = (*nb) - 2;

        fclose(f);
    }

    else{
      fclose(f);
    }
    *(etatcam) = 3;
    }
}
//initialisation of pictures
void recupImage(int nb,DonneesImageRGB *Vid,DonneesImageRGB *VidNB, int *etatcam, unsigned char **GL, unsigned char **GX ,unsigned char **GY ,unsigned char **GXY, int matriceGrad[LarImg][HauImg], int matriceRad[LarImg][HauImg][Ray], jointure *j, FILE*f){
  char nomFichier[25];
  char nomFichierNB[25];

  if(*(etatcam) == 3){
	 for(int i=0;i<nb;i++){
     //printf("jesuislalala\n");
     sprintf(nomFichier,"Vid/%d.bmp",(i+1));
		 Vid = lisBMPRGB(nomFichier);
     VidNB = lisBMPRGB(nomFichier);
     pixels(Vid, VidNB);
     createMatrice(VidNB, GL,GX ,GY ,GXY,matriceGrad,matriceRad,j);
     registerCentre(j,f);
     sprintf(nomFichierNB,"Vid/Grad%d.bmp",(i+1));
     ecrisBMPRGB_Dans(VidNB, nomFichierNB);
     libereDonneesImageRGB(&Vid);
     libereDonneesImageRGB(&VidNB);

	}
  printf("ja fait grad\n");
  *(etatcam) = 4;

}

}

//fonction radon problème sur les valeurs négatives
void pointRadon(int matriceGrad[LarImg][HauImg], int matriceRad[LarImg][HauImg][Ray])
{
	//i keep the same rayon
	int r = 43 ;
	int XcMin = 0;
	int XcMax = 573;
	float delta;
	int X = XcMax-XcMin;
	int i=0;
	int j=0;
	int x1=0;
	equCercle C[X];
	//printf("rad= %d\n",matriceGrad[243][101]);
	//printf("entré2 Grad= %d\n",matriceGrad[0][0]);
	for(i=0;i<LarImg;i++)
	{
		//printf("entré i=%d\n",i);
		for(j=0;j<HauImg;j++)
		{
			//printf("entré2 \n");
			if(matriceGrad[i][j]==1)
			{
				//printf("entré3\n");
				for(x1=0;x1<X;x1++)
				{

					delta = 4*j*j-4*((i*i)-2*i*x1+x1*x1+j*j-(r*r));
					//printf("entré4 %f \n", delta);
					if(delta==0)
					{
						C[x1].Xc=x1;
						C[x1].r=r;
						C[x1].Yc1=-j;
					}if(delta>0)
					{
						C[x1].Xc=x1;
						C[x1].r=r;
						C[x1].Yc1=((-2*j)+sqrt(delta))/2;
						C[x1].Yc2=((-2*j)-sqrt(delta))/2;
						if(C[x1].Yc1>0 && C[x1].Yc1<131 )
							matriceRad[C[x1].Xc][C[x1].Yc1][45]=matriceRad[C[x1].Xc][C[x1].Yc1][45]+1;
						if(C[x1].Yc2>0 && C[x1].Yc2<131)
							matriceRad[C[x1].Xc][C[x1].Yc2][45]=matriceRad[C[x1].Xc][C[x1].Yc1][45]+1;
						//printf("entré5 %f Rad = %d\n en x=%d y=%d et i=%d j=%d\n", delta,matriceRad[C[x1].Xc][C[x1].Yc2][45],C[x1].Xc,C[x1].Yc1,i,j);
						//printf("entré5 %f Rad = %d\n en x=%d y2=%d et i=%d j=%d\n", delta,matriceRad[C[x1].Xc][C[x1].Yc2][45],C[x1].Xc,C[x1].Yc2,i,j);
					}else
					{
						/*C[x1].Xc=x1;
						C[x1].r=r;
						C[x1].Yc1=((-(2*j)+sqrt(-delta))/2);
						C[x1].Yc2=((-(2*j)-sqrt(-delta))/2);
						if(C[x1].Yc1>0 && C[x1].Yc1<131)
							matriceRad[C[x1].Xc][C[x1].Yc1]=matriceRad[C[x1].Xc][C[x1].Yc1]+1;
						if(C[x1].Yc2>0 && C[x1].Yc2<131)
							matriceRad[C[x1].Xc][C[x1].Yc2]=matriceRad[C[x1].Xc][C[x1].Yc1]+1;  WRONG*/
					}

				}
			}

		}

	}

}

//fonction barycentre trouve les barycentre des yeux
void barCentre(jointure *j)
{
	int i,h;

	long int somX;

	long int somY;


for(h=0;h<JOINT;h++)

	{

		somX=0;

		somY=0;

		for(i=0;i<j->j[h].nb;i++)

		{
			somX += j->j[h].position[i].x;
			somY += j->j[h].position[i].y;

			//printf(" (%d,%d)\n",somX,somY);

		}

		if(j->j[h].nb != 0)

		{

			j->j[h].centre.x=somX/j->j[h].nb;

			j->j[h].centre.y=somY/j->j[h].nb;



		}

	}
}

//enregistre dans les fichiers milieu des eyes
void registerCentre(jointure *j, FILE*f){
  //printf("jesuisla\n");
  fprintf(f,"eye1(%f,%f) eye2(%f,%f)\n",j->j[0].centre.x,j->j[0].centre.y,j->j[1].centre.x,j->j[1].centre.y);
}

//gere nloading screen
void gereJeuLoading(int *etatcam, int *hj){

  if(*(etatcam) == 5 && *(hj) == 0){
    system("cd /media/sf_Partage/T5/att/Big-Project; ./exemple&");

    *(hj) = 1;
  }

}

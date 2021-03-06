Bledsoe: exemple.o libisentlib.a affichage.o lecturecard.o collision.o calcul.o functions.o graphic.o IHM.o gereMath.o
	gcc -Wall exemple.o -o Bledsoe libisentlib.a lecturecard.o affichage.o IHM.o gereMath.o collision.o calcul.o functions.o graphic.o -lm -lglut -lGL -lX11
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall exemple.o -o exemple libisentlib.a -lm -framework OpenGL -framework GLUT

exempleTortue: exempleTortue.o libisentlib.a
	gcc -Wall exempleTortue.o -o exempleTortue libisentlib.a -lm -lglut -lGL -lX11
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall exempleTortue.o -o exempleTortue libisentlib.a -lm -framework OpenGL -framework GLUT

affichage.o: affichage.c affichage.h structures.h GfxLib.h BmpLib.h
	gcc -Wall -c affichage.c

lecturecard.o: lecturecard.c fichier.h structures.h GfxLib.h BmpLib.h
	gcc -Wall -c lecturecard.c

collision.o: calcul.h collision.c structures.h GfxLib.h BmpLib.h
	gcc -Wall -c collision.c

calcul.o: calcul.h calcul.c structures.h BmpLib.h
	gcc -Wall -c calcul.c

graphic.o : graphic.c GfxLib.h structures.h BmpLib.h
	gcc -Wall -c graphic.c

functions.o : functions.c GfxLib.h structures.h BmpLib.h
	gcc -Wall -c functions.c

gereMath.o: gereMath.c gereMath.h structures.h GfxLib.h BmpLib.h ESLib.h
	gcc -c -Wall gereMath.c

IHM.o: IHM.c structures.h gereMath.h GfxLib.h BmpLib.h ESLib.h
	gcc -c -Wall IHM.c

exemple.o: exemple.c GfxLib.h structures.h BmpLib.h ESLib.h  gereMath.h
	gcc -Wall -c exemple.c

exempleTortue.o: exempleTortue.c GfxLib.h BmpLib.h ESLib.h TortueLib.h
	gcc -Wall -c exempleTortue.c


libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ranlib libisentlib.a

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -Wall -O2 -c BmpLib.c

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	gcc -Wall -O2 -c ESLib.c

ErreurLib.o: ErreurLib.c ErreurLib.h
	gcc -Wall -O2 -c ErreurLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	gcc -Wall -O2 -c GfxLib.c -I/usr/include/GL
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c GfxLib.c -Wno-deprecated-declarations

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -Wall -O2 -c OutilsLib.c

SocketLib.o: SocketLib.c SocketLib.h
	gcc -Wall -O2 -c SocketLib.c

ThreadLib.o: ThreadLib.c ThreadLib.h
	gcc -Wall -O2 -c ThreadLib.c

TortueLib.o: TortueLib.c TortueLib.h GfxLib.h
	gcc -Wall -O2 -c TortueLib.c

VectorLib.o: VectorLib.c VectorLib.h
	gcc -Wall -O2 -c VectorLib.c -msse3

WavLib.o: WavLib.c WavLib.h OutilsLib.h
	gcc -Wall -O2 -c WavLib.c -Wno-unused-result
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c WavLib.c

zip:
	tar -cvzf libisentlib.tgz *.[ch] *.bmp *.pdf makefile

clean:
	rm -f *~ *.o

deepclean: clean
	rm -f exemple exempleTortue libisentlib.a

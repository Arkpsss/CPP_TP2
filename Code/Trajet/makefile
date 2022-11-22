
#Modele de makefile C/C++
#A utiliser pour des projets de plusieurs fichiers
#A adapter au besoin

# version évoluée avec variables et patterns

#Variables (mettre @ devant une commande pour la passer en mode silencieux)
ECHO = echo
GCC = g++ #gcc
CCFLAGS = -c -g -ansi -pedantic -Wall -std=c++11 -DMAP#-c -O1 # debug : -c -g
OBJETS = main.o Trajet.o TrajetSimple.o
EXE = main
LIBRAIRIES = #-lm

#Règles


#Creation executable -> linker
$(EXE) : $(OBJETS)
	$(GCC) -o $(EXE) $(OBJETS) $(LIBRAIRIES)


#Creation fichier binaire -> compilation
%.o : %.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

TrajetSimple.o : TrajetSimple.h Trajet.h
main.o : Trajet.h TrajetSimple.h
Trajet.o : Trajet.h


#Nettoyage
clean :
	rm -f $(OBJETS) $(EXE)

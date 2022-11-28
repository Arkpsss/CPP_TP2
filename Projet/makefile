
#Modele de makefile C/C++
#A utiliser pour des projets de plusieurs fichiers
#A adapter au besoin

# version évoluée avec variables et patterns

#Variables (mettre @ devant une commande pour la passer en mode silencieux)
ECHO = echo
GCC = g++ #gcc
CCFLAGS = -c -g -ansi -pedantic -Wall -std=c++11 -DMAP#-c -O1 # debug : -c -g
OBJETS = main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o LinkedList.o Catalogue.o Terminal.o
EXE = main
LIBRAIRIES = #-lm

#Règles


#Creation executable -> linker
$(EXE) : $(OBJETS)
	$(GCC) -o $(EXE) $(OBJETS) $(LIBRAIRIES)


#Creation fichier binaire -> compilation
%.o : Modele/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

%.o : Vue/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

%.o : Controleur/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

TrajetSimple.o : Modele/TrajetSimple.h Modele/Trajet.h
main.o : Modele/Trajet.h Modele/TrajetSimple.h
Trajet.o : Modele/Trajet.h
TrajetCompose.o : Modele/TrajetCompose.h Modele/Trajet.h
Element.o : Modele/Element.h Modele/Trajet.h
LinkedList.o : Modele/LinkedList.h Modele/Element.h
Catalogue.o : Controleur/Catalogue.h Modele/LinkedList.h
Terminal.o : Vue/Terminal.h Controleur/Catalogue.h



#Nettoyage
clean :
	rm -f $(OBJETS) $(EXE)

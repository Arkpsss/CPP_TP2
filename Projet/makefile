
#Modele de makefile C/C++
#A utiliser pour des projets de plusieurs fichiers
#A adapter au besoin

# version évoluée avec variables et patterns

#Variables (mettre @ devant une commande pour la passer en mode silencieux)
ECHO = echo
GCC = g++ #gcc
CCFLAGS = -c -g -ansi -pedantic -Wall -std=c++11 #-DMAP#-c -O1 # debug : -c -g
OBJETS = main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o LinkedList.o Catalogue.o Terminal.o fonction_string.o
EXE = trajet
LIBRAIRIES = #-lm

#Règles


#Creation executable -> linker
$(EXE) : $(OBJETS)
	$(GCC) -o $(EXE) $(OBJETS) $(LIBRAIRIES)


#Creation fichier binaire -> compilation
%.o : %.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

%.o : Modele/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

%.o : Vue/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

%.o : Controleur/%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $<

TrajetSimple.o : Modele/TrajetSimple.h Modele/Trajet.h Modele/fonction_string.h
main.o : Modele/Trajet.h Modele/TrajetSimple.h
Trajet.o : Modele/Trajet.h Modele/fonction_string.h
TrajetCompose.o : Modele/TrajetCompose.h Modele/Trajet.h Modele/LinkedList.h Modele/fonction_string.h
Element.o : Modele/Element.h Modele/Trajet.h
LinkedList.o : Modele/LinkedList.h Modele/Element.h Modele/fonction_string.h
Catalogue.o : Controleur/Catalogue.h Modele/LinkedList.h Modele/Trajet.h
Terminal.o : Vue/Terminal.h Controleur/Catalogue.h Modele/Trajet.h Modele/TrajetSimple.h Modele/TrajetCompose.h Modele/fonction_string.h
fonction_string.o : Modele/fonction_string.h



#Nettoyage
clean :
	rm -f $(OBJETS) $(EXE)

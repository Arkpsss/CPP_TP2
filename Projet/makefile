#Variables 
ECHO = echo
GCC = g++ 
CCFLAGS = -c -ansi -pedantic -Wall -std=c++11
OBJETS = main.o Trajet.o TrajetSimple.o TrajetCompose.o Element.o LinkedList.o Catalogue.o Terminal.o fonction_string.o
EXE = trajets
LIBRAIRIES = #-lm

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

#Règles
TrajetSimple.o : Modele/TrajetSimple.h Modele/Trajet.h Modele/fonction_string.h
main.o : Modele/Trajet.h Modele/TrajetSimple.h
Trajet.o : Modele/Trajet.h Modele/fonction_string.h
TrajetCompose.o : Modele/TrajetCompose.h Modele/Trajet.h Modele/LinkedList.h Modele/fonction_string.h
Element.o : Modele/Element.h Modele/Trajet.h
LinkedList.o : Modele/LinkedList.h Modele/Element.h Modele/fonction_string.h
Catalogue.o : Controleur/Catalogue.h Modele/LinkedList.h Modele/Trajet.h
Terminal.o : Vue/Terminal.h Controleur/Catalogue.h Modele/Trajet.h Modele/TrajetSimple.h Modele/TrajetCompose.h Modele/fonction_string.h
fonction_string.o : Modele/fonction_string.h

.PHONY : clean, debug
#Nettoyage
clean :
	rm -f $(OBJETS) $(EXE)

#Mode debug
debug : CCFLAGS += -DMAP -g
debug : $(EXE)

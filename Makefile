#Programme à créer
PROG = projet

#Sources
SRC = main.c creation_personnage.c combat.c affichage.c

#Regle par defaut
all: $(PROG)
	./$(PROG)

#compilation
$(PROG): $(SRC) head.h
	gcc -o $(PROG) $(SRC)

#Nettoyage
clean :
rm -f $(PROG)

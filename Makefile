# Nom de l'exécutable
TARGET = cymon

# Fichiers source
SRC = main.c Biblio_lin.c crea_persov2.c combat.c

# Fichiers objets (.o)
OBJ = $(SRC:.c=.o)

# En-têtes
HEADERS = Biblio_lin.h creapers.h combat.h

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g

# Librairies (SDL2 ou autre si besoin)
LDFLAGS = $(shell sdl2-config --libs)
INCLUDES = $(shell sdl2-config --cflags)

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation des .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET)

# Pour forcer re-compilation
re: clean all

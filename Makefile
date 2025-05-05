# Nom de l'exécutable
TARGET = cymon

# Fichiers source
SRC = main.c Biblio_lin.c crea_persov2.c combat.c affichagevs.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g $(shell sdl2-config --cflags)

# Librairies à linker
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Règle pour compiler un fichier .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild complet
re: clean all

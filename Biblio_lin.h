#ifndef BIBLIO_LIN_H
#define BIBLIO_LIN_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <SDL2/SDL.h>

#define couleur(param) printf("\033[%sm",param)

typedef enum {
    Nitrocharge, Abri, Feu_Follet, Flammeche, Griffe, Close_Combat, Danse_lame,
    Aboiement, Choc_Mental, Repos, Plenitude, Psyko, Crocs_givre, Laser_glace,
    Douche_froide, Feuillage, Giga_sangsue, Tranche, Balayage, Gonflette,
    Poison_croix, Osmerang, Queue_de_fer, Seisme, Mur_de_fer, Eclair, Cage_eclair,
    Pistolet_a_O, Surf, Draco_griffe, Abattage, Danse_draco, Tonnerre, Electacle
} Competence_spe;

typedef enum {
    Neutre, Brulure, Gel, Empoisonnement, Paralysie, Sommeil, KO
} Statut;

typedef enum {
    Normal, Feu, Eau, Plante, Electrik, Glace, Combat, Poison, Sol, Vol, Psy,
    Insecte, Roche, Spectre, Dragon, Tenebres, Acier, Fee
} Type;

typedef struct {
    Competence_spe comp;
    int cooldown;
    int cooldownmax;
    Type type;
    int puissance;
    int precision;
} Comp;

typedef struct {
    char nom_poke[30];
    int numero;
    float pv_courant;
    float pv_max;
    int attaque;
    int defense;
    int agilite;
    int vitesse;
    float précision;
    int protec;
    int sleep;
    Statut etat;
    Comp atkbase;
    Comp spe1;
    Comp spe2;
    Comp spe3;
    Type t;
    int speedbar;
} Pokemon;
int compare_chaine(char* un, char* deux);
void aff_char(char* tab);
char* get_comp_name(Competence_spe comp);
Competence_spe get_comp_from_name(char* name);
Type get_type_from_name(char* name);
char* read_ligne_char(FILE* fichier, int nbligne);
int read_ligne_int(FILE* fichier, int nbligne);
float read_ligne_float(FILE* fichier, int nbligne);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <SDL2/SDL.h>
#define couleur(param) printf("\033[%sm",param)
int compare_chaine(char* un, char* deux){//testé
    int i=0;
    int iun=0;
    int ideux=0;
    while(un[iun]!='\0'){
        iun++;
    }
    while(deux[ideux]!='\0'){
        ideux++;
    }
    while((un[i]!='\0') && (deux[i]!='\0')){
        if(un[i]!=deux[i]){
            return -1;
        }
        i++;
    }
    if(i==iun && iun==ideux){
        return 0;
    }
    return -1;
}
void aff_char(char* tab){
    int i=0;
    while(tab[i]!='\0'){
        printf("%c", tab[i]);
        i++;
    }
}
//attaques speciales
typedef enum{
    Nitrocharge, Abri, Feu_Follet, Flammeche, Griffe, Close_Combat, Danse_lame, Aboiement, Choc_Mental, Repos, Plenitude, Psyko, Crocs_givre, Laser_glace, Douche_froide, Feuillage, Giga_sangsue, Vive_attaque, Balayage, Gonflette, Poison_croix, Osmerang, Queue_de_fer, Seisme, Mur_de_fer, Eclair, Cage_eclair, Pistolet_a_O, Surf, Draco_griffe, Abattage, Danse_draco
}Competence_spe;
//attaques de bases
//statut du pokemon
typedef enum{
    Neutre, Brulure, Gel, Empoisonnement, Paralysie, Sommeil, KO
}Statut;

//les types possibles
typedef enum{
    Normal, Feu, Eau, Plante, Electrik, Glace, Combat, Poison, Sol, Vol, Psy, Insecte, Roche, Spectre, Dragon, Tenebres, Acier, Fee
}Type;
typedef struct{
    Competence_spe comp;
    int cooldown;//0 a l'instant t=0s
    int cooldownmax; //si pp=5 10 tours si 10 5 tours etc
    Type type;
    int puissance;
    int precision;
}Comp;
//stats du pokemon
typedef struct{
    char nom_poke[30];
    int numero;
    float pv_courant;//= a pv_max a l'instant t=0s
    float pv_max;
    int attaque;
    int defense;
    int agilite;
    int vitesse;
    float précision;
    int protec;//0 a l'instant t=0s
    int sleep;//0 a l'instant t=0s
    Statut etat;
    Comp atkbase;//les attaques de base sont des attaques speciale avec un cooldownn de 0 (par souci de facilite)
    Comp spe1;
    Comp spe2;
    Comp spe3;
    Type t;
    int speedbar;//0 a l'instant t=0s
}Pokemon;
char* get_comp_name(Competence_spe comp){
    switch(comp){
        case Nitrocharge:       return "Nitrocharge";
        case Abri:              return "Abri";
        case Feu_Follet:        return "Feu_Follet";
        case Flammeche:         return "Flammeche";
        case Griffe:            return "Griffe";
        case Close_Combat:      return "Close_Combat";
        case Danse_lame:        return "Danse_lame";
        case Aboiement:         return "Aboiement";
        case Choc_Mental:       return "Choc_Mental";
        case Repos:             return "Repos";
        case Plenitude:         return "Plenitude";
        case Psyko:             return "Psyko";
        case Crocs_givre:       return "Crocs_givre";
        case Laser_glace:       return "Laser_glace";
        case Douche_froide:     return "Douche_froide";
        case Feuillage:         return "Feuillage";
        case Giga_sangsue:      return "Giga_sangsue";
        case Vive_attaque:      return "Vive_attaque";
        case Balayage:          return "Balayage";
        case Gonflette:         return "Gonflette";
        case Poison_croix:      return "Poison_croix";
        case Osmerang:          return "Osmerang";
        case Queue_de_fer:      return "Queue_de_fer";
        case Seisme:            return "Seisme";
        case Mur_de_fer:        return "Mur_de_fer";
        case Eclair:            return "Eclair";
        case Cage_eclair:       return "Cage_eclair";
        case Pistolet_a_O:      return "Pistolet_a_O";
        case Surf:              return "Surf";
        case Draco_griffe:      return "Draco_griffe";
        case Abattage:          return "Abattage";
        case Danse_draco:       return "Danse_draco";
        default:                return "Inconnu";
    }
}
Competence_spe get_comp_from_name(char* name) {
    if (compare_chaine(name, "Nitrocharge") == 0)      return Nitrocharge;
    if (compare_chaine(name, "Abri") == 0)             return Abri;
    if (compare_chaine(name, "Feu_Follet") == 0)       return Feu_Follet;
    if (compare_chaine(name, "Flammeche") == 0)        return Flammeche;
    if (compare_chaine(name, "Griffe") == 0)           return Griffe;
    if (compare_chaine(name, "Close_Combat") == 0)     return Close_Combat;
    if (compare_chaine(name, "Danse_lame") == 0)       return Danse_lame;
    if (compare_chaine(name, "Aboiement") == 0)        return Aboiement;
    if (compare_chaine(name, "Choc_Mental") == 0)      return Choc_Mental;
    if (compare_chaine(name, "Repos") == 0)            return Repos;
    if (compare_chaine(name, "Plenitude") == 0)        return Plenitude;
    if (compare_chaine(name, "Psyko") == 0)            return Psyko;
    if (compare_chaine(name, "Crocs_givre") == 0)      return Crocs_givre;
    if (compare_chaine(name, "Laser_glace") == 0)      return Laser_glace;
    if (compare_chaine(name, "Douche_froide") == 0)    return Douche_froide;
    if (compare_chaine(name, "Feuillage") == 0)        return Feuillage;
    if (compare_chaine(name, "Giga_sangsue") == 0)     return Giga_sangsue;
    if (compare_chaine(name, "Vive_attaque") == 0)     return Vive_attaque;
    if (compare_chaine(name, "Balayage") == 0)         return Balayage;
    if (compare_chaine(name, "Gonflette") == 0)        return Gonflette;
    if (compare_chaine(name, "Poison_croix") == 0)     return Poison_croix;
    if (compare_chaine(name, "Osmerang") == 0)         return Osmerang;
    if (compare_chaine(name, "Queue_de_fer") == 0)     return Queue_de_fer;
    if (compare_chaine(name, "Seisme") == 0)           return Seisme;
    if (compare_chaine(name, "Mur_de_fer") == 0)       return Mur_de_fer;
    if (compare_chaine(name, "Eclair") == 0)           return Eclair;
    if (compare_chaine(name, "Cage_eclair") == 0)      return Cage_eclair;
    if (compare_chaine(name, "Pistolet_a_O") == 0)     return Pistolet_a_O;
    if (compare_chaine(name, "Surf") == 0)             return Surf;
    if (compare_chaine(name, "Draco_griffe") == 0)     return Draco_griffe;
    if (compare_chaine(name, "Abattage") == 0)         return Abattage;
    if (compare_chaine(name, "Danse_draco") == 0)      return Danse_draco;
    return -1; // Flop
}

Type get_type_from_name(char* name) {
    if (compare_chaine(name, "Normal") == 0)    return Normal;
    if (compare_chaine(name, "Feu") == 0)       return Feu;
    if (compare_chaine(name, "Eau") == 0)       return Eau;
    if (compare_chaine(name, "Plante") == 0)    return Plante;
    if (compare_chaine(name, "Electrik") == 0)  return Electrik;
    if (compare_chaine(name, "Glace") == 0)     return Glace;
    if (compare_chaine(name, "Combat") == 0)    return Combat;
    if (compare_chaine(name, "Poison") == 0)    return Poison;
    if (compare_chaine(name, "Sol") == 0)       return Sol;
    if (compare_chaine(name, "Vol") == 0)       return Vol;
    if (compare_chaine(name, "Psy") == 0)       return Psy;
    if (compare_chaine(name, "Insecte") == 0)   return Insecte;
    if (compare_chaine(name, "Roche") == 0)     return Roche;
    if (compare_chaine(name, "Spectre") == 0)   return Spectre;
    if (compare_chaine(name, "Dragon") == 0)    return Dragon;
    if (compare_chaine(name, "Tenebres") == 0)  return Tenebres;
    if (compare_chaine(name, "Acier") == 0)     return Acier;
    if (compare_chaine(name, "Fee") == 0)       return Fee;
    return -1; //Flop
}


char* read_ligne_char(FILE* fichier, int nbligne){
    rewind(fichier);
    int j=0;
    char ligne[100];
    char poubelle[100];
    char* copie = malloc(sizeof(char)*100);
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }

    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        printf("Erreur de lecture\n");
        exit(1);
    }
    for(int i=0; i<100; i++){
        *(copie+i)=' ';
    }
    while(j<100 && ligne[j]!='\n'){
        *(copie+j)=ligne[j];
        j++;
    }
    *(copie+j)='\0';
    return copie;
}
int read_ligne_int(FILE* fichier, int nbligne){
    rewind(fichier);
    int result=0;
    char poubelle[100];
    char* copie = malloc(sizeof(char)*100);
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }
    if (fscanf(ligne, "%d", &result) == 0) {
        printf("Erreur\n");
        exit(1);
    }
    return result;
}
float read_ligne_float(FILE* fichier, int nbligne){
    rewind(fichier);
    float result=0;
    char poubelle[100];
    char* copie = malloc(sizeof(char)*100);
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }
    if (fscanf(ligne, "%f", &result) == 0) {
        printf("Erreur\n");
        exit(1);
    }
    return result;
}

#include "head.h"

//attaques speciales
typedef enum{
  Nitrocharge, Abri, Feu_Follet
}competence_spe;

//attaques de bases
typedef enum{
  Flammeche
}attaque_base;

//statut du pokemon
typedef enum{
  Neutre, Brulure, Gel, Empoisonnement, Paralysie, Sommeil
}statut;

//les types possibles
typedef enum{
  Normal, Feu, Eau, Plante, Electrik, Glace, Combat, Poison, Sol, Vol, Psy, Insecte, Roche, Spectre, Dragon, Tenebres, Acier, Fee
}type;

//stats du pokemon
typedef struct{
  int pv_courant;
  int pv_max;
  int attaque;
  int defense;
  int agilite;
  int vitesse;
  statut etat;
  attaque_base atk1;
  competence_spe spe1;
  competence_spe spe2;
  competence_spe spe3;
  type t;
}pokemon;

pokemon* create_poke(){
  pokemon* p;
  char nom[30];
  do{
    printf("Rentrez le nom du pokemon choisi avec une majuscule au debut : ");
    scanf(" %s", nom);
  }while(nom != "Arcanin");

  if(nom == "Arcanin"){
    FILE* fichier;
    fopen = ("arcanin.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
    char nom_fichier[30];
        int pv, attaque, defense, vitesse;
        char type_str[20];
        char atk1_str[20], spe1_str[20], spe2_str[20], spe3_str[20];
        fscanf(fichier, "%s", nom_fichier);
        fscanf(fichier, "%d", &pv);
        fscanf(fichier, "%d", &attaque);
        fscanf(fichier, "%d", &defense);
        fscanf(fichier, "%d", &vitesse);
        fscanf(fichier, "%s", type_str);
        fscanf(fichier, "%s", atk1_str);
        fscanf(fichier, "%s", spe1_str);
        fscanf(fichier, "%s", spe2_str);
        fscanf(fichier, "%s", spe3_str);
        fclose(fichier);
        // Affectation des stats
        p->pv_courant = pv;
        p->pv_max = pv;
        p->attaque = attaque;
        p->defense = defense;
        p->vitesse = vitesse;
        p->agilite = 0;
        p->etat = Neutre;
        // Affectation des attaques
        p->atk1 = Flammeche;
        // Affectation des compétences spéciales
        p->spe1 = Nitrocharge;
        p->spe2 = Abri;
        p->spe3 = Feu_Follet;
        // Type du Pokémon
        p->t = Feu;
    }
  }
}

pokemon* create1(){
  pokemon* p;
  char nom[30];
  do{
    printf("Voici tous les pokemon disponibles (...)\n");
    printf("Rentrez le nom du pokemon choisi avec une majuscule au debut : ");
    scanf(" %s", nom);
  }while(nom != "Arcanin");

  if(nom == "Arcanin"){
    FILE* fichier;
    fopen = ("arcanin.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
    //appel fontion

}

void create2(FILE* fichier, char* nom_poke){

}

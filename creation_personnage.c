#include "head.h"

//attaques speciales
typedef enum{
  //à définir
}competence_spe;

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
  competence_spe spe;
  statut etat;
  type t;
}pokemon;

pokemon* create_poke(){
  pokemon* p;
  //pv max entre 100 et 250
  p->pv_max = (rand()%(250-101)) + 100;
  p->pv_courant = p->pv_max;
  //attaque et defense de base entre 50 et 100
  p->attaque = (rand()%(100-51)) + 50;
  p->defense = (rand()%(100-51)) + 50;
  //agilite entre 1 et 50
  p->agilite = (rand()%50) + 1;
  //vitesse entre 30 et 130
  p->vitesse = (rand()%(130-31)) + 30;
  do{
    printf("Ecrivez le type que vous voulez que votre pokemon ait parmis :\n
}

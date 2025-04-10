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
  char nom_poke[30];
  int numero;
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

//ancienne version de la fonction
pokemon* create_poke(int numero){
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
  return p;
}

//on pourrait mettre aussi en arugment de la fonction la structure pokemon pour utiliser son nom
void create_part2_poke(pokemon* p, char* nom_poke){
  if(nom_poke == "Arcanin"){
    // Affectation des attaques
    p->atk1 = Flammeche;
    // Affectation des compétences spéciales
    p->spe1 = Nitrocharge;
    p->spe2 = Abri;
    p->spe3 = Feu_Follet;
    // Type du Pokémon
    p->t = Feu;
  }
  else if(nom_poke == "Pikachu"){
    //
  }
  else if(nom_poke == "Gardevoir"){
    //
  }
  else if(nom_poke == "Tortank"){
    //
  }
  else if(nom_poke == "Jungko"){
    //
  }
  else if(nom_poke == "Mackogneur"){
    //
  }
  else if(nom_poke == "Absol"){
    //
  }
  else if(nom_poke == "Noctunoir"){
    //
  }
  else if(nom_poke == "Oniglali"){
    //
  }
  else{
    printf("Erreur dans la creation de personage\n");
    exit(2);
  }

}

pokemon* create_part1_poke_joueur(int* numero){
  pokemon* p;
  char nom[30];
  do{
    printf("Voici tous les pokemon disponibles : Arcanin, Pikachu, Tortank, Gardevoir, Absol, Mackogneur\n");
    printf("Rentrez le nom du pokemon choisi avec une majuscule au debut : ");
    scanf(" %s", nom);
  }while(nom != "Arcanin");
  FILE* fichier;
  p->numero = *numero;
  (*numero)++;
  if(nom == "Arcanin"){
    fichier = fopen("arcanin.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  p->nom_poke = nom;
  create_part2_poke(fichier, p->nom_poke);
  fclose(fichier);
  return p;
}


pokemon* create_part1_poke_ordi(int* numero){
  pokemon* p;
  int n;
  char nom[30];
  FILE* fichier;
  p->numero = *numero;
  (*numero)++;
  // si on part du principe qu'on ait 10 pokemon
  n = rand()%10;
  if(n == 0){
    fichier = fopen("arcanin.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    p->nom_poke = nom;
    create_part2_poke(fichier, p->nom_poke);
  }
  //pareil pour tous les n jusqu'a 9
  fclose(fichier);
  return p;
}

pokemon** create_team_joueur(int* numero){
  pokemon** team = malloc(3*sizeof(pokemon*));
  for(int i = 0; i < 3; i++){
    team[i] = create_part1_poke_joueur(*numero);
  }
  return team;
}

pokemon** create_team_ordi(int* numero){
  pokemon** team = malloc(3*sizeof(pokemon*));
  for(int i = 0; i < 3; i++){
    team[i] = create_part1_poke_ordi(*numero);
  }
  return team;
}

#include "Biblio_lin.h"
#include "affichagevs.h"
#include "creapers.h"
void crea_comp(Comp* comp, Competence_spe comp_spe){
  comp->comp = comp_spe;
  comp->cooldown = 0;

  if (comp_spe == Nitrocharge) {
      comp->cooldownmax = 3;
      comp->type = Feu;
      comp->puissance = 50;
      comp->precision = 100;
  }
  if (comp_spe == Abri) {
      comp->cooldownmax = 5;
      comp->type = Normal;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Feu_Follet) {
      comp->cooldownmax = 4;
      comp->type = Feu;
      comp->puissance = 0;
      comp->precision = 85;
  }
  if (comp_spe == Flammeche) {
      comp->cooldownmax = 0;
      comp->type = Feu;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Griffe) {
      comp->cooldownmax = 0;
      comp->type = Normal;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Close_Combat) {
      comp->cooldownmax = 10;
      comp->type = Combat;
      comp->puissance = 120;
      comp->precision = 100;
  }
  if (comp_spe == Danse_lame) {
      comp->cooldownmax = 5;
      comp->type = Normal;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Aboiement) {
      comp->cooldownmax = 3;
      comp->type = Tenebres;
      comp->puissance = 55;
      comp->precision = 95;
  }
  if (comp_spe == Choc_Mental) {
      comp->cooldownmax = 0;
      comp->type = Psy;
      comp->puissance = 50;
      comp->precision = 100;
  }
  if (comp_spe == Repos) {
      comp->cooldownmax = 10;
      comp->type = Psy;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Plenitude) {
      comp->cooldownmax = 4;
      comp->type = Psy;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Psyko) {
      comp->cooldownmax = 5;
      comp->type = Psy;
      comp->puissance = 90;
      comp->precision = 100;
  }
  if (comp_spe == Crocs_givre) {
      comp->cooldownmax = 0;
      comp->type = Glace;
      comp->puissance = 50;
      comp->precision = 95;
  }
  if (comp_spe == Laser_glace) {
      comp->cooldownmax = 5;
      comp->type = Glace;
      comp->puissance = 90;
      comp->precision = 100;
  }
  if (comp_spe == Douche_froide) {
      comp->cooldownmax = 5;
      comp->type = Eau;
      comp->puissance = 50;
      comp->precision = 90;
  }
  if (comp_spe == Feuillage) {
      comp->cooldownmax = 0;
      comp->type = Plante;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Giga_sangsue) {
      comp->cooldownmax = 6;
      comp->type = Plante;
      comp->puissance = 75;
      comp->precision = 100;
  }
  if (comp_spe == Tranche) {
      comp->cooldownmax = 2;
      comp->type = Normal;
      comp->puissance = 70;
      comp->precision = 100;
  }
  if (comp_spe == Balayage) {
      comp->cooldownmax = 0;
      comp->type = Combat;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Gonflette) {
      comp->cooldownmax = 5;
      comp->type = Combat;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Poison_croix) {
      comp->cooldownmax = 3;
      comp->type = Poison;
      comp->puissance = 70;
      comp->precision = 100;
  }
  if (comp_spe == Osmerang) {
      comp->cooldownmax = 0;
      comp->type = Sol;
      comp->puissance = 70;
      comp->precision = 90;
  }
  if (comp_spe == Queue_de_fer) {
      comp->cooldownmax = 4;
      comp->type = Acier;
      comp->puissance = 100;
      comp->precision = 75;
  }
  if (comp_spe == Seisme) {
      comp->cooldownmax = 10;
      comp->type = Sol;
      comp->puissance = 100;
      comp->precision = 100;
  }
  if (comp_spe == Mur_de_fer) {
      comp->cooldownmax = 4;
      comp->type = Acier;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Eclair) {
      comp->cooldownmax = 0;
      comp->type = Electrik;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Cage_eclair) {
      comp->cooldownmax = 4;
      comp->type = Electrik;
      comp->puissance = 0;
      comp->precision = 90;
  }
  if (comp_spe == Pistolet_a_O) {
      comp->cooldownmax = 0;
      comp->type = Eau;
      comp->puissance = 40;
      comp->precision = 100;
  }
  if (comp_spe == Surf) {
      comp->cooldownmax = 10;
      comp->type = Eau;
      comp->puissance = 90;
      comp->precision = 100;
  }
  if (comp_spe == Draco_griffe) {
      comp->cooldownmax = 0;
      comp->type = Dragon;
      comp->puissance = 80;
      comp->precision = 100;
  }
  if (comp_spe == Abattage) {
      comp->cooldownmax = 6;
      comp->type = Dragon;
      comp->puissance = 120;
      comp->precision = 100;
  }
  if (comp_spe == Danse_draco) {
      comp->cooldownmax = 6;
      comp->type = Dragon;
      comp->puissance = 0;
      comp->precision = 100;
  }
  if (comp_spe == Tonnerre) {
    comp->cooldownmax = 5;
    comp->type = Electrik;
    comp->puissance = 90;
    comp->precision = 100;
  }
  if (comp_spe == Electacle) {
    comp->cooldownmax = 6;
    comp->type = Electrik;
    comp->puissance = 120;
    comp->precision = 100;
  }
}
//on pourrait mettre aussi en arugment de la fonction la structure pokemon pour utiliser son nom
void create_part2_poke(FILE* file, Pokemon* poke, int* nb){
  poke->numero=*nb;
  poke->sleep=0;
  poke->protec=0;
  poke->speedbar=0;
  poke->etat=Neutre;
  poke->précision=rand()%11+90;
  poke->pv_max=read_ligne_float(file, 2);
  poke->pv_courant=poke->pv_max;
  poke->attaque=read_ligne_int(file, 3);
  poke->defense=read_ligne_int(file, 4);
  poke->vitesse=read_ligne_int(file, 5);
  poke->agilite=(poke->vitesse)/5;
  poke->t=get_type_from_name(read_ligne_char(file, 6));
  crea_comp(&(poke->atkbase), get_comp_from_name(read_ligne_char(file, 7)));
  crea_comp(&(poke->spe1), get_comp_from_name(read_ligne_char(file, 8)));
  crea_comp(&(poke->spe2), get_comp_from_name(read_ligne_char(file, 9)));
  crea_comp(&(poke->spe3), get_comp_from_name(read_ligne_char(file, 10)));
}

Pokemon* create_part1_poke_joueur(int* numero, int unoudeux){
  Pokemon* p = malloc(sizeof(Pokemon));
  char* nom=malloc(30*sizeof(char));
  FILE* fichier;
  int x=0;
  int y=0;
  SDL_Window* window2 = NULL;
  SDL_Renderer* renderer2 = NULL;
  SDL_Surface* surface2 = NULL;
  SDL_Surface* icon2 = NULL;
  SDL_Texture* texture2_2 = NULL;
  if (!p) {
    printf("Erreur d'allocation mémoire\n");
    exit(1);
  }  
  do{
    if(unoudeux==1){
      aff_fenetre(3, window2, renderer2, surface2, icon2, texture2_2, &nom);
    }
    else if(unoudeux==2){
      aff_fenetre(5, window2, renderer2, surface2, icon2, texture2_2, &nom);
    }
    else if(unoudeux==3){
      aff_fenetre(6, window2, renderer2, surface2, icon2, texture2_2, &nom);
    }
    close_sdl(surface2, window2, renderer2, texture2_2, NULL);
  }while(compare_chaine("Arcanin", nom)!=0 && compare_chaine("Pikachu", nom)!=0 && compare_chaine("Tortank", nom)!=0 && compare_chaine("Gardevoir", nom)!=0 && compare_chaine("Absol", nom)!=0 && compare_chaine("Mackogneur", nom)!=0 && compare_chaine("Givrali", nom)!=0 && compare_chaine("Jungko", nom)!=0 && compare_chaine("Ossatueur", nom)!=0 && compare_chaine("Tranchodon", nom)!=0 );
  printf("Pokémon Validé\n");
  p->numero = *numero;
  strcpy(p->nom_poke,nom);
  (*numero)++;
  close_sdl(surface2, window2, renderer2, texture2_2, NULL);
  aff_fenetre(4, window2, renderer2, surface2, icon2, texture2_2, NULL);
  if(compare_chaine("Arcanin", nom)==0){
    fichier = fopen("arcanin.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Pikachu", nom)==0){
    fichier = fopen("pikachu.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Tortank", nom)==0){
    fichier = fopen("tortank.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Absol", nom)==0){
    fichier = fopen("absol.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Gardevoir", nom)==0){
    fichier = fopen("gardevoir.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }else if(compare_chaine("Givrali", nom)==0){
    fichier = fopen("givrali.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Jungko", nom)==0){
    fichier = fopen("jungko.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }else if(compare_chaine("Mackogneur", nom)==0){
    fichier = fopen("mackogneur.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  else if(compare_chaine("Ossatueur", nom)==0){
    fichier = fopen("ossatueur.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }else if(compare_chaine("Tranchodon", nom)==0){
    fichier = fopen("tranchodon.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier\n");
      exit(1);
    }
  }
  create_part2_poke(fichier, p, numero);
  fclose(fichier);
  (*numero)++;
  free(nom);
  return p;
}


Pokemon* create_part1_poke_ordi(int* numero){
  Pokemon* p = malloc(sizeof(Pokemon));
  if (!p) {
    printf("Erreur d'allocation mémoire\n");
    exit(1);
  }
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
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 1){
    fichier = fopen("absol.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 2){
    fichier = fopen("gardevoir.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 3){
    fichier = fopen("givrali.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 4){
    fichier = fopen("jungko.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 5){
    fichier = fopen("mackogneur.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 6){
    fichier = fopen("ossatueur.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 7){
    fichier = fopen("pikachu.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 8){
    fichier = fopen("tortank.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  else if(n == 9){
    fichier = fopen("tranchodon.txt", "r");
    if(fichier == NULL){
      printf("Erreur d'ouverture de fichier \n");
      exit(1);
    }
    fscanf(fichier, "%s", nom);
    for(int k=0; k<30; k++){
        p->nom_poke[k] = nom[k];
    }
    create_part2_poke(fichier, p, numero);
  }
  fclose(fichier);
  (*numero)++;
  return p;
}

Pokemon** create_team_joueur(int* numero, int unoudeux){
  Pokemon** team = malloc(3*sizeof(Pokemon*));
  for(int i = 0; i < 3; i++){
    team[i] = create_part1_poke_joueur(numero, unoudeux);
  }
  return team;
}

Pokemon** create_team_ordi(int* numero){
  Pokemon** team = malloc(3*sizeof(Pokemon*));
  for(int i = 0; i < 3; i++){
    team[i] = create_part1_poke_ordi(numero);
  }
  return team;
}

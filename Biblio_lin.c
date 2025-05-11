#include "Biblio_lin.h"
int compare_chaine(char* un, char* deux){//testé Sert à comparer deux chaine de caractère (c'était absolument nécessaire dans la version sur le terminal)
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
void aff_char(char* tab){//affiche un str (c'était absolument nécessaire dans la version sur le terminal)
    int i=0;
    while(tab[i]!='\0'){
        printf("%c", tab[i]);
        i++;
    }
}
char* get_comp_name(Competence_spe comp){//Sert à obtenir une chaine de caracteres d'une Comp plutôt qu'un int
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
        case Tranche:      return "Tranche";
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
        case Tonnerre:           return "Tonnerre";
        case Electacle:         return "Electacle";
        default:                return "Inconnu";
    }
}
Competence_spe get_comp_from_name(char* name) {//Fais l'inverse de la fonction précédente (servait au entrer utilisateur dans le terminal)
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
    if (compare_chaine(name, "Tranche") == 0)     return Tranche;
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
    if (compare_chaine(name, "Tonnerre") == 0)          return Tonnerre;
    if (compare_chaine(name, "Electacle") == 0)        return Electacle;
    return -1; // Flop
}

Type get_type_from_name(char* name) {//comme en haut mais avec des types
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


char* read_ligne_char(FILE* fichier, int nbligne) {//Sert à aller chercher une chaine de caracteres dans un fichier à une ligne donnée
    rewind(fichier);
    char ligne[100];
    char poubelle[100];
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }

    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        printf("Erreur de lecture ligne %d\n", nbligne);
        exit(1);
    }

    ligne[strcspn(ligne, "\n")] = '\0';  // Retirer le \n

    char* copie = malloc(strlen(ligne) + 1);
    if (!copie) {
        printf("Erreur malloc\n");
        exit(1);
    }

    strcpy(copie, ligne);
    return copie;
}


int read_ligne_int(FILE* fichier, int nbligne){//comme celle avant mais avec un int
    rewind(fichier);
    int result=0;
    char poubelle[100];
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }
    if (fscanf(fichier, "%d", &result) == 0) {
        printf("Erreur\n");
        exit(1);
    }
    return result;
}
float read_ligne_float(FILE* fichier, int nbligne){//pareil avec float
    rewind(fichier);
    float result=0;
    char poubelle[100];
    for (int i = 1; i < nbligne; i++) {
        fgets(poubelle, sizeof(poubelle), fichier);
    }
    if (fscanf(fichier, "%f", &result) == 0) {
        printf("Erreur\n");
        exit(1);
    }
    return result;
}
void vide_buffer(){
    while(getchar()!='\n');
}

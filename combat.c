#include "Biblio_lin.h"

//attaques speciales
typedef enum{
    Nitrocharge, Abri, Feu_Follet
}Competence_spe;

//attaques de bases
typedef enum{
    Flammeche
}Attaque_base;

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
    int cooldown;
    Type type;
}Comp;
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
    Statut etat;
    Attaque_base atk1;
    Comp spe1;
    Comp spe2;
    Comp spe3;
    Type t;
    int speedbar;
}Pokemon;
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
int type_effect(Type atk, Type def){
    if(((atk==Normal) && (def==Spectre)) || ((atk==Electrik) && (def==Sol)) || ((atk==Combat) && (def==Spectre)) || ((atk==Poison) && (def==Acier)) || ((atk==Sol) && (def==Vol)) || ((atk==Psy) && (def==Tenebres)) || ((atk==Spectre) && (def==Normal)) || ((atk==Dragon) && (def==Fee))){
        return 0;
    }
    else if(((atk==Feu) && (def==Plante)) || ((atk==Feu) && (def==Glace)) || ((atk==Feu) && (def==Insecte)) || ((atk==Feu) && (def==Acier)) || ((atk==Eau) && (def==Feu)) || ((atk==Eau) && (def==Sol)) || ((atk==Eau) && (def==Roche)) || ((atk==Plante) && (def==Eau)) || ((atk==Plante) && (def==Sol)) || ((atk==Plante) && (def==Roche)) || ((atk==Electrik) && (def==Eau)) || ((atk==Electrik) && (def==Vol)) || ((atk==Glace) && (def==Plante)) || ((atk==Glace) && (def==Sol)) || ((atk==Glace) && (def==Vol)) || ((atk==Glace) && (def==Dragon))){
        return 2;
    }
    else if(((atk==Combat) && (def==Normal)) || ((atk==Combat) && (def==Glace)) || ((atk==Combat) && (def==Roche)) || ((atk==Combat) && (def==Tenebres)) || ((atk==Combat) && (def==Acier)) || ((atk==Poison) && (def==Plante)) || ((atk==Poison) && (def==Fee)) || ((atk==Sol) && (def==Feu)) || ((atk==Sol) && (def==Electrik)) || ((atk==Sol) && (def==Poison)) || ((atk==Sol) && (def==Roche)) || ((atk==Sol) && (def==Acier)) || ((atk==Vol) && (def==Plante)) || ((atk==Vol) && (def==Combat)) || ((atk==Vol) && (def==Insecte)) || ((atk==Psy) && (def==Combat)) || ((atk==Psy) && (def==Poison)) || ((atk==Insecte) && (def==Plante)) || ((atk==Insecte) && (def==Psy)) || ((atk==Insecte) && (def==Tenebres))){
        return 2;
    }
    else if(((atk==Normal) && (def==Roche)) || ((atk==Normal) && (def==Acier)) || ((atk==Feu) && (def==Feu)) || ((atk==Feu) && (def==Eau)) || ((atk==Feu) && (def==Roche)) || ((atk==Feu) && (def==Dragon)) || ((atk==Eau) && (def==Eau)) || ((atk==Eau) && (def==Plante)) || ((atk==Eau) && (def==Dragon)) || ((atk==Plante) && (def==Feu)) || ((atk==Plante) && (def==Plante)) || ((atk==Plante) && (def==Poison)) || ((atk==Plante) && (def==Vol)) || ((atk==Plante) && (def==Insecte)) || ((atk==Plante) && (def==Dragon)) || ((atk==Electrik) && (def==Plante)) || ((atk==Electrik) && (def==Electrik)) || ((atk==Electrik) && (def==Dragon)) || ((atk==Glace) && (def==Feu)) || ((atk==Glace) && (def==Eau)) || ((atk==Glace) && (def==Glace)) || ((atk==Glace) && (def==Acier)) || ((atk==Combat) && (def==Poison)) || ((atk==Combat) && (def==Vol)) || ((atk==Combat) && (def==Psy)) || ((atk==Combat) && (def==Insecte)) || ((atk==Combat) && (def==Fee)) || ((atk==Poison) && (def==Poison)) || ((atk==Poison) && (def==Sol)) || ((atk==Poison) && (def==Roche)) || ((atk==Poison) && (def==Spectre)) || ((atk==Sol) && (def==Plante)) || ((atk==Sol) && (def==Insecte)) || ((atk==Vol) && (def==Electrik)) || ((atk==Vol) && (def==Roche)) || ((atk==Vol) && (def==Acier)) || ((atk==Psy) && (def==Psy)) || ((atk==Psy) && (def==Acier)) || ((atk==Insecte) && (def==Feu)) || ((atk==Insecte) && (def==Combat)) || ((atk==Insecte) && (def==Spectre)) || ((atk==Roche) && (def==Combat)) || ((atk==Roche) && (def==Sol)) || ((atk==Roche) && (def==Acier)) || ((atk==Spectre) && (def==Ténèbres)) || ((atk==Dragon) && (def==Acier)) || ((atk==Tenebres) && (def==Combat)) || ((atk==Tenebres) && (def==Tenebres)) || ((atk==Tenebres) && (def==Fee)) || ((atk==Acier) && (def==Feu)) || ((atk==Acier) && (def==Eau)) || ((atk==Acier) && (def==Electrik)) || ((atk==Fee) && (def==Feu)) || ((atk==Fee) && (def==Poison)) || ((atk==Fee) && (def==Acier))){
        return -1;
    }
    else {
        return 1;
    }
}

char* get_comp_name(Competence_spe comp){
    switch(comp){
        case Nitrocharge: return "Nitrocharge";
        case Abri: return "Abri";
        case Feu_Follet: return "Feu_Follet";
        default: return "Inconnu";
    }
}
void aff_effect_atk(Competence_spe atk){
    switch (atk){
        case Nitrocharge: printf("Feu: 50 puissance (amplifie la vitesse)");
        case Abri: return printf("Normal: bloque la prochaine attaque");
        case Feu_Follet: return printf("Feu: Brule");
        default: return "Inconnu";
    }
}
void speedbarplus(Pokemon* un, Pokemon* deux, Pokemon* trois, Pokemon* quatre, Pokemon* cinq, Pokemon* six){
    (*un).speedbar=(*un).speedbar+(*un).vitesse;
    (*deux).speedbar=(*deux).speedbar+(*deux).vitesse;
    (*trois).speedbar=(*trois).speedbar+(*trois).vitesse;
    (*quatre).speedbar=(*quatre).speedbar+(*quatre).vitesse;
    (*cinq).speedbar=(*cinq).speedbar+(*cinq).vitesse;
    (*six).speedbar=(*six).speedbar+(*six).vitesse;
}
int plus1000(Pokemon un, Pokemon deux, Pokemon trois, Pokemon quatre, Pokemon cinq, Pokemon six){
    if(un.speedbar>=1000 || deux.speedbar>=1000 || trois.speedbar>=1000 || quatre.speedbar>=1000 || cinq.speedbar>=1000 || six.speedbar>=1000 ){
        return 1;
    }
    return 0;
}

Comp choise_atk(Pokemon* attaquant, Pokemon** team_allie, Pokemon** team adverse){//à testé
    int i=0;
    char* name=malloc(100*sizeof(char));
    do{
        printf("\nQuel compétence choisissez vous utilisez(Rentrer son nom sinon écrivez 0 si vous ne voulez pas en utilisez et donc utlisez l'attaque normale):");
        printf("\n-");
        aff_char(get_comp_name(attaquant[0].spe1.comp));
        printf("     ");
        aff_effect_atk(attaquant[0].spe1.comp);
        printf("     Tours restants avant utilisation %d", attaquant[0].spe1.cooldown);
        printf("\n-");
        aff_char(get_comp_name(attaquant[0].spe2.comp));
        printf("     ");
        aff_effect_atk(attaquant[0].spe2.com);
        printf("     Tours restants avant utilisation %d", attaquant[0].spe2.cooldown);
        printf("\n-");
        aff_char(get_comp_name(attaquant[0].spe3.comp));
        printf("     ");
        aff_effect_atk(attaquant[0].spe3.comp);
        printf("     Tours restants avant utilisation %d", attaquant[0].spe3.cooldown);
        scanf("%s", name);
        if(compare_chaine(name, get_comp_name(attaquant[0].spe1.comp))==0 && attaquant[0].spe1.cooldown==0){
            free(name);
            return attaquant[0].spe1;
        }
        else if(compare_chaine(name, get_comp_name(attaquant[0].spe2.comp))==0 && attaquant[0].spe2.cooldown==0){
            free(name);
            return attaquant[0].spe2;
        }
        else if(compare_chaine(name, get_comp_name(attaquant[0].spe3.comp))==0 && attaquant[0].spe3.cooldown==0){
            free(name);
            return attaquant[0].spe3;
        }
        else if(compare_chaine(name, "0") == 0){
            free(name);
            return NULL;
        }
    }while(1);
}
Pokemon effect_atk(Pokemon* attaquant, Pokemon* cible, Comp atk){
    
}

Pokemon maj(Pokemon un, Pokemon deux){
    if(un.speedbar>deux.speedbar){
        return un;
    }
    else{
        return deux;
    }
}
Pokemon maj6(Pokemon un, Pokemon deux, Pokemon trois, Pokemon quatre, Pokemon cinq, Pokemon six){
    return maj(maj(maj(un, deux), maj(trois, quatre)),maj(cinq, six));
}
int fight(Pokemon** player, Pokemon** bot){
    while (((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0) && ((*(bot[0])).pv_courant>0 || (*(bot[1])).pv_courant>0 || (*(bot[2])).pv_courant>0)){
        speedbarplus(player[0], player[1], player[2], bot[0], bot[1], bot[2]);
        if(plus1000(*(player[0]), *(player[1]), *(player[2]), *(bot[0]), *(bot[1]), *(bot[2]))==1){
            
        }
    }
}


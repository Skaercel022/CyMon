#include "Biblio_lin.h"
#include <SDL2/SDL.h>

//attaques speciales
typedef enum{
    Nitrocharge, Abri, Feu_Follet, Flammeche
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
float type_effect(Type atk, Type def){
    if(((atk==Normal) && (def==Spectre)) || ((atk==Electrik) && (def==Sol)) || ((atk==Combat) && (def==Spectre)) || ((atk==Poison) && (def==Acier)) || ((atk==Sol) && (def==Vol)) || ((atk==Psy) && (def==Tenebres)) || ((atk==Spectre) && (def==Normal)) || ((atk==Dragon) && (def==Fee))){
        return 0.0;
    }
    else if(((atk==Feu) && (def==Plante)) || ((atk==Feu) && (def==Glace)) || ((atk==Feu) && (def==Insecte)) || ((atk==Feu) && (def==Acier)) || ((atk==Eau) && (def==Feu)) || ((atk==Eau) && (def==Sol)) || ((atk==Eau) && (def==Roche)) || ((atk==Plante) && (def==Eau)) || ((atk==Plante) && (def==Sol)) || ((atk==Plante) && (def==Roche)) || ((atk==Electrik) && (def==Eau)) || ((atk==Electrik) && (def==Vol)) || ((atk==Glace) && (def==Plante)) || ((atk==Glace) && (def==Sol)) || ((atk==Glace) && (def==Vol)) || ((atk==Glace) && (def==Dragon))){
        printf("\nL'attaque est super efficace");
        return 2.0;
    }
    else if(((atk==Combat) && (def==Normal)) || ((atk==Combat) && (def==Glace)) || ((atk==Combat) && (def==Roche)) || ((atk==Combat) && (def==Tenebres)) || ((atk==Combat) && (def==Acier)) || ((atk==Poison) && (def==Plante)) || ((atk==Poison) && (def==Fee)) || ((atk==Sol) && (def==Feu)) || ((atk==Sol) && (def==Electrik)) || ((atk==Sol) && (def==Poison)) || ((atk==Sol) && (def==Roche)) || ((atk==Sol) && (def==Acier)) || ((atk==Vol) && (def==Plante)) || ((atk==Vol) && (def==Combat)) || ((atk==Vol) && (def==Insecte)) || ((atk==Psy) && (def==Combat)) || ((atk==Psy) && (def==Poison)) || ((atk==Insecte) && (def==Plante)) || ((atk==Insecte) && (def==Psy)) || ((atk==Insecte) && (def==Tenebres))){
        printf("\nL'attaque est super efficace");
        return 2.0;
    }
    else if(((atk==Normal) && (def==Roche)) || ((atk==Normal) && (def==Acier)) || ((atk==Feu) && (def==Feu)) || ((atk==Feu) && (def==Eau)) || ((atk==Feu) && (def==Roche)) || ((atk==Feu) && (def==Dragon)) || ((atk==Eau) && (def==Eau)) || ((atk==Eau) && (def==Plante)) || ((atk==Eau) && (def==Dragon)) || ((atk==Plante) && (def==Feu)) || ((atk==Plante) && (def==Plante)) || ((atk==Plante) && (def==Poison)) || ((atk==Plante) && (def==Vol)) || ((atk==Plante) && (def==Insecte)) || ((atk==Plante) && (def==Dragon)) || ((atk==Electrik) && (def==Plante)) || ((atk==Electrik) && (def==Electrik)) || ((atk==Electrik) && (def==Dragon)) || ((atk==Glace) && (def==Feu)) || ((atk==Glace) && (def==Eau)) || ((atk==Glace) && (def==Glace)) || ((atk==Glace) && (def==Acier)) || ((atk==Combat) && (def==Poison)) || ((atk==Combat) && (def==Vol)) || ((atk==Combat) && (def==Psy)) || ((atk==Combat) && (def==Insecte)) || ((atk==Combat) && (def==Fee)) || ((atk==Poison) && (def==Poison)) || ((atk==Poison) && (def==Sol)) || ((atk==Poison) && (def==Roche)) || ((atk==Poison) && (def==Spectre)) || ((atk==Sol) && (def==Plante)) || ((atk==Sol) && (def==Insecte)) || ((atk==Vol) && (def==Electrik)) || ((atk==Vol) && (def==Roche)) || ((atk==Vol) && (def==Acier)) || ((atk==Psy) && (def==Psy)) || ((atk==Psy) && (def==Acier)) || ((atk==Insecte) && (def==Feu)) || ((atk==Insecte) && (def==Combat)) || ((atk==Insecte) && (def==Spectre)) || ((atk==Roche) && (def==Combat)) || ((atk==Roche) && (def==Sol)) || ((atk==Roche) && (def==Acier)) || ((atk==Spectre) && (def==Tenebres)) || ((atk==Dragon) && (def==Acier)) || ((atk==Tenebres) && (def==Combat)) || ((atk==Tenebres) && (def==Tenebres)) || ((atk==Tenebres) && (def==Fee)) || ((atk==Acier) && (def==Feu)) || ((atk==Acier) && (def==Eau)) || ((atk==Acier) && (def==Electrik)) || ((atk==Fee) && (def==Feu)) || ((atk==Fee) && (def==Poison)) || ((atk==Fee) && (def==Acier))){
        printf("\nL'attaque n'est pas tres efficace");
        return 0.5;
    }
    else {
        return 1.0;
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
void aff_effect_atk(Competence_spe atk) {
    switch (atk) {
        case Nitrocharge:
            printf("Feu: 50 puissance (amplifie la vitesse)\n");
            break;
        case Abri:
            printf("Normal: bloque la prochaine attaque\n");
            break;
        case Feu_Follet:
            printf("Feu: Brule\n");
            break;
        default:
            printf("Inconnu\n");
            break;
    }
}
void aff_atk(Competence_spe atk) {
    switch (atk) {
        case Nitrocharge:
            printf("Nitrocharge");
            break;
        case Abri:
            printf("Abri");
            break;
        case Feu_Follet:
            printf("Feu Follet");
            break;
        default:
            printf("Inconnu\n");
            break;
    }
}
void speedbarplus(Pokemon* un, Pokemon* deux, Pokemon* trois, Pokemon* quatre, Pokemon* cinq, Pokemon* six){
    if(un->etat==Paralysie){
        (*un).speedbar=(*un).speedbar+((*un).vitesse)/2;
    }
    else{
        (*un).speedbar=(*un).speedbar+(*un).vitesse;
    }
    if(deux->etat==Paralysie){
        (*deux).speedbar=(*deux).speedbar+((*deux).vitesse)/2;
    }
    else{
        (*deux).speedbar=(*deux).speedbar+(*deux).vitesse;
    }
    if(trois->etat==Paralysie){
        (*trois).speedbar=(*trois).speedbar+((*trois).vitesse)/2;
    }
    else{
        (*trois).speedbar=(*trois).speedbar+(*trois).vitesse;
    }
    if(quatre->etat==Paralysie){
        (*quatre).speedbar=(*quatre).speedbar+((*quatre).vitesse)/2;
    }
    else{
        (*quatre).speedbar=(*quatre).speedbar+(*quatre).vitesse;
    }
    if(cinq->etat==Paralysie){
        (*cinq).speedbar=(*cinq).speedbar+((*cinq).vitesse)/2;
    }
    else{
        (*cinq).speedbar=(*cinq).speedbar+(*cinq).vitesse;
    }
    if(six->etat==Paralysie){
        (*six).speedbar=(*six).speedbar+((*six).vitesse)/2;
    }
    else{
        (*six).speedbar=(*six).speedbar+(*six).vitesse;
    }
}
int plus1000(Pokemon un, Pokemon deux, Pokemon trois, Pokemon quatre, Pokemon cinq, Pokemon six){
    if(un.speedbar>=1000 || deux.speedbar>=1000 || trois.speedbar>=1000 || quatre.speedbar>=1000 || cinq.speedbar>=1000 || six.speedbar>=1000 ){
        return 1;
    }
    return 0;
}

Comp choix_atk(Pokemon* bu){//à testé
    char* name=malloc(100*sizeof(char));
    printf("\n\n%s", (*bu).nom_poke);
    do{
        printf("\nQuel compétence choisissez vous utilisez(Rentrer son nom sinon écrivez 0 si vous ne voulez pas en utilisez et donc utlisez l'attaque normale):");
        printf("\n-");
        aff_char(get_comp_name(bu[0].spe1.comp));
        printf("     ");
        aff_effect_atk(bu[0].spe1.comp);
        printf("     Tours restants avant utilisation %d", bu[0].spe1.cooldown);
        printf("\n-");
        aff_char(get_comp_name(bu[0].spe2.comp));
        printf("     ");
        aff_effect_atk(bu[0].spe2.comp);
        printf("     Tours restants avant utilisation %d", bu[0].spe2.cooldown);
        printf("\n-");
        aff_char(get_comp_name(bu[0].spe3.comp));
        printf("     ");
        aff_effect_atk(bu[0].spe3.comp);
        printf("     Tours restants avant utilisation %d\n", bu[0].spe3.cooldown);
        scanf("%s", name);
        if(compare_chaine(name, get_comp_name(bu[0].spe1.comp))==0 && bu[0].spe1.cooldown==0){
            free(name);
            return bu[0].spe1;
        }
        else if(compare_chaine(name, get_comp_name(bu[0].spe2.comp))==0 && bu[0].spe2.cooldown==0){
            free(name);
            return bu[0].spe2;
        }
        else if(compare_chaine(name, get_comp_name(bu[0].spe3.comp))==0 && bu[0].spe3.cooldown==0){
            free(name);
            return bu[0].spe3;
        }
        else if(compare_chaine(name, "0") == 0){
            free(name);
            return bu[0].atkbase;
        }
    }while(1);
}
int attaque_esquivee(Comp atk, Pokemon* attaque, Pokemon* defend){
    int alea=rand()%100+1;
    if(alea> (atk.precision*(attaque[0].précision/defend[0].agilite))){
        printf("\n");
        aff_char(defend->nom_poke);
        return 0;
    }
    else{
        return 1;
    }
}
float degats(Pokemon* attaquant, Pokemon* defenseur, Comp atk){
    int aleacm= rand()%15 +85;
    int aleacrit= rand()%100 +1;
    if(defenseur->pv_courant<0){
        printf("L'attaque echoue (pourquoi vous attaquez des pokemons KO ???)");
        return 0.0;
    }
    if(atk.comp==Abri){
        printf("\n");
        aff_char(defenseur->nom_poke);
        printf(" se protege");
        defenseur->protec=0;
        return 0.0;
    }//else if a rajouter
    else{
        if(aleacrit<5){
            if(attaquant[0].t==atk.type){
                return attaque_esquivee(atk, attaquant, defenseur)*((3*(((3*aleacm)/200)*type_effect(atk.type, defenseur[0].t)*((20*attaquant[0].attaque*atk.puissance)/50*defenseur[0].defense)))/2);
            }
            else{
                return attaque_esquivee(atk, attaquant, defenseur)*(((3*aleacm)/200)*type_effect(atk.type, defenseur[0].t)*((20*attaquant[0].attaque*atk.puissance)/50*defenseur[0].defense));
            }
        }
        else{
            if(attaquant[0].t==atk.type){
                return attaque_esquivee(atk, attaquant, defenseur)*(((3*aleacm)/200)*type_effect(atk.type, defenseur[0].t)*((20*attaquant[0].attaque*atk.puissance)/50*defenseur[0].defense));
            }
            else{
                return attaque_esquivee(atk, attaquant, defenseur)*(((aleacm)/100)*type_effect(atk.type, defenseur[0].t)*((20*attaquant[0].attaque*atk.puissance)/50*defenseur[0].defense));
            }
        }
    }
}
void effet_spe(Pokemon* attaquant, Pokemon* defenseur, Comp atk){
    if(atk.comp==Nitrocharge){
        attaquant[0].vitesse=(7*attaquant[0].vitesse)/6;
    }
    else if(atk.comp==Feu_Follet){
        if(defenseur[0].t!=Feu){
            defenseur[0].etat=Brulure;
            printf("\n");
            aff_char(defenseur[0].nom_poke);
            printf(" est brule");
        }
    }
}
Comp maj_damage(Pokemon* offense, Pokemon** team, Pokemon** adversaires, Pokemon* cible){
    Comp* result;
    Pokemon* cible2;
    
    int max=0;
    for(int j=0; j<3; j++){
        if(degats(offense, adversaires[j], offense->atkbase)>max){
            result=&offense->atkbase;
            cible2=adversaires[j];
        }
        if((degats(offense, adversaires[j], offense->spe1)>max) && offense->spe1.cooldown==0){
            result=&offense->spe1;
            cible2=adversaires[j];
        }
        if((degats(offense, adversaires[j], offense->spe2)>max) && offense->spe2.cooldown==0){
            result=&offense->spe2;
            cible2=adversaires[j];
        }
        if((degats(offense, adversaires[j], offense->spe3)>max) && offense->spe3.cooldown==0){
            result=&offense->spe3;
            cible2=adversaires[j];
        }
    }
    if(cible->précision==-1){
        cible=cible2;
    }
    return *result;
}
void effect_atk_bot(Pokemon* offense, Pokemon** team, Pokemon** adversaires){
    int x=0;
    int aleapara=rand()%100+1;
    int aleagel=rand()%100+1;
    printf("\n\n%s", (*offense).nom_poke);
    Pokemon* cible;
    Comp choix;
    choix.precision=-1;
    for(int j=0; j<3; j++){
        if(((degats(offense, adversaires[j], offense->atkbase))>adversaires[j]->pv_courant) && (adversaires[j]->pv_courant>0)){
            cible=adversaires[j];
            choix=offense->atkbase;
        }
    }
    if(choix.precision==-1){
        for(int j=0; j<3; j++){
            if(((degats(offense, adversaires[j], offense->spe1)>adversaires[j]->pv_courant && offense->spe1.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                cible=adversaires[j];
                choix=offense->spe1;
            }
        }
        if(choix.precision==-1){
            for(int j=0; j<3; j++){
                if(((degats(offense, adversaires[j], offense->spe2)>adversaires[j]->pv_courant && offense->spe2.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                    cible=adversaires[j];
                    choix=offense->spe2;
                }
            }
            if(choix.precision==-1){
                for(int j=0; j<3; j++){
                    if(((degats(offense, adversaires[j], offense->spe3)>adversaires[j]->pv_courant && offense->spe3.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                        cible=adversaires[j];
                        choix=offense->spe3;
                    }
                }
            }
        }
    }
    
    choix=maj_damage(offense, team, adversaires, cible);
    printf("\n");
    aff_char(offense->nom_poke);
    printf(" utilise ");
    aff_atk(choix.comp);
    printf(" sur ");
    aff_char(cible->nom_poke);
    x=degats(offense, cible, choix);
    if(offense->sleep>0){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" dort il n'a pas pu attaque");
        offense->sleep=offense->sleep-1;
        if(offense->sleep=0){
            offense->etat=Neutre;
        }
        x=0;
    }
    if(aleagel>20){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est gele il n'a pas pu attaque");
        x=0;
    }
    else{
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" n'est plus gele");
    }
    if(aleapara<26){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est paralyse il n'a pas pu attaque");
        x=0;
    }
    else if(x==0){
        printf("\nL'attaque a echoue ou a ete esquive");
    }
    effet_spe(offense, cible, choix);
    printf("\n");
    aff_char(cible->nom_poke);
    if(offense->etat==Brulure){
        printf(" a prit %d degats", x/2);//a retiré outils de dev
        cible[0].pv_courant=cible[0].pv_courant-(x/2);
    }
    else{
        printf(" a prit %d degats", x);//a retiré outils de dev
        cible[0].pv_courant=cible[0].pv_courant-x;
    }
    if(cible->pv_courant<0){
        cible->vitesse=0;
        printf("\n");
        aff_char(cible->nom_poke);
        printf(" est KO");
    }
}
void effect_atk(Pokemon* offense, Pokemon** team, Pokemon** adversaires, Comp atk){
    char* name=malloc(100*sizeof(char));
    int rep=0;
    int x=0;
    int aleapara=rand()%100+1;
    int aleagel=rand()%100+1;
    Pokemon* cible;
    int i=0;
    if(aleapara<26){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est parlyse il n'a pas pu attaque");
    }
    atk.cooldown=atk.cooldownmax;
    do{
        if(atk.comp==Abri){
            cible=offense;
            cible->protec=1;
        }
        else{
            printf("\n Choisissez une cible :\n");
            for (int j = 0; j < 3; j++) {
                printf("- "); aff_char(team[j]->nom_poke); printf("\n");
                printf("- "); aff_char(adversaires[j]->nom_poke); printf("\n");
            }
            scanf("%s", name);
            for(int j=0; j<2; j++){
                if((compare_chaine(name, (team[j])[0].nom_poke))==0 && ((compare_chaine((team[j])[0].nom_poke, (adversaires[0])[0].nom_poke))==0 || (compare_chaine((team[j])[0].nom_poke, (adversaires[1])[0].nom_poke))==0 || (compare_chaine((team[j])[0].nom_poke, (adversaires[2])[0].nom_poke))==0)){
                    do{
                        printf("\nPrecisez sa position (c'est-a-dire donnez une valeur entre 1 et 6 1 etant le premier pokemon de l'adversaire et 6 votre dernier) :");
                        scanf("%d", &rep);
                        if(rep==1){
                            cible=adversaires[0];
                        }
                        if(rep==2){
                            cible=adversaires[1];
                        }
                        if(rep==3){
                            cible=adversaires[2];
                        }
                        if(rep==4){
                            cible=team[0];
                        }
                        if(rep==5){
                            cible=team[1];
                        }
                        if(rep==4){
                            cible=team[2];
                        }
                    }while(rep<1 || rep>6);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (compare_chaine(name, team[j]->nom_poke) == 0){
                    cible = team[j];
                } 
                if (compare_chaine(name, adversaires[j]->nom_poke) == 0){
                    cible = adversaires[j];
                } 
            }
        }
        if(cible==adversaires[0] || cible==adversaires[1] || cible==adversaires[2] || cible==team[2] || cible==team[1] || cible==team[0]){
            i=1;
        }
    }while(i=0);
    printf("\n");
    aff_char(offense->nom_poke);
    printf(" utilise ");
    aff_atk(atk.comp);
    x=degats(offense, cible, atk);
    if(offense->sleep>0){
        printf("\n");
        aff_char(offense->nom_poke);
        printf("dort il n'a pas pu attaque");
        offense->sleep=offense->sleep-1;
        if(offense->sleep=0){
            offense->etat=Neutre;
        }
        x=0;
    }
    if(aleagel>20){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est gele il n'a pas pu attaque");
        x=0;
    }
    else{
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" n'est plus gele");
    }
    if(aleapara<26){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est paralyse il n'a pas pu attaque");
        x=0;
    }
    else if(x==0){
        printf("\nL'attaque a echoue ou a ete esquive");
    }
    effet_spe(offense, cible, atk);
    printf("\n");
    aff_char(cible->nom_poke);
    if(offense->etat==Brulure){
        printf(" a prit %d degats", x/2);//a retiré outils de dev
        cible[0].pv_courant=cible[0].pv_courant-(x/2);
    }
    else{
        printf(" a prit %d degats", x);//a retiré outils de dev
        cible[0].pv_courant=cible[0].pv_courant-x;
    }
    if(cible->pv_courant<0){
        cible->vitesse=0;
        printf("\n");
        aff_char(cible->nom_poke);
        printf(" est KO");
    }
}

Pokemon* maj(Pokemon* un, Pokemon* deux){
    if((*un).speedbar>(*deux).speedbar){
        return un;
    }
    else{
        return deux;
    }
}
Pokemon* maj6(Pokemon* un, Pokemon* deux, Pokemon* trois, Pokemon* quatre, Pokemon* cinq, Pokemon* six){
    return maj(maj(maj(un, deux), maj(trois, quatre)),maj(cinq, six));
}
void cooldown1poke(Pokemon* poke){
    if((*poke).spe1.cooldown>0){
        (*poke).spe1.cooldown=(*poke).spe1.cooldown-1;
    }
    if((*poke).spe2.cooldown>0){
        (*poke).spe2.cooldown=(*poke).spe2.cooldown-1;
    }
    if((*poke).spe3.cooldown>0){
        (*poke).spe3.cooldown=(*poke).spe3.cooldown-1;
    }
}
void cooldownmatch(Pokemon** un, Pokemon** deux){
    for(int i=0; i<3; i++){
        cooldown1poke(un[i]);
        cooldown1poke(deux[i]);
    }
}
void effect_status(Pokemon* poke, int nbtour){
    if(poke->etat==Brulure){
        printf("\n");
        aff_char(poke->nom_poke);
        printf(" est brule\n il prend des degats");
        poke->pv_courant=poke->pv_courant-(poke->pv_max/16);
    }
    if(poke->etat==Empoisonnement){
        printf("\n");
        aff_char(poke->nom_poke);
        printf(" est empoisonne\n il prend des degats");
        poke->pv_courant=poke->pv_courant-((nbtour*(poke->pv_max))/16);
    }
}
int fight(Pokemon** player, Pokemon** bot){//rajouter un srand dans le main
    while (((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0) && ((*(bot[0])).pv_courant>0 || (*(bot[1])).pv_courant>0 || (*(bot[2])).pv_courant>0)){
        speedbarplus(player[0], player[1], player[2], bot[0], bot[1], bot[2]);
        if(plus1000(*(player[0]), *(player[1]), *(player[2]), *(bot[0]), *(bot[1]), *(bot[2]))==1){
            cooldownmatch(player, bot);
            printf("\n\n\n");
            if(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[0] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[1] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[2]){
                effect_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), player, bot, choix_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])));
            }
            else{
                effect_atk_bot(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), bot, player);
            }
            (maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->speedbar)=0;
        }
    }
    if((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0){
        printf("\nBravo vous avez GAGNE!!!");
        return 0;
    }
    else{
        printf("Hahaha t'as perdu t'es trop nul Bouhhh");
        return -1;
    }
}
int main() {
    srand(time(NULL));

    // Créer 3 Pokémon pour le joueur
    Pokemon pikachu = {
        .nom_poke = "Pikachu", .pv_max = 100, .pv_courant = 100,
        .attaque = 55, .defense = 40, .vitesse = 90, .précision = 1.0, .etat = Neutre,
        .spe1 = { Nitrocharge, 0, 3, Electrik, 50, 95 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Feu_Follet, 0, 5, Feu, 0, 90 },
        .t = Electrik, .speedbar = 0
    };

    Pokemon bulbizarre = {
        .nom_poke = "Bulbizarre", .pv_max = 120, .pv_courant = 120,
        .attaque = 49, .defense = 49, .vitesse = 45, .précision = 1.0, .etat = Neutre,
        .spe1 = { Feu_Follet, 0, 3, Plante, 0, 90 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Nitrocharge, 0, 5, Plante, 50, 90 },
        .t = Plante, .speedbar = 0
    };

    Pokemon carapuce = {
        .nom_poke = "Carapuce", .pv_max = 110, .pv_courant = 110,
        .attaque = 48, .defense = 65, .vitesse = 43, .précision = 1.0, .etat = Neutre,
        .spe1 = { Nitrocharge, 0, 3, Eau, 40, 95 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Feu_Follet, 0, 5, Eau, 0, 90 },
        .t = Eau, .speedbar = 0
    };

    // Créer 3 Pokémon pour le bot
    Pokemon salameche = {
        .nom_poke = "Salameche", .pv_max = 100, .pv_courant = 100,
        .attaque = 52, .defense = 43, .vitesse = 65, .précision = 1.0, .etat = Neutre,
        .spe1 = { Nitrocharge, 0, 3, Feu, 50, 95 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Feu_Follet, 0, 5, Feu, 0, 85 },
        .t = Feu, .speedbar = 0
    };

    Pokemon mystherbe = {
        .nom_poke = "Mystherbe", .pv_max = 90, .pv_courant = 90,
        .attaque = 50, .defense = 55, .vitesse = 30, .précision = 1.0, .etat = Neutre,
        .spe1 = { Nitrocharge, 0, 3, Plante, 40, 95 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Feu_Follet, 0, 5, Plante, 0, 90 },
        .t = Plante, .speedbar = 0
    };

    Pokemon racaillou = {
        .nom_poke = "Racaillou", .pv_max = 130, .pv_courant = 130,
        .attaque = 80, .defense = 100, .vitesse = 20, .précision = 1.0, .etat = Neutre,
        .spe1 = { Nitrocharge, 0, 3, Roche, 60, 90 },
        .spe2 = { Abri, 0, 4, Normal, 0, 100 },
        .spe3 = { Feu_Follet, 0, 5, Sol, 0, 80 },
        .t = Roche, .speedbar = 0
    };

    // Création des équipes (tableaux de pointeurs)
    Pokemon* team[3] = { &pikachu, &bulbizarre, &carapuce };
    Pokemon* bot[3] = { &salameche, &mystherbe, &racaillou };

    printf("\n=== DEBUT DU COMBAT ===\n");
    fight(team, bot);
    printf("\n=== FIN DU COMBAT ===\n");

    return 0;
}

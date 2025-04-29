#include "Biblio_lin.h"
#include "combat.h"
float type_effect(Type atk, Type def){
    if(((atk==Normal) && (def==Spectre)) || ((atk==Electrik) && (def==Sol)) || ((atk==Combat) && (def==Spectre)) || ((atk==Poison) && (def==Acier)) || ((atk==Sol) && (def==Vol)) || ((atk==Psy) && (def==Tenebres)) || ((atk==Spectre) && (def==Normal)) || ((atk==Dragon) && (def==Fee))){
        return 0.0;
    }
    else if(((atk==Feu) && (def==Plante)) || ((atk==Feu) && (def==Glace)) || ((atk==Feu) && (def==Insecte)) || ((atk==Feu) && (def==Acier)) || ((atk==Eau) && (def==Feu)) || ((atk==Eau) && (def==Sol)) || ((atk==Eau) && (def==Roche)) || ((atk==Plante) && (def==Eau)) || ((atk==Plante) && (def==Sol)) || ((atk==Plante) && (def==Roche)) || ((atk==Electrik) && (def==Eau)) || ((atk==Electrik) && (def==Vol)) || ((atk==Glace) && (def==Plante)) || ((atk==Glace) && (def==Sol)) || ((atk==Glace) && (def==Vol)) || ((atk==Glace) && (def==Dragon))){
        return 2.0;
    }
    else if(((atk==Combat) && (def==Normal)) || ((atk==Combat) && (def==Glace)) || ((atk==Combat) && (def==Roche)) || ((atk==Combat) && (def==Tenebres)) || ((atk==Combat) && (def==Acier)) || ((atk==Poison) && (def==Plante)) || ((atk==Poison) && (def==Fee)) || ((atk==Sol) && (def==Feu)) || ((atk==Sol) && (def==Electrik)) || ((atk==Sol) && (def==Poison)) || ((atk==Sol) && (def==Roche)) || ((atk==Sol) && (def==Acier)) || ((atk==Vol) && (def==Plante)) || ((atk==Vol) && (def==Combat)) || ((atk==Vol) && (def==Insecte)) || ((atk==Psy) && (def==Combat)) || ((atk==Psy) && (def==Poison)) || ((atk==Insecte) && (def==Plante)) || ((atk==Insecte) && (def==Psy)) || ((atk==Insecte) && (def==Tenebres))){
        return 2.0;
    }
    else if(((atk==Normal) && (def==Roche)) || ((atk==Normal) && (def==Acier)) || ((atk==Feu) && (def==Feu)) || ((atk==Feu) && (def==Eau)) || ((atk==Feu) && (def==Roche)) || ((atk==Feu) && (def==Dragon)) || ((atk==Eau) && (def==Eau)) || ((atk==Eau) && (def==Plante)) || ((atk==Eau) && (def==Dragon)) || ((atk==Plante) && (def==Feu)) || ((atk==Plante) && (def==Plante)) || ((atk==Plante) && (def==Poison)) || ((atk==Plante) && (def==Vol)) || ((atk==Plante) && (def==Insecte)) || ((atk==Plante) && (def==Dragon)) || ((atk==Electrik) && (def==Plante)) || ((atk==Electrik) && (def==Electrik)) || ((atk==Electrik) && (def==Dragon)) || ((atk==Glace) && (def==Feu)) || ((atk==Glace) && (def==Eau)) || ((atk==Glace) && (def==Glace)) || ((atk==Glace) && (def==Acier)) || ((atk==Combat) && (def==Poison)) || ((atk==Combat) && (def==Vol)) || ((atk==Combat) && (def==Psy)) || ((atk==Combat) && (def==Insecte)) || ((atk==Combat) && (def==Fee)) || ((atk==Poison) && (def==Poison)) || ((atk==Poison) && (def==Sol)) || ((atk==Poison) && (def==Roche)) || ((atk==Poison) && (def==Spectre)) || ((atk==Sol) && (def==Plante)) || ((atk==Sol) && (def==Insecte)) || ((atk==Vol) && (def==Electrik)) || ((atk==Vol) && (def==Roche)) || ((atk==Vol) && (def==Acier)) || ((atk==Psy) && (def==Psy)) || ((atk==Psy) && (def==Acier)) || ((atk==Insecte) && (def==Feu)) || ((atk==Insecte) && (def==Combat)) || ((atk==Insecte) && (def==Spectre)) || ((atk==Roche) && (def==Combat)) || ((atk==Roche) && (def==Sol)) || ((atk==Roche) && (def==Acier)) || ((atk==Spectre) && (def==Tenebres)) || ((atk==Dragon) && (def==Acier)) || ((atk==Tenebres) && (def==Combat)) || ((atk==Tenebres) && (def==Tenebres)) || ((atk==Tenebres) && (def==Fee)) || ((atk==Acier) && (def==Feu)) || ((atk==Acier) && (def==Eau)) || ((atk==Acier) && (def==Electrik)) || ((atk==Fee) && (def==Feu)) || ((atk==Fee) && (def==Poison)) || ((atk==Fee) && (def==Acier))){
        return 0.5;
    }
    else {
        return 1.0;
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
    nbtour++;
    if(poke->etat==Sommeil){
        nbtour--;
        nbtour--;
    }
}
void aff_effect_atk(Competence_spe atk){ 
    switch (atk) {
        case Nitrocharge:     printf("||Feu: 50 puissance (amplifie la vitesse)"); 
        break;
        case Abri:            printf("||Normal: bloque la prochaine attaque"); 
        break;
        case Feu_Follet:      printf("||Feu: inflige Brûlure"); 
        break;
        case Flammeche:       printf("||Feu: 40 puissance"); 
        break;
        case Griffe:          printf("||Normal: 40 puissance"); 
        break;
        case Close_Combat:    printf("||Combat: 120 puissance (risque de baisse défense)"); 
        break;
        case Danse_lame:      printf("||Normal: boost attaque"); 
        break;
        case Aboiement:       printf("||Ténèbres: 55 puissance (baisse attaque spé)"); 
        break;
        case Choc_Mental:     printf("||Psy: 50 puissance"); 
        break;
        case Repos:           printf("||Psy: soigne totalement et endort pendant 2 tours"); 
        break;
        case Plenitude:       printf("||Psy: augmente attaque spé et défense spé"); 
        break;
        case Psyko:           printf("||Psy: 90 puissance (risque baisse défense spé)"); 
        break;
        case Crocs_givre:     printf("||Glace: 65 puissance (peut geler)"); 
        break;
        case Laser_glace:     printf("||Glace: 90 puissance (peut geler)"); 
        break;
        case Douche_froide:   printf("||Glace: 50 puissance (réduit attaque adverse)"); 
        break;
        case Feuillage:       printf("||Plante: 40 puissance"); 
        break;
        case Giga_sangsue:    printf("||Plante: 75 puissance (vole des PV)"); 
        break;
        case Vive_attaque:    printf("||Normal: 40 puissance (prioritaire)"); 
        break;
        case Balayage:        printf("||Combat: 65 puissance (plus efficace contre lourds)"); 
        break;
        case Gonflette:       printf("||Combat: augmente attaque et défense"); 
        break;
        case Poison_croix:    printf("||Poison: 70 puissance (peut empoisonner)"); 
        break;
        case Osmerang:        printf("||Sol: 70 puissance "); 
        break;
        case Queue_de_fer:    printf("||Acier: 100 puissance (peut baisser défense)"); 
        break;
        case Seisme:          printf("||Sol: 100 puissance"); 
        break;
        case Mur_de_fer:      printf("||Acier: boost défense fortement"); 
        break;
        case Eclair:          printf("||Électrik: 40 puissance (peut paralyser)"); 
        break;
        case Cage_eclair:     printf("||Électrik: inflige Paralysie"); 
        break;
        case Pistolet_a_O:    printf("||Eau: 40 puissance"); 
        break;
        case Surf:            printf("||Eau: 90 puissance"); 
        break;
        case Draco_griffe:    printf("||Dragon: 80 puissance"); 
        break;
        case Abattage:        printf("||Plante: 120 puissance"); 
        break;
        case Danse_draco:     printf("||Dragon: augmente attaque et vitesse"); 
        break;
        default:
            printf("||Inconnu");
            break;
    }
}

void aff_atk(Competence_spe atk){
    switch (atk) {
        case Nitrocharge:     printf("Nitrocharge"); break;
        case Abri:            printf("Abri"); break;
        case Feu_Follet:      printf("Feu Follet"); break;
        case Flammeche:       printf("Flammèche"); break;
        case Griffe:          printf("Griffe"); break;
        case Close_Combat:    printf("Close Combat"); break;
        case Danse_lame:      printf("Danse Lame"); break;
        case Aboiement:       printf("Aboiement"); break;
        case Choc_Mental:     printf("Choc Mental"); break;
        case Repos:           printf("Repos"); break;
        case Plenitude:       printf("Plénitude"); break;
        case Psyko:           printf("Psyko"); break;
        case Crocs_givre:     printf("Crocs Givre"); break;
        case Laser_glace:     printf("Laser Glace"); break;
        case Douche_froide:   printf("Douche Froide"); break;
        case Feuillage:       printf("Feuillage"); break;
        case Giga_sangsue:    printf("Giga-Sangsue"); break;
        case Vive_attaque:    printf("Vive-Attaque"); break;
        case Balayage:        printf("Balayage"); break;
        case Gonflette:       printf("Gonflette"); break;
        case Poison_croix:    printf("Poison Croix"); break;
        case Osmerang:        printf("Osmerang"); break;
        case Queue_de_fer:    printf("Queue de Fer"); break;
        case Seisme:          printf("Séisme"); break;
        case Mur_de_fer:      printf("Mur de Fer"); break;
        case Eclair:          printf("Éclair"); break;
        case Cage_eclair:     printf("Cage-Éclair"); break;
        case Pistolet_a_O:    printf("Pistolet à O"); break;
        case Surf:            printf("Surf"); break;
        case Draco_griffe:    printf("Draco-Griffe"); break;
        case Abattage:        printf("Abattage"); break;
        case Danse_draco:     printf("Danse Draco"); break;
        default:
            printf("Inconnu");
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
        printf("\nQuel compétence choisissez vous utilisez(Rentrer son nom):");
        printf("\n-Attaque de base: ");
        aff_char(get_comp_name(bu->atkbase.comp));
        printf("     ");
        printf("\n-");
        aff_char(get_comp_name(bu->spe1.comp));
        printf("     ");
        aff_effect_atk(bu->spe1.comp);
        printf(".....Tours restants avant utilisation %d", bu->spe1.cooldown);
        printf("\n-");
        aff_char(get_comp_name(bu->spe2.comp));
        printf("     ");
        aff_effect_atk(bu->spe2.comp);
        printf(".....Tours restants avant utilisation %d", bu->spe2.cooldown);
        printf("\n-");
        aff_char(get_comp_name(bu->spe3.comp));
        printf("     ");
        aff_effect_atk(bu->spe3.comp);
        printf(".....Tours restants avant utilisation %d\n", bu->spe3.cooldown);
        scanf("%s", name);
        if(compare_chaine(name, get_comp_name(bu->spe1.comp))==0 && bu->spe1.cooldown==0){
            free(name);
            bu->spe1.cooldown=bu->spe1.cooldownmax;
            return (bu->spe1);
        }
        else if(compare_chaine(name, get_comp_name(bu->spe2.comp))==0 && bu->spe2.cooldown==0){
            free(name);
            bu->spe2.cooldown=bu->spe2.cooldownmax;
            return (bu->spe2);
        }
        else if(compare_chaine(name, get_comp_name(bu->spe3.comp))==0 && bu->spe3.cooldown==0){
            free(name);
            bu->spe3.cooldown=bu->spe3.cooldownmax;
            return (bu->spe3);
        }
        else{
            free(name);
            return (bu->atkbase);
        }
    }while(1);
}
int attaque_esquivee(Comp atk, Pokemon* attaque, Pokemon* defend){
    int alea=rand()%100+1;
    if(alea> (atk.precision*(attaque->précision/defend->agilite))){
        printf("\n");
        aff_char(defend->nom_poke);
        return 0;
    }
    else{
        return 1;
    }
}
float degats(Pokemon* attaquant, Pokemon* defenseur, Comp atq){
    int aleacm = rand() % 15 + 85;
    int aleacrit = rand() % 100 + 1;
    if(defenseur==NULL){
        return 0.0;
    }
    if(defenseur->pv_courant < 0){
        printf("L'attaque échoue (pourquoi vous attaquez des pokémons KO ?)");
        return 0.0;
    }
    if(atq.comp == Abri){
        return 0.0;
    } 
    else {
        if(aleacrit < 5){
            if(attaquant[0].t == atq.type){
                return attaque_esquivee(atq, attaquant, defenseur)*((3 * ((3 * aleacm) / 200.0) * type_effect(atq.type, defenseur->t)*((20.0 * attaquant->attaque * atq.puissance) / (50.0 * defenseur->defense))) / 2.0);
            }
            else {
                return attaque_esquivee(atq, attaquant, defenseur)*((3 * aleacm) / 200.0) * type_effect(atq.type, defenseur[0].t)*((20.0 * attaquant->attaque * atq.puissance) / (50.0 * defenseur->defense));
            }
        }
        else {
            if(attaquant[0].t == atq.type){
                return attaque_esquivee(atq, attaquant, defenseur)*((3 * aleacm) / 200.0) * type_effect(atq.type, defenseur[0].t)*((20.0 * attaquant->attaque * atq.puissance) / (50.0 * defenseur->defense));
            }
            else {
                return attaque_esquivee(atq, attaquant, defenseur)*(aleacm / 100.0) * type_effect(atq.type, defenseur[0].t)*((20.0 * attaquant->attaque * atq.puissance) / (50.0 * defenseur->defense));
            }
        }
    }
}
void effet_spe(Pokemon* attaquant, Pokemon* defenseur, Comp atk) {
    int alea = rand() % 100;
    // Effets aléatoires basés sur une probabilité
    if (alea < 10) {
        switch (atk.comp) {
            case Psyko:
                defenseur->defense = (5 * (defenseur->defense)) / 6;
                printf("\nLa defense de ");
                aff_char(defenseur->nom_poke);
                printf(" diminue ");
                break;

            case Eclair:
                defenseur->etat = Paralysie;
                printf("\n");
                aff_char(defenseur->nom_poke);
                printf(" est paralyse");
                break;

            case Poison_croix:
                defenseur->etat = Empoisonnement;
                printf("\n");
                aff_char(defenseur->nom_poke);
                printf(" est empoisonne");
                break;

            case Crocs_givre:
            case Laser_glace:
                defenseur->etat = Gel;
                printf("\n");
                aff_char(defenseur->nom_poke);
                printf(" est gele");
                break;

            default:
                break;
        }
    }
    if (alea < 30) {
        switch (atk.comp) {
            case Queue_de_fer:
                defenseur->defense = (5 * (defenseur->defense)) / 6;
                printf("\nLa defense de ");
                aff_char(defenseur->nom_poke);
                printf(" diminue ");
                break;

            default:
                break;
        }
    }
    // Effets directs (sans probabilité)
    switch (atk.comp) {
        case Nitrocharge:
            attaquant->vitesse = (7 * (attaquant->vitesse)) / 6;
            printf("\nLa vitesse de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente");
            break;

        case Danse_draco:
            attaquant->vitesse = (7 * (attaquant->vitesse)) / 6;
            printf("\nLa vitesse de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente");
            attaquant->attaque = (7 * (attaquant->attaque)) / 6;
            printf("\nL'attaque de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente");
            break;

        case Plenitude:
        case Gonflette:
            attaquant->defense = (7 * (attaquant->defense)) / 6;
            printf("\nLa defense de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente");
            attaquant->attaque = (7 * (attaquant->attaque)) / 6;
            printf("\nL'attaque de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente");
            break;

        case Close_Combat:
            attaquant->defense = (2 * (attaquant->defense)) / 3;
            printf("\nLa defense de ");
            aff_char(attaquant->nom_poke);
            printf(" diminue beaucoup");
            break;

        case Repos:
            attaquant->pv_courant = attaquant->pv_max;
            printf("\n");
            aff_char(attaquant->nom_poke);
            printf(" se soigne");
            attaquant->sleep = 2;
            attaquant->etat = Sommeil;
            printf("\n");
            aff_char(attaquant->nom_poke);
            printf(" dort");
            break;

        case Cage_eclair:
            defenseur->etat = Paralysie;
            printf("\n");
            aff_char(defenseur->nom_poke);
            printf(" est paralyse");
            break;

        case Giga_sangsue:
            if((attaquant->pv_courant+(degats(attaquant, defenseur, atk)) / 2)>attaquant->pv_max){
                attaquant->pv_courant=attaquant->pv_max;
            }
            else{
                attaquant->pv_courant += (degats(attaquant, defenseur, atk)) / 2;
            }
            printf("\n");
            aff_char(attaquant->nom_poke);
            printf(" draine des pv");
            break;

        case Douche_froide:
        case Abattage:
        case Aboiement:
            defenseur->attaque = (5 * (defenseur->attaque)) / 6;
            printf("\nL'attaque de ");
            aff_char(defenseur->nom_poke);
            printf(" diminue ");
            break;

        case Danse_lame:
            attaquant->attaque = (4 * (attaquant->attaque)) / 3;
            printf("\nL'attaque de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente beaucoup");
            break;

        case Mur_de_fer:
            attaquant->defense = (4 * (attaquant->defense)) / 3;
            printf("\nLa defense de ");
            aff_char(attaquant->nom_poke);
            printf(" augmente beaucoup");
            break;

        case Feu_Follet:
            if (defenseur->t != Feu) {
                defenseur->etat = Brulure;
                printf("\n");
                aff_char(defenseur->nom_poke);
                printf(" est brule");
            }
            break;

        default:
            break;
    }
}
Comp maj_damage(Pokemon* offense, Pokemon** adversaires, Pokemon** cible){
    Comp result;
    Comp* adr=&(offense->atkbase);
    float max=0.0;
    *cible=adversaires[0];
    for(int j=0; j<3; j++){
        if(degats(offense, adversaires[j], offense->atkbase)>max){
            result=offense->atkbase;
            *cible=adversaires[j];
            max=degats(offense, adversaires[j], offense->atkbase);
            adr=&(offense->atkbase);
        }
        if((degats(offense, adversaires[j], offense->spe1)>max) && offense->spe1.cooldown==0){
            result=offense->spe1;
            *cible=adversaires[j];
            max=degats(offense, adversaires[j], offense->spe1);
            adr=&(offense->spe1);
        }
        if((degats(offense, adversaires[j], offense->spe2)>max) && offense->spe2.cooldown==0){
            result=offense->spe2;
            *cible=adversaires[j];
            max=degats(offense, adversaires[j], offense->spe2);
            adr=&(offense->spe2);
        }
        if((degats(offense, adversaires[j], offense->spe3)>max) && offense->spe3.cooldown==0){
            result=offense->spe3;
            *cible=adversaires[j];
            max=degats(offense, adversaires[j], offense->spe3);
            adr=&(offense->spe3);
        }
    }
    (*adr).cooldown=(*adr).cooldownmax;   
    return result;
}
Comp choix_bot_spe(Pokemon* offense, Pokemon** adversaires, Pokemon** cible, int nb){
    Comp result=offense->atkbase;
    Comp* adr=&(offense->atkbase);
    if(offense->pv_courant > (offense->pv_max*8)/10){
        if(nb==1){
            if(offense->spe1.comp==Feu_Follet || offense->spe1.comp==Plenitude || offense->spe1.comp==Douche_froide || offense->spe1.comp==Gonflette || offense->spe1.comp==Mur_de_fer || offense->spe1.comp==Cage_eclair || offense->spe1.comp==Danse_draco){
                if(offense->spe1.cooldown==0){
                    result=offense->spe1;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    }           
                    adr=&(offense->spe1);
                }                
            }
        }
        else if(nb==2){
            if(offense->spe2.comp == Feu_Follet || offense->spe2.comp == Plenitude || offense->spe2.comp == Douche_froide || offense->spe2.comp == Gonflette || offense->spe2.comp == Mur_de_fer || offense->spe2.comp == Cage_eclair || offense->spe2.comp == Danse_draco){
                if(offense->spe2.cooldown==0){
                    result = offense->spe2;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    } 
                    adr = &(offense->spe2);
                }
            }            
        }
        else if(nb==3){
            if(offense->spe3.comp == Feu_Follet || offense->spe3.comp == Plenitude || offense->spe3.comp == Douche_froide || offense->spe3.comp == Gonflette || offense->spe3.comp == Mur_de_fer || offense->spe3.comp == Cage_eclair || offense->spe3.comp == Danse_draco){
                if(offense->spe3.cooldown==0){
                    result = offense->spe3;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    } 
                    adr = &(offense->spe3);
                }                
            }            
        }
    }
    if(offense->pv_courant < (offense->pv_max*3)/10){
        if(nb==1){
            if(offense->spe1.comp==Abri || offense->spe1.comp==Repos){
                if(offense->spe1.cooldown==0){
                    result=offense->spe1;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    }           
                    adr=&(offense->spe1);
                }     
            }
        }
        else if(nb==2){
            if(offense->spe2.comp == Abri || offense->spe2.comp == Repos){
                if(offense->spe2.cooldown==0){
                    result = offense->spe2;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    } 
                    adr = &(offense->spe2);
                }
            }           
        }
        else if(nb==3){
            if(offense->spe3.comp == Abri || offense->spe3.comp == Repos){
                result = offense->spe3;
                if(offense->spe3.cooldown==0){
                    result = offense->spe3;
                    for(int j=0;j<3;j++){
                        if(adversaires[j]->pv_courant>0){
                            *cible=adversaires[j];
                        }
                    } 
                    adr = &(offense->spe3);
                }
            }            
        }
    }
    if(adr!=(&(offense->atkbase))){
        (*adr).cooldown=(*adr).cooldownmax;
    }
    return result;
}
void fin_e_a_b(Pokemon* offense, Pokemon* cible, Comp choix){
    int x=0;
    int aleapara=rand()%100+1;
    int aleagel=rand()%100+1;
    if (cible == NULL || cible->pv_courant <= 0) {
        return;
    }    
    printf("\n");
    aff_char(offense->nom_poke);
    printf(" utilise ");
    aff_atk(choix.comp);
    printf(" sur ");
    aff_char(cible->nom_poke);
    if(((choix.type==Feu) && (cible->t==Plante)) || ((choix.type==Feu) && (cible->t==Glace)) || ((choix.type==Feu) && (cible->t==Insecte)) || ((choix.type==Feu) && (cible->t==Acier)) || ((choix.type==Eau) && (cible->t==Feu)) || ((choix.type==Eau) && (cible->t==Sol)) || ((choix.type==Eau) && (cible->t==Roche)) || ((choix.type==Plante) && (cible->t==Eau)) || ((choix.type==Plante) && (cible->t==Sol)) || ((choix.type==Plante) && (cible->t==Roche)) || ((choix.type==Electrik) && (cible->t==Eau)) || ((choix.type==Electrik) && (cible->t==Vol)) || ((choix.type==Glace) && (cible->t==Plante)) || ((choix.type==Glace) && (cible->t==Sol)) || ((choix.type==Glace) && (cible->t==Vol)) || ((choix.type==Glace) && (cible->t==Dragon))){
        printf("\nL'attaque est super efficace");
    }   
    if(((choix.type==Combat) && (cible->t==Normal)) || ((choix.type==Combat) && (cible->t==Glace)) || ((choix.type==Combat) && (cible->t==Roche)) || ((choix.type==Combat) && (cible->t==Tenebres)) || ((choix.type==Combat) && (cible->t==Acier)) || ((choix.type==Poison) && (cible->t==Plante)) || ((choix.type==Poison) && (cible->t==Fee)) || ((choix.type==Sol) && (cible->t==Feu)) || ((choix.type==Sol) && (cible->t==Electrik)) || ((choix.type==Sol) && (cible->t==Poison)) || ((choix.type==Sol) && (cible->t==Roche)) || ((choix.type==Sol) && (cible->t==Acier)) || ((choix.type==Vol) && (cible->t==Plante)) || ((choix.type==Vol) && (cible->t==Combat)) || ((choix.type==Vol) && (cible->t==Insecte)) || ((choix.type==Psy) && (cible->t==Combat)) || ((choix.type==Psy) && (cible->t==Poison)) || ((choix.type==Insecte) && (cible->t==Plante)) || ((choix.type==Insecte) && (cible->t==Psy)) || ((choix.type==Insecte) && (cible->t==Tenebres))){
        printf("\nL'attaque est super efficace");
    }    
    if(((choix.type==Normal) && (cible->t==Roche)) || ((choix.type==Normal) && (cible->t==Acier)) || ((choix.type==Feu) && (cible->t==Feu)) || ((choix.type==Feu) && (cible->t==Eau)) || ((choix.type==Feu) && (cible->t==Roche)) || ((choix.type==Feu) && (cible->t==Dragon)) || ((choix.type==Eau) && (cible->t==Eau)) || ((choix.type==Eau) && (cible->t==Plante)) || ((choix.type==Eau) && (cible->t==Dragon)) || ((choix.type==Plante) && (cible->t==Feu)) || ((choix.type==Plante) && (cible->t==Plante)) || ((choix.type==Plante) && (cible->t==Poison)) || ((choix.type==Plante) && (cible->t==Vol)) || ((choix.type==Plante) && (cible->t==Insecte)) || ((choix.type==Plante) && (cible->t==Dragon)) || ((choix.type==Electrik) && (cible->t==Plante)) || ((choix.type==Electrik) && (cible->t==Electrik)) || ((choix.type==Electrik) && (cible->t==Dragon)) || ((choix.type==Glace) && (cible->t==Feu)) || ((choix.type==Glace) && (cible->t==Eau)) || ((choix.type==Glace) && (cible->t==Glace)) || ((choix.type==Glace) && (cible->t==Acier)) || ((choix.type==Combat) && (cible->t==Poison)) || ((choix.type==Combat) && (cible->t==Vol)) || ((choix.type==Combat) && (cible->t==Psy)) || ((choix.type==Combat) && (cible->t==Insecte)) || ((choix.type==Combat) && (cible->t==Fee)) || ((choix.type==Poison) && (cible->t==Poison)) || ((choix.type==Poison) && (cible->t==Sol)) || ((choix.type==Poison) && (cible->t==Roche)) || ((choix.type==Poison) && (cible->t==Spectre)) || ((choix.type==Sol) && (cible->t==Plante)) || ((choix.type==Sol) && (cible->t==Insecte)) || ((choix.type==Vol) && (cible->t==Electrik)) || ((choix.type==Vol) && (cible->t==Roche)) || ((choix.type==Vol) && (cible->t==Acier)) || ((choix.type==Psy) && (cible->t==Psy)) || ((choix.type==Psy) && (cible->t==Acier)) || ((choix.type==Insecte) && (cible->t==Feu)) || ((choix.type==Insecte) && (cible->t==Combat)) || ((choix.type==Insecte) && (cible->t==Spectre)) || ((choix.type==Roche) && (cible->t==Combat)) || ((choix.type==Roche) && (cible->t==Sol)) || ((choix.type==Roche) && (cible->t==Acier)) || ((choix.type==Spectre) && (cible->t==Tenebres)) || ((choix.type==Dragon) && (cible->t==Acier)) || ((choix.type==Tenebres) && (cible->t==Combat)) || ((choix.type==Tenebres) && (cible->t==Tenebres)) || ((choix.type==Tenebres) && (cible->t==Fee)) || ((choix.type==Acier) && (cible->t==Feu)) || ((choix.type==Acier) && (cible->t==Eau)) || ((choix.type==Acier) && (cible->t==Electrik)) || ((choix.type==Fee) && (cible->t==Feu)) || ((choix.type==Fee) && (cible->t==Poison)) || ((choix.type==Fee) && (cible->t==Acier))){
        printf("\nL'attaque n'est pas très efficace");
    }       
    x=degats(offense, cible, choix);
    if(cible->protec==1){
        printf("\n\n");
        aff_char(cible->nom_poke);
        x=0;
        printf(" s'est protege");
        cible->protec=0;
    }
    if(offense->sleep>0){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" dort il n'a pas pu attaque");
        offense->sleep=offense->sleep-1;
        if(offense->sleep==0){
            offense->etat=Neutre;
        }
        x=0;
    }
    if(aleagel>20 && offense->etat==Gel){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est gele il n'a pas pu attaque");
        x=0;
    }
    else if (offense->etat==Gel){
        offense->etat=Neutre;
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" n'est plus gele");
    }
    if(aleapara<26 && offense->etat==Paralysie){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est paralyse il n'a pas pu attaque");
        x=0;
    }
    else if(x==0 && choix.comp!=Abri && choix.comp!=Feu_Follet && choix.comp!=Danse_lame && choix.comp!=Feu_Follet && choix.comp!=Repos && choix.comp!=Plenitude && choix.comp!=Douche_froide && choix.comp!=Gonflette && choix.comp!=Mur_de_fer && choix.comp!=Cage_eclair && choix.comp!=Danse_draco){
        printf("\nL'attaque a echoue ou a ete esquive");
    }
    effet_spe(offense, cible, choix);
    if (offense->etat == Brulure) {
        cible->pv_courant -= x / 2;
    } 
    else {
        cible->pv_courant -= x;
    }
    if(cible->pv_courant<0){
        cible->pv_courant=0;
        cible->vitesse=0;
        printf("\n");
        aff_char(cible->nom_poke);
        printf(" est KO");
    }
}
void effect_atk_bot(Pokemon* offense, Pokemon** team, Pokemon** adversaires){
    printf("\n\n%s", (*offense).nom_poke);
    Pokemon* cible;
    cible=NULL;
    Comp choix;
    for(int j=0; j<3; j++){
        if(((degats(offense, adversaires[j], offense->atkbase))>adversaires[j]->pv_courant) && (adversaires[j]->pv_courant>0)){
            cible=adversaires[j];
            choix=offense->atkbase;
        }
    }
    if(cible==NULL){
        for(int j=0; j<3; j++){
            if(((degats(offense, adversaires[j], offense->spe1)>adversaires[j]->pv_courant && offense->spe1.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                cible=adversaires[j];
                choix=offense->spe1;
                offense->spe1.cooldown=offense->spe1.cooldownmax;
            }
        }
    }
    if(cible==NULL){
        for(int j=0; j<3; j++){
            if(((degats(offense, adversaires[j], offense->spe2)>adversaires[j]->pv_courant && offense->spe2.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                cible=adversaires[j];
                choix=offense->spe2;
                offense->spe2.cooldown=offense->spe2.cooldownmax;
            }
        }
    }
    if(cible==NULL){
        for(int j=0; j<3; j++){
            if(((degats(offense, adversaires[j], offense->spe3)>adversaires[j]->pv_courant && offense->spe3.cooldown==0)) && (adversaires[j]->pv_courant>0)){
                cible=adversaires[j];
                choix=offense->spe3;
                offense->spe3.cooldown=offense->spe3.cooldownmax;
            }
        }
    }
    if(cible==NULL){
        choix=choix_bot_spe(offense, adversaires, &cible, 1);
    }
    if(cible==NULL){
        choix=choix_bot_spe(offense, adversaires, &cible, 2);
    }
    if(cible==NULL){
        choix=choix_bot_spe(offense, adversaires, &cible, 3);
    }
    if(cible==NULL){
        choix=maj_damage(offense, adversaires, &cible);
    }
    if(choix.comp==Abri){
        fin_e_a_b(offense, offense, choix);
    }
    else if(choix.comp==Aboiement || choix.comp==Seisme || choix.comp==Abattage || choix.comp==Surf){
        if(choix.comp==Seisme || choix.comp==Surf){
            offense->pv_courant+=degats(offense, offense, choix);
            for(int l=0; l<3; l++){
                if (team[l] != NULL && team[l]->pv_courant > 0) {
                    fin_e_a_b(offense, team[l], choix);
                }
            }            
            for(int l=0; l<3; l++){
                if (adversaires[l] != NULL && adversaires[l]->pv_courant > 0) {
                    fin_e_a_b(offense, adversaires[l], choix);
                }
            }            
        }
        else{
            for(int l=0; l<3; l++){
                if (adversaires[l] != NULL && adversaires[l]->pv_courant > 0) {
                    fin_e_a_b(offense, adversaires[l], choix);
                }
            }
            
        }
    }
    else{
        fin_e_a_b(offense, cible, choix);
    }
    effect_status(offense, offense->sleep);
}
Pokemon* choix_target(Pokemon** team, Pokemon** opp){
    char name[100];
    int occurences = 0;
    int rep = 0;
    Pokemon* cible = NULL;
    do {
        occurences = 0;
        printf("\nChoisissez une cible :\n");
        for (int j = 0; j < 3; j++) {
            if (opp[j]->pv_courant > 0) {
                printf("- "); 
                aff_char(opp[j]->nom_poke); 
                printf(" (adverse)\n");
            }
        }
        for (int j = 0; j < 3; j++) {
            if (team[j]->pv_courant > 0) {
                printf("- "); 
                aff_char(team[j]->nom_poke); 
                printf(" (allié)\n");
            }
        }
        scanf("%s", name);
        for (int j = 0; j < 3; j++) {
            if (compare_chaine(name, opp[j]->nom_poke) == 0 && opp[j]->pv_courant > 0) {
                cible = opp[j];
                occurences++;
            }
            if (compare_chaine(name, team[j]->nom_poke) == 0 && team[j]->pv_courant > 0) {
                cible = team[j];
                occurences++;
            }
        }
        if (occurences > 1) {
            do {
                printf("\nPlusieurs pokémons ont ce nom. Donnez sa position (1 à 6) :\n");
                printf("1-3 : adversaires, 4-6 : alliés\n");
                scanf("%d", &rep);
            } while (rep < 1 || rep > 6);
            if (!cible) {
                printf("Erreur : cible invalide (NULL)\n");
                exit(1);
            }
            switch(rep) {
                case 1: cible = opp[0]; break;
                case 2: cible = opp[1]; break;
                case 3: cible = opp[2]; break;
                case 4: cible = team[0]; break;
                case 5: cible = team[1]; break;
                case 6: cible = team[2]; break;
            }

            if (cible->pv_courant <= 0) {
                printf("\nCe Pokémon est déjà KO. \nDu mal a lire ?\n");
                cible = NULL;
            }
        }
        if (cible == NULL) {
            printf("\nNom invalide ou Pokémon KO. Veuillez réessayer.\n");
        }
    } while (cible == NULL);
    return cible;
}
void fin_e_a(Pokemon* offense, Pokemon* cible, Comp atk){
    int x=0;
    int aleapara=rand()%100+1;
    int aleagel=rand()%100+1;
    printf("\n");
    aff_char(offense->nom_poke);
    printf(" utilise ");
    aff_atk(atk.comp);
    if(((atk.type==Feu) && (cible->t==Plante)) || ((atk.type==Feu) && (cible->t==Glace)) || ((atk.type==Feu) && (cible->t==Insecte)) || ((atk.type==Feu) && (cible->t==Acier)) || ((atk.type==Eau) && (cible->t==Feu)) || ((atk.type==Eau) && (cible->t==Sol)) || ((atk.type==Eau) && (cible->t==Roche)) || ((atk.type==Plante) && (cible->t==Eau)) || ((atk.type==Plante) && (cible->t==Sol)) || ((atk.type==Plante) && (cible->t==Roche)) || ((atk.type==Electrik) && (cible->t==Eau)) || ((atk.type==Electrik) && (cible->t==Vol)) || ((atk.type==Glace) && (cible->t==Plante)) || ((atk.type==Glace) && (cible->t==Sol)) || ((atk.type==Glace) && (cible->t==Vol)) || ((atk.type==Glace) && (cible->t==Dragon))){
        printf("\nL'attaque est super efficace");
    }    
    if(((atk.type==Combat) && (cible->t==Normal)) || ((atk.type==Combat) && (cible->t==Glace)) || ((atk.type==Combat) && (cible->t==Roche)) || ((atk.type==Combat) && (cible->t==Tenebres)) || ((atk.type==Combat) && (cible->t==Acier)) || ((atk.type==Poison) && (cible->t==Plante)) || ((atk.type==Poison) && (cible->t==Fee)) || ((atk.type==Sol) && (cible->t==Feu)) || ((atk.type==Sol) && (cible->t==Electrik)) || ((atk.type==Sol) && (cible->t==Poison)) || ((atk.type==Sol) && (cible->t==Roche)) || ((atk.type==Sol) && (cible->t==Acier)) || ((atk.type==Vol) && (cible->t==Plante)) || ((atk.type==Vol) && (cible->t==Combat)) || ((atk.type==Vol) && (cible->t==Insecte)) || ((atk.type==Psy) && (cible->t==Combat)) || ((atk.type==Psy) && (cible->t==Poison)) || ((atk.type==Insecte) && (cible->t==Plante)) || ((atk.type==Insecte) && (cible->t==Psy)) || ((atk.type==Insecte) && (cible->t==Tenebres))){
        printf("\nL'attaque est super efficace");
    }    
    if(((atk.type==Normal) && (cible->t==Roche)) || ((atk.type==Normal) && (cible->t==Acier)) || ((atk.type==Feu) && (cible->t==Feu)) || ((atk.type==Feu) && (cible->t==Eau)) || ((atk.type==Feu) && (cible->t==Roche)) || ((atk.type==Feu) && (cible->t==Dragon)) || ((atk.type==Eau) && (cible->t==Eau)) || ((atk.type==Eau) && (cible->t==Plante)) || ((atk.type==Eau) && (cible->t==Dragon)) || ((atk.type==Plante) && (cible->t==Feu)) || ((atk.type==Plante) && (cible->t==Plante)) || ((atk.type==Plante) && (cible->t==Poison)) || ((atk.type==Plante) && (cible->t==Vol)) || ((atk.type==Plante) && (cible->t==Insecte)) || ((atk.type==Plante) && (cible->t==Dragon)) || ((atk.type==Electrik) && (cible->t==Plante)) || ((atk.type==Electrik) && (cible->t==Electrik)) || ((atk.type==Electrik) && (cible->t==Dragon)) || ((atk.type==Glace) && (cible->t==Feu)) || ((atk.type==Glace) && (cible->t==Eau)) || ((atk.type==Glace) && (cible->t==Glace)) || ((atk.type==Glace) && (cible->t==Acier)) || ((atk.type==Combat) && (cible->t==Poison)) || ((atk.type==Combat) && (cible->t==Vol)) || ((atk.type==Combat) && (cible->t==Psy)) || ((atk.type==Combat) && (cible->t==Insecte)) || ((atk.type==Combat) && (cible->t==Fee)) || ((atk.type==Poison) && (cible->t==Poison)) || ((atk.type==Poison) && (cible->t==Sol)) || ((atk.type==Poison) && (cible->t==Roche)) || ((atk.type==Poison) && (cible->t==Spectre)) || ((atk.type==Sol) && (cible->t==Plante)) || ((atk.type==Sol) && (cible->t==Insecte)) || ((atk.type==Vol) && (cible->t==Electrik)) || ((atk.type==Vol) && (cible->t==Roche)) || ((atk.type==Vol) && (cible->t==Acier)) || ((atk.type==Psy) && (cible->t==Psy)) || ((atk.type==Psy) && (cible->t==Acier)) || ((atk.type==Insecte) && (cible->t==Feu)) || ((atk.type==Insecte) && (cible->t==Combat)) || ((atk.type==Insecte) && (cible->t==Spectre)) || ((atk.type==Roche) && (cible->t==Combat)) || ((atk.type==Roche) && (cible->t==Sol)) || ((atk.type==Roche) && (cible->t==Acier)) || ((atk.type==Spectre) && (cible->t==Tenebres)) || ((atk.type==Dragon) && (cible->t==Acier)) || ((atk.type==Tenebres) && (cible->t==Combat)) || ((atk.type==Tenebres) && (cible->t==Tenebres)) || ((atk.type==Tenebres) && (cible->t==Fee)) || ((atk.type==Acier) && (cible->t==Feu)) || ((atk.type==Acier) && (cible->t==Eau)) || ((atk.type==Acier) && (cible->t==Electrik)) || ((atk.type==Fee) && (cible->t==Feu)) || ((atk.type==Fee) && (cible->t==Poison)) || ((atk.type==Fee) && (cible->t==Acier))){
        printf("\nL'attaque n'est pas très efficace");
    }           
    x=degats(offense, cible, atk);
    if(cible->protec==1){
        printf("\n\n");
        aff_char(cible->nom_poke);
        x=0;
        printf(" s'est protege");
        cible->protec=0;
    }
    if(offense->sleep>0){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" dort il n'a pas pu attaque");
        offense->sleep=offense->sleep-1;
        if(offense->sleep==0){
            offense->etat=Neutre;
        }
        x=0;
    }
    if(aleagel>20 && offense->etat==Gel){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est gele il n'a pas pu attaque");
        x=0;
    }
    else if (offense->etat==Gel){
        offense->etat=Neutre;
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" n'est plus gele");
    }
    if(aleapara<26 && offense->etat==Paralysie){
        printf("\n");
        aff_char(offense->nom_poke);
        printf(" est paralyse il n'a pas pu attaque");
        x=0;
    }
    else if(x==0 && atk.comp!=Abri && atk.comp!=Feu_Follet && atk.comp!=Danse_lame && atk.comp!=Feu_Follet && atk.comp!=Repos && atk.comp!=Plenitude && atk.comp!=Douche_froide && atk.comp!=Gonflette && atk.comp!=Mur_de_fer && atk.comp!=Cage_eclair && atk.comp!=Danse_draco){
        printf("\nL'attaque a echoue ou a ete esquive");    
    }
    effet_spe(offense, cible, atk);
    if(cible->protec==1){
        x=0;
        printf(" s'est protege");
        cible->protec=0;
    }
    if (offense->etat == Brulure) {
        cible->pv_courant -= x / 2;
    } 
    else {
        cible->pv_courant -= x;
    }
    if(cible->pv_courant<0){
        cible->pv_courant=0;
        cible->vitesse=0;
        printf("\n");
        aff_char(cible->nom_poke);
        printf(" est KO");
    }
}
void effect_atk(Pokemon* offense, Pokemon** team, Pokemon** adversaires, Comp atk){
    Pokemon* cible;
    if(atk.comp==Abri || atk.comp==Danse_lame || atk.comp==Repos || atk.comp==Plenitude || atk.comp==Gonflette || atk.comp==Aboiement || atk.comp==Mur_de_fer || atk.comp==Seisme || atk.comp==Abattage || atk.comp==Danse_draco || atk.comp==Surf){
        if(atk.comp==Aboiement || atk.comp==Abattage){
            for(int o=0; o<3; o++){
                if (adversaires[o] != NULL && adversaires[o]->pv_courant > 0){
                    fin_e_a(offense, adversaires[o], atk);
                }
            }            
        }
        else if(atk.comp==Seisme || atk.comp==Surf){
            offense->pv_courant+=degats(offense, offense, atk);
            for(int o=0; o<3; o++){
                if (team[o] != NULL && team[o]->pv_courant > 0){
                    fin_e_a(offense, team[o], atk);
                }
            }            
            for(int o=0; o<3; o++){
                if (adversaires[o] != NULL && adversaires[o]->pv_courant > 0){
                    fin_e_a(offense, adversaires[o], atk);
                }
            }            
        }
    }
    else{
        cible=choix_target(team, adversaires);
        fin_e_a(offense, cible, atk);
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
int fight(Pokemon** player, Pokemon** bot, int mode){//rajouter un srand dans le main
    for(int h=0; h<3; h++){
        player[h]->protec=0;
        bot[h]->protec=0;
    }
    if(mode==2){
        while (((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0) && ((*(bot[0])).pv_courant>0 || (*(bot[1])).pv_courant>0 || (*(bot[2])).pv_courant>0)){
            speedbarplus(player[0], player[1], player[2], bot[0], bot[1], bot[2]);
            if(plus1000(*(player[0]), *(player[1]), *(player[2]), *(bot[0]), *(bot[1]), *(bot[2]))==1){
                sleep(2);
                system("clear");
                for(int f=0; f<15; f++){
                    printf("\n");
                }
                printf("\n\n");
                for(int t=0; t<3; t++){//a enlever uniquement pour les tests
                    aff_char(bot[t]->nom_poke);
                    printf(" : %f                      ", bot[t]->pv_courant);
                }
                for(int f=0; f<15; f++){
                    printf("\n");
                }
                for(int t=0; t<3; t++){//a enlever uniquement pour les tests
                    aff_char(player[t]->nom_poke);
                    printf(" : %f                      ", player[t]->pv_courant);
                }
                if(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[0] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[1] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[2]){
                    effect_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), player, bot, choix_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])));
                    effect_status(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->sleep);
                    cooldown1poke(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]));
                }
                else{
                    effect_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), bot, player, choix_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])));
                    effect_status(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->sleep);
                    cooldown1poke(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]));
                }
                (maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->speedbar)=0;
                for(int g=0; g<3; g++){
                    if(player[g]->pv_courant<=0.0){
                        player[g]->vitesse=0;
                        player[g]->speedbar=0;
                    } 
                    if(bot[g]->pv_courant<=0.0){
                        bot[g]->vitesse=0;
                        bot[g]->speedbar=0;
                    }
                }      
            }
        }
        if((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0){
            printf("\nP1 a gagne!!!");
            return 0;
        }
        else{
            printf("\nP2 a gagne!!!");
            return -1;
        }
    }
    else{
        while (((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0) && ((*(bot[0])).pv_courant>0 || (*(bot[1])).pv_courant>0 || (*(bot[2])).pv_courant>0)){
            speedbarplus(player[0], player[1], player[2], bot[0], bot[1], bot[2]);
            if(plus1000(*(player[0]), *(player[1]), *(player[2]), *(bot[0]), *(bot[1]), *(bot[2]))==1){
                sleep(2);
                for(int f=0; f<15; f++){
                    printf("\n");
                }
                for(int t=0; t<3; t++){//a enlever uniquement pour les tests
                    aff_char(bot[t]->nom_poke);
                    printf(" : %f                      ", bot[t]->pv_courant);
                }
                for(int f=0; f<15; f++){
                    printf("\n");
                }
                for(int t=0; t<3; t++){//a enlever uniquement pour les tests
                    aff_char(player[t]->nom_poke);
                    printf(" : %f                      ", player[t]->pv_courant);
                }
                printf("\n\n");
                if(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[0] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[1] || maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])==player[2]){
                    effect_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), player, bot, choix_atk(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])));
                    effect_status(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->sleep);
                    cooldown1poke(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]));
                }
                else{
                    effect_atk_bot(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]), bot, player);
                    cooldown1poke(maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2]));
                }
                (maj6(player[0], player[1], player[2], bot[0], bot[1], bot[2])->speedbar)=0;
            }
        }
        if((*(player[0])).pv_courant>0 || (*(player[1])).pv_courant>0 || (*(player[2])).pv_courant>0){
            printf("\nBravo vous avez GAGNE!!!");
            return 0;
        }
        else{
            printf("\nHahaha t'as perdu t'es trop nul Bouhhh");
            return -1;
        }
    }
}

#include "Biblio_lin.h"
#include "combat.h"
#include "creapers.h"
#include "affichagevs.h"
int main(){
    srand(time(NULL));
    int num=1;
    int mode=0;
    int verif=0;
    int* adr=&num;
    Pokemon** p1;
    Pokemon** p2;
    printf("\n                                         BIENVENUE DANS CYMON ");
    do{
        printf("\n\nChoisissez votre mode de jeu : \n 1- Mode Solo \n 2- Mode Multi joueur\nRentrer votre choix ici : ");
        verif=scanf("%d", &mode);
        vide_buffer();
    }while((mode!=1 && mode!=2) || verif!=1);
    if(mode==2){
        printf("Vous avez choisi le mode multijoueur");
        printf("\n\n                             Veuillez creer une equipe pour P1");
        p1=create_team_joueur(adr);
        printf("\n\n                             Veuillez creer une equipe pour P2");
        p2=create_team_joueur(adr);
    }
    else{
        printf("Vous avez choisi le mode solo");
        p1=create_team_joueur(adr);
        p2=create_team_ordi(adr);
    }
    fight(p1, p2, mode);
    return 0;
}

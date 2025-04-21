#include "Biblio_lin.h"
#include "combat.h"
#include "creapers.h"
int main(){
    srand(time(NULL));
    int num=1;
    int* adr=&num;
    Pokemon** teamplayer;
    Pokemon** teambot;
    printf("\n                                         BIENVENUE DANS CYMON ");
    printf("\nVeuillez creer une equipe");
    teamplayer=create_team_joueur(adr);
    teambot=create_team_ordi(adr);
    fight(teamplayer, teambot);
}

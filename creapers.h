#ifndef CREAPERS_H
#define CREAPERS_H
void crea_comp(Comp* comp, Competence_spe comp_spe); 
void create_part2_poke(FILE* file, Pokemon* poke, int* nb);
Pokemon* create_part1_poke_joueur(int* numero);
Pokemon* create_part1_poke_ordi(int* numero);
Pokemon** create_team_joueur(int* numero);
Pokemon** create_team_ordi(int* numero);
#endif

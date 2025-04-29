#ifndef COMBAT_H
#define COMBAT_H
float type_effect(Type atk, Type def);
void aff_effect_atk(Competence_spe atk);
void aff_atk(Competence_spe atk);
void speedbarplus(Pokemon* un, Pokemon* deux, Pokemon* trois, Pokemon* quatre, Pokemon* cinq, Pokemon* six);
int plus1000(Pokemon un, Pokemon deux, Pokemon trois, Pokemon quatre, Pokemon cinq, Pokemon six);
Comp choix_atk(Pokemon* bu);
int attaque_esquivee(Comp atk, Pokemon* attaque, Pokemon* defend);
float degats(Pokemon* attaquant, Pokemon* defenseur, Comp atq);
void effet_spe(Pokemon* attaquant, Pokemon* defenseur, Comp atk);
Comp maj_damage(Pokemon* offense, Pokemon** adversaires, Pokemon** cible);
Comp choix_bot_spe(Pokemon* offense, Pokemon** adversaires, Pokemon** cible, int nb);
void fin_e_a_b(Pokemon* offense, Pokemon* cible, Comp choix);
void effect_atk_bot(Pokemon* offense, Pokemon** team, Pokemon** adversaires);
Pokemon* choix_target(Pokemon** team, Pokemon** opp);
void fin_e_a(Pokemon* offense, Pokemon* cible, Comp atk);
void effect_atk(Pokemon* offense, Pokemon** team, Pokemon** adversaires, Comp atk);
Pokemon* maj(Pokemon* un, Pokemon* deux);
Pokemon* maj6(Pokemon* un, Pokemon* deux, Pokemon* trois, Pokemon* quatre, Pokemon* cinq, Pokemon* six);
void cooldown1poke(Pokemon* poke);
void effect_status(Pokemon* poke, int nbtour);
int fight(Pokemon** player, Pokemon** bot, int mode);
#endif 

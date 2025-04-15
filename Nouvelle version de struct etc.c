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
    float precision;
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

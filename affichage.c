// Fonction pour afficher une barre de vie (simple)
void afficher_barre_de_vie(int pv_courant, int pv_max) {
    int barres = 50;
    int progression = (pv_courant * barres) / pv_max;
    for (int i = 0; i < barres; i++) {
        if (i < progression)
            printf("█");
        else
            printf("░");
    }
}

// Fonction d'affichage d'un Pokémon
void afficher_pokemon(Pokemon* poke) {
    // Définir les états possibles
    char* etat_str;
    switch (poke->etat) {
        case Neutre: etat_str = "Neutre"; break;
        case Brulure: etat_str = "🔥"; break;
        case Gel: etat_str = "❄️"; break;
        case Empoisonnement: etat_str = "🧪"; break;
        case Paralysie: etat_str = "⚡"; break;
        case Sommeil: etat_str = "💤"; break;
        case KO: etat_str = "☠️"; break;
        default: etat_str = "Inconnu"; break;
    }

    printf("Nom: %s\n", poke->nom_poke);
    printf("PV: ");
    afficher_barre_de_vie(poke->pv_courant, poke->pv_max);
    printf(" (%d/%d)\n", poke->pv_courant, poke->pv_max);
    printf("Attaque: %d | Defense: %d | Vitesse: %d\n", poke->attaque, poke->defense, poke->vitesse);
    printf("Etat: %s\n", etat_str);
    printf("\n");
}

// Fonction pour afficher les attaques d'un Pokémon
void afficher_attaques(Pokemon* poke) {
    printf("Attaques:\n");
    printf("- Flammeche: Feu | Puissance: 50 | Precision: 95\n");
    printf("- Nitrocharge: Electrik | Puissance: 50 | Precision: 95\n");
    printf("- Abri: Normal | Puissance: 0 | Precision: 100\n");
    printf("- Feu Follet: Feu | Puissance: 0 | Precision: 90\n");
    printf("\n");
}

// Fonction d'affichage de l'état du combat
void afficher_combat(Pokemon** equipe_joueur, Pokemon** equipe_ordi) {
    printf("\n=== Combat en cours ===\n");

    // Afficher l'équipe du joueur
    printf("\n=== Equipe Joueur ===\n");
    for (int i = 0; i < 3; i++) {
        afficher_pokemon(equipe_joueur[i]);
        afficher_attaques(equipe_joueur[i]);
    }

    // Afficher l'équipe de l'adversaire
    printf("\n=== Equipe Adversaire ===\n");
    for (int i = 0; i < 3; i++) {
        afficher_pokemon(equipe_ordi[i]);
        afficher_attaques(equipe_ordi[i]);
    }

    printf("\n=========================\n");
}


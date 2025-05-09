#include "Biblio_lin.h"

void jouer_musique(int choix, int boucle){
    Mix_Music *musique = NULL;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erreur SDL_mixer : %s\n", Mix_GetError());
        return;
    }
    if(choix==1){
        musique = Mix_LoadMUS("PU-Credits.ogg"); // ici ton fichier OGG
    }
    else if(choix == 2){
        musique = Mix_LoadMUS("PU-Credits.ogg");
    }
    else{
        musique = Mix_LoadMUS("PU-Credits.ogg");
    }
    if(musique==NULL){
        printf("Erreur de chargement de la musique : %s\n", Mix_GetError());
    }
    Mix_PlayMusic(musique, boucle); // -1 pour jouer en boucle
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
}
int sdl_scanf_int(int nb){
    int value=0;
    SDL_Event event;
    printf("\nsdl_scanf_int");
    if(nb==1){
        while(value<1 || value>6){
            SDL_WaitEvent(&event);
            if (event.type == SDL_QUIT) {
                return -1; // Sortie forcée
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                printf("Touche pressée : %d\n", key);
                if(key==49){
                    return 1;
                }
                else if(key==50){
                    return 2;
                }
                else if(key==51){
                    return 3;
                }
                else if(key==52){
                    return 4;
                }
                else if(key==53){
                    return 5;
                }
                else if(key==54){
                    return 6;
                }
                else if(key==SDLK_RETURN){
                    return -1;
                }
                else {
                    printf("Valeur attendue\n");
                }
            }
        }
    }
    else if(nb==2){
        while(value!=1 && value!=2){
            SDL_WaitEvent(&event);
            if (event.type == SDL_QUIT) {
                return -1; // Sortie forcée
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                printf("Touche pressée : %d\n", key);
                if(key==49){
                    return 1;
                }
                else if(key==50){
                    return 2;
                }
                else if(key==SDLK_RETURN){
                    return -1;
                }
                else {
                    printf("Valeur attendue\n");
                }
            }
        }
    }
    return 0;
}
void sdl_scanf_str(char* str){
    char* chaine=malloc(sizeof(char)*45);
    SDL_Event event;
    int i=0;
    int finish=0;
    printf("Attente de saisie dans sdl_scanf_str...\n");
    while(finish==0){
        SDL_WaitEvent(&event); 
        if (event.type == SDL_QUIT) {
            free(chaine);
            exit(0); // Sortie forcée 
        }
        if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            printf("Touche pressée : %c\n", key);
            if(key==SDLK_RETURN){
                chaine[i]='\0';
                finish=1;
            }
            else if((key >= SDLK_a && key <= SDLK_z) || (key >= SDLK_0 && key <= SDLK_9) || key == SDLK_SPACE){
                chaine[i]=(char)key;
            }
            else if (key == SDLK_BACKSPACE && i > 0) {
                i--;
                chaine[i] = '\0'; // efface le dernier caractère
            }            
            i++;
        }
    }  
    for(int j=0; j<45; j++){
        str[j]=chaine[j];
    }
}
void aff_cooldown(Pokemon* poke, SDL_Renderer* renderer2){
    SDL_Texture* texture2_2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Rect place={0, 0, 473, 748};
    if(poke->spe1.cooldown==0){
        surface2=IMG_Load("0.png");
    }
    if(poke->spe1.cooldown==1){
        surface2=IMG_Load("1.png");
    }
    if(poke->spe1.cooldown==2){
        surface2=IMG_Load("2.png");
    }
    if(poke->spe1.cooldown==3){
        surface2=IMG_Load("3.png");
    }
    if(poke->spe1.cooldown==4){
        surface2=IMG_Load("4.png");
    }
    if(poke->spe1.cooldown==5){
        surface2=IMG_Load("5.png");
    }
    if(poke->spe1.cooldown==6){
        surface2=IMG_Load("6.png");
    }
    if(poke->spe1.cooldown==7){
        surface2=IMG_Load("7.png");
    }
    if(poke->spe1.cooldown==8){
        surface2=IMG_Load("8.png");
    }
    if(poke->spe1.cooldown==9){
        surface2=IMG_Load("9.png");
    }
    if (surface2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
    if (texture2_2 == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
    SDL_RenderPresent(renderer2);
    place.x=734;
    if(poke->spe2.cooldown==0){
        surface2=IMG_Load("0.png");
    }
    if(poke->spe2.cooldown==1){
        surface2=IMG_Load("1.png");
    }
    if(poke->spe2.cooldown==2){
        surface2=IMG_Load("2.png");
    }
    if(poke->spe2.cooldown==3){
        surface2=IMG_Load("3.png");
    }
    if(poke->spe2.cooldown==4){
        surface2=IMG_Load("4.png");
    }
    if(poke->spe2.cooldown==5){
        surface2=IMG_Load("5.png");
    }
    if(poke->spe2.cooldown==6){
        surface2=IMG_Load("6.png");
    }
    if(poke->spe2.cooldown==7){
        surface2=IMG_Load("7.png");
    }
    if(poke->spe2.cooldown==8){
        surface2=IMG_Load("8.png");
    }
    if(poke->spe2.cooldown==9){
        surface2=IMG_Load("9.png");
    }
    if (surface2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
    if (texture2_2 == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
    SDL_RenderPresent(renderer2);
    place.x=994;
    if(poke->spe3.cooldown==0){
        surface2=IMG_Load("0.png");
    }
    if(poke->spe3.cooldown==1){
        surface2=IMG_Load("1.png");
    }
    if(poke->spe3.cooldown==2){
        surface2=IMG_Load("2.png");
    }
    if(poke->spe3.cooldown==3){
        surface2=IMG_Load("3.png");
    }
    if(poke->spe3.cooldown==4){
        surface2=IMG_Load("4.png");
    }
    if(poke->spe3.cooldown==5){
        surface2=IMG_Load("5.png");
    }
    if(poke->spe3.cooldown==6){
        surface2=IMG_Load("6.png");
    }
    if(poke->spe3.cooldown==7){
        surface2=IMG_Load("7.png");
    }
    if(poke->spe3.cooldown==8){
        surface2=IMG_Load("8.png");
    }
    if(poke->spe3.cooldown==9){
        surface2=IMG_Load("9.png");
    }
    if (surface2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
    if (texture2_2 == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
    SDL_RenderPresent(renderer2);
}
void aff_barre(Pokemon* poke, SDL_Renderer* renderer2, int position){
    SDL_Rect rect_vie={279, 83, 85, 18};
    SDL_Rect rect_speedbar={304, 114, 60, 18};
    SDL_Color rouge = {255, 0, 0, 255};
    SDL_Color vert = {0, 255, 0, 255};
    SDL_Color gris = {211, 211, 211, 255};
    SDL_Color bleu_clair = {34, 95, 120, 255};
    SDL_Color jaune = {255, 255, 0, 255};
    SDL_Color violet = {128, 0, 128, 255};
    SDL_Color orange = {255, 165, 0, 255};
    SDL_Color noir = {0, 0, 0, 255};
    if(position==2){
        rect_vie.x=679;
        rect_speedbar.x=704;
    }
    if(position==3){
        rect_vie.x=1079;
        rect_speedbar.x=1104;
    }

    if(position==4){
        rect_vie.y=440;
        rect_speedbar.y=440;
    }
    if(position==5){
        rect_vie.y=440;
        rect_vie.x=679;
        rect_speedbar.x=704;
        rect_speedbar.y=440;
    }
    if(position==6){
        rect_vie.y=440;
        rect_vie.x=1079;
        rect_speedbar.x=1104;
        rect_speedbar.y=440;
    }
    if(0 != SDL_SetRenderDrawColor(renderer2, noir.r, noir.g, noir.b, noir.a)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }  
    if(0 != SDL_RenderFillRect(renderer2, &rect_speedbar)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(0 != SDL_RenderFillRect(renderer2, &rect_vie)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(poke->speedbar<1000){
        rect_speedbar.w=(60*poke->speedbar)/1000;
    }
    else{
        rect_speedbar.w=60;
    }
    if(0 != SDL_SetRenderDrawColor(renderer2, vert.r, vert.g, vert.b, vert.a)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    } 
    if(0 != SDL_RenderFillRect(renderer2, &rect_speedbar)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(poke->pv_courant==poke->pv_max){
        rect_vie.w=85;
    }
    else{
        rect_vie.w=(85*(poke->pv_courant))/poke->pv_max;
    }
    if(0 != SDL_SetRenderDrawColor(renderer2, vert.r, vert.g, vert.b, vert.a)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    } 
    if(0 != SDL_RenderFillRect(renderer2, &rect_speedbar)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(0 != SDL_SetRenderDrawColor(renderer2, rouge.r, rouge.g, rouge.b, rouge.a)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    } 
    if(poke->etat==Sommeil){
        if(0 != SDL_SetRenderDrawColor(renderer2, gris.r, gris.g, gris.b, gris.a)){
            fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    if(poke->etat==Gel){
        if(0 != SDL_SetRenderDrawColor(renderer2, bleu_clair.r, bleu_clair.g, bleu_clair.b, bleu_clair.a)){
            fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    if(poke->etat==Paralysie){
        if(0 != SDL_SetRenderDrawColor(renderer2, jaune.r, jaune.g, jaune.b, jaune.a)){
            fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    if(poke->etat==Empoisonnement){
        if(0 != SDL_SetRenderDrawColor(renderer2, violet.r, violet.g, violet.b, violet.a)){
            fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    if(poke->etat==Brulure){
        if(0 != SDL_SetRenderDrawColor(renderer2, orange.r, orange.g, orange.b, orange.a)){
            fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    if(0 != SDL_RenderFillRect(renderer2, &rect_vie)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderPresent(renderer2);
}
SDL_Surface* aff_pokemon_1(Pokemon* poke){
    SDL_Surface* surface3 = NULL;
    if(poke->pv_courant<=0.0){
        surface3 = IMG_Load("Vide.png");
    }
    else if(poke->atkbase.comp==Griffe){
        surface3 = IMG_Load("Absol.png");
    }
    else if(poke->atkbase.comp==Flammeche){
        surface3 = IMG_Load("Arcanin.png");
    }
    else if(poke->atkbase.comp==Choc_Mental){
        surface3 = IMG_Load("Gardevoir.png");
    }
    else if(poke->atkbase.comp==Crocs_givre){
        surface3 = IMG_Load("Givrali.png");
    }
    else if(poke->atkbase.comp==Feuillage){
        surface3 = IMG_Load("Jungko.png");
    }
    else if(poke->atkbase.comp==Balayage){
        surface3 = IMG_Load("Mackogneur.png");
    }
    else if(poke->atkbase.comp==Osmerang){
        surface3 = IMG_Load("Ossatueur.png");
    }
    else if(poke->atkbase.comp==Eclair){
        surface3 = IMG_Load("Pikachu.png");
    }
    else if(poke->atkbase.comp==Pistolet_a_O){
        surface3 = IMG_Load("Tortank.png");
    }
    else if(poke->atkbase.comp==Draco_griffe){
        surface3 = IMG_Load("Tranchodon.png");
    }
    else if (surface3==NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    return surface3;
}
void aff_pokemon_2(Pokemon** p1, Pokemon** p2, SDL_Renderer* renderer2){
    SDL_Texture* texture2_2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Rect place={0, 0, 400, 326};
    int position = 1;
    for(int i=0; i<3; i++){
        surface2 = aff_pokemon_1(p2[i]);
        if (surface2 == NULL) {
            printf("Erreur IMG_Load : %s\n", IMG_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
        SDL_RenderPresent(renderer2);
        aff_barre(p2[i], renderer2, position);
        position++;
        place.x=i*400;
    }
    place.y=326;
    for(int i=0; i<3; i++){
        surface2 = aff_pokemon_1(p1[i]);
        if (surface2 == NULL) {
            printf("Erreur IMG_Load : %s\n", IMG_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
        SDL_RenderPresent(renderer2);
        aff_barre(p1[i], renderer2, position);
        position++;
        place.x=i*400;
    }
}
void aff_event_no_name(SDL_Renderer* renderer2, int choix){
    SDL_Texture* texture2_2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Rect place={0, 0, 1200, 653};
    if(choix==1){
        surface2 = IMG_Load("Choisissez une cible.png");
    }
    else if(choix==2){
        surface2 = IMG_Load("L'attaque est super efficace.png");
    }
    else if(choix==3){
        surface2 = IMG_Load("L'attaque n'a aucun effet.png");
    }
    else if(choix==4){
        surface2 = IMG_Load("L'attaque n'est pas très efficace.png");
    }
    else if(choix==5){
        surface2 = IMG_Load("Paralysie 2.png");
    }
    if (surface2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
    SDL_RenderCopy(renderer2, texture2_2, NULL, &place);
    SDL_RenderPresent(renderer2);
}
SDL_Surface* sdl_aff_name(Pokemon* poke, SDL_Rect* rect){
    SDL_Surface* surface3 = NULL;
    if(poke->pv_courant<=0.0){
        surface3 = IMG_Load("Vide.png");
    }
    else if(poke->atkbase.comp==Griffe){
        surface3 = IMG_Load("Absol name.png");
    }
    else if(poke->atkbase.comp==Flammeche){
        surface3 = IMG_Load("Arcanin name.png");
        rect->w=343;
    }
    else if(poke->atkbase.comp==Choc_Mental){
        surface3 = IMG_Load("Gardevoir name.png");
        rect->w=439;
    }
    else if(poke->atkbase.comp==Crocs_givre){
        surface3 = IMG_Load("Givrali name.png");
        rect->w=309;
    }
    else if(poke->atkbase.comp==Feuillage){
        surface3 = IMG_Load("Jungko name.png");
        rect->w=324;
    }
    else if(poke->atkbase.comp==Balayage){
        surface3 = IMG_Load("Mackogneur name.png");
        rect->w=500;
    }
    else if(poke->atkbase.comp==Osmerang){
        surface3 = IMG_Load("Ossatueur name.png");
        rect->w=432;
    }
    else if(poke->atkbase.comp==Eclair){
        surface3 = IMG_Load("Pikachu name.png");
        rect->w=355;
    }
    else if(poke->atkbase.comp==Pistolet_a_O){
        surface3 = IMG_Load("Tortank name.png");
        rect->w=385;
    }
    else if(poke->atkbase.comp==Draco_griffe){
        surface3 = IMG_Load("Tranchodon name.png");
        rect->w=520;
    }
    else if (surface3==NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    return surface3;
}
void aff_simple_event(SDL_Renderer* renderer2, int choix, Pokemon* cible){
    SDL_Texture* texture2 = NULL;
    SDL_Texture* texture2_2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Surface* surface2_2 = NULL;
    SDL_Rect place={0, 0, 1200, 653};
    SDL_Rect place2={0, 0, 228, 40};
    if(choix==1){
        surface2 = IMG_Load("KO.png");
    }
    else if(choix==2){
        surface2 = IMG_Load("Paralysie.png");
    }
    else if(choix==3){
        surface2 = IMG_Load("sommeil 1.png");
    }
    else if(choix==4){
        surface2 = IMG_Load("sommeil 2.png");
    }
    else if(choix==5){
        surface2 = IMG_Load("sommeil 3.png");
    }
    else if(choix==6){
        surface2 = IMG_Load("gel 1.png");
    }
    else if(choix==7){
        surface2 = IMG_Load("gel 2.png");
    }
    else if(choix==8){
        surface2 = IMG_Load("Brûlure 1.png");
    }
    else if(choix==9){
        surface2 = IMG_Load("Brûlure 2.png");
    }
    else if(choix==10){
        surface2 = IMG_Load("Poison 1.png");
    }
    else if(choix==11){
        surface2 = IMG_Load("Poison 2.png");
    }
    if (surface2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2 = SDL_CreateTextureFromSurface(renderer2, surface2);
    SDL_RenderCopy(renderer2, texture2, NULL, &place);
    SDL_RenderPresent(renderer2);
    surface2_2=sdl_aff_name(cible,&place2);
    if (surface2_2 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2_2);
    SDL_RenderCopy(renderer2, texture2_2, NULL, &place2);
    SDL_RenderPresent(renderer2);
}
void aff_atk_screen(SDL_Renderer* renderer2, Pokemon* poke){
    SDL_Texture* texture2 = NULL;
    SDL_Surface* surface3 = NULL;
    SDL_Rect place={0, 0, 1200, 653};
    if(poke->atkbase.comp==Griffe){
        surface3 = IMG_Load("Absol ecran.png");
    }
    else if(poke->atkbase.comp==Flammeche){
        surface3 = IMG_Load("Arcanin ecran.png");
    }
    else if(poke->atkbase.comp==Choc_Mental){
        surface3 = IMG_Load("Gardevoir ecran.png");
    }
    else if(poke->atkbase.comp==Crocs_givre){
        surface3 = IMG_Load("Givrali ecran.png");
    }
    else if(poke->atkbase.comp==Feuillage){
        surface3 = IMG_Load("Jungko ecran.png");
    }
    else if(poke->atkbase.comp==Balayage){
        surface3 = IMG_Load("Mackogneur ecran.png");
    }
    else if(poke->atkbase.comp==Osmerang){
        surface3 = IMG_Load("Ossatueur ecran.png");
    }
    else if(poke->atkbase.comp==Eclair){
        surface3 = IMG_Load("Pikachu ecran.png");
    }
    else if(poke->atkbase.comp==Pistolet_a_O){
        surface3 = IMG_Load("Tortank ecran.png");
    }
    else if(poke->atkbase.comp==Draco_griffe){
        surface3 = IMG_Load("Tranchodon ecran.png");
    }
    else if (surface3==NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    if (surface3 == NULL) {
        printf("Erreur IMG_Load : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    texture2 = SDL_CreateTextureFromSurface(renderer2, surface3);
    SDL_RenderCopy(renderer2, texture2, NULL, &place);
    SDL_RenderPresent(renderer2);
}
char* get_name_from_mouse(int choix, int* x, int* y, Pokemon poke, Pokemon** poke1, Pokemon** poke2){
    SDL_Event event;
    int finish=0;
    char* name=malloc(40*sizeof(char));
    SDL_Point point = {0, 0};
    SDL_Rect absol={193, 150, 738, 90};
    SDL_Rect arcanin={193, 150, 287, 75};
    SDL_Rect gardevoir={193, 150, 43, 15};
    SDL_Rect givrali={193, 150, 768, 342};
    SDL_Rect jungko={193, 150, 287, 322};
    SDL_Rect mackogneur={193, 150, 504, 404};
    SDL_Rect ossatueur={193, 150, 982, 412};
    SDL_Rect pikachu={193, 150, 967, 30};
    SDL_Rect tortank={193, 150, 521, 15};
    SDL_Rect tranchodon={193, 150, 47, 417};
    SDL_Rect atkb={233, 104, 53, 72};
    SDL_Rect spe1={233, 104, 313, 72};
    SDL_Rect spe2={233, 104, 563, 72};
    SDL_Rect spe3={233, 834, 53, 72};
    SDL_Rect cible1={400, 326, 0, 0};
    SDL_Rect cible2={400, 326, 400, 0};
    SDL_Rect cible3={400, 326, 800, 0};
    SDL_Rect cible4={400, 326, 0, 326};
    SDL_Rect cible5={400, 326, 400, 326};
    SDL_Rect cible6={400, 326, 800, 326};
    printf("Attente de click pour continuer...\n");
    while(finish==0){
        SDL_WaitEvent(&event); 
        if (event.type == SDL_QUIT) {
            exit(0); // Sortie forcée 
        }
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *x=event.motion.x;
            *y=event.motion.y;
            point.x=*x;
            point.y=*y;
            if(choix==1){
                if (SDL_PointInRect(&point, &absol)){
                    strcpy(name, "Absol");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &arcanin)){
                    strcpy(name, "Arcanin");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &gardevoir)){
                    strcpy(name, "Gardevoir");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &givrali)){
                    strcpy(name, "Givrali");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &jungko)){
                    strcpy(name, "Jungko");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &mackogneur)){
                    strcpy(name, "Mackogneur");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &ossatueur)){
                    strcpy(name, "Ossatueur");
                    finish=1;
                }
                else if (SDL_PointInRect(&point, &pikachu)){
                    strcpy(name, "Pikachu");
                    finish=1;
                }
                else if (SDL_PointInRect(&point, &tortank)){
                    strcpy(name, "Tortank");
                    finish=1;
                } 
                else if (SDL_PointInRect(&point, &tranchodon)){
                    strcpy(name, "Tranchodon");
                    finish=1;
                }
            }
            if(choix==2){
                if(SDL_PointInRect(&point, &atkb)){
                    strcpy(name, get_comp_name(poke.atkbase.comp));
                    finish=1;
                }
                else if(SDL_PointInRect(&point, &spe1)){
                    strcpy(name, get_comp_name(poke.spe1.comp));
                    finish=1;
                }
                else if(SDL_PointInRect(&point, &spe2)){
                    strcpy(name, get_comp_name(poke.spe2.comp));
                    finish=1;
                }
                else if(SDL_PointInRect(&point, &spe3)){
                    strcpy(name, get_comp_name(poke.spe3.comp));
                    finish=1;
                }
            }
            if(choix==3){
                if(SDL_PointInRect(&point, &cible1)){
                    strcpy(name, (*poke2)->nom_poke);
                }
                if(SDL_PointInRect(&point, &cible2)){
                    strcpy(name, (*(poke2+1))->nom_poke);
                }
                if(SDL_PointInRect(&point, &cible3)){
                    strcpy(name, (*(poke2+2))->nom_poke);
                }
                if(SDL_PointInRect(&point, &cible4)){
                    strcpy(name, (*poke1)->nom_poke);
                }
                if(SDL_PointInRect(&point, &cible5)){
                    strcpy(name, (*(poke1+1))->nom_poke);
                }
                if(SDL_PointInRect(&point, &cible6)){
                    strcpy(name, (*(poke1+2))->nom_poke);
                }
            }
        }
    }
    return name;
}
void aff_fenetre(int nb, SDL_Window* window2, SDL_Renderer* renderer2, SDL_Surface* surface2, SDL_Surface* icon2, SDL_Texture* texture2_2){
    if(nb==0){
        printf("Attente de saisie dans sdl_scanf_str...\n");
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    else if(nb==1){
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = SDL_LoadBMP("Écran-titre-pixelisé-de-Cymon.bmp");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(1,-1); // Montre ce qu'on a rendu
    }
    else if(nb==2){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = SDL_LoadBMP("Choisissez votre mode de jeu.bmp");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(1,-1); // Montre ce qu'on a rendu
    }
    else if(nb==3){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = SDL_LoadBMP("Choisissez vos pokemon.bmp");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==4){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = IMG_Load("Choix validé.png");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==5){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = SDL_LoadBMP("Choisissez vos pokemon P1.bmp");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==6){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = SDL_LoadBMP("Choisissez vos pokemon P2.bmp");
        if (surface2 == NULL) {
            printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==7){    
        icon2 = SDL_LoadBMP("Icon.bmp");
        if (icon2 == NULL) {
            printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        window2 = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window2 == NULL) {
            printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_SetWindowIcon(window2, icon2);
        renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
        if (renderer2 == NULL) {
            printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        surface2 = IMG_Load("Combat.png");
        if (surface2 == NULL) {
            printf("Erreur IMG_Load : %s\n", IMG_GetError());
            exit(EXIT_FAILURE);
        }
        texture2_2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2_2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2_2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
}
void aff_atk_fight(Pokemon* poke, SDL_Renderer* renderer){

}
void close_sdl(SDL_Surface* surf, SDL_Window* wind, SDL_Renderer* ren, SDL_Texture* tex, SDL_Surface* surf2){
    SDL_FreeSurface(surf);
    SDL_FreeSurface(surf2);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(wind);
}



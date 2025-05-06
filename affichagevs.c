#include "Biblio_lin.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

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

    }
    else{

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
    char number;
    if(nb==1){
        while(value<1 || value>6){
            SDL_WaitEvent(&event);
            if (event.type == SDL_QUIT) {
                return -1; // Sortie forcée
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                if (key >= SDLK_1 && key <= SDLK_6) {
                    number='0'+(key-SDLK_0);
                    value=number-'0';
                }
                else if(key==SDLK_RETURN){
                    return -1;
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
                if (key==SDLK_1 || key==SDLK_2) {
                    number='0'+(key-SDLK_0);
                    value=number-'0';
                }
                else if(key==SDLK_RETURN){
                    return -1;
                }
            }
        }
    }
    return value;
}
char* sdl_scanf_str(){
    char* chaine=malloc(sizeof(char)*45);
    SDL_Event event;
    int i=0;
    int finish=0;
    while(finish==0){
        SDL_WaitEvent(&event); 
        if (event.type == SDL_QUIT) {
            free(chaine);
            return NULL; // Sortie forcée 
        }
        if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
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
    return chaine;
}
void aff_pokemon(Pokemon* poke, int place){

}
void aff_fenetre(int nb){
    SDL_Window* window2 = NULL;
    SDL_Renderer* renderer2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Surface* icon2 = NULL;
    SDL_Texture* texture2_2 = NULL;
    if(nb==1){
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        surface2 = SDL_LoadBMP("Choisissez-votre-mode-de-jeu.bmp");
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
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
    else if(nb==5){    
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
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
        surface2 = SDL_LoadBMP("Combat.png");
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
}
void aff_barre(int nb){
    SDL_Renderer* renderer2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Surface* icon2 = NULL;
    SDL_Texture* texture2_2 = NULL;

}
void close_sdl(SDL_Surface* surf, SDL_Window* wind, SDL_Renderer* ren, SDL_Texture* tex, SDL_Surface* surf2){
    SDL_FreeSurface(surf);
    SDL_FreeSurface(surf2);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(wind);
}


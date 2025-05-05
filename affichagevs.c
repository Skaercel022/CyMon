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
    if(musique==NULL){
        printf("Erreur de chargement de la musique : %s\n", Mix_GetError());
    }
    Mix_PlayMusic(musique, boucle); // -1 pour jouer en boucle
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
}
int sdl_scanf(int nb){
    int value=0;
    SDL_Event event;
    if(nb==1){

    }
    else if(nb==2){
        while(value!=1 && value!=2){
            SDL_WaitEvent(&event);
        }
    }
    else{

    }
    SDL_WaitEvent(NULL);
}
void aff_all(int nb){
    SDL_Window* window2 = NULL;
    SDL_Renderer* renderer2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Surface* icon2 = NULL;
    SDL_Texture* texture2.2 = NULL;
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==4){    
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        icon2 = SDL_LoadBMP("Choix surnom.bmp");
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==5){    
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        icon2 = SDL_LoadBMP("Choix surnom.bmp");
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
    else if(nb==6){    
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        icon2 = SDL_LoadBMP("Choix surnom.bmp");
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
        texture2.2 = SDL_CreateTextureFromSurface(renderer2, surface2);
        if (texture2.2 == NULL) {
            printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_RenderClear(renderer2);
        SDL_RenderCopy(renderer2, texture2.2, NULL, NULL);
        SDL_RenderPresent(renderer2);
        jouer_musique(2,-1); // Montre ce qu'on a rendu
    }
}
void close_sdl(SDL_Surface* surf, SDL_Window* wind, SDL_Renderer* ren, SDL_Texture* tex, SDL_Surface* surf2){
    SDL_FreeSurface(surf);
    SDL_FreeSurface(surf2);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(wind);
}


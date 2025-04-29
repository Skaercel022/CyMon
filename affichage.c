#include "Biblio_lin.h"
#include "combat.h"
#include "creapers.h"
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
void aff_all() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surface = NULL;
    SDL_Surface* icon = NULL;
    SDL_Texture* texture2 = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    icon = SDL_LoadBMP("Icon.bmp");
    if (icon == NULL) {
        printf("Erreur lors du chargement de l'icône : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow("CyMon par Nathan, Sarah & Tom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowIcon(window, icon);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    surface = SDL_LoadBMP("Écran-titre-pixelisé-de-Cymon.bmp");
    if (surface == NULL) {
        printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    texture2 = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture2 == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture2, NULL, NULL);
    SDL_RenderPresent(renderer);
    jouer_musique(1,-1); // Montre ce qu'on a rendu
    SDL_Delay(10000);
    SDL_FreeSurface(surface);
    SDL_FreeSurface(icon);
    SDL_DestroyTexture(texture2);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


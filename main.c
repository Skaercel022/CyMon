#include "Biblio_lin.h"
#include "combat.h"
#include "creapers.h"
#include "affichagevs.h"
int main(){
    srand(time(NULL));
    int num=1;
    int mode=0;
    int* adr=&num;
    Pokemon** p1;
    Pokemon** p2;
    SDL_Window* window2 = NULL;
    SDL_Renderer* renderer2 = NULL;
    SDL_Surface* surface2 = NULL;
    SDL_Surface* icon2 = NULL;
    SDL_Texture* texture2_2 = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Erreur IMG_Init : %s\n", IMG_GetError());
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
    sdl_scanf_int(1);
    if(renderer2==NULL ){
        printf("\nerreur");
    }
    mode=aff_fenetre(2, window2, renderer2, surface2, icon2, texture2_2, NULL);
    printf("\nLe blocage n'est pas ici");
    printf("\nLe blocage n'est pas ici");
    if(mode==2){
        SDL_Delay(100); // 100 ms de pause
        p1=create_team_joueur(adr, 2);
        SDL_Delay(100); // 100 ms de pause
        p2=create_team_joueur(adr, 3);
    }
    else if(mode!=2){
        SDL_Delay(100); // 100 ms de pause
        p1=create_team_joueur(adr, 1);
        printf("ok\n");
        p2=create_team_ordi(adr);
        printf("ok\n");
    }
    printf("\nOK");
    fight(p1, p2, mode, renderer2, window2);
    SDL_DestroyRenderer(renderer2);
    SDL_DestroyWindow(window2);
    IMG_Quit();
    SDL_Quit();
}

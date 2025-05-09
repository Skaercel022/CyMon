#ifndef AFFICHAGEVS_H
#define AFFICHAGEVS_H
void jouer_musique(int choix, int boucle);
int sdl_scanf_int(int nb);
void sdl_scanf_str(char* str);
void aff_cooldown(Pokemon* poke, SDL_Renderer* renderer2);
void aff_barre(Pokemon* poke, SDL_Renderer* renderer2, int position);
void aff_pokemon_2(Pokemon** p1, Pokemon** p2, SDL_Renderer* renderer2);
void aff_event_no_name(SDL_Renderer* renderer2, int choix);
SDL_Surface* sdl_aff_name(Pokemon* poke, SDL_Rect* rect);
void aff_simple_event(SDL_Renderer* renderer2, int choix, Pokemon* cible);
void aff_atk_screen(SDL_Renderer* renderer2, Pokemon* poke);
char* get_name_from_mouse(int choix, int* x, int* y, Pokemon poke, Pokemon** poke1, Pokemon** poke2);
void aff_fenetre(int nb, SDL_Window* window2, SDL_Renderer* renderer2, SDL_Surface* surface2, SDL_Surface* icon2, SDL_Texture* texture2_2);
void aff_atk_fight(Pokemon* poke, SDL_Renderer* renderer);
void close_sdl(SDL_Surface* surf, SDL_Window* wind, SDL_Renderer* ren, SDL_Texture* tex, SDL_Surface* surf2);
#endif

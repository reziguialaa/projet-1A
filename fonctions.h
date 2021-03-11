#ifndef FONCTIONS_H_
#define FONCTIONS_H_
void free_sd(Mix_Music* music,SDL_Surface* image,SDL_Surface* start,SDL_Surface* start_hold,SDL_Surface* option,SDL_Surface* option_hold,SDL_Surface* quit,SDL_Surface* quit_hold,Mix_Chunk* click_sound,TTF_Font *police);
void standard(SDL_Surface* ecran,SDL_Surface* image,SDL_Rect position);
void effet(Mix_Chunk* sound,SDL_Surface* ecran,SDL_Surface* image,SDL_Rect position);
#endif



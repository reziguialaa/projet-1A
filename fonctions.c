#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
void free_sd(Mix_Music* music,SDL_Surface* image,SDL_Surface* start,SDL_Surface* start_hold,SDL_Surface* option,SDL_Surface* option_hold,SDL_Surface* quit,SDL_Surface* quit_hold,Mix_Chunk* click_sound,TTF_Font *police)
{	
   	SDL_FreeSurface(image);
   	SDL_FreeSurface(start);
   	SDL_FreeSurface(start_hold);
	SDL_FreeSurface(option);
	SDL_FreeSurface(option_hold);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(quit_hold);
   	Mix_FreeMusic(music);
   	Mix_FreeChunk(click_sound);
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();
}
void standard(SDL_Surface* ecran,SDL_Surface* image,SDL_Rect position)
{
	SDL_BlitSurface(image,NULL,ecran,&position);
       	SDL_Flip(ecran);
}

void effet(Mix_Chunk* sound,SDL_Surface* ecran,SDL_Surface* image,SDL_Rect position)
{
	SDL_BlitSurface(image,NULL,ecran,&position);
	Mix_PlayChannel(0,sound,0);
	SDL_Flip(ecran);
}

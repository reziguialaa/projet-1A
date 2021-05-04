#ifndef FONCTIONS_H_
#define FONCTIONS_H_

void afficher(SDL_Surface *ecran,char *chaine);
void correcte(SDL_Surface *ecran,Mix_Chunk *corr);
void incorrecte(SDL_Surface *ecran,Mix_Chunk *not );
void resultat(int ligneVoulu,int jew, SDL_Surface *ecran,Mix_Chunk *corr,Mix_Chunk *not);
#endif 

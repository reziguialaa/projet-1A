
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"

void afficher(SDL_Surface *ecran,char *chaine)
{

TTF_Init();
TTF_Font *police1=NULL;
TTF_Font *police2=NULL;
SDL_Color ques= {255,255,255};
 SDL_Color noir= {0,0,0};


police1 = TTF_OpenFont("AU.ttf", 100);
police2 = TTF_OpenFont("auu.ttf", 20);
SDL_Surface *texte_ques,*vrai=NULL,*faux;
SDL_Rect posques,pos_vrai,pos_faux;
posques.x=10;
posques.y=80;
pos_vrai.x=0;
pos_vrai.y=200;
pos_faux.x=0;
pos_faux.y=300;
vrai= TTF_RenderText_Blended(police1,"v-->Oui", noir);
faux= TTF_RenderText_Blended(police1,"f-->Non", noir);
texte_ques=TTF_RenderText_Blended(police2,chaine,noir);
SDL_BlitSurface(texte_ques,NULL,ecran,&posques);
 SDL_BlitSurface(vrai,NULL,ecran,&pos_vrai);
SDL_BlitSurface(faux,NULL,ecran,&pos_faux);


}
void correcte(SDL_Surface *ecran,Mix_Chunk *corr)
{
 TTF_Init();
TTF_Font *police1=NULL;
SDL_Color ques= {255,255,255};
police1 = TTF_OpenFont("AU.ttf", 100);
SDL_Surface *vr;
SDL_Rect posvr;
posvr.x=540;
posvr.y=400;
vr=TTF_RenderText_Blended(police1,"correcte",ques);
SDL_BlitSurface(vr,NULL,ecran,&posvr);
}
void incorrecte(SDL_Surface *ecran,Mix_Chunk *not )
{
TTF_Init();
TTF_Font *police1=NULL;
SDL_Color ques= {255,255,255};
police1 = TTF_OpenFont("AU.ttf", 100);
SDL_Surface *vf;
SDL_Rect posvf;
 posvf.x=540;
posvf.y=400;
vf=TTF_RenderText_Blended(police1,"incorrecte",ques);
SDL_BlitSurface(vf,NULL,ecran,&posvf);

}
void resultat(int ligneVoulu,int jew, SDL_Surface *ecran,Mix_Chunk *corr,Mix_Chunk *not)
{
 if(ligneVoulu==1 && jew==1)
{
  incorrecte(ecran,not );
    
}
else {if( ligneVoulu==1 && jew==0)
{
correcte(ecran,corr);}
else{if(ligneVoulu==2 && jew==1)
{
incorrecte(ecran,not );
}
 else{if(ligneVoulu==2 && jew==0)
{
correcte(ecran,corr);
}
else{if(ligneVoulu==3 && jew==1)
{ 
    correcte(ecran,corr);
}
else {if(ligneVoulu==3 && jew==0)
{
incorrecte(ecran,not );


    }
else {if(ligneVoulu==4 && jew==1)
{ 
correcte(ecran,corr);
}
else {if(ligneVoulu==4 && jew==0)
{
incorrecte(ecran,not );
 }  
else {if(ligneVoulu==5 && jew==1)
{
 incorrecte(ecran,not );
}
else{if(ligneVoulu==5 && jew==0)
{
correcte(ecran,corr);

} 

}}}}}}}}}
}









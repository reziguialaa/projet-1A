
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"
#include <time.h>
int main(int argc, char *argv[])
{
SDL_Event event;
int vol=50;

   char chaine[8000];
int ligneVoulu  ;// génération aléatoire d'un numero de ligne entre MAX et MIN=1 (des constantes )
  Mix_Chunk *corr,*not;
   Mix_Music *music;
    int cont=1,jew=2,res=1;
    SDL_Surface *ecran = NULL,*image = NULL,*t=NULL,*f=NULL;
    SDL_Surface *texte_ques=NULL;
    SDL_Rect posbg,posques;
TTF_Font *police=NULL;
    SDL_Color ques= {255,255,255};
    
   FILE *fichier=NULL;

	//initialisation
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
   
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Initialisation Error!!!!%s\n",SDL_GetError());
		return 1;
	}
    ecran = SDL_SetVideoMode(1080,800,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(ecran==NULL)
	{
		printf("VideoMode Error!!%s\n",SDL_GetError());
		return 1;
	}
    SDL_WM_SetCaption("Groupe CD PROJEKT", NULL);
    image=IMG_Load("2d.jpg");
	if(image==NULL)
		{
			printf("BACKGROUND Loading Error!! %s\n",SDL_GetError());
		}
  

    
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("tartaglia.mp3");
Mix_VolumeMusic(vol); 
Mix_PlayMusic(music,100);

police = TTF_OpenFont("A.ttf", 100);

     posbg.x=0;
     posbg.y=0;
    

srand(time(NULL));

ligneVoulu= rand() %5+1;
char ques1[8000]="sydney est la capitale de l'australie\n";
char ques2[8000]="elton john est le roi du pop";
char ques3[8000]="l'esperance sportive de Tunis a remporte 4 fois champions ligue africaine\n";
char ques4[8000]="En 1956,La tunisie a devenu un pays indépendant \n";
char ques5[8000]="5*4*2-2*3=36";
if(ligneVoulu==1)
{
sprintf(chaine,"%s",ques1);
}
else{ if(ligneVoulu==2)
{
sprintf(chaine,"%s",ques2);}
else{ if(ligneVoulu==3)
{
sprintf(chaine,"%s",ques3);}
else{ if(ligneVoulu==4)
{
sprintf(chaine,"%s",ques4);}
else{ if(ligneVoulu==5)
{
sprintf(chaine,"%s",ques5);}
}}}}

fichier=fopen("question.txt","w+");
if(fichier!=NULL)
{
if(ligneVoulu==1)
fprintf(fichier,"sydney est la capitale de l'australie\n");
else if(ligneVoulu==2)
fprintf(fichier,"elton john est le roi du pop\n");
else if(ligneVoulu==3)
fprintf(fichier,"l'esperance sportive de Tunis a remporte 4 fois champions ligue africaine\n");
else if(ligneVoulu==4)
fprintf(fichier,"En 1956,La tunisie a devenu un pays indépendant \n");
else if(ligneVoulu==5)
fprintf(fichier,"5*4*2-2*3=36");
fclose(fichier);
}
    printf("%d",jew);

	//event&boucle du jeu
while(cont)
{
SDL_WaitEvent(&event);
SDL_BlitSurface(image,NULL,ecran,&posbg);
	  afficher(ecran,chaine);
  
SDL_Flip(ecran);
 switch(event.type) 
{case SDL_QUIT:
  
   remove("question.txt");
    cont=0;
   break;
case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
  case SDLK_v:
     jew=1;
      break;
   case SDLK_f:
     jew=0;
break;}
break;
   }
 resultat( ligneVoulu, jew,ecran,corr,not);

SDL_Flip(ecran);

}

}








  

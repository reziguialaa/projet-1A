#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
int main(int argc, char *argv[])
{
    int vol=50,ver=1;
    SDL_Event event;
    Mix_Chunk *select;
    Mix_Music *music;
    int cont=1,res=1,c=1;
    SDL_Surface *ecran = NULL,*image = NULL,*texte_main=NULL,*texte_sub=NULL,*texteop=NULL,*texte_option1=NULL,*texte_option2=NULL,*texte_option3=NULL,*texte_option4=NULL,*logo=NULL;
    SDL_Surface *start=NULL,*option=NULL,*quit=NULL,*start_hold=NULL,*option_hold=NULL,*quit_hold=NULL,*on=NULL,*retur=NULL;
    SDL_Surface *on_hold=NULL,*off_hold=NULL,*off=NULL,*back=NULL,*opbg=NULL;
    SDL_Rect posbg,posst,posop,posqu,poson,posoff,postx,posre,postxop,postxoption1,postxoption2,postxoption3,postxoption4;
    TTF_Font *police=NULL,*police1=NULL;
    SDL_Color coul= {255,255,255},coul_sub={0,0,0},coulop={180,180,180};
	//initialisation
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Initialisation Error!!!!%s\n",SDL_GetError());
		return 1;
	}
    ecran = SDL_SetVideoMode(1200,850,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(ecran==NULL)
	{
		printf("VideoMode Error!!%s\n",SDL_GetError());
		return 1;
	}
    SDL_WM_SetCaption("Groupe CD PROJEKT", NULL);
    image=SDL_LoadBMP("lobobg.bmp");
	if(image==NULL)
		{
			printf("BACKGROUND Loading Error!! %s\n",SDL_GetError());
		}
    start=SDL_LoadBMP("start1.bmp");
    if(start==NULL)
{
printf("ERROR loading start %s\n",SDL_GetError());
}
option=SDL_LoadBMP("options1.bmp");
        if(option==NULL)
                {
                        printf("ERROR loading options %s\n",SDL_GetError());
                }
quit=SDL_LoadBMP("quit1.bmp");
        if(quit==NULL)
                {
                        printf("ERROR Loading quit! %s\n",SDL_GetError());
                }
start_hold=SDL_LoadBMP("start_hold1.bmp");
	if(start_hold==NULL)
		{
			printf("ERROR loading starthold %s\n",SDL_GetError());
		}
option_hold=SDL_LoadBMP("options_hold1.bmp");
        if(start_hold==NULL)
                {
                        printf("ERROR loading optionthold %s\n",SDL_GetError());
                }
quit_hold=SDL_LoadBMP("quit_hold1.bmp");
        if(quit_hold==NULL)
                {
                        printf("ERROR loading quitthold %s\n",SDL_GetError());
                }
on=SDL_LoadBMP("on.bmp");
	if(on==NULL)
		{
			printf("ERROR loading sound_on %s\n",SDL_GetError());
		}
off=SDL_LoadBMP("off.bmp");
	if(off==NULL)
		{
			printf("ERROR loading sound_off %s\n",SDL_GetError());
		}
retur=SDL_LoadBMP("return.bmp");
	if(retur==NULL)
		{
			printf("ERROR loading return %s\n",SDL_GetError());
		}
opbg=SDL_LoadBMP("opbg.bmp");
	if(opbg==NULL)
		{
			printf("ERROR loading opbg %s\n",SDL_GetError());
		}
logo=IMG_Load("logo.png");
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("tartaglia.mp3");
Mix_VolumeMusic(vol); 
Mix_PlayMusic(music,100);
select=Mix_LoadWAV("button.wav");
postx.x=0;
postx.y=0;
police = TTF_OpenFont("A.ttf", 100);
police1=TTF_OpenFont("A.ttf", 30);
texte_main= TTF_RenderText_Blended(police,"CD PROJECT", coul);
texte_sub= TTF_RenderText_Blended(police,"CD PROJECT", coul_sub);
texteop=TTF_RenderText_Blended(police1, "Game settings", coulop);
texte_option1=TTF_RenderText_Blended(police1,"+ to increase sound",coulop);
texte_option2=TTF_RenderText_Blended(police1,"- to decrease sound",coulop);
texte_option3=TTF_RenderText_Blended(police1,"F for fullscreenmode,W for window mode",coulop);
texte_option4=TTF_RenderText_Blended(police1,"Press ESC to return",coulop);
    posbg.x=0;
    posbg.y=0;
    posst.x=0;
    posst.y=400;
    posop.x=0;
    posop.y=550;
    posqu.x=0;
    posqu.y=700;
    poson.x=800;
    poson.y=500;
    posoff.x=800;
    posoff.y=700;
    posre.x=800;
    posre.y=100;
    postxop.x=10;
    postxop.y=0;
    postxoption1.x=10;
    postxoption1.y=50;
    postxoption2.x=10;
    postxoption2.y=100;
    postxoption3.x=10;
    postxoption3.y=150;
    postxoption4.x=500;
    postxoption4.y=750;
    SDL_BlitSurface(image,NULL,ecran,&posbg);
    SDL_BlitSurface(start,NULL,ecran, &posst);
    SDL_BlitSurface(option,NULL,ecran, &posop);
    SDL_BlitSurface(quit,NULL,ecran, &posqu);
    SDL_Flip(ecran);
	//event&boucle du jeu
while(cont)
{
	if(res==1)
	SDL_BlitSurface(logo,NULL,ecran, &postx);
	SDL_WaitEvent(&event);
        switch(event.type)
        {
		case SDL_QUIT:
			cont=0;
			break;
		case SDL_MOUSEMOTION:
			if(((event.motion.x>=posst.x)&&(event.motion.x<=(posst.x)+375))&&((event.motion.y>=posst.y)&&(event.motion.y<=(posst.y)+118)))
			{if((res==1)&&(ver!=0)){
				effet(select,ecran,start_hold,posst);
			}}
			else
			{if((res==1)&&(ver!=0)){
				standard(ecran,start,posst);
			}}
			if(((event.motion.x>=posop.x)&&(event.motion.x<=(posop.x)+375))&&((event.motion.y>=posop.y)&&(event.motion.y<=(posop.y)+118)))
                        {if((res==1)&&(ver!=0))
				{
                               	effet(select,ecran,option_hold,posop);
                        }}
                        else
                        {if((res==1)&&(ver!=0)){
                               standard(ecran,option,posop);
			}}
			if(((event.motion.x>=posqu.x)&&(event.motion.x<=(posqu.x)+375))&&((event.motion.y>=posqu.y)&&(event.motion.y<=(posqu.y)+118)))
                        {if((res==1)&&(ver!=0)){
                                effet(select,ecran,quit_hold,posqu);
			}}
	               else
                        {if((res==1)&&(ver!=0)){
                                standard(ecran,quit,posqu);
			}}
			break;
		case SDL_MOUSEBUTTONUP:
			if(((event.button.x>=posqu.x)&&(event.button.x<=(posqu.x)+375))&&((event.button.y>=posqu.y)&&(event.button.y<=(posqu.y)+118)))
				{	 //free
					if(res==1)
					{ cont=0;
					 free_sd( music, image, start, start_hold, option, option_hold, quit, quit_hold, select,police);
				}}
			else if(((event.button.x>=posop.x)&&(event.button.x<=(posop.x)+375))&&((event.button.y>=posop.y)&&(event.button.y<=(posop.y)+118)))
				{	res=0;
					SDL_BlitSurface(opbg,NULL,ecran,&posbg);
					SDL_BlitSurface(retur,NULL,ecran,&posre);	
					SDL_BlitSurface(on,NULL,ecran,&poson);
					SDL_BlitSurface(off, NULL,ecran, &posoff);
					SDL_BlitSurface(texteop,NULL,ecran,&postxop);
					SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
					SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
					SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
					SDL_Flip(ecran);
				}
			else  if(((event.button.x>=posoff.x)&&(event.button.x<=(posoff.x)+375))&&((event.button.y>=posoff.y)&&(event.button.y<=(posoff.y)+118)))
                                                {if(res==0)
                                                        {Mix_PauseMusic();}
                                                }
			 else  if(((event.button.x>=poson.x)&&(event.button.x<=(poson.x)+375))&&((event.button.y>=poson.y)&&(event.button.y<=(poson.y)+118)))
                                                {if(res==0)
                                                        {Mix_ResumeMusic();}
                                                }
			else if(((event.button.x>=posre.x)&&(event.button.x<=(posre.x)+375))&&((event.button.y>=posre.y)&&(event.button.y<=(posre.y)+118)))
						{if(res==0)
							{SDL_BlitSurface(image,NULL,ecran,&posbg);
							SDL_BlitSurface(start,NULL,ecran, &posst);
   							SDL_BlitSurface(option,NULL,ecran, &posop);
  							SDL_BlitSurface(quit,NULL,ecran, &posqu);
							SDL_BlitSurface(texte_main,NULL,ecran,&postx);
							res=1;
						}}
			else if(((event.button.x>=posst.x)&&(event.button.x<=(posst.x)+375))&&((event.button.y>=posst.y)&&(event.button.y<=(posst.y)+118)))
						{if(res==1)
							ver=0;
							SDL_BlitSurface(image,NULL,ecran,&posbg);
							SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
							SDL_Flip(ecran);
						}
			
				break;
		 case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:///retour vers main menu avec échap
                    	SDL_BlitSurface(image,NULL,ecran,&posbg);
			SDL_BlitSurface(start,NULL,ecran, &posst);
   			SDL_BlitSurface(option,NULL,ecran, &posop);
  			SDL_BlitSurface(quit,NULL,ecran, &posqu);
			//SDL_BlitSurface(texte_main,NULL,ecran,&postx);
			res=1;
			ver=1;
			SDL_Flip(ecran);
			break;
		case SDLK_f:///mode fullscreen
			ecran = SDL_SetVideoMode(1200,850,32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
			if((res==1)&&(ver!=0))///fullscreen main menu
			{
				SDL_BlitSurface(image,NULL,ecran,&posbg);
				SDL_BlitSurface(start,NULL,ecran, &posst);
   				SDL_BlitSurface(option,NULL,ecran, &posop);
  				SDL_BlitSurface(quit,NULL,ecran, &posqu);
				SDL_BlitSurface(texte_main,NULL,ecran,&postx);
				SDL_Flip(ecran);
			}
			else if(ver==0)
			{
				SDL_BlitSurface(image,NULL,ecran,&posbg);
				SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
				SDL_Flip(ecran);
				
			}
			else if(res==0)///fullscreen options menu
			{
				SDL_BlitSurface(opbg,NULL,ecran,&posbg);
				SDL_BlitSurface(retur,NULL,ecran,&posre);	
				SDL_BlitSurface(on,NULL,ecran,&poson);
				SDL_BlitSurface(off, NULL,ecran, &posoff);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
				SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
				SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
				SDL_Flip(ecran);
			}
			break;
		case SDLK_w:///window mode
			ecran = SDL_SetVideoMode(1200,850,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
			if((res==1)&&(ver!=0))
			{
				SDL_BlitSurface(image,NULL,ecran,&posbg);
				SDL_BlitSurface(start,NULL,ecran, &posst);
   				SDL_BlitSurface(option,NULL,ecran, &posop);
  				SDL_BlitSurface(quit,NULL,ecran, &posqu);
				SDL_BlitSurface(texte_main,NULL,ecran,&postx);
				SDL_Flip(ecran);
			}
			else if(ver==0)
			{
				SDL_BlitSurface(image,NULL,ecran,&posbg);
				SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
				SDL_Flip(ecran);
				
			}
			else if(res==0)
			{
				SDL_BlitSurface(opbg,NULL,ecran,&posbg);
				SDL_BlitSurface(retur,NULL,ecran,&posre);	
				SDL_BlitSurface(on,NULL,ecran,&poson);
				SDL_BlitSurface(off, NULL,ecran, &posoff);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
				SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
				SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
				SDL_Flip(ecran);
			}
			break;
		case SDLK_KP_PLUS:///augmenter le volume avec la touche +
			if(vol<125)
			{
				vol=vol+25;
			}
		Mix_VolumeMusic(vol);
		break;
		case SDLK_KP_MINUS:///diminuer le volume avec la touche -
			if(vol>0)
			{
				vol=vol-25;
			}	
		Mix_VolumeMusic(vol);
		break;
		     }
}
}
	return EXIT_SUCCESS;

}

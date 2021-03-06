#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;//ACT2: Mal, aqui debes de poner tu estado inicial, por eso te marcara error.
	atexit(SDL_Quit);
	//ACT3:Mal, este codigo no va aqui.
	///ACT3: Mal, este codigo de abajo, debera ir en un metodo inicializando.
	//if (SDL_Init(SDL_INIT_VIDEO)){
	//	printf("Error %s", SDL_GetError());
	//	exit(EXIT_FAILURE);
	//}
	//screen = SDL_SetVideoMode ( 640, 480, 24, SDL_SWSURFACE );

	//if (screen == NULL){
	//	printf("Error %s ", SDL_GetError());
	//	exit(EXIT_FAILURE);
	//}
	//SDL_Flip(screen); //este codigo estara provicionalmente aqui.
	//SDL_WM_SetCaption("Mi primer Juego", NULL);
}

//ACT3: Mal, Falto crear el metodo "iniciando()"
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode ( 640, 480, 24, SDL_SWSURFACE );

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_WM_SetCaption("Mi primer Juego", NULL);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
			case Estado::ESTADO_INICIANDO: //INICIALIZAR
				Iniciando();//ACT3: Mal, falto mandar a llamr este metodo.
				estado = ESTADO_MENU;
			break;
			case Estado::ESTADO_MENU:	//MENU
			break;
			case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};
    }
	return true;
}

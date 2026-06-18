#ifndef __MAIN_H
#define __MAIN_H
//BUSCAR DEFINIR
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define GAME_NAME "PONGG"
#define TICKS_FOR_NEXT_FRAME (1000 / 60)
#define FONT_SIZE 120
/* estamos utilizando define en todos los .h por que si usamos cualquier tipo de variable 
nos da un error de simbolo duplicado al linkeditar
indicando que se nos estan duplicando nuestras variables (que son de scope global) por cada ".cpp" que incluya a defs.h
esto no sucedia antes por que los #define trbajan se reemplzan como constantes antes de compilar el codigo
por ende no son simbolos del programa 
*/

#define ASSET_BG "./assets/img/bg.png"
#define ASSET_BALL  "./assets/img/ball.png"
#define ASSET_BAR  "./assets/img/bar.png"
#define ASSET_WALL "./assets/img/wall.png"

#endif




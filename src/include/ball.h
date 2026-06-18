#ifndef __BALL_H
#define __BALL_H
//BUSCAR QUE ES ESTO
#include <SDL.h>



#define MAX_BALL_SPEED  4000
#define BALL_SPEED_DEFAULT  500
#define BALL_RADIUS 100
#define BALL_SPEED_DAMPEN_FACTOR  0.995
#define COLLIDER_PRECISIO 100
/* estamos utilizando define en todos los .h por que si usamos cualquier tipo de variable 
nos da un error de simbolo duplicado al linkeditar
indicando que se nos estan duplicando nuestras variables (que son de scope global) por cada ".cpp" que incluya a defs.h
esto no sucedia antes por que los #define trbajan se reemplzan como constantes antes de compilar el codigo
por ende no son simbolos del programa 
*/

typedef struct ball_t{
    int x;
    int y;
    int newx;
    int newy;
    int vx;
    int vy;
    int radius;
    SDL_Texture* texture;
    int angle;
} ball_t;

typedef struct collidable_t{
    int x;
    int y;
    int lastx;
    int lasty;
    int w;
    int h;
    int vx;
    int vy;
} collidable_t;

bool check_collisions(ball_t* ball, vector<collidable_t*>obstacles);
bool move_ball(ball_t* ball, long ticks, vector<collidable_t*> obstacles);
void init_ball(ball_t* ball, SDL_Texture* texture);
void draw_ball(SDL_Renderer* renderer, ball_t* ball);
void bounceoff(int* vnorm, int* vtan, int collider_vtan, int collider_vnorm);
void dampen_speed(ball_t* ball);

#endif
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
using namespace std;

#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <defs.h>
#include <loop.h>
#include <input.h>
#include <draw.h>
#include <ball.h>
#include <text.h>
#include <bar.h>

extern SDL_Renderer* renderer;

SDL_Texture* bg;
ball_t ball;
vector<collidable_t*> obstacles = {};
bar_t bars[2] = {0};

void run_game_loop(){
    uint64_t ticks = 0;
    input_t input;
    init_input(&input);
    init_text();

    init_ball(&ball, load_texture(ASSET_BALL));

    bg = load_texture(ASSET_BG);


    collidable_t wall1 = {0, 0, 0, 0, 1920, 10};
    collidable_t wall2 = {0, 0, 0, 0, 10, 1080};
    collidable_t wall3 = {0, 1080, 0, 1080, 1920, 10};
    collidable_t wall4 = {1920, 0, 1920, 0, 10, 1080};

    obstacles.push_back(&wall1);
    obstacles.push_back(&wall2);
    obstacles.push_back(&wall3);
    obstacles.push_back(&wall4);

    init_bar(&bars[P1], load_texture(ASSET_BAR), P1_INIT_X, BAR_PARRY_SPEED);
    init_bar(&bars[P2], load_texture(ASSET_BAR), P2_INIT_X, -BAR_PARRY_SPEED);

    obstacles.push_back(bar_to_collider(&bars[P1]));
    obstacles.push_back(bar_to_collider(&bars[P2]));

    while(1){
        handle_input(&input);
        prepareScene(bg);
        if (!run_frame(ticks, input)) return;
        //SDL_Texture* passion = getTextTexture("GRAPHIC DESIGN IS MY PASSION", font);
        //easyblit(passion, 200, 200);
        presentScene();
        ticks = SDL_GetTicks64();
    }
}

bool run_frame(uint64_t lastTicks, input_t input){
    while (SDL_GetTicks64() - lastTicks < TICKS_FOR_NEXT_FRAME) {
        SDL_Delay(1);
    }
    if (input.p1_up){
        set_bar_movement(&bars[P1], 1);
    } else if (input.p1_down){
        set_bar_movement(&bars[P1], -1);
    } else {
        set_bar_movement(&bars[P1], 0);
    }
    if (input.p2_up){
        set_bar_movement(&bars[P2], 1);
    } else if (input.p2_down){
        set_bar_movement(&bars[P2], -1);
    } else {
        set_bar_movement(&bars[P2], 0);
    }

    if(input.p1_parry){
        parry(&bars[P1]);
    }

    if(input.p2_parry){
        parry(&bars[P2]);
    }

    move_bar(&bars[P1], SDL_GetTicks64() - lastTicks);
    move_bar(&bars[P2], SDL_GetTicks64() - lastTicks);

    draw_bar(&bars[P1]);
    draw_bar(&bars[P2]);

    if (!move_ball(&ball, SDL_GetTicks64() - lastTicks, obstacles)) return false;
    draw_ball(renderer, &ball);
    return true;
}   
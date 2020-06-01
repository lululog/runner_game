#ifndef _MY_RUNNER__
#define _MY_RUNNER__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "enum_runner.h"

typedef struct game {
    sfTexture **texture;
    sfSprite **sprite;
    sfIntRect *rect;
    sfText **text;
    sfFont *font;
    sfClock **clock;
    sfTime *time;
    sfVector2f *position;
    sfEvent event;
    sfMusic **music;
    int jump;
    int end;
} game_t;

typedef struct menu {
    int i;
    sfSprite **sprite;
    sfTexture **texture;
    sfVector2f *position;
    sfEvent event;
} menu_t;

typedef struct anim {
    sfVector2f move;
    sfVector2f position;
    float x;
    float y;
}anim_t;

typedef struct runner {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    game_t game;
    menu_t menu;
    anim_t anim_start;
    anim_t anim_exit;
    anim_t anim_mouse;
    int statut;
} runner_t;

typedef struct position {
    sfVector2f pos_npc_one;
    sfVector2f pos_npc_two;
    sfVector2f pos_player;
} position_t;

bool launcher(int, char **);
void init_game(runner_t *);
sfRenderWindow *MyNewWindow(unsigned, unsigned);
void launch_game_menu (runner_t *);
void launch_game(runner_t *);
void main_game(runner_t *);
void manage_mouse_click(sfMouseButtonEvent, runner_t *);
void manage_mouse_move(sfMouseMoveEvent, runner_t *);
void manage_mouse_move_main(sfMouseMoveEvent, runner_t *);
void anim_start_move(sfMouseMoveEvent, runner_t *);
void anim_start_click(sfMouseButtonEvent, runner_t *);
void anim_exit_click(sfMouseButtonEvent, runner_t *);
void anim_exit_move(sfMouseMoveEvent, runner_t *);
void destroy_menu (runner_t *);
void destroy_game(runner_t *);
void move_sky(runner_t *);
void move_background(runner_t *);
void move_foreground(runner_t *);
void move_player(runner_t *);
void anim_player_jump(runner_t *);
void move_npc(runner_t *);
void move_life(runner_t *);
void move_end_game(runner_t *);
void finish_game(runner_t *);
void launch_end(runner_t *);
char *my_revstr(char *);
char *my_getchar(int);

#endif /* _MY_RUNNER_ */

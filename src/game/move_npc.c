#include "runner.h"

void move_rect_npc_second(runner_t *runner)
{
    if (runner->game.rect[NPC_TWO].left == 0) {
        runner->game.rect[NPC_TWO].left = 119;
        return;
    }
    if (runner->game.rect[NPC_TWO].left == 119) {
        runner->game.rect[NPC_TWO].width = 108;
        runner->game.rect[NPC_TWO].left = 226;
        return;
    }
    if (runner->game.rect[NPC_TWO].left == 226) {
        runner->game.rect[NPC_TWO].width = 110;
        runner->game.rect[NPC_TWO].left = 337;
        return;
    }
    if (runner->game.rect[NPC_TWO].left == 337) {
        runner->game.rect[NPC_TWO].left = 0;
        runner->game.rect[NPC_TWO].width = 100;
        return;
    }
}

void move_rect_npc_first(runner_t *runner)
{
    if (runner->game.rect[NPC_ONE].left == 0) {
        runner->game.rect[NPC_ONE].left = 119;
        return;
    }
    if (runner->game.rect[NPC_ONE].left == 119) {
        runner->game.rect[NPC_ONE].left = 226;
        return;
    }
    if (runner->game.rect[NPC_ONE].left == 226) {
        runner->game.rect[NPC_ONE].width = 120;
        runner->game.rect[NPC_ONE].left = 332;
        return;
    }
    if (runner->game.rect[NPC_ONE].left == 332) {
        runner->game.rect[NPC_ONE].left = 0;
        runner->game.rect[NPC_ONE].width = 100;
        return;
    }
}

sfVector2f rand_move(int nombre_aleatoire)
{
    float borne_minimale = -10;
    float borne_maximale = -30;

    sfVector2f move = {(int)(nombre_aleatoire *
    (borne_maximale + 1 - borne_minimale) / RAND_MAX + borne_minimale), 0};
    return (move);
}

sfVector2f rand_spawn(int nombre_aleatoire)
{
    float borne_minimale = 1850;
    float borne_maximale = 2800;

    sfVector2f spawn = {(int)(nombre_aleatoire *
    (borne_maximale + 1 - borne_minimale) / RAND_MAX + borne_minimale), 800};
    return (spawn);
}

int change_position(sfSprite *sprite)
{
    float rand_number = rand();
    sfVector2f position = {0, 0};
    sfVector2f position_initial = rand_spawn(rand_number);

    position = sfSprite_getPosition(sprite);
    if (position.x < -100) {
        sfSprite_setPosition(sprite, position_initial);
        return (1);
    }
    return (0);
}

void move_npc(runner_t *runner)
{
    float rand_number_one = rand();
    float rand_number_two = rand();
    float seconds;
    static float speed = 0.070;
    sfVector2f move_one = rand_move(rand_number_one);
    sfVector2f move_two = rand_move(rand_number_two);

    runner->game.rect[NPC_ONE] = sfSprite_getTextureRect(runner->game.sprite[NPC_ONE]);
    runner->game.rect[NPC_TWO] = sfSprite_getTextureRect(runner->game.sprite[NPC_TWO]);
    runner->game.time[NPC_ONE] = sfClock_getElapsedTime(runner->game.clock[NPC_ONE]);
    seconds = runner->game.time[NPC_ONE].microseconds / 1000000.0;
    if (seconds > speed) {
        move_rect_npc_first(runner);
        move_rect_npc_second(runner);
        sfSprite_move(runner->game.sprite[NPC_ONE], move_one);
        sfSprite_move(runner->game.sprite[NPC_TWO], move_two);
        if ((change_position(runner->game.sprite[NPC_ONE]) == true) ||
            (change_position(runner->game.sprite[NPC_TWO]) == true))
            speed = speed - 0.002;
        sfClock_restart(runner->game.clock[NPC_ONE]);
    }
    if (speed < 0.050)
        speed = 0.070;
    sfSprite_setTextureRect(runner->game.sprite[NPC_ONE], runner->game.rect[NPC_ONE]);
    sfSprite_setTextureRect(runner->game.sprite[NPC_TWO], runner->game.rect[NPC_TWO]);
}

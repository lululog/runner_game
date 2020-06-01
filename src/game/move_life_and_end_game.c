#include "runner.h"

void move_rect_life(runner_t *runner)
{
    if (runner->game.rect[LIFE_ONE].left == 0) {
        runner->game.rect[LIFE_ONE].left = 70;
        return;
    }
    if (runner->game.rect[LIFE_ONE].left == 70) {
        runner->game.rect[LIFE_ONE].width = 50;
        runner->game.rect[LIFE_ONE].left = 130;
        return;
    }
    if (runner->game.rect[LIFE_ONE].left == 130) {
        runner->game.rect[LIFE_ONE].width = 50;
        runner->game.rect[LIFE_ONE].left = 210;
        return;
    }
    if (runner->game.rect[LIFE_ONE].left == 210) {
        runner->game.rect[LIFE_ONE].left = 271;
        return;
    }
    if (runner->game.rect[LIFE_ONE].left == 271) {
        runner->game.rect[LIFE_ONE].width = 70;
        runner->game.rect[LIFE_ONE].left = 0;
        return;
    }
}

void move_life(runner_t *runner)
{
    float seconds;

    runner->game.rect[LIFE_ONE] = sfSprite_getTextureRect(runner->game.sprite[LIFE_ONE]);
    runner->game.time[LIFE_ONE] = sfClock_getElapsedTime(runner->game.clock[LIFE_ONE]);
    seconds = runner->game.time[LIFE_ONE].microseconds / 1000000.0;
    if (seconds > 0.50) {
        move_rect_life(runner);
        sfClock_restart(runner->game.clock[LIFE_ONE]);
    }
    sfSprite_setTextureRect(runner->game.sprite[LIFE_ONE], runner->game.rect[LIFE_ONE]);
    sfSprite_setTextureRect(runner->game.sprite[LIFE_TWO], runner->game.rect[LIFE_ONE]);
    sfSprite_setTextureRect(runner->game.sprite[LIFE_THREE], runner->game.rect[LIFE_ONE]);
}
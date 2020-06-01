#include "runner.h"

void move_rect_background(runner_t *runner)
{
    static int i = 1;

    if (runner->game.rect[BACKGROUND].left < 5760) {
        runner->game.rect[BACKGROUND].left = i;
        i++;
        return;
    }
    if (runner->game.rect[BACKGROUND].left == 5760) {
        runner->game.rect[BACKGROUND].left = 0;
        i = 1;
        return;
    }
}

void move_background(runner_t *runner)
{
    float seconds;

    runner->game.rect[BACKGROUND] = sfSprite_getTextureRect(runner->game.sprite[BACKGROUND]);
    runner->game.time[BACKGROUND] = sfClock_getElapsedTime(runner->game.clock[BACKGROUND]);
    seconds = runner->game.time[BACKGROUND].microseconds / 1000000.0;
    if (seconds > 0.010) {
        move_rect_background(runner);
        sfClock_restart(runner->game.clock[BACKGROUND]);
    }
    sfSprite_setTextureRect(runner->game.sprite[BACKGROUND], runner->game.rect[BACKGROUND]);
}

void move_rect_sky(runner_t *runner)
{
    static int i = 1;

    if (runner->game.rect[SKY].left < 5760) {
        runner->game.rect[SKY].left = i;
        i++;
        return;
    }
    if (runner->game.rect[SKY].left == 5760) {
        runner->game.rect[SKY].left = 0;
        i = 1;
        return;
    }
}

void move_sky(runner_t *runner)
{
    float seconds;

    runner->game.rect[SKY] = sfSprite_getTextureRect(runner->game.sprite[SKY]);
    runner->game.time[SKY] = sfClock_getElapsedTime(runner->game.clock[SKY]);
    seconds = runner->game.time[SKY].microseconds / 1000000.0;
    if (seconds > 0.0010) {
        move_rect_sky(runner);
        sfClock_restart(runner->game.clock[SKY]);
    }
    sfSprite_setTextureRect(runner->game.sprite[SKY], runner->game.rect[SKY]);
}

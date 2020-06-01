#include "runner.h"

int move_rect_jump(runner_t *runner, sfVector2f *position)
{
    int i = 10;

    if (position->y <= 800 && position->y >= 700) {
        runner->game.rect[PLAYER].left = 119;
        return i;
    }
    if (position->y <= 700 && position->y >= 500) {
        runner->game.rect[PLAYER].left = 238;
        i = 10;
        return i;
    }
    if (position->y <= 500 && position->y >= 400) {
        runner->game.rect[PLAYER].left = 357;
        i = 5;
        return i;
    }
    return 0;
}

void move_jump(runner_t *runner, sfVector2f *position, int i)
{
    if (runner->game.jump == 1) {
        if (position->y != 400) {
            position->y = position->y - i;
            sfSprite_setPosition(runner->game.sprite[PLAYER], *position);
            sfClock_restart(runner->game.clock[PLAYER]);
        }
        if (position->y == 400)
            runner->game.jump = 2;
    }
    if (runner->game.jump == 2) {
        if (position->y != 800) {
            position->y = position->y + i;
            sfSprite_setPosition(runner->game.sprite[PLAYER], *position);
            sfClock_restart(runner->game.clock[PLAYER]);
        }
    }
    if (position->y == 800)
        runner->game.jump = 3;
}

void anim_player_jump(runner_t *runner)
{
    float seconds;
    sfVector2f position = {0, 0};
    static int i = 25;

    runner->game.time[PLAYER] = sfClock_getElapsedTime(runner->game.clock[PLAYER]);
    seconds = runner->game.time[PLAYER].microseconds / 100000.0;
    position = sfSprite_getPosition(runner->game.sprite[PLAYER]);
    if (seconds > 0.10) {
        i = move_rect_jump(runner, &position);
        move_jump(runner, &position, i);
    }
}
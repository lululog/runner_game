#include "runner.h"

void move_rect_player_two(runner_t *runner)
{
    if (runner->game.rect[PLAYER].left == 476) {
        runner->game.rect[PLAYER].left = 595;
        return;
    }
    if (runner->game.rect[PLAYER].left == 595) {
        runner->game.rect[PLAYER].left = 714;
        return;
    }
    if (runner->game.rect[PLAYER].left == 714) {
        runner->game.rect[PLAYER].left = 833;
        return;
    }
    if (runner->game.rect[PLAYER].left == 833) {
        runner->game.rect[PLAYER].left = 0;
        return;
    }
}

bool move_rect_player_one(runner_t *runner)
{
    if (runner->game.rect[PLAYER].left == 0) {
        runner->game.rect[PLAYER].left = 119;
        return true;
    }
    if (runner->game.rect[PLAYER].left == 119) {
        runner->game.rect[PLAYER].left = 238;
        return true;
    }
    if (runner->game.rect[PLAYER].left == 238) {
        runner->game.rect[PLAYER].left = 357;
        return true;
    }
    if (runner->game.rect[PLAYER].left == 357) {
        runner->game.rect[PLAYER].left = 476;
        return true;
    }
    return false;
}

void move_rect_player(runner_t *runner)
{
    if (move_rect_player_one(runner))
        return;
    move_rect_player_two(runner);
}

void move_player(runner_t *runner)
{
    float seconds;

    runner->game.rect[PLAYER] = sfSprite_getTextureRect(runner->game.sprite[PLAYER]);
    runner->game.time[PLAYER] = sfClock_getElapsedTime(runner->game.clock[PLAYER]);
    seconds = runner->game.time[PLAYER].microseconds / 1000000.0;
    if (seconds > 0.050) {
        if (runner->game.jump != 3 && runner->game.jump != 2 && runner->game.jump != 1)
            move_rect_player(runner);
        sfClock_restart(runner->game.clock[PLAYER]);
    }
    sfSprite_setTextureRect(runner->game.sprite[PLAYER], runner->game.rect[PLAYER]);
}

void move_rect_foreground(runner_t *runner)
{
    static int i = 10;

    if (runner->game.rect[FOREGROUND].left < 5760) {
        runner->game.rect[FOREGROUND].left = i;
        i = i + 10;
        return;
    }
    if (runner->game.rect[FOREGROUND].left == 5760) {
        runner->game.rect[FOREGROUND].left = 0;
        i = 0;
        return;
    }
    return;
}

void move_foreground(runner_t *runner)
{
    float seconds;

    runner->game.rect[FOREGROUND] = sfSprite_getTextureRect(runner->game.sprite[FOREGROUND]);
    runner->game.time[FOREGROUND] = sfClock_getElapsedTime(runner->game.clock[FOREGROUND]);
    seconds = runner->game.time[FOREGROUND].microseconds / 1000000.0;
    if (seconds > 0.030) {
        move_rect_foreground(runner);
        sfClock_restart(runner->game.clock[FOREGROUND]);
    }
    sfSprite_setTextureRect(runner->game.sprite[FOREGROUND], runner->game.rect[FOREGROUND]);
}

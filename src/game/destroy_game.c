#include "runner.h"

void destroy_game(runner_t *runner)
{
    for (int i = 0; i != MOUSE + 1; i++)
        sfSprite_destroy(runner->menu.sprite[i]);
    for (int i = 0; i != BACKGROUND_END + 1; i++)
        sfSprite_destroy(runner->game.sprite[i]);
    sfMusic_destroy(runner->game.music[MAIN_MUSIC]);
    sfMusic_destroy(runner->game.music[JUMP]);
    sfMusic_destroy(runner->game.music[COUP]);
    for (int i = 0; i != END + 1; i++)
        sfClock_destroy(runner->game.clock[i]);
}

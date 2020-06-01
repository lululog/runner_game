#include "runner.h"

void destroy_game(runner_t *runner)
{
    sfSprite_destroy(runner->menu.sprite[MENU]);
    sfSprite_destroy(runner->menu.sprite[START]);
    sfSprite_destroy(runner->menu.sprite[EXIT]);
    sfSprite_destroy(runner->menu.sprite[MOUSE]);
    sfMusic_destroy(runner->game.music[MAIN_MUSIC]);
    sfMusic_destroy(runner->game.music[JUMP]);
    sfMusic_destroy(runner->game.music[COUP]);
}

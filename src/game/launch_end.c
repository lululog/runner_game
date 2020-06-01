#include "runner.h"

void analyse_events_end(runner_t *runner)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 ||
        runner->game.event.type == sfEvtClosed)
            runner->statut = 6;
}

void launch_end(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window, runner->game.sprite[BACKGROUND_END], NULL);
    sfRenderWindow_drawText(runner->window, runner->game.text[FINISH], NULL);
    analyse_events_end(runner);
}
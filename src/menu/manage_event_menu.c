#include "runner.h"

void manage_mouse_move_main(sfMouseMoveEvent event, runner_t *runner)
{
    runner->anim_mouse.position.x = event.x;
    runner->anim_mouse.position.y = event.y;
    sfSprite_setPosition(runner->menu.sprite[MOUSE], runner->anim_mouse.position);
}

void manage_mouse_move(sfMouseMoveEvent event, runner_t *runner)
{
    anim_start_move(event, runner);
    anim_exit_move(event, runner);
    if (runner->anim_start.x <= 400 && runner->anim_start.x >= 0 &&
    runner->anim_start.y <= 170 && runner->anim_start.y >= 0)
        sfSprite_setPosition(runner->menu.sprite[START], runner->anim_start.move);
    else
        sfSprite_setPosition(runner->menu.sprite[START], runner->anim_start.position);
    if (runner->anim_exit.x <= 400 && runner->anim_exit.x >= 0 &&
    runner->anim_exit.y <= 170 && runner->anim_exit.y >= 0)
        sfSprite_setPosition(runner->menu.sprite[EXIT], runner->anim_exit.move);
    else
        sfSprite_setPosition(runner->menu.sprite[EXIT], runner->anim_exit.position);
}

void manage_mouse_click(sfMouseButtonEvent event, runner_t *runner)
{
    anim_start_click(event, runner);
    anim_exit_click(event, runner);
    if (runner->anim_start.x <= 400 && runner->anim_start.y >= 0 &&
    runner->anim_start.y <= 170 && runner->anim_start.y >= 0)
        runner->statut = 2;
    if (runner->anim_exit.x <= 400 && runner->anim_exit.x >= 0 &&
    runner->anim_exit.y <= 170 && runner->anim_exit.y >= 0)
        runner->statut = 5;
}

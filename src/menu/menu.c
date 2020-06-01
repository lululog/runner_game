#include "runner.h"

void destroy_menu (runner_t *runner)
{
    for (int i = 0; i != MOUSE; i++) {
        sfSprite_destroy(runner->menu.sprite[i]);
        sfTexture_destroy(runner->menu.texture[i]);
    }
}

void analyse_events_menu(runner_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->menu.event)) {
        if (runner->menu.event.type == sfEvtKeyPressed) {
            runner->statut = 2;
        }
        if (runner->menu.event.type == sfEvtMouseMoved) {
            manage_mouse_move_main(runner->menu.event.mouseMove, runner);
            manage_mouse_move(runner->menu.event.mouseMove, runner);
        }
        if (runner->menu.event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(runner->menu.event.mouseButton, runner);
    }
}

void launch_game_menu (runner_t *runner)
{
    for (int i = 0; i < MOUSE + 1; i++)
        sfRenderWindow_drawSprite(runner->window, runner->menu.sprite[i], NULL);
    analyse_events_menu(runner);
}
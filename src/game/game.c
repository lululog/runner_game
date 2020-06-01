#include "runner.h"

void get_score(runner_t *runner)
{
    float seconds;
    static int i = 0;
    char *str = NULL;

    runner->game.time[7] = sfClock_getElapsedTime(runner->game.clock[7]);
    seconds = runner->game.time[7].microseconds / 1000000.0;
    if (seconds > 0.10) {
        str = my_getchar(i);
        sfText_setString(runner->game.text[SCORE_NUMBER], str);
        i++;
        sfClock_restart(runner->game.clock[7]);
    }
    if (i == runner->game.end) {
        sfText_setString(runner->game.text[FINISH], "YOU ARE WIN ! PRESS Q FOR QUIT");
        runner->statut = 3;
    }
}

void analyse_events(runner_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->game.event)) {
        if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 ||
        runner->game.event.type == sfEvtClosed)
            runner->statut = 5;
        if (runner->game.jump != 3 && runner->game.jump != 2 && runner->game.jump != 1) {
            if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
                sfMusic_play(runner->game.music[JUMP]);
                runner->game.jump = 1;
                while (runner->game.jump < 3) {
                    sfRenderWindow_display(runner->window);
                    launch_game(runner);
                    anim_player_jump(runner);
                }
                runner->game.jump = 0;
            }
        }
    }
}

void launch_game(runner_t *runner)
{
    for (int i = 0; i != LIFE_THREE + 1; i++)
        sfRenderWindow_drawSprite(runner->window, runner->game.sprite[i], NULL);
    for (int i = 0; i != SCORE_OBTAINED + 1; i++)
        sfRenderWindow_drawText(runner->window, runner->game.text[i], NULL);
    move_sky(runner);
    move_background(runner);
    move_foreground(runner);
    move_player(runner);
    move_life(runner);
    move_npc(runner);
    get_score(runner);
    analyse_events(runner);
    finish_game(runner);
}

void main_game(runner_t *runner)
{
    sfRenderWindow_display(runner->window);
    if (runner->statut == 1)
        launch_game_menu(runner);
    else if (runner->statut == 2)
        launch_game(runner);
    else if (runner->statut == 3)
        launch_end(runner);
    else
        sfRenderWindow_close(runner->window);
}

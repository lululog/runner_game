#include "runner.h"

void check_finish_game(runner_t *runner, int i)
{
    sfVector2f position = {-200, 0};

    if (i == 1)
        sfSprite_setPosition(runner->game.sprite[LIFE_THREE], position);
    if (i == 2)
        sfSprite_setPosition(runner->game.sprite[LIFE_TWO], position);
    if (i == 3) {
        sfText_setString(runner->game.text[FINISH], "YOU ARE DEAD ! PRESS Q FOR QUIT");
        runner->statut = 3;
    }
}

int position_sprite(runner_t *runner, position_t position, int i)
{
    static int j = 0;

    if ((position.pos_npc_one.x <= position.pos_player.x + 60 &&
         position.pos_npc_one.x >= position.pos_player.x - 60) &&
         position.pos_player.y >= 628) {
        sfMusic_play(runner->game.music[COUP]);
        i++;
    }
    if ((position.pos_npc_two.x <= position.pos_player.x + 60 &&
         position.pos_npc_two.x >= position.pos_player.x - 60) &&
         position.pos_player.y >= 628) {
        sfMusic_play(runner->game.music[COUP]);
        i++;
    }
    j = i;
    return j;
}

void finish_game(runner_t *runner)
{
    position_t position;
    float seconds;
    static int i = 0;

    runner->game.time[END] = sfClock_getElapsedTime(runner->game.clock[END]);
    seconds = runner->game.time[END].microseconds / 1000000.0;
    if (seconds > 0.50) {
        position.pos_npc_one = sfSprite_getPosition(runner->game.sprite[NPC_ONE]);
        position.pos_npc_two = sfSprite_getPosition(runner->game.sprite[NPC_TWO]);
        position.pos_player = sfSprite_getPosition(runner->game.sprite[PLAYER]);
        i = position_sprite(runner, position, i);
        sfClock_restart(runner->game.clock[END]);
    }
    check_finish_game(runner, i);
}

#include "runner.h"

void anim_start_move(sfMouseMoveEvent event, runner_t *runner)
{
    runner->anim_start.move.x = runner->anim_start.position.x + 50;
    runner->anim_start.move.y = runner->anim_start.position.y;
    runner->anim_start.x = event.x - runner->anim_start.position.x;
    runner->anim_start.y = event.y - runner->anim_start.position.y;
}

void anim_start_click(sfMouseButtonEvent event, runner_t *runner)
{
    runner->anim_start.move.x = runner->anim_start.position.x + 1;
    runner->anim_start.move.y = runner->anim_start.position.y;
    runner->anim_start.x = event.x - runner->anim_start.position.x;
    runner->anim_start.y = event.y - runner->anim_start.position.y;
}

void anim_exit_click(sfMouseButtonEvent event, runner_t *runner)
{
    runner->anim_exit.move.x = runner->anim_exit.position.x - 1;
    runner->anim_exit.move.y = runner->anim_exit.position.y;
    runner->anim_exit.x = event.x - runner->anim_exit.position.x;
    runner->anim_exit.y = event.y - runner->anim_exit.position.y;
}

void anim_exit_move(sfMouseMoveEvent event, runner_t *runner)
{
    runner->anim_exit.move.x = runner->anim_exit.position.x - 50;
    runner->anim_exit.move.y = runner->anim_exit.position.y;
    runner->anim_exit.x = event.x - runner->anim_exit.position.x;
    runner->anim_exit.y = event.y - runner->anim_exit.position.y;
}

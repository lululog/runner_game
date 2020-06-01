#include "runner.h"

bool print_message_help_and_error(int argc, char **argv, runner_t *runner)
{
    if (argc != 2) {
        printf("./my_runner:\tbad arguments.\nretry with -h\n");
        return false;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
       printf("Finite runner created with CSFML.\n\nUSAGE\n\t./my_runner [score to be obtained]\n\nOPTIONS\n");
       printf("-h\tprint the usage and quit.\n\nUSER INTERACTIONS\nSPACE_KEY\tjump.\n\nThe score must be between 100 and 9999");
       exit (0);
    }
    if ((runner->game.end = atoi(argv[1])) == 0 ||
        runner->game.end > 9999 || runner->game.end < 100) {
       printf("./my_runner:\tbad arguments.\nretry with -h\n");
       return false;
    }
    return true;
}

void game(runner_t *runner)
{
    while (sfRenderWindow_isOpen(runner->window))
        main_game(runner);
    destroy_game(runner);
}

bool launcher(int argc, char **argv)
{
    runner_t runner;

    if (!print_message_help_and_error(argc, argv, &runner))
        return false;
    init_game(&runner);
    game(&runner);
    return true;
}
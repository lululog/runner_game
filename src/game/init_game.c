#include "runner.h"

sfSprite *create_sprite(sfTexture *texture, char *path, int top, int left, int width, int height)
{
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;

    if (width != 0 && height != 0) {
        if (height == 172 || height == 95) {
            rect.top = 0;
            rect.left = 0;
        } else {
            rect.top = top;
            rect.left = left;
        }
        rect.width = width;
        rect.height = height;
    }
    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(path, NULL);
    if (top != 0 || left != 0) {
        position.x = top;
        position.y = left;
        sfSprite_setPosition(sprite, position);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (height == 172 || height == 95)
        sfSprite_setTextureRect(sprite, rect);
    return sprite;
}

void init_sprite(runner_t *runner)
{
    runner->menu.sprite[MENU] = create_sprite(runner->menu.texture[MENU], "./assets/MENU/Background.png", 0, 0, 0, 0);
    runner->menu.sprite[START] = create_sprite(runner->menu.texture[START], "./assets/MENU/RUN.png", 1000, 500, 0, 0);
    runner->anim_start.position.x = 1000;
    runner->anim_start.position.y = 500;
    runner->menu.sprite[EXIT] = create_sprite(runner->menu.texture[EXIT], "./assets/MENU/EXIT.png", 500, 500, 0, 0);
    runner->anim_exit.position.x = 500;
    runner->anim_exit.position.y = 500;
    runner->menu.sprite[MOUSE] = create_sprite(runner->menu.texture[MOUSE], "./assets/GAME/cursor.png", 0, 0, 0, 0);
    runner->anim_mouse.position.x = 0;
    runner->anim_mouse.position.y = 0;
    runner->game.sprite[SKY] = create_sprite(runner->game.texture[SKY], "./assets/GAME/ciel.png", 0, 0, 1920, 1080);
    runner->game.sprite[BACKGROUND] = create_sprite(runner->game.texture[BACKGROUND], "./assets/GAME/background.png", 0, 0, 1920, 1080);
    runner->game.sprite[FOREGROUND] = create_sprite(runner->game.texture[FOREGROUND], "./assets/GAME/ground_and_ceiling.png", 0, 0, 1920, 1080);
    runner->game.sprite[PLAYER] = create_sprite(runner->game.texture[PLAYER], "./assets/GAME/PLAYER.png", 400, 800, 119, 172);
    runner->game.sprite[NPC_ONE] = create_sprite(runner->game.texture[NPC_ONE], "./assets/GAME/COP.CARLOSRUN.V2.png", 1800, 800, 100, 172);
    runner->game.sprite[NPC_TWO] = create_sprite(runner->game.texture[NPC_TWO], "./assets/GAME/COP.CARLOSRUN.V3.png", 2500, 800, 100, 172);
    runner->game.sprite[LIFE_ONE] = create_sprite(runner->game.texture[LIFE_ONE], "./assets/GAME/life.png", 1300, 0, 70, 95);
    runner->game.sprite[LIFE_TWO] = create_sprite(runner->game.texture[LIFE_TWO], "./assets/GAME/life.png", 1350, 0, 70, 95);
    runner->game.sprite[LIFE_THREE] = create_sprite(runner->game.texture[LIFE_THREE], "./assets/GAME/life.png", 1400, 0, 70, 95);
    runner->game.sprite[BACKGROUND_END] = create_sprite(runner->game.texture[BACKGROUND_END], "./assets/MENU/Background.png", 0, 0, 0, 0);
}

void create_text(runner_t *runner, int index, char *str, float x, float y, int size)
{
    sfVector2f position = {x, y};

    if (str != NULL)
        sfText_setString(runner->game.text[index], str);
    sfText_setPosition(runner->game.text[index], position);
    sfText_setCharacterSize(runner->game.text[index], size);
}

void init_text(runner_t *runner)
{
    char *str = NULL;

    runner->game.text = malloc(sizeof(sfText *) * 6);
    runner->game.font = sfFont_createFromFile("./assets/POLICE/Pixeled.ttf");
    for (int i = 0; i < 6; i++) {
        runner->game.text[i] = sfText_create();
        sfText_setFont(runner->game.text[i], runner->game.font);
        sfText_setColor(runner->game.text[i], sfWhite);
    }
    str = my_getchar(runner->game.end);
    create_text(runner, SCORE, "SCORE :", 1580, 30, 30);
    create_text(runner, SCORE_NUMBER, NULL, 1780, 30, 30);
    create_text(runner, INFO, "Press Q for quit", 50, 50, 20);
    create_text(runner, LIFE, "LIFE :", 1150, 30, 30);
    create_text(runner, FINISH, NULL, 400, 500, 50);
    create_text(runner, SCORE_OBTAINED, str, 1780, 100, 30);
}

void init_game(runner_t *runner)
{
    runner->window = MyNewWindow(1920, 1080);
    runner->statut = 1;
    runner->game.clock = malloc(sizeof(sfClock *) * 11);
    runner->game.time = malloc(sizeof(sfTime) * 11);
    runner->game.music = malloc(sizeof(sfMusic *) * 3);
    runner->menu.sprite = malloc(sizeof(sfSprite *) * 4);
    runner->menu.texture = malloc(sizeof(sfTexture *) * 4);
    runner->game.sprite = malloc(sizeof(sfSprite *) * 10);
    runner->game.texture = malloc(sizeof(sfTexture *) * 10);
    runner->game.rect = malloc(sizeof(sfIntRect) * 11);
    for (int i = 0; i < 11; i++)
        runner->game.clock[i] = sfClock_create();
    runner->game.music[MAIN_MUSIC] = sfMusic_createFromFile("assets/MUSIC/main_music.ogg");
    runner->game.music[JUMP] = sfMusic_createFromFile("assets/MUSIC/jump.ogg");
    runner->game.music[COUP] = sfMusic_createFromFile("assets/MUSIC/coup.ogg");
    sfMusic_play(runner->game.music[MAIN_MUSIC]);
    sfMusic_setVolume(runner->game.music[MAIN_MUSIC], 30.0);
    sfMusic_setLoop(runner->game.music[MAIN_MUSIC], sfTrue);
    sfRenderWindow_setMouseCursorVisible(runner->window, 0);
    init_text(runner);
    init_sprite(runner);
    runner->game.jump = 0;
}

#include "runner.h"

sfRenderWindow *MyNewWindow(unsigned width, unsigned height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(video_mode,
                                   "MY_RUNNER",
                                   sfFullscreen,
                                   NULL);
    return (window);
}

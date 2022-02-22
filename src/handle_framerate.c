/*
** EPITECH PROJECT, 2021
** framerate
** File description:
** framerate
*/

#include "my_defender.h"

void handle_framerate(sfRenderWindow *win, sfClock *fps)
{
    float framerate = 0.f;
    framerate = 1.f / (sfClock_getElapsedTime(fps).microseconds * 0.000001);
    sfRenderWindow_setFramerateLimit(win, framerate);
}

/*
** EPITECH PROJECT, 2022
** create
** File description:
** Function to create objects
*/

#include "my_defender.h"

sfText *create_text(sfFont *font, sfVector2f pos, char *txt, int size)
{
    sfText *text = sfText_create();
    sfText_setString(text, txt);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return text;
}

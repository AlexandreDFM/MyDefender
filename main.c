/*
** EPITECH PROJECT, 2021
** main
** File description:
** Main of Runner
*/

#include "my_defender.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc == 2 && my_strlen(argv[1]) == 2 && argv[1][0] == '-'
    && argv[1][1] == 'h') {
    } else if (argc == 1) {
        load_window();
    }
    return (0);
}

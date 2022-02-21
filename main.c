/*
** EPITECH PROJECT, 2021
** main
** File description:
** Main of Runner
*/

#include "./include/my_defender.h"

void print_manual(void)
{
    my_putstr("\n                                                  DINO "
                "RUN\n\n");
    my_putstr("Dino run is a runner game in which the objective is to "
                "jump and crouch to avoid the ennemies on the screen in.\n");
    my_putstr("The dino will move faster with the score.\n");
    my_putstr("\n                                                  RULES\n\n");
    my_putstr("Don't be killed by ennemies. (You must avoid ennemies)\n");
    my_putstr("\n                                                  "
                "CONTROLS\n\n");
    my_putstr("      - Click on the play bouton to start or exit bouton to "
                "exit.\n");
    my_putstr("      - Once in game press escape to pause.\n");
    my_putstr("      - If paused press space or click on the play bouton to "
                "resume, you can also click on the exit bouton to exit.\n");
    my_putstr("      - If you Game Over you can press Play Again or "
    "Escape bouton to close.\n");
}

void print_manual2(void)
{
    my_putstr("      - Jump with RSHIFT and Crouch with LShift.\n");
    my_putstr("      - On Menu you can change dino color by clicking "
    "on it.\n");
    my_putstr("\n                                                  "
                "MAPS\n\n");
    my_putstr("  You can create your map using a .txt file in the maps "
                "directory (see map1.txt for an exemple)\n");
    my_putstr("  Replace empty spaces with numbers of your choice\n\n");
    my_putstr("      - 1 = basic snowman\n");
    my_putstr("      - 2 = flying snowman\n");
    my_putstr("      - 4 = coin (+10 to score)\n");
    my_putstr("      - 5 = flag to finish\n\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strlen(argv[1]) == 2 && argv[1][0] == '-'
    && argv[1][1] == 'h') {
        print_manual();
        print_manual2();
    } else if (argc == 1) {
        srand(time(0));
        display_window();
    }
    return (0);
}

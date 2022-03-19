##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = my_defender

CC    = gcc

RM    = rm -f

SRC    = main.c								\
		src/check_map.c						\
		src/create_textures.c				\
		src/create.c						\
		src/create_2.c						\
		src/create_node.c					\
		src/cursor.c						\
		src/defender.c						\
		src/display.c						\
		src/debug.c							\
		src/menu.c							\
		src/game.c							\
		src/gameover.c						\
		src/gamewin.c						\
		src/init_defender.c					\
		src/init_game_1.c					\
		src/uninit_defender.c				\
		src/uninit_game_1.c					\
		src/intro.c							\
		src/load_bloons.c					\
		src/monkey.c						\
		src/waves.c							\
		src/bloons_color.c					\
		src/pause.c							\
		src/skill_tree.c					\
		src/select_map.c					\
		src/tower_nodes.c					\
		src/tower_hitbox.c					\
		src/check_towers_placement.c		\
		src/tower_attack.c					\
		src/how_to_play.c					\
		src/settings.c						\
		src/score.c							\
		src/utils/my_atoi.c					\
		src/utils/my_free_array.c			\
		src/utils/my_memset.c				\
		src/utils/my_strcat_alloc.c			\
		src/utils/my_strdup.c				\
		src/utils/my_strcpy.c				\
		src/utils/my_strtwa.c				\
		src/utils/my_itoa.c					\

OBJ    = $(SRC:.c=.o)

CFLAGS += -Wall -pedantic -I./include -g3

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics 		\
-lcsfml-window -lcsfml-system -lcsfml-audio								\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib/my
	@$(CC) $(SRC) -o $(NAME) $(LIBFLAG) -lm

clean:
	@$(RM) $(OBJ)
	@make -C ./lib/my fclean

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)

re: fclean all

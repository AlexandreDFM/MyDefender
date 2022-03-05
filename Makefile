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
		src/cursor.c						\
		src/defender.c						\
		src/display.c						\
		src/gamemenu.c						\
		src/game.c							\
		src/init.c							\
		src/intro.c							\
		src/load_bloons.c					\
		src/monkey.c						\
		src/waves.c							\
		src/bloons_color.c					\
		src/utils/my_atoi.c					\
		src/utils/my_memset.c				\
		src/utils/my_strdup.c				\
		src/utils/my_strcpy.c				\
		src/utils/my_strtwa.c				\
		src/utils/my_itoa.c					\
		src/pause.c							\

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

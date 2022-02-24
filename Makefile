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
		src/create_textures.c				\
		src/create.c						\
		src/cursor.c						\
		src/defender.c						\
		src/display.c						\
		src/gamemenu.c						\
		src/my_str_to_word_array.c			\
		src/game.c							\
		src/check_map.c						\
		src/load_bloons.c					\
		src/my_atoi.c						\
		src/my_memset.c						\
		src/my_strdup.c						\
		src/my_strcpy.c						\

OBJ    = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -pedantic -I./include -g3

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics 		\
-lcsfml-window -lcsfml-system -lcsfml-audio								\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib/my
	@$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	@$(RM) $(OBJ)
	@make -C ./lib/my fclean

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJS)

re: fclean all

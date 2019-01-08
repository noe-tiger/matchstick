##
## Makefile for  in /home/nono/bootstrap_wolf3D
## 
## Made by Noé
## Login   <noe.tiger@epitech.eu@epitech.net>
## 
## Started on  Mon Dec 12 16:14:00 2016 Noé
## Last update Mon Feb 20 13:14:39 2017 Noe_tiger
##

SRC     =	src/main.c		\
		src/put.c		\
		src/my_strlen.c		\
		src/my_int.c		\
		src/map_create.c	\
		src/game.c		\
		src/player.c		\
		src/intelligence.c	\
		src/get_old.c		\
		src/ia_last.c

NAME    =	matchstick

OBJ     =       $(SRC:.c=.o)

CC      =       gcc -Werror -g3

CFLAGS  =       -Wall -Wextra -I./include -Werror

RM      =       rm -f

all:    $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

$(NAME):    $(OBJ)
	$(CC) $(SRC) -o $(NAME)

re:     fclean all clean

.PHONY: all re clean fclean

##
## Makefile for tekadventure in /home/heychsea/MUL/tekadventure
## 
## Made by Hugo Cousin
## Login   <hugo.cousin@epitech.eu>
## 
## Started on  Wed Apr 12 15:45:03 2017 Hugo Cousin
## Last update Thu Apr 13 16:27:50 2017 Hugo Cousin
##

SRC	=	src/main.c		\
		src/init/sentences.c	\
		src/end/free_players.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tekadventure

CFLAGS	=	-W -Wall -Wextra -I ./include

LDFLAGS	=	-Llib -lmy

CC	=	gcc

RM	=	rm

all:	$(NAME)

lib:
	$(MAKE) -C lib/my

clib:
	$(MAKE) -C lib/my clean

$(NAME):$(OBJ)
	@if ! [ -f lib/libmy.a ]; then $(MAKE) -C lib/my; fi;
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) -rf $(OBJ)

fclean:	clean
	$(RM) -rf $(NAME)

re: fclean all

debug: override CFLAGS := -ggdb3 $(CFLAGS)
debug: fclean clib lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

.PHONY: all lib clib clean fclean re full

##
## Makefile for refresh in /home/heychsea/MUL/tekadventure/refresh
## 
## Made by Hugo Cousin
## Login   <hugo.cousin@epitech.eu>
## 
## Started on  Tue May 23 12:13:06 2017 Hugo Cousin
## Last update Tue May 23 12:15:15 2017 Hugo Cousin
##

SRC	=	main.c		\
		refresh.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I../include

LDFLAGS	=	-L../lib -lmy -lc_graph_prog_full -lm

NAME	=	refresh

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

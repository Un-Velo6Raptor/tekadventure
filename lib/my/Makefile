##
## Makefile for LIB in /home/heychsea/PSU/PSU_2016_minishell2/lib/min
## 
## Made by Hugo Cousin
## Login   <hugo.cousin@epitech.eu>
## 
## Started on  Wed Apr 19 18:24:42 2017 Hugo Cousin
## Last update Tue May 23 11:23:34 2017 Hugo Cousin
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_putnbr.c		\
		my_getnbr.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_strcat.c		\
		my_strdup.c		\
		my_show_wordtab.c	\
		my_str_to_wordtab.c	\
		char_test.c		\
		strclean.c		\
		mem.c			\
		gnl.c			\
		tab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

LIB:	$(NAME) $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) ../$(NAME)

debug: CFLAGS += -ggdb3
debug: re

re: fclean all

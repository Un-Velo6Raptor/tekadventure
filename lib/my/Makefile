##
## Makefile for my in /home/heychsea/MUL/ceciesttemporaire
## 
## Made by Hugo Cousin
## Login   <hugo.cousin@epitech.eu>
## 
## Started on  Wed Apr 12 15:46:22 2017 Hugo Cousin
## Last update Wed Apr 12 15:46:41 2017 Hugo Cousin
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
		get_next_line.c		\
		char_test.c		\
		gnlfix.c		\
		strclean.c		\
		mem.c			\
		tab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

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

re: fclean all

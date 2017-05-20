##
## Makefile for  in /home/januar_m/delivery/graphical/tekadventure
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Fri May 19 15:09:40 2017 Martin Januario
## Last update Sat May 20 22:12:18 2017 Martin Januario
##

.PHONY:		all clean fclean re

SRC	=	src/main.c			\
		src/check_env.c			\
		src/create_vector.c		\
		src/create_color.c		\
		src/match.c

DISPLAY	=	src/display/window_menu.c	\
		src/display/create_window.c

MENU	=	src/menu/loop_menu.c		\
		src/menu/draw_sprite_menu.c	\
		src/menu/place_sprite_menu.c	\
		src/menu/destroy_menu.c		\
		src/menu/ini_text_menu.c	\
		src/menu/gest_mouse_menu.c	\
		src/menu/ini_music_menu.c	\
		src/menu/music_or_not.c		\
		src/menu/music_pause.c		\
		src/menu/ini_sprite_menu.c

LIB	=	src/lib/my_putstr.c		\
		src/lib/my_strlen.c

OBJ	=	$(SRC:.c=.o)			\
		$(DISPLAY:.c=.o)		\
		$(MENU:.c=.o)			\
		$(LIB:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include

NAME	=	tekadventure

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog_full -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

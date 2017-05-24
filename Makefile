##
## Makefile for  in /home/januar_m/delivery/graphical/tekadventure
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Fri May 19 15:09:40 2017 Martin Januario
## Last update Tue May 23 19:34:51 2017 Martin Januario
##

.PHONY:		all clean fclean re

SRC	=	src/main.c			\
		src/check_env.c			\
		src/create_vector.c		\
		src/create_color.c		\
		src/match.c			\
		src/init/sentences.c

DISPLAY	=	src/display/window_menu.c	\
		src/display/window_game.c	\
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

GAME	=	src/game/loop_game.c		\

MECHS	=	src/moves/moves.c		\

OBJ	=	$(SRC:.c=.o)			\
		$(DISPLAY:.c=.o)		\
		$(MENU:.c=.o)			\
		$(GAME:.c=.o)			\
		$(MECHS:.c=.o)			\
		$(LIB:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include

LDFLAGS	=	-L lib -lmy -lc_graph_prog_full -lm

NAME	=	tekadventure

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

lib:
		$(MAKE) -C lib/my re

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

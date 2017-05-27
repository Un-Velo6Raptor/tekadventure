##
## Makefile for  in /home/januar_m/delivery/graphical/tekadventure
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Fri May 19 15:09:40 2017 Martin Januario
## Last update Fri May 26 21:49:04 2017 Hugo Cousin
##

.PHONY:		all clean fclean re

SRC	=	src/main.c			\
		src/check_env.c			\
		src/create_vector.c		\
		src/create_color.c		\
		src/match.c			\
		src/init/sentences.c		\
		src/init/boss.c			\
		src/init/character.c		\
		src/init/map.c			\
		src/init/config.c		\
		src/init/player.c

DISPLAY	=	src/display/window_menu.c	\
		src/display/create_window.c	\
		src/display/refresh.c		\
		src/display/window_game.c	\
		src/display/anim.c		\
		src/display/shade.c		\
		src/display/utils.c

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

TUTO	=	src/tuto/clean_tuto.c		\
		src/tuto/init_tuto.c		\
		src/tuto/my_sleep.c		\
		src/tuto/tuto.c

GAME	=	src/game/loop_game.c		\
		src/game/room.c

MECHS	=	src/moves/moves.c		\
		src/moves/doors.c

BAR	=	src/bar/bar_create.c            \
		src/bar/my_framebuffer_create.c \
		src/bar/get_set_pixel.c         \
		src/bar/fill_square.c           \
		src/bar/update_sprite_bar.c     \
		src/bar/reset_frame.c

SELECT	=	src/select/select_player.c	\
		src/select/click_select.c	\
		src/select/place_select.c

OBJ	=	$(SRC:.c=.o)			\
		$(DISPLAY:.c=.o)		\
		$(MENU:.c=.o)			\
		$(GAME:.c=.o)			\
		$(MECHS:.c=.o)			\
		$(LIB:.c=.o)			\
		$(BAR:.c=.o)			\
		$(SELECT:.c=.o)			\
		$(TUTO:.c=.o)

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

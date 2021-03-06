##
## Makefile for  in /home/januar_m/delivery/graphical/tekadventure
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Fri May 19 15:09:40 2017 Martin Januario
## Last update Sun May 28 22:38:41 2017 Martin Januario
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
		src/dico.c			\
		src/init/map.c			\
		src/init/config.c		\
		src/concat.c			\
		src/music.c			\
		src/init/player.c		\
		src/init/velleda.c		\
		src/game/room_handler.c		\
		src/end/free_needs.c

DISPLAY	=	src/display/window_menu.c	\
		src/display/create_window.c	\
		src/display/refresh.c		\
		src/display/window_game.c	\
		src/display/anim.c		\
		src/display/shade.c		\
		src/display/utils.c		\
		src/display/velleda.c

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
		src/game/draw_game.c		\
		src/game/first_part.c		\
		src/game/get_mouse_pos.c	\
		src/game/room.c

MECHS	=	src/moves/moves.c		\
		src/moves/doors.c

BAR	=	src/bar/bar_create.c            \
		src/bar/my_framebuffer_create.c \
		src/bar/get_set_pixel.c         \
		src/bar/fill_square.c           \
		src/bar/update_sprite_bar.c     \
		src/bar/display_fight.c		\
		src/bar/reset_frame.c		\
		src/bar/disp.c

SELECT	=	src/select/select_player.c	\
		src/select/click_select.c	\
		src/select/place_select.c	\
		src/select/select_init.c

BOSS	=	src/boss/check_map_boss.c	\
		src/boss/final_fight.c		\
		src/boss/mike.c

OBJ	=	$(SRC:.c=.o)			\
		$(DISPLAY:.c=.o)		\
		$(MENU:.c=.o)			\
		$(GAME:.c=.o)			\
		$(MECHS:.c=.o)			\
		$(LIB:.c=.o)			\
		$(BOSS:.c=.o)			\
		$(BAR:.c=.o)			\
		$(SELECT:.c=.o)			\
		$(TUTO:.c=.o)

CFLAGS	=	-Wall -Wextra -I include

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

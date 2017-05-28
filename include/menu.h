/*
** menu.h for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 19 16:37:41 2017 Martin Januario
** Last update Sun May 28 19:35:48 2017 Sahel Lucas--Saoudi
*/

#ifndef		MENU_H_
# define	MENU_H_

# include	"display.h"

# define	WIDTH		1000
# define	HEIGHT		800

# define	MAX_SPRITE_MENU	2
# define	TITLE_M		0
# define	BUTTON_PLAY	1

# define	MAX_SONG_MENU	5
# define	THEME_MENU	0
# define	JOKE_MENU	1
# define	EASY_MENU	2
# define	HARD_MENU	3
# define	NORMAL_MENU	4

/*
**	m_sprite[0]: title.png
*/

typedef struct		s_sprite_menu
{
  sfSprite		*m_sprite[2];
  sfTexture		*m_texture[2];
}			t_sprite_menu;

typedef struct		s_text_menu
{
  sfFont		*font;
  sfText		*title_diff;
  sfText		*diff[4];
  sfText		*title_lang;
  sfText		*lang[3];
  sfText		*title_key;
  sfText		*keyboard[3];
  sfText		*title_sound;
  sfText		*sound[3];
}			t_text_menu;

typedef struct          s_core
{
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  sfMusic               *music[6];
}                       t_core;

int		loop_menu(t_mode_game *, t_core *);
int		ini_sprite_menu(t_sprite_menu *, t_core *);
int		ini_text_menu(t_text_menu *, t_core *);
void		draw_sprite_menu(t_sprite_menu *, t_core *, t_text_menu *);
void		place_sprite_menu(t_sprite_menu *);
int		destroy_menu(t_core *, t_sprite_menu *, t_text_menu *,
			     t_mode_game *);
void		gest_mouse_menu(t_mode_game *, sfEvent *,
				t_text_menu *, t_core *);
int		ini_music_menu(t_core *);
void		destroy_music(t_core *, int, t_mode_game *);
void		music_play_menu(t_mode_game *, t_core *);
void		music_stop_menu(t_mode_game *, t_core *);
void		stop_music_except_one(t_core *, int);

#endif		/* !MENU_H_ */

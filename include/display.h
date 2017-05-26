/*
** display.h for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 19 15:18:37 2017 Martin Januario
** Last update Fri May 26 20:48:08 2017 Martin Januario
*/

#ifndef			DISPLAY_H_
# define		DISPLAY_H_

# include		<SFML/Graphics/RenderWindow.h>
# include		<SFML/Graphics/Sprite.h>
# include		<SFML/Graphics/Texture.h>
# include		<SFML/Graphics/Color.h>
# include		<SFML/System.h>
# include		<SFML/Audio.h>
# include		<SFML/Graphics.h>
# include		"config.h"
# include		"character.h"

typedef struct  s_map
{
  char          *name;
  sfSprite      *map;
  sfImage       *image;
  sfVector2i    pos_map;
  int           veleda;
  int           boss;
  sfVector2u	size;
  sfMusic       *theme;
}               t_map;

typedef struct		s_needs
{
  char			*dirs[CONFIG_DIR + 1];
  sfRenderWindow	*window;
  t_map			**map;
  int			current_map;
  int			current_player;
  int			current_veleda;
  sfVector2i		pos;
  t_char		**player;
  t_char		**boss;
  struct s_mode_game	*mode;
}			t_needs;

typedef struct		s_mode_game
{
  int			difficult;
  int			lang;
  int			keyboard;
  int			sound;
  int			play;
}			t_mode_game;

/*
**			Prototypes of file's display
*/
int			window_menu(t_mode_game *);
int			window_game(t_needs *);
sfRenderWindow		*create_window(char *, int, int);

/*
**			Prototypes of file's sources.
*/
int			match(char *, char *);
int			check_env(char **);
sfVector2f		vector_2f(float, float);
sfVector2i		vector_2i(int, int);
sfColor			color(int, int, int);
int			config(t_needs *);

#endif			/* !DISPLAY_H_ */

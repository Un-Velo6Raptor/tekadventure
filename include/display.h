/*
** display.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 15:18:37 2017 Martin Januario
** Last update Tue May 23 17:21:02 2017 Martin Januario
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

typedef struct		s_core
{
  sfRenderWindow       	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfMusic		*music[6];
}			t_core;

typedef struct		s_map
{
  sfImage		*map;
  sfVector2u		size;
  struct s_map		*next;
}			t_map;

typedef struct		s_needs
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_map			map;		
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
int			window_game(t_mode_game *);
sfRenderWindow		*create_window(char *, int, int);

/*
**			Prototypes of file's sources.
*/
int			match(char *, char *);
int			check_env(char **);
sfVector2f		vector_2f(float, float);
sfVector2i		vector_2i(int, int);
sfColor			color(int, int, int);

#endif			/* !DISPLAY_H_ */

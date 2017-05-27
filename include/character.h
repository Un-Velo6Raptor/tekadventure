/*
** character.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:15:04 2017 Sahel Lucas--Saoudi
** Last update Sat May 27 22:49:45 2017 Sahel Lucas--Saoudi
*/

#ifndef CHARACTER_H_
# define CHARACTER_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include "struct.h"

# ifndef ALIVE
#  define ALIVE 0
# endif /* !ALIVE */

# ifndef DEAD
#  define DEAD 1
# endif /* !DEAD */

struct				s_char
{
  char				*name;
  sfSprite			*sprite;
  sfSprite			*select;
  sfVector2f			pos;
  t_text			*phrase;
  int				death;
  sfMusic			*music;
};

typedef struct s_char		t_char;

t_char				*new_char(char *, char *,
					  sfVector2f, t_text *);

#endif /* !CHARACTER_H_ */

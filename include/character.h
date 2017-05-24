/*
** character.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:15:04 2017 Sahel Lucas--Saoudi
** Last update Wed May 24 16:57:57 2017 Sahel Lucas--Saoudi
*/

#ifndef CHARACTER_H_
# define CHARACTER_H_

# include <SFML/Graphics.h>

struct                  s_char
{
  char                  *name;
  sfSprite              *sprite;
  sfVector2i            pos;
};

typedef struct s_char		t_char;

struct				s_character
{
  t_char			**boss;
  t_char			**player;
};

typedef struct s_character	t_character;

t_character			*init_character();
t_char				*new_char(char *, char *, int, int);

#endif /* !CHARACTER_H_ */

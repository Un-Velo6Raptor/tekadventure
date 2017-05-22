/*
** refresh.h for tekadventure in /home/heychsea/MUL/tekadventure/refresh
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon May 22 14:34:35 2017 Hugo Cousin
** Last update Mon May 22 15:26:56 2017 Hugo Cousin
*/

#ifndef REFRESH_H_
# define REFRESH_H_

# include	<SFML/Graphics.h>

typedef struct	s_refresh
{
  sfSprite	*sprite;
  sfIntRect	rect;
  int		step;
  int		mode;
}		t_refresh;

# define SPRITE_W 64
# define SPRITE_H 64

#endif /* ! REFRESH_H_ */

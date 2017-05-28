/*
** refresh.h for tekadventure in /home/heychsea/MUL/tekadventure/refresh
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon May 22 14:34:35 2017 Hugo Cousin
** Last update Sun May 28 21:33:05 2017 Hugo Cousin
*/

#ifndef REFRESH_H_
# define REFRESH_H_

# include	<SFML/Graphics.h>

# ifndef SPRIE_W
#  define SPRITE_W 64
# endif /* ! SPRITE_W */

# ifndef SPRITE_H
#  define SPRITE_H 64
# endif /* ! SPRITE_H */

#define UP 8
#define DOWN 10
#define LEFT 9
#define RIGHT 11

typedef struct	s_refresh
{
  sfSprite	*sprite;
  sfIntRect	rect;
  float		step;
  int		mode;
}		t_refresh;

void	refresh_sprite(sfSprite *, sfVector2f, int, int);
void	player_refresh(sfSprite *, sfVector2f, sfVector2i, sfVector2i);

#endif /* ! REFRESH_H_ */

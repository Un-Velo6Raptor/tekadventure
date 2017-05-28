/*
** refresh.h for tekadventure in /home/heychsea/MUL/tekadventure/refresh
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon May 22 14:34:35 2017 Hugo Cousin
** Last update Sun May 28 15:22:48 2017 Martin Januario
*/

#ifndef REFRESH_H_
# define REFRESH_H_

# include	<SFML/Graphics.h>

typedef struct	s_refresh
{
  sfSprite	*sprite;
  sfIntRect	rect;
  float		step;
  int		mode;
}		t_refresh;

# define SPRITE_W 64
# define SPRITE_H 64

#define UP 8
#define DOWN 10
#define LEFT 9
#define RIGHT 11

void	refresh_sprite(sfSprite *, sfVector2f, int, int);
void	player_refresh(sfSprite *, sfVector2f, sfVector2i, sfVector2i);

#endif /* ! REFRESH_H_ */

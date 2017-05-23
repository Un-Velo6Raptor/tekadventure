/*
** moves.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 16:40:42 2017 Hugo Cousin
** Last update Tue May 23 17:12:47 2017 Hugo Cousin
*/

#include	<math.h>
#include	<SFML/Graphics.h>
#include	"lib.h"

static int		check_color(t_map *map, sfVector2i pos)
{
  sfColor		color;
  static sfColor	white = {255, 255, 255, 255};

  if (pos.x < 0 || pos.x >= map->size.x || pos.y < 0 || pos.y >= map->size.y)
    return (0);
  color = sfImage_getPixel(map->map, pos.x, pos.y);
  if (color != white)
    return (0);
  return (1);
}

int		check_path(t_map *map, sfVector2i from,
			   sfVector2i to)
{
  sfVector2i	delta;
  sfVector2i	err;

  delta.y = abs(to.y - from.y);
  delta.x =  abs(to.x - from.x);
  err.x = (delta.x > delta.y ? delta.x : -delta.y) / 2;
  while (1)
    {
      if (!check_color(map, base, from))
	return (0);
      if (from.x == to.x && from.y == to.y)
        return (1);
      err.y = err.x;
      if (err.y > -delta.x)
        {
          err.x -= delta.y;
          from.x += (from.x < to.x) ? 1 : -1;
        
      if (err.y < delta.y)
        {
          err.x += delta.x;
          from.y += (from.y < to.y) ? 1 : -1;
        }
    }
}

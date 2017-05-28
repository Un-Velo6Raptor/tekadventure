/*
** moves.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 16:40:42 2017 Hugo Cousin
** Last update Sun May 28 16:22:25 2017 Hugo Cousin
*/

#include	<math.h>
#include	"lib.h"
#include	"game.h"
#include	"refresh.h"

static int		check_color(t_map *map, sfVector2i pos)
{
  sfColor		color;

  if (pos.x < 0 || pos.x >= (int) map->size.x ||
      pos.y < 0 || pos.y >= (int) map->size.y)
    return (0);
  color = sfImage_getPixel(map->image, pos.x, pos.y);
  if (color.r == color.g && color.g == color.b && color.r < 255)
    return (0);
  return (1);
}

int			check_path(t_map *map, sfVector2i from,
				   sfVector2i to)
{
  sfVector2i	delta;
  sfVector2i	err;

  delta.y = abs(to.y - from.y);
  delta.x = abs(to.x - from.x);
  err.x = (delta.x > delta.y ? delta.x : -delta.y) / 2;
  while (1)
    {
      if (!check_color(map, from))
	return (0);
      if (from.x == to.x && from.y == to.y)
        return (1);
      err.y = err.x;
      if (err.y > -delta.x)
        {
          err.x -= delta.y;
          from.x += (from.x < to.x) ? 1 : -1;
	}
      if (err.y < delta.y)
	{
	  err.x += delta.x;
	  from.y += (from.y < to.y) ? 1 : -1;
	}
    }
  return (1);
}

void			update_rect(sfSprite *sprite, sfVector2i pos)
{
  sfIntRect		rect;

  rect = sfSprite_getTextureRect(sprite);
  rect.top = pos.y;
  rect.left = pos.x;
  sfSprite_setTextureRect(sprite, rect);
}

sfVector2i		move_map(sfSprite *sprite, sfVector2i from,
				 sfVector2i to, int reset)
{
  sfVector2i		delta;
  static sfVector2i	err;

  delta.y = abs(to.y - from.y);
  delta.x = abs(to.x - from.x);
  if (reset)
    {
      err.x = (delta.x > delta.y ? delta.x : -delta.y) / 2;
      return (from);
    }
  err.y = err.x;
  if (err.y > -delta.x)
    {
      err.x -= delta.y;
      from.x += (from.x < to.x) ? 1 : -1;
    }
  if (err.y < delta.y)
    {
      err.x += delta.x;
      from.y += (from.y < to.y) ? 1 : -1;
    }
  update_rect(sprite, from);
  return (from);
}

void			player_refresh(sfSprite *sprite, sfVector2f pos,
				       sfVector2i from, sfVector2i to)

{
  sfVector2i		delta;

  delta.y = to.y - from.y;
  delta.x = to.x - from.x;
  if (abs(delta.x) > abs(delta.y) && delta.x > 0)
    refresh_sprite(sprite, pos, RIGHT, 9);
  else if (abs(delta.x) > abs(delta.y) && delta.x < 0)
    refresh_sprite(sprite, pos, LEFT, 9);
  else if (abs(delta.x) < abs(delta.y) && delta.y > 0)
    refresh_sprite(sprite, pos, DOWN, 9);
  else if (abs(delta.x) < abs(delta.y) && delta.y < 0)
    refresh_sprite(sprite, pos, UP, 9);
  else
    refresh_sprite(sprite, pos, 2, 0);
}

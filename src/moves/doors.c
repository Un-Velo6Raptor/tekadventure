/*
** doors.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 17:54:15 2017 Hugo Cousin
** Last update Sun May 28 08:22:40 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"display.h"
#include	"lib.h"
#include	"anim.h"
#include	"game.h"
#include	"refresh.h"

int			choose_room(t_needs *needs, sfColor color, int *check)
{
  size_t		index;

  index = 1;
  while (needs->map[index])
    {
      if (index == (size_t)color.b)
	{
	  //launch_anim(needs->window, "ressources/tuto/", 1);
	  needs->current_map = index;
	  room_main(needs, check);
	  return (1);
	}
      index++;
    }
  return (0);
}

static int		diff_color(sfColor a, sfColor b)
{
  if (a.r != b.r || a.g != b.g || a.b != b.b)
    return (0);
  return (1);
}

sfVector2i		check_room(t_needs *needs,
				   sfVector2i last, sfVector2i to, int *check)
{
  sfColor		color;
  static sfColor	save = {255, 255, 255, 255};

  if (needs->pos.x < 0 || needs->pos.y < 0 ||
      needs->pos.x >= (int)needs->map[needs->current_map]->size.x ||
      needs->pos.y >= (int)needs->map[needs->current_map]->size.y)
    return (to);
  color = sfImage_getPixel(needs->map[needs->current_map]->image,
			   needs->pos.x, needs->pos.y);
  if (color.r == 255 && color.g == 0 && !diff_color(save, color))
    {
      choose_room(needs, color, check);
      to.x = last.x;
      to.y = last.y;
    }
  if (!diff_color(save, color))
    save = color;
  return (to);
}

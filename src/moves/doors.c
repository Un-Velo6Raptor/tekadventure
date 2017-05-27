/*
** doors.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 17:54:15 2017 Hugo Cousin
** Last update Fri May 26 21:55:01 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"display.h"
#include	"lib.h"
#include	"anim.h"

int			choose_room(t_needs *needs, sfColor color)
{
  size_t		index;

  index = 0;
  while (needs->map[index])
    {
      if (1)//index == (size_t)color.b)
	{
	  //launch_anim(needs->window, "ressources/tuto/", 1);
	  needs->current_map = 1;
	  room_main(needs);
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

int			check_room(t_needs *needs)
{
  sfColor		color;
  int			ret;
  static sfColor	save = {255, 255, 255, 255};

  if (needs->pos.x < 0 || needs->pos.y < 0 ||
      needs->pos.x >= (int)needs->map[needs->current_map]->size.x ||
      needs->pos.y >= (int)needs->map[needs->current_map]->size.y)
    return (0);
  color = sfImage_getPixel(needs->map[needs->current_map]->image,
			   needs->pos.x, needs->pos.y);
  ret = 0;
  if (color.r == 119 && color.g == 119 && !diff_color(save, color))
    ret = choose_room(needs, color);
  if (!diff_color(save, color))
    save = color;
  return (ret);
}

/*
** loop_game.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Tue May 23 17:18:19 2017 Martin Januario
** Last update Sun May 28 21:56:03 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"
#include	"refresh.h"
#include	"anim.h"

sfVector2i		check_move_map(sfVector2i to, t_needs *needs,
				       sfVector2i from,
				       sfVector2i last)
{
  sfIntRect		rect;

  rect = sfSprite_getTextureRect(needs->map[needs->current_map]->map);
  to.x += rect.left;
  to.y += rect.top;
  if (check_path(needs->map[needs->current_map], from, to) != 0)
      return (to);
  return (last);
}

sfVector2i		get_map_move(sfSprite *map, sfVector2i from,
				     sfVector2i to,
				     sfSprite *player)
{
  sfIntRect		rect;
  sfVector2i		tmp;

  rect = sfSprite_getTextureRect(map);
  tmp.x = to.x - from.x + rect.left;
  tmp.y = to.y - from.y + rect.top;
  from = vector_2i(rect.left, rect.top);
  if (from.x != tmp.x || from.y != tmp.y)
    from = move_map(map, from, tmp, 0);
  else
    {
      player_refresh(player, vector_2f(450, 450), from, tmp);
      move_map(map, from, tmp, 1);
    }
  from.x += WIDTH / 2;
  from.y += HEIGHT / 2;
  return (from);
}

int                     loop_game(t_needs *needs)
{
  sfVector2i		to;
  sfEvent               event;
  int			check;

  while (count_dead_player(needs) != 4 && sfRenderWindow_isOpen(needs->window)
	 && needs->current_veleda)
    {
      if (first_part(needs, &check, &to) == 84)
	return (84);
      while (check == 0 && sfRenderWindow_isOpen(needs->window)
	     && needs->current_veleda)
	{
	  player_refresh(needs->player[needs->current_player]->sprite,
			 vector_2f(450, 450), needs->pos, to);
	  sfRenderWindow_clear(needs->window, sfBlack);
	  while (sfRenderWindow_pollEvent(needs->window, &event))
	    get_mouse_pos(needs, &to, &event);
	  draw_game(needs, &to, &check);
	}
    }
  return (0);
}

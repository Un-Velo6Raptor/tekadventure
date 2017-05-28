/*
** first_part.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 21:49:41 2017 Martin Januario
** Last update Sun May 28 21:51:52 2017 Martin Januario
*/

#include	"game.h"
#include	"display.h"

int		first_part(t_needs *needs, int *check,
			   sfVector2i *to)
{
  *check = 0;
  music_pause(needs->map[0]->theme, needs);
  if (start_select(needs) == 84)
    return (84);
  music_start(needs->map[0]->theme, needs);
  needs->pos = vector_2i(387, 1038);
  *to = vector_2i(387, 1038);
  update_rect(needs->map[needs->current_map]->map,
	      vector_2i(needs->pos.x - WIDTH / 2,
			needs->pos.y - HEIGHT / 2));
  return (0);
}

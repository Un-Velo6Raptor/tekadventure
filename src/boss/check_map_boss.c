/*
** check_map_boss.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat May 27 22:50:48 2017 Martin Januario
** Last update Sun May 28 14:04:55 2017 Martin Januario
*/

#include	<stdio.h>
#include	"display.h"
#include	"boss.h"
#include	"bar.h"

int		loop_boss(t_needs *needs, sfVector2i to)
{
  int		tmp;

  if (needs->mode->sound == 0)
    sfMusic_play(needs->boss[needs->map[needs->current_map]->boss]->music);
  tmp = bar_create(needs, needs->mode->difficult, to, 0);
  if (needs->mode->sound == 0)
    sfMusic_stop(needs->boss[needs->map[needs->current_map]->boss]->music);
  if (tmp != 1)
    {
      needs->player[needs->current_player]->death = 1;
      return (1);
    }
  needs->boss[needs->map[needs->current_map]->boss]->death = 1;
  return (0);
}

int		check_map_boss(t_needs *needs, sfVector2i to)
{
  if (needs->map[needs->current_map]->boss >= 1 &&
      needs->boss[needs->map[needs->current_map]->boss]->death != 1)
    return (loop_boss(needs, to));
  return (0);
}

/*
** music_pause.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat May 20 21:19:54 2017 Martin Januario
** Last update Sat May 20 21:44:20 2017 Martin Januario
*/

#include	"menu.h"

void		stop_music_except_one(t_core *needs, int opt)
{
  int		idx;

  idx = 0;
  while (needs->music[idx] != NULL)
    {
      if (idx != THEME_MENU && idx != opt)
	sfMusic_stop(needs->music[idx]);
      idx++;
    }
  if (opt != -1)
    sfMusic_play(needs->music[opt]);
}

/*
** music_or_not.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat May 20 20:59:12 2017 Martin Januario
** Last update Sat May 20 21:03:49 2017 Martin Januario
*/

#include	"menu.h"

void		music_play_menu(t_mode_game *mode, t_core *needs)
{
  if (mode->sound == 0)
    return ;
  mode->sound = 0;
  sfMusic_play(needs->music[THEME_MENU]);
}

void		music_stop_menu(t_mode_game *mode, t_core *needs)
{
  int		idx;

  idx = 0;
  if (mode->sound == 1)
    return ;
  mode->sound = 1;
  while (needs->music[idx] != NULL)
    {
      sfMusic_pause(needs->music[idx]);
      idx++;
    }
}

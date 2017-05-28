/*
** mike.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Sun May 28 20:44:45 2017 Hugo Cousin
** Last update Sun May 28 20:46:14 2017 Hugo Cousin
*/

#include	<stdio.h>
#include	"boss.h"
#include	"display.h"
#include	"anim.h"
#include	"bar.h"

static int	mike_loop(t_needs *needs)
{
  int		idx;
  int		save;
  int		cpt;

  cpt = 0;
  idx = 0;
  save = -1;
  while (sfRenderWindow_isOpen(needs->window) && idx != 10)
    {
      if (cpt % 100000 == 0)
	{
	  save = idx;
	  idx += bar_create(needs, count_dead_player(needs),
			    vector_2i(0, 0), 1);
	}
      if (idx == save)
	{
	  launch_anim(needs->window, "ressources/defeat/",
		      needs->mode->sound, 1);
	  return (0);
	}
      cpt++;
    }
  return (1);
}

void		fight_mike(t_needs *needs)
{
  if (needs->mode->sound == 0)
    {
      sfMusic_play(needs->boss[0]->music);
      sfMusic_setLoop(needs->boss[0]->music, sfTrue);
    }
  if (!mike_loop(needs))
    return ;
  if (needs->mode->sound == 0)
    sfMusic_stop(needs->boss[0]->music);
  launch_anim(needs->window, "ressources/victory/", needs->mode->sound, 1);
}

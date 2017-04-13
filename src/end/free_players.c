/*
** free_players.c for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Apr 13 15:03:36 2017 Hugo Cousin
** Last update Thu Apr 13 15:22:37 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "lib.h"
#include "struct.h"

void		free_players(t_player *players)
{
  size_t	i;

  i = 0;
  while (players && i < 4)
    {
      tabfree(players[i].sentences);
      free(players[i].name);
      i++;
    }
  free(players);
}

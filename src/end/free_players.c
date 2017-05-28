/*
** free_players.c for tekadventure in /home/heychsea/MUL/ceciesttemporaire
**
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
**
** Started on  Thu Apr 13 15:03:36 2017 Hugo Cousin
** Last update Sun May 28 19:32:23 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "lib.h"
#include "struct.h"

void		free_players(t_player *players)
{
  size_t	i;
  size_t	j;

  i = 0;
  while (players && i < 4)
    {
      j = 0;
      while (players[i].text[j].sentence)
	free(players[i].text[j++].sentence);
      free(players[i].text);
      free(players[i].name);
      i++;
    }
  free(players);
}

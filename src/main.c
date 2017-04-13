/*
** main.c for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Apr 12 14:18:02 2017 Hugo Cousin
** Last update Thu Apr 13 15:22:17 2017 Hugo Cousin
*/

#include "funcs.h"

int		main(void)
{
  t_player	*players;

  players = get_sentences();
  free_players(players);
  return (0);
}

/*
** boss.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:40:34 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 19:29:33 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	<SFML/Graphics.h>
#include	"boss.h"
#include	"player.h"
#include	"funcs.h"
#include	"character.h"

t_char		**init_boss(char **path, char **name)
{
  t_char	**boss;
  t_player	*sentences;

  sentences = get_sentences(path[0], NB_BOSS + NB_PLAYER);
  boss = malloc(sizeof(t_char) * NB_BOSS);
  if (!boss)
    return (NULL);
  boss[MIKE] = new_player(path, "mike", sentences, name[MIKE]);
  boss[MALEX] = new_player(path, "malex", sentences, name[MALEX]);
  boss[CHLOE] = new_player(path, "chloe", sentences, name[CHLOE]);
  boss[REMI] = new_player(path, "remi", sentences, name[REMI]);
  boss[ARTHUR] = new_player(path, "arthur", sentences, name[ARTHUR]);
  if (!boss[MIKE] || !boss[MALEX] || !boss[CHLOE] ||
      !boss[REMI] || !boss[ARTHUR])
    return (NULL);
  return (boss);
}

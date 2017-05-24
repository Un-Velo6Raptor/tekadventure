/*
** player.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:40:34 2017 Sahel Lucas--Saoudi
** Last update Wed May 24 16:47:37 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "player.h"

t_char		**init_player()
{
  t_char	**player;

  player = malloc(sizeof(t_char) * NB_PLAYER);
  if (!player)
    return (NULL);
  player[MARTIN] = new_char(MARTIN_FILE, MARTIN_NAME, MARTIN_POS_X, MARTIN_POS_Y);
  player[CHARLOTTE] = new_char(CHARLOTTE_FILE, CHARLOTTE_NAME, CHARLOTTE_POS_X, CHARLOTTE_POS_Y);
  player[HUGO] = new_char(HUGO_FILE, HUGO_NAME, HUGO_POS_X, HUGO_POS_Y);
  player[SAHEL] = new_char(SAHEL_FILE, SAHEL_NAME, SAHEL_POS_X, SAHEL_POS_Y);
  if (!player[MARTIN] || !player[CHARLOTTE] || !player[HUGO] || !player[SAHEL])
    return (NULL);
  return (player);
}

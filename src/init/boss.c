/*
** boss.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:40:34 2017 Sahel Lucas--Saoudi
** Last update Fri May 26 14:55:08 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "boss.h"

t_char		**init_boss()
{
  t_char	**boss;

  boss = malloc(sizeof(t_char) * NB_BOSS);
  if (!boss)
    return (NULL);
  /*  boss[MIKE] = new_char(MIKE_FILE, MIKE_NAME, MIKE_POS_X, MIKE_POS_Y);
  boss[MALEX] = new_char(MALEX_FILE, MALEX_NAME, MALEX_POS_X, MALEX_POS_Y);
  boss[CHLOE] = new_char(CHLOE_FILE, CHLOE_NAME, CHLOE_POS_X, CHLOE_POS_Y);
  boss[REMI] = new_char(REMI_FILE, REMI_NAME, REMI_POS_X, REMI_POS_Y);
  if (!boss[MIKE] || !boss[MALEX] || !boss[CHLOE] || !boss[REMI])*/
    return (NULL);
  return (boss);
}

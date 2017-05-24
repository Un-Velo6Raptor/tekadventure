/*
** character.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:08:44 2017 Sahel Lucas--Saoudi
** Last update Wed May 24 16:58:14 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "character.h"
#include "boss.h"
#include "player.h"

t_char  *new_char(char *path, char *name, int x, int y)
{
  t_char        *boss;
  sfTexture     *texture;

  boss = malloc(sizeof(t_char));
  if (!boss)
    return (NULL);
  boss->pos.x = x;
  boss->pos.y = y;
  boss->name = strdup(name);
  texture = sfTexture_createFromFile(path, NULL);
  if (!texture || !boss->name)
    return (NULL);
  boss->sprite = sfSprite_create();
  sfSprite_setTexture(boss->sprite, texture, sfTrue);
  if (!boss->sprite)
    return (NULL);
  return (boss);
}

t_character	*init_character()
{
  t_character	*character;

  character = malloc(sizeof(t_character));
  if (!character)
    return (NULL);
  character->boss = init_boss();
  if (!character->boss)
    return (NULL);
  character->player = init_player();
  if (!character->player)
    return (NULL);
  return (character);
}

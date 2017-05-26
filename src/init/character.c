/*
** character.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:08:44 2017 Sahel Lucas--Saoudi
** Last update Fri May 26 16:13:47 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "character.h"
#include "boss.h"
#include "player.h"

t_char  *new_char(char *path, char *name, sfVector2i pos, t_text *text)
{
  t_char        *character;
  sfTexture     *texture;

  character = malloc(sizeof(t_char));
  if (!character || !text)
    return (NULL);
  puts("sdfsdf");
  character->pos = pos;
  character->name = strdup(name);
  texture = sfTexture_createFromFile(path, NULL);
  if (!texture || !character->name)
    return (NULL);
  puts("sdfsdfsdf");
  character->sprite = sfSprite_create();
  sfSprite_setTexture(character->sprite, texture, sfTrue);
  if (!character->sprite)
    return (NULL);
  puts("qsqsdlih");
  character->phrase = text;
  character->death = ALIVE;
  return (character);
}

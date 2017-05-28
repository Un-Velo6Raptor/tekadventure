/*
** character.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:08:44 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 19:28:43 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"character.h"
#include	"boss.h"
#include	"player.h"
#include	"display.h"
#include	"lib.h"

t_char		*new_char(char *path, char *name, sfVector2f pos, t_text *text)
{
  t_char        *character;
  sfTexture     *texture;

  character = malloc(sizeof(t_char));
  if (!character || !text)
    return (NULL);
  character->pos = pos;
  character->name = my_strdup(name);
  texture = sfTexture_createFromFile(path, NULL);
  if (!texture || !character->name)
    return (NULL);
  character->sprite = sfSprite_create();
  sfSprite_setTexture(character->sprite, texture, sfTrue);
  if (!character->sprite)
    return (NULL);
  sfSprite_setOrigin(character->sprite, vector_2f(32, 64));
  character->phrase = text;
  character->death = ALIVE;
  return (character);
}

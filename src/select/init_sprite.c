/*
** init_sprite.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sat May 27 21:53:04 2017 Sahel Lucas--Saoudi
** Last update Sat May 27 21:54:22 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "select.h"
#include "lib.h"

sfSprite		*create_sprite(char *path)
{
  sfTexture             *texture;
  sfSprite              *tmp;

  tmp = sfSprite_create();
  if (tmp == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfSprite_setTexture(tmp, texture, sfTrue);
  return (tmp);
}

sfSprite	**set_sprite(t_needs *needs)
{
  sfSprite      **sprite;

  sprite = malloc(sizeof(sfSprite *) * 8);
  if (!sprite)
    return (NULL);
  sprite[0] = create_sprite("ressources/character/plage.jpg");
  sprite[1] = needs->player[2]->select;
  sprite[2] = needs->player[1]->select;
  sprite[3] = needs->player[0]->select;
  sprite[4] = needs->player[3]->select;
  sprite[5] = create_sprite("ressources/character/select_title.png");
  sprite[6] = create_sprite("ressources/character/confirm.png");
  sprite[7] = NULL;
  return (sprite);
}

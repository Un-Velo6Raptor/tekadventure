/*
** free_needs.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sun May 28 22:07:38 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 22:36:23 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "lib.h"
#include "game.h"
#include "select.h"
#include "anim.h"
#include "character.h"
#include "boss.h"
#include "player.h"

void	free_map(t_map *map)
{
  free(map->name);
  sfSprite_destroy(map->map);
  sfImage_destroy(map->image);
  sfMusic_destroy(map->theme);
  free(map);
}

void	free_text(t_text *text)
{
  free(text->sentence);
  free(text);
}

void	free_char(t_char *character)
{
  free(character->name);
  sfSprite_destroy(character->sprite);
  sfSprite_destroy(character->select);
  sfMusic_destroy(character->music);
  free_text(character->phrase);
  free(character);
}

void	free_needs(t_needs *needs)
{
  int	i;

  i = 0;
  while (needs->map[i])
    {
      free_map(needs->map[i]);
      i++;
    }
  free(needs->map);
  i = 0;
  while (i < NB_PLAYER)
    free_char(needs->player[i++]);
  i = 0;
  while (i < NB_BOSS)
    free_char(needs->boss[i++]);
  free(needs->player);
  free(needs->boss);
  sfSprite_destroy(needs->veleda_sprite);
  sfText_destroy(needs->texte);
  sfText_destroy(needs->nb_veleda);
  free(needs);
}

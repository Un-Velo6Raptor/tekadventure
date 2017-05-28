/*
** player.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:40:34 2017 Sahel Lucas--Saoudi
** Last update Sat May 27 22:14:24 2017 Lucas Sahel
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "player.h"
#include "boss.h"
#include "lib.h"
#include "funcs.h"
#include "display.h"

t_text		*get_player_text(t_player *sentences, char *name)
{
  int		i;

  i = 0;
  while (i < NB_PLAYER)
    {
      if (match(sentences[i].name, name))
	return (sentences[i].text);
      i++;
    }
  return (NULL);
}

int		set_music_and_select(t_char *player, char *music, char *select)
{
  char		*new_path;
  sfTexture	*texture;

  if (!player)
    return (1);
  new_path = concat(3, music, player->name, ".ogg");
  player->music = sfMusic_createFromFile(new_path);
  free(new_path);
  new_path = concat(3, select, player->name, "_select.png");
  texture = sfTexture_createFromFile(new_path, NULL);
  free(new_path);
  if (!texture || !player->music)
    return (1);
  player->select = sfSprite_create();
  sfSprite_setTexture(player->select, texture, sfTrue);
  if (!player->select)
    return (1);
  return (0);
}

t_char		*new_player(char **path, char *name,
			    t_player *sentences, char *real_name)
{
  t_char	*new;
  char		*new_path;
  sfVector2f	pos;

  pos.x = 0;
  pos.y = 0;
  new_path = concat(3, path[3], name, "_tek_ad.png");
  if (!new_path)
    return (NULL);
  new = new_char(new_path, real_name, pos,
			get_player_text(sentences, name));
  if (set_music_and_select(new, path[1], path[2]))
    return (NULL);
  free(new_path);
  return (new);
}

t_char		**init_player(char **path, char **name)
{
  t_char	**player;
  t_player	*sentences;

  sentences = get_sentences(path[0], NB_PLAYER + NB_BOSS);
  if (!sentences)
    return (NULL);
  player = malloc(sizeof(t_char) * (NB_PLAYER));
  if (!player)
    return (NULL);
  player[MARTIN] = new_player(path, "martin", sentences, name[MARTIN]);
  player[CHARLOTTE] = new_player(path, "romain", sentences, name[CHARLOTTE]);
  player[HUGO] = new_player(path, "hugo", sentences, name[HUGO]);
  player[SAHEL] = new_player(path, "sahel", sentences, name[SAHEL]);
  free(sentences);
  if (!player[MARTIN] || !player[CHARLOTTE] || !player[HUGO] || !player[SAHEL])
    return (NULL);
  return (player);
}

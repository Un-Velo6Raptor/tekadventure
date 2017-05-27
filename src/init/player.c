/*
** player.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:40:34 2017 Sahel Lucas--Saoudi
** Last update Fri May 26 22:16:06 2017 Hugo Cousin
*/

#include <stdlib.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include "player.h"
#include "lib.h"
#include "funcs.h"
#include "display.h"

char		*concat(int nb_str, ...)
{
  va_list	ap;
  char		*str;
  int		size;
  int		idx;

  size = 0;
  va_start(ap, nb_str);
  idx = 0;
  while (idx < nb_str)
    {
      size += my_strlen(va_arg(ap, char *));
      idx++;
    }
  va_end(ap);
  str = malloc(sizeof(char) * (size + 1));
  if (!str)
    return (NULL);
  va_start(ap, nb_str);
  my_strcpy(str, va_arg(ap, char *));
  idx = 0;
  while (idx < nb_str - 1)
    {
      my_strcat(str, va_arg(ap, char *));
      idx++;
    }
  va_end(ap);
  return (str);
}

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

t_char		**init_player(char **path, char **name)
{
  t_char	**player;
  sfVector2f	pos;
  char		*new_path;
  t_player	*sentences;

  sentences = get_sentences(path[0], NB_PLAYER);
  if (!sentences)
    return (NULL);
  pos.x = 0;
  pos.y = 0;
  new_path = NULL;
  player = malloc(sizeof(t_char) * (NB_PLAYER));
  if (!player)
    return (NULL);
  new_path = concat(2, path[3], "martin_tek_ad.png");
  player[MARTIN] = new_char(new_path, name[MARTIN], pos, get_player_text(sentences, "martin"));
  if (set_music_and_select(player[MARTIN], path[1], path[2]))
    return (NULL);
  new_path = concat(2, path[3], "romain_tek_ad.png");
  player[CHARLOTTE] = new_char(new_path, name[CHARLOTTE], pos, get_player_text(sentences, "romain"));
  if (set_music_and_select(player[CHARLOTTE], path[1], path[2]))
    return (NULL);
  new_path = concat(2, path[3], "hugo_tek_ad.png");
  player[HUGO] = new_char(new_path, name[HUGO], pos, get_player_text(sentences, "hugo"));
  if (set_music_and_select(player[HUGO], path[1], path[2]))
    return (NULL);
  new_path = concat(2, path[3], "sahel_tek_ad.png");
  player[SAHEL] = new_char(new_path, name[SAHEL], pos, get_player_text(sentences, "sahel"));
  if (set_music_and_select(player[SAHEL], path[1], path[2]))
    return (NULL);
  free(sentences);
  if (!player[MARTIN] || !player[CHARLOTTE] || !player[HUGO] || !player[SAHEL])
    return (NULL);
  return (player);
}

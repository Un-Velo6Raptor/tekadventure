/*
** map.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 26 11:52:16 2017 Martin Januario
** Last update Sun May 28 10:37:32 2017 Martin Januario
*/

#include	"map.h"
#include	"lib.h"
#include	"funcs.h"

static int	ini_sprite_map(t_map *map, char *path, char *name)
{
  sfTexture	*texture;
  char		*tmp;

  tmp = concat(3, path, name, "_map.png");
  if (!tmp)
    return (84);
  map->map = sfSprite_create();
  texture = sfTexture_createFromFile(tmp, NULL);
  if (map->map == NULL || texture == NULL)
    return (84);
  sfSprite_setTexture(map->map, texture, sfTrue);
  return (0);
}

static int	ini_image_map(t_map *map, char *path, char *name)
{
  char		*tmp;

  tmp = concat(3, path, name, "_back.png");
  if (!tmp)
    return (84);
  map->image = sfImage_createFromFile(tmp);
  if (map->map == NULL)
    return (84);
  return (0);
}

static int	ini_music_map(t_map *map, char *path, char *name)
{
  char		*tmp;

  tmp = concat(3, path, name, "_map.ogg");
  if (!tmp)
    return (84);
  map->theme = sfMusic_createFromFile(tmp);
  if (map->theme == NULL)
    return (84);
  return (0);
}

static t_map	*ini_map(char *path, char *name, int boss)
{
  t_map		*map;

  map = malloc(sizeof(t_map));
  if (map == NULL)
    return (NULL);
  map->name = my_strdup(name);
  if (map->name == NULL)
    return (NULL);
  if (ini_sprite_map(map, path, name) == 84)
    return (NULL);
  if (ini_image_map(map, path, name) == 84)
    return (NULL);
  map->pos_map = vector_2i(0, 0);
  map->veleda = (my_strcmp(name, "byron") != 0) ? 1 : 0;
  map->boss = boss;
  map->size = sfImage_getSize(map->image);
  if (ini_music_map(map, path, name) == 84)
    return (NULL);
  return (map);
}

t_map		**ini_all_map(char *path)
{
  t_map		**map;
  int		idx;

  idx = 0;
  map = malloc(sizeof(t_map *) * 7);
  if (map == NULL)
    return (NULL);
  map[0] = ini_map(path, "couloir", 0);
  map[1] = ini_map(path, "turing", 1);
  map[2] = ini_map(path, "pascal", 0);
  map[3] = ini_map(path, "babbage", 2);
  map[4] = ini_map(path, "byron", 4);
  map[5] = ini_map(path, "cray", 3);
  map[6] = NULL;
  while (map[idx] != NULL)
    idx++;
  if (idx != 6)
    return (NULL);
  return (map);
}

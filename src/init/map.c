/*
** map.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 26 11:52:16 2017 Martin Januario
** Last update Fri May 26 17:03:15 2017 Martin Januario
*/

#include	"map.h"
#include	"lib.h"

static int	ini_sprite_map(t_map *map, char *path, char *name)
{
  sfTexture	*texture;
  char		*tmp;

  if ((tmp = my_allocat(path, name, 0)) == NULL)
    return (84);
  if ((tmp = my_allocat(tmp, "_map.png", 0)) == NULL)
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

  if ((tmp = my_allocat(path, name, 0)) == NULL)
    return (84);
  if ((tmp = my_allocat(tmp, "_map.png", 0)) == NULL)
    return (84);
  map->image = sfImage_createFromFile(tmp);
  if (map->map == NULL)
    return (84);
  return (0);
}

static int	ini_music_map(t_map *map, char *path, char *name)
{
  char		*tmp;

  if ((tmp = my_allocat(path, name, 0)) == NULL)
    return (84);
  if ((tmp = my_allocat(tmp, "_map.ogg", 0)) == NULL)
    return (84);
  map->theme = sfMusic_createFromFile(tmp);
  if (map->theme == NULL)
    return (84);
  return (0);
}

static t_map	*ini_map(char *path, char *name)
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
  map->boss = (my_strcmp(name, "pascal") != 0) ? 1 : 0;
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
  map = malloc(sizeof(t_map *) * 6);
  if (map == NULL)
    return (NULL);
  map[0] = ini_map(path, "turing");
  map[1] = ini_map(path, "pascal");
  map[2] = ini_map(path, "babbage");
  map[3] = ini_map(path, "cray");
  map[4] = ini_map(path, "byron");
  map[5] = NULL;
  while (map[idx] != NULL)
    idx++;
  if (idx != 5)
    return (NULL);
  return (map);
}

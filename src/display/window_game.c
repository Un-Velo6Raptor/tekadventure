/*
** window_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:13:45 2017 Martin Januario
** Last update Tue May 23 18:00:35 2017 Martin Januario
*/

#include	"lib.h"
#include	"game.h"

static int	ini_map_game(t_needs *map)
{
  map->map.map = sfImage_createFromFile("ressources/map/map.png");
  if (map->map.map == NULL)
    return (84);
  map->map.size = sfImage_getSize(map->map.map);
  return (0);
}

int		window_game(t_mode_game *mode)
{
  t_needs	needs;

  needs.window = create_window("Game <-> Move Backward.", WIDTH, HEIGHT);
  if (needs.window == NULL)
    return (my_puterror("Can't create the window.\n"));
  sfRenderWindow_setFramerateLimit(needs.window, 30);
  needs.sprite = sfSprite_create();
  needs.texture = NULL;
  if (ini_map_game(&needs) == 84)
    return (84);
  return (loop_game(mode, &needs));
}

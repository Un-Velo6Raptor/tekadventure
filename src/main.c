/*
** main.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 19 15:27:55 2017 Martin Januario
** Last update Sun May 28 23:30:36 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"display.h"
#include	"lib.h"
#include	"character.h"
#include	"tuto.h"
#include	"map.h"
#include	"config.h"
#include	"player.h"
#include	"boss.h"
#include	"velleda.h"

static t_needs	*ini_needs(void)
{
  t_needs	*needs;
  char          **name;
  char          **boss;
  char          **path;

  name = c_dico(4, "Martin", "Romain", "Hugo", "Sahel");
  boss = c_dico(5, "Mike", "Malex", "Chloe", "Remi", "Arthur");
  path = c_dico(4, "ressources/sentences/", "ressources/music/",
		"ressources/select/", "ressources/player/");
  needs = malloc(sizeof(t_needs) * 1);
  if (needs == NULL)
    return (NULL);
  needs->player = init_player(path, name);
  needs->boss = init_boss(path, boss);
  if (!needs->player || !needs->boss)
    return (NULL);
  if (config(needs) == 84)
    return (NULL);
  if ((needs->map = ini_all_map(needs->dirs[MAP])) == NULL)
    return (NULL);
  if (init_velleda(needs) == 84)
    return (NULL);
  return (needs);
}

int		main(int __attribute__ ((unused)) argc,
		     char __attribute__ ((unused)) **argv, char **env)
{
  t_needs	*needs;
  t_mode_game	mode;

  if (check_env(env) == 1)
    return (my_puterror("Error in ENV.\n"));
  needs = ini_needs();
  if (needs == NULL)
    return (84);
  needs->mode = &mode;
  needs->current_player = 0;
  needs->current_map = 0;
  needs->pos = vector_2i(1560, 1152);
  needs->current_veleda = 4;
  if (window_menu(&mode) == 84)
    return (my_puterror("See you later !"));
  if (mode.play != 1)
    return (0);
  if (tuto(mode) == 84)
    return (my_puterror("Error\n"));
  return (window_game(needs));
}

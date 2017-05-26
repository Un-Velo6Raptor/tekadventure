/*
** main.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 19 15:27:55 2017 Martin Januario
** Last update Fri May 26 14:15:17 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"display.h"
#include	"lib.h"
#include	"character.h"
#include	"tuto.h"
#include	"map.h"
#include	"config.h"

static t_needs	*ini_needs(t_mode_game *mode)
{
  t_needs	*needs;

  needs = malloc(sizeof(t_needs) * 1);
  if (needs == NULL)
    return (NULL);
  if (config(needs) == 84)
    return (NULL);
  if ((needs->map = ini_all_map(needs->dirs[MAP])) == NULL)
    return (NULL);
  needs->mode = mode;
  return (needs);
}

int		main(int __attribute__ ((unused)) argc,
		     char __attribute__ ((unused)) **argv, char **env)
{
  t_needs	*needs;
  t_mode_game	mode;
  t_character	*character;

  needs = ini_needs(&mode);
  if (needs == NULL)
    return (84);
  character = init_character();
  if (!character)
    return (my_puterror("Error in Character.\n"));
  if (check_env(env) == 1)
    return (my_puterror("Error in ENV.\n"));
  if (window_menu(&mode) == 84)
    return (my_puterror("See you later !"));
  //  if (tuto(mode) == 84)
  //    return (my_puterror("Error\n"));
  //  if (mode.play == 1)
  //    return (window_game(&mode));
  return (0);
}

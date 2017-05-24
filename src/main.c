/*
** main.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 15:27:55 2017 Martin Januario
** Last update Tue May 23 19:35:56 2017 Martin Januario
*/

#include	"display.h"
#include	"lib.h"

int		main(int __attribute__ ((unused)) argc,
		     char __attribute__ ((unused)) **argv, char **env)
{
  t_mode_game	mode;

  if (check_env(env) == 1)
    return (my_puterror("Error in ENV.\n"));
  if (window_menu(&mode) == 84)
    return (my_puterror("See you later !"));
  if (mode.play == 1)
    return (window_game(&mode));
  return (0);
}

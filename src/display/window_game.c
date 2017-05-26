/*
** window_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:13:45 2017 Martin Januario
** Last update Fri May 26 17:06:43 2017 Martin Januario
*/

#include	"lib.h"
#include	"game.h"

int		window_game(t_needs *needs)
{
  needs->window = create_window("Game <-> Move Backward.", WIDTH, HEIGHT);
  if (needs->window == NULL)
    return (my_puterror("Can't create the window.\n"));
  sfRenderWindow_setFramerateLimit(needs->window, 60);
  return (loop_game(needs));
}

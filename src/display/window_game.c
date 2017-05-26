/*
** window_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:13:45 2017 Martin Januario
** Last update Fri May 26 22:07:31 2017 Martin Januario
*/

#include	"lib.h"
#include	"game.h"
#include	"select.h"

int		start_select(t_needs *needs)
{
  sfMusic	*music;

  music = NULL;
  if (needs->mode->sound == 0)
    {
      music = sfMusic_createFromFile("ressources/menu/theme.ogg");
      if (music != NULL)
	{
	  sfMusic_play(music);
	  sfMusic_setLoop(music, sfTrue);
	}
    }
  needs->current_player = select_player(needs);
  if (needs->current_player < 0)
    return (84);
  if (music != NULL)
    sfMusic_destroy(music);
  return (0);
}

int		window_game(t_needs *needs)
{
  needs->window = create_window("Game <-> Move Backward.", WIDTH, HEIGHT);
  if (needs->window == NULL)
    return (my_puterror("Can't create the window.\n"));
  sfRenderWindow_setFramerateLimit(needs->window, 60);
  if (start_select(needs) == 84)
    return (84);
  return (loop_game(needs));
}

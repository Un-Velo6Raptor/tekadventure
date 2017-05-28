/*
** window_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:13:45 2017 Martin Januario
** Last update Sun May 28 19:28:29 2017 Martin Januario
*/

#include	"lib.h"
#include	"game.h"
#include	"select.h"
#include	"anim.h"

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

int		count_dead_player(t_needs *needs)
{
  int		tmp;
  int		idx;

  idx = 0;
  tmp = 0;
  while (idx < 4)
    {
      tmp += needs->player[idx]->death;
      idx++;
    }
  return (tmp);
}

int		window_game(t_needs *needs)
{
  needs->window = create_window("Game <-> Move Backward.", WIDTH, HEIGHT);
  if (needs->window == NULL)
    return (my_puterror("Can't create the window.\n"));
  sfRenderWindow_setFramerateLimit(needs->window, 60);
  launch_anim(needs->window, "ressources/story/", needs->mode->sound, 2);
  if (needs->mode->sound == 0)
    {
      sfMusic_play(needs->map[0]->theme);
      sfMusic_setLoop(needs->map[0]->theme, sfTrue);
    }
  loop_game(needs);
  if (needs->mode->sound == 0)
    sfMusic_stop(needs->map[0]->theme);
  return (0);
}

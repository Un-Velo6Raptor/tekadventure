/*
** ini_music_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat May 20 20:07:46 2017 Martin Januario
** Last update Sat May 20 21:51:52 2017 Martin Januario
*/

#include	"menu.h"

static sfMusic	*music_create(char *path, int opt)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(path);
  if (!music)
    return (NULL);
  if (opt >= 1)
    sfMusic_play(music);
  if (opt >= 2)
    sfMusic_setLoop(music, sfTrue);
  return (music);
}

static int	check_music_menu(t_core *needs)
{
  int		idx;

  idx = 0;
  while (needs->music[idx] != NULL)
    idx++;
  if (idx != MAX_SONG_MENU)
    return (84);
  return (0);
}

int		ini_music_menu(t_core *needs)
{
  needs->music[THEME_MENU] = music_create("library/menu/theme.ogg", 2);
  needs->music[JOKE_MENU] = music_create("library/menu/diabolic_joke.ogg", 0);
  needs->music[EASY_MENU] = music_create("library/menu/easy.ogg", 0);
  needs->music[HARD_MENU] = music_create("library/menu/hard.ogg", 0);
  needs->music[NORMAL_MENU] = music_create("library/menu/normal.ogg", 0);
  needs->music[MAX_SONG_MENU] = NULL;
  return (check_music_menu(needs));
}

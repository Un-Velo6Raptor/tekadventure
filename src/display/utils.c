/*
** utils.c for tekadventure in /home/heychsea/MUL/tekadventure/anim
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu May 25 16:19:39 2017 Hugo Cousin
** Last update Thu May 25 17:43:47 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	<limits.h>
#include	"lib.h"
#include	"display.h"
#include	"anim.h"

size_t			get_images_nb(char **tab)
{
  size_t	number;
  size_t	i;

  number = 0;
  i = 0;
  while (tab[i])
    {
      if (extension(tab[i], ".jpg") || extension(tab[i], ".png"))
        number++;
      i++;
    }
  return (number);
}

int			back_music(const char *dir_path, char **tab)
{
  static sfMusic	*music = NULL;
  size_t		i;
  char			path[PATH_MAX];

  i = 0;
  while (tab[i] && !extension(tab[i], ".ogg"))
    i++;
  if (!tab || !tab[i])
    return (0);
  if (!music)
    {
      my_strcpy(path, dir_path);
      my_strcat(path, tab[i]);
      music = sfMusic_createFromFile(path);
      if (!music)
	return (0);
      sfMusic_play(music);
      sfMusic_setLoop(music, sfTrue);
    }
  else if (music)
    {
      sfMusic_destroy(music);
      music = NULL;
    }
  return (1);
}

int			extension(const char *file, const char *ext)
{
  char			*pos;

  pos = my_strstr(file, ext);
  if (pos && my_strcmp(pos, ext) == 0)
    return (1);
  return (0);
}

void			my_sort_wordtab(char **tab)
{
  char			*tmp;
  size_t		index;
  int			ord;

  ord = 0;
  while (!ord)
    {
      index = 0;
      while (tab[index + 1])
	{
	  if (my_strcmp(tab[index], tab[index + 1]) < 0)
	    {
	      tmp = tab[index];
	      tab[index] = tab[index + 1];
	      tab[index + 1] = tmp;
	      ord = 1;
	    }
	  index++;
	}
      ord--;
    }
}

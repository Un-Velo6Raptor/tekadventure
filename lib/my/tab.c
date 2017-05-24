/*
** tab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:16:08 2017 Hugo Cousin
** Last update Tue May 23 11:16:09 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

void		tabfree(char **t)
{
  char		**save;

  if (t)
    {
      save = t;
      while (*t)
	free(*t++);
      free(*t);
      free(save);
    }
}

char		**my_tabdup(char **t, int mode)
{
  size_t	i;
  char		**dest;

  if (!t)
    return (NULL);
  i = tablen(t) + 1;
  dest = malloc(sizeof(char*) * i);
  if (!dest)
    return (NULL);
  i = 0;
  while (t[i])
    {
      dest[i] = my_strdup(t[i]);
      i++;
    }
  dest[i] = NULL;
  if (mode == 1)
    tabfree(t);
  return (dest);
}

char		**my_tabrea(char **t, char *s)
{
  size_t	i;
  char		**dest;

  i = tablen(t);
  dest = malloc(sizeof(char*) * (i + 2));
  if (!dest)
    return (NULL);
  if (t)
    my_memcpy(dest, t, sizeof(char*) * (i + 1));
  dest[i] = my_strdup(s);
  dest[i + 1] = NULL;
  free(t);
  return (dest);
}

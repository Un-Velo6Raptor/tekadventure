/*
** tab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Apr  5 11:10:27 2017 Hugo Cousin
** Last update Wed Apr  5 21:18:08 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "my.h"

void	tabfree(char **t)
{
  int	i;

  i = 0;
  while (t && t[i] != NULL)
    free(t[i++]);
  if (t)
    free(t[i]);
  free(t);
}

char		**my_tabdup(char **t, int mode)
{
  size_t	i;
  char		**dest;

  i = tablen(t) + 1;
  if ((dest = malloc(sizeof(char*) * i)) == NULL)
    return (NULL);
  i = 0;
  while (t[i] != NULL)
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
  if ((dest = malloc(sizeof(char*) * (i + 2))) == NULL)
    return (NULL);
  my_memcpy(dest, t, sizeof(char*) * (i + 1));
  dest[i] = my_strdup(s);
  dest[i + 1] = NULL;
  free(t);
  return (dest);
}

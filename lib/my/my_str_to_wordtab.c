/*
** my_str_to_wordtab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:13:31 2017 Hugo Cousin
** Last update Wed Apr  5 21:16:35 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "my.h"

int	my_wordlen(int i, const char *str, char c)
{
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

void	*check_full(char **tab, int j)
{
  if (j == 0)
    {
      free(tab);
      return (NULL);
    }
  else
    return (tab);
}

int	nbwords(const char *s, char c)
{
  int	i;
  int	ct;

  i = 0;
  ct = 0;
  while (s[i])
    {
      while (s[i] && s[i] != c)
        i++;
      ct++;
      while (s[i] && s[i] == c)
        i++;
    }
  return (ct);
}

char	**my_str_to_wordtab(const char *str, char c)
{
  char	**dest;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if ((dest = malloc(sizeof(char*) * (nbwords(str, c) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      if (!(dest[j] = malloc(sizeof(char) * (my_wordlen(i, str, c) + 1))))
	return (NULL);
      while (str[i] && str[i] != c)
	dest[j][k++] = str[i++];
      dest[j++][k] = 0;
      while (str[i] && str[i] == c)
	i++;
      k = 0;
    }
  dest[j] = NULL;
  return (check_full(dest, j));
}

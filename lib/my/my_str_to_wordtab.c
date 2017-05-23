/*
** my_str_to_wordtab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:17:22 2017 Hugo Cousin
** Last update Tue May 23 11:17:23 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_wordlen(int i, const char *str, char c)
{
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

void		*check_full(char **tab, int j)
{
  if (j == 0)
    {
      free(tab);
      return (NULL);
    }
  else
    return (tab);
}

int		nbwords(const char *s, char c)
{
  int		i;
  int		ct;

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

char		**my_str_to_wordtab(const char *str, char c)
{
  char		**dest;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  dest = malloc(sizeof(char*) * (nbwords(str, c) + 1));
  if (!dest)
    return (NULL);
  while (str[i])
    {
      k = 0;
      dest[j] = malloc(sizeof(char) * (my_wordlen(i, str, c) + 1));
      if (!dest[j])
	return (NULL);
      while (str[i] && str[i] != c)
	dest[j][k++] = str[i++];
      dest[j++][k] = 0;
      while (str[i] && str[i] == c)
	i++;
    }
  dest[j] = NULL;
  return (check_full(dest, j));
}

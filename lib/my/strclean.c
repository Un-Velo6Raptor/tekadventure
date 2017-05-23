/*
** strclean.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:16:20 2017 Hugo Cousin
** Last update Tue May 23 11:19:30 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

void		shaft(char **t, size_t i)
{
  while (t[i])
    {
      t[i] = t[i + 1];
      i++;
    }
}

void		shift(char *str, size_t i)
{
  while (str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
}

void		tabclean(char **tab)
{
  size_t	i;
  char		*tmp;

  i = 0;
  while (tab[i])
    {
      strclean(tab[i]);
      if (!my_strlen(tab[i]))
	{
	  tmp = tab[i];
	  shaft(tab, i--);
	  free(tmp);
	}
      i++;
    }
}

void		strclean(char *s)
{
  size_t	i;

  i = 0;
  while (s[i])
    {
      if (s[0] == ' ' || s[0] == '\t')
	shift(s, 0);
      else if (s[i] == '\t')
	s[i--] = ' ';
      else if (s[i] == ' ' && s[i + 1] == ' ')
	shift(s, i--);
      else if (s[i] == ' ' && !s[i + 1])
	shift(s, i--);
      else
	i++;
    }
}

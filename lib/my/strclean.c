/*
** strclean.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 16:07:02 2017 Hugo Cousin
** Last update Thu Apr  6 22:55:30 2017 Hugo Cousin
*/

#include <stdlib.h>

void	shift(char *str, size_t i)
{
  while (str[i] != 0)
    {
      str[i] = str[i + 1];
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

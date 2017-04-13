/*
** my_strncmp.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:05:41 2017 Hugo Cousin
** Last update Tue Apr  4 15:17:14 2017 Hugo Cousin
*/

#include <stdlib.h>

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}


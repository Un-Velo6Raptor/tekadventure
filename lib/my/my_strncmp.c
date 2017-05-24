/*
** my_strncmp.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:17:44 2017 Hugo Cousin
** Last update Tue May 23 11:17:46 2017 Hugo Cousin
*/

#include	<stdlib.h>

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
  if (!s1 || !s2)
    return (0);
  while (n--)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
    }
  return (0);
}


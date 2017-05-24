/*
** my_strlen.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:17:54 2017 Hugo Cousin
** Last update Tue May 23 11:17:55 2017 Hugo Cousin
*/

#include	<stdlib.h>

size_t		my_strlen(const char *s)
{
  const char	*save;

  if (!s)
    return (0);
  save = s;
  while (*s)
    s++;
  return (s - save);
}

size_t		tablen(char **t)
{
  char		**save;

  if (!t)
    return (0);
  save = t;
  while (*t)
    t++;
  return (t - save);
}

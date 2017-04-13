/*
** my_strlen.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 14:42:23 2017 Hugo Cousin
** Last update Wed Apr  5 10:29:09 2017 Hugo Cousin
*/

#include <stdlib.h>

size_t		my_strlen(const char *s)
{
  size_t	i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}

size_t		tablen(char **t)
{
  size_t	i;

  i = 0;
  while (t && t[i])
    i++;
  return (i);
}

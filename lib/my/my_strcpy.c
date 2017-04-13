/*
** my_strcpy.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:06:23 2017 Hugo Cousin
** Last update Tue Apr  4 15:29:27 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcpy(char *dest, const char *src)
{
  size_t	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

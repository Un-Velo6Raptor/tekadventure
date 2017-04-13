/*
** my_strcat.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:05:17 2017 Hugo Cousin
** Last update Wed Apr  5 11:09:56 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "my.h"

char	*my_allocat(char *dest, char *src, int mode)
{
  char		*cat;

  if ((cat = malloc(sizeof(char) *
		    (my_strlen(dest) +
		     my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_strcpy(cat, dest);
  my_strcpy(cat + my_strlen(dest), src);
  if (mode == 1)
    {
      free(dest);
      free(src);
    }
  return (cat);
}

char	*my_strcat(char *dest, const char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}

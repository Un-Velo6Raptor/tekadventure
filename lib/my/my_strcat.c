/*
** my_strcat.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:18:42 2017 Hugo Cousin
** Last update Tue May 23 11:18:43 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_allocat(char *dest, char *src, int mode)
{
  char		*cat;

  cat = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
  if (!cat)
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

char		*my_strcat(char *dest, const char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}

/*
** my_strdup.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:13:07 2017 Hugo Cousin
** Last update Sun Apr  9 15:32:40 2017 Hugo Cousin
*/

#include <stdlib.h>
#include "my.h"

char	*my_sdup(char *src, int mode)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  if (mode == 1)
    free(src);
  return (dest);
}

char	*my_strndup(const char *src, size_t n)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  my_strncpy(dest, src, n);
  return (dest);
}

char	*my_strdup(const char *src)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

/*
** my_strdup.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:18:02 2017 Hugo Cousin
** Last update Tue May 23 11:18:03 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_sdup(char *src, int mode)
{
  char		*dest;

  if (!src)
    return (NULL);
  dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (!dest)
    return (NULL);
  my_strcpy(dest, src);
  if (mode == 1)
    free(src);
  return (dest);
}

char		*my_strndup(const char *src, size_t n)
{
  char		*dest;

  if (!src)
    return (NULL);
  dest = malloc(sizeof(char) * (n + 1));
  if (!dest)
    return (NULL);
  my_strncpy(dest, src, n);
  return (dest);
}

char		*my_strdup(const char *src)
{
  char		*dest;

  if (!src)
    return (NULL);
  dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (!dest)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

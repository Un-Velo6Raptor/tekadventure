/*
** mem.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon Feb 13 11:48:22 2017 Hugo Cousin
** Last update Thu Apr 13 16:56:05 2017 Hugo Cousin
*/

#include <string.h>
#include <stdlib.h>

void	*my_memset(void *s, int c, size_t n)
{
  int	i;
  char	*s_p;

  i = 0;
  s_p = s;
  while (n--)
    s_p[i++] = (unsigned char)c;
  return (s);
}

void		*my_memcpy(void *dest, const void *src, size_t n)
{
  size_t	i;
  char		*new;
  const char	*s;

  i = 0;
  new = dest;
  s = src;
  while (n--)
    {
      new[i] = s[i];
      i++;
    }
  return (dest);
}

void		*my_realloc(void *src, size_t old, size_t new)
{
  void		*ptr;

  ptr = malloc(new);
  if (!ptr)
    return (NULL);
  if (new < old)
    old = new;
  my_memcpy(ptr, src, old);
  free(src);
  return (ptr);
}

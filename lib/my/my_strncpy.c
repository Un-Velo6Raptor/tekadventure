/*
** my_strncpy.c for my_strncpy.c in /home/Heychsea/CPool_Day06
** 
** Made by Cousin Hugo
** Login   <Heychsea@epitech.net>
** 
** Started on  Mon Oct 10 09:43:32 2016 Cousin Hugo
** Last update Wed Apr  5 11:15:14 2017 Hugo Cousin
*/

#include "my.h"

char		*my_strncpy(char *dest, const char *src, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

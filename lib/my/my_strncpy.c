/*
** my_strncpy.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:17:31 2017 Hugo Cousin
** Last update Tue May 23 11:17:32 2017 Hugo Cousin
*/

#include	"lib.h"

char		*my_strncpy(char *dest, const char *src, size_t n)
{
  if (src)
    {
      while (n-- && *src)
	*dest++ = *src++;
      *dest = 0;
    }
  return (dest);
}

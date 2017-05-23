/*
** my_strcpy.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:18:21 2017 Hugo Cousin
** Last update Tue May 23 11:18:23 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strcpy(char *dest, const char *src)
{
  if (src && dest)
    my_memcpy(dest, src, my_strlen(src) + 1);
  return (dest);
}

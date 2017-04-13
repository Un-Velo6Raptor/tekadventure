/*
** glnfix.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 19 14:18:45 2017 Hugo Cousin
** Last update Fri Feb 24 17:35:55 2017 Hugo Cousin
*/

#include <stdlib.h>

char	*fix(char *next, char *buff, int rlen)
{
  if (!next && rlen == 0)
    {
      free(buff);
      return (NULL);
    }
  else
    return (buff);
}

char	*eof(char *next, char *buff, int len)
{
  if (len == 0)
    {
      free(buff);
      if (next)
	free(next);
      return (NULL);
    }
  return (NULL);
}

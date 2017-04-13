/*
** my_show_wordtab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:05:04 2017 Hugo Cousin
** Last update Sat Apr  8 13:53:24 2017 Hugo Cousin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void		my_show_wordtab(int fd, char **array, char *s)
{
  size_t	i;

  i = 0;
  while (array[i])
    {
      my_putstr(array[i++], fd);
      my_putstr(s, fd);
    }
}

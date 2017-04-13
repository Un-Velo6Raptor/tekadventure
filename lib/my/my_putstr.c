/*
** my_putstr.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:04:06 2017 Hugo Cousin
** Last update Tue Apr  4 15:57:10 2017 Hugo Cousin
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(const char *s, int fd)
{
  if (s)
    write(fd, s, my_strlen(s));
}

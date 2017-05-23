/*
** my_putstr.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:18:59 2017 Hugo Cousin
** Last update Tue May 23 11:20:40 2017 Hugo Cousin
*/

#include	<unistd.h>
#include	"lib.h"

void		my_putstr(int fd, const char *s)
{
  if (s)
    write(fd, s, my_strlen(s));
}

int		my_puterror(char *s)
{
  if (s)
    write(2, s, my_strlen(s));
  return (1);
}

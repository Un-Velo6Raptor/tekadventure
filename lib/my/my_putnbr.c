/*
** my_putnbr.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:19:06 2017 Hugo Cousin
** Last update Tue May 23 11:19:07 2017 Hugo Cousin
*/

#include	"lib.h"

void		putnb(int fd,  int nb)
{
  if (nb >= 10)
    {
      putnb(fd, nb / 10);
      putnb(fd, nb % 10);
    }
  else
    my_putchar(fd, nb + 48);
}


/*
** my_put_nbr_base.c for printf in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Nov  9 17:38:17 2016 Hugo Cousin
** Last update Sun Apr  9 19:56:00 2017 Hugo Cousin
*/

#include "my.h"

void	putnb(int fd,  int nb)
{
  if (nb >= 10)
    {
      putnb(fd, nb / 10);
      putnb(fd, nb % 10);
    }
  else
    my_putchar(fd, nb + 48);
}


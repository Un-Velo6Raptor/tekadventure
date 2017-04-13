/*
** my_putchar.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:03:46 2017 Hugo Cousin
** Last update Sun Apr  9 19:52:46 2017 Hugo Cousin
*/

#include <unistd.h>

void	my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}

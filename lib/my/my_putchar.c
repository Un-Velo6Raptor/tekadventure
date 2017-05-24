/*
** my_putchar.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:19:15 2017 Hugo Cousin
** Last update Tue May 23 11:19:16 2017 Hugo Cousin
*/

#include	<unistd.h>

void		my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}

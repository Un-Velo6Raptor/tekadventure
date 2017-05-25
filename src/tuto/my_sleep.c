/*
** my_sleep.c for my_sleep.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:29:06 2017 Romain Melin
** Last update Thu May 25 15:20:04 2017 Romain Melin
*/

#include	<time.h>
#include	<unistd.h>

void		my_sleep()
{
  int		i;

  i = time(NULL);
  while (time(NULL) == i);
}

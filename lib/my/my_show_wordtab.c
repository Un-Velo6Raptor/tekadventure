/*
** my_show_wordtab.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:18:51 2017 Hugo Cousin
** Last update Tue May 23 11:23:06 2017 Hugo Cousin
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"

void		my_show_wordtab(int fd, char **array, char *s)
{
  size_t	i;

  i = 0;
  if (array)
    {
      while (array[i])
	{
	  my_putstr(fd, array[i++]);
	  my_putstr(fd, s);
	}
    }
}

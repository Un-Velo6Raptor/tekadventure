/*
** my_putstr.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 15:40:53 2017 Martin Januario
** Last update Fri May 19 15:44:39 2017 Martin Januario
*/

#include	<unistd.h>
#include	"lib.h"

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}

int		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}

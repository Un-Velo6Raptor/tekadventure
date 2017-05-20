/*
** my_strlen.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 15:43:17 2017 Martin Januario
** Last update Fri May 19 15:45:12 2017 Martin Januario
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}

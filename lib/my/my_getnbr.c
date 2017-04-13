/*
** my_getnbr.c for getnnb in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue Feb 21 14:41:20 2017 Hugo Cousin
** Last update Tue Apr  4 15:57:38 2017 Hugo Cousin
*/

#include "my.h"

int	get_sign(const char *s)
{
  int	sign;
  int	i;

  sign = 1;
  i = 0;
  while (s[i] == '-' || s[i] == '+')
    {
      if (s[i] == '-')
        sign = -sign;
      i++;
    }
  return (sign);
}

int	getnb(const char *s)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = get_sign(s);
  while (s[i] == '-' || s[i] == '+')
    i++;
  while (s[i] >= 48 && s[i] <= 57)
    nb = (nb * 10) + (s[i++] - 48);
  nb *= sign;
  return (nb);
}

int	u_getnb(const char *s)
{
  int	nb;
  unsigned int	i;

  nb = 0;
  i = 0;
  if ((my_strlen(s) == 10 &&
      my_strcmp(s, "2147483647") > 0)
      || my_strlen(s) > 10 || str_num(s) == -1)
    return (-1);
  while (s[i] >= 48 && s[i] <= 57)
    nb = (nb * 10) + (s[i++] - 48);
  return (nb);
}

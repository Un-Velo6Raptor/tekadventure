/*
** char_test.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Jan 18 22:28:11 2017 Hugo Cousin
** Last update Tue Apr  4 16:08:54 2017 Hugo Cousin
*/

#include <stdlib.h>

int	alnum(char c)
{
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    return (1);
  return (0);
}

int	str_num(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] >= 48 && s[i] <= 57)
	i++;
      else
	return (-1);
    }
  return (0);
}

char		*my_strchr(const char *s, int c)
{
  while (*s != (char)c)
    {
      if (!*s++)
	return (0);
    }
  return ((char *)s);
}

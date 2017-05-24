/*
** char_test.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:15:39 2017 Hugo Cousin
** Last update Tue May 23 11:15:42 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"lib.h"

int		alnum(char c)
{
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    return (1);
  return (0);
}

int		str_num(const char *s)
{
  int		i;

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
  if (!s)
    return (NULL);
  while (*s != (char)c)
    {
      if (!*s++)
	return (0);
    }
  return ((char *)s);
}

char		*my_strstr(const char *haystack, const char *needle)
{
  size_t	size;

  size = my_strlen(needle);
  while (*haystack)
    {
      if (*haystack == *needle && !my_strncmp(haystack, needle, size))
	return ((char *)haystack);
      haystack++;
    }
  return (NULL);
}

/*
** get_next_line.c for getnext_line in /home/heychsea/CPE/CPE_2016_getnextline
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Jan  4 15:58:09 2017 Hugo Cousin
** Last update Thu Apr 13 12:22:55 2017 Hugo Cousin
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

long	my_len(char *s, int mode)
{
  long   i;

  i = 0;
  if (mode == 0)
    {
      while (s[i] != 0)
	i++;
      return (i);
    }
  else
    {
      while (s[i] != 0)
	{
	  if (s[i] == '\n')
	    return (-2);
	  i++;
	}
      return (1);
    }
}

char	*my_dup(char *str, int mode)
{
  long	size;
  char	*s;
  long	i;

  i = 0;
  size = my_len(str, 0);
  if ((s = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      s[i] = str[i];
      i++;
    }
  s[i] = 0;
  if (mode == 1)
    free(str);
  return (s);
}

char	*newchar(char *b, char *str)
{
  int	i[3];
  char	*new;

  i[0] = 0;
  i[1] = 0;
  i[2] = 0;
  if ((new = malloc(sizeof(char) *
		    (my_len(b, 0) + my_len(str, 0) + 1))) == NULL)
    return (NULL);
  while (b[i[0]] != 0)
    new[i[2]++] = b[i[0]++];
  while (str[i[1]] != 0)
    new[i[2]++] = str[i[1]++];
  new[i[2]] = 0;
  free(b);
  free(str);
  return (new);
}

t_gnl	my_rea(char *s, const int fd)
{
  t_gnl g;
  char	*new;
  long	i;

  g.status = 1;
  if ((new = malloc(sizeof(char) * (my_len(s, 0) + READ_SIZE + 1))) == NULL)
    {
      g.status = 0;
      return (g);
    }
  i = 0;
  while (s[i] != 0)
    {
      new[i] = s[i];
      i++;
    }
  free(s);
  g.rlen = read(fd, new + i, READ_SIZE);
  new[i + g.rlen] = 0;
  g.buff = my_dup(new, 1);
  return (g);
}

char		*get_next_line(const int fd)
{
  t_gnl		s;
  static char	*next = NULL;

  s.status = 1;
  if ((s.buff = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((s.rlen = (!next || (next && my_len(next, 1) != -2)) ?
       read(fd, s.buff, READ_SIZE) : 0) <= 0 && !next)
    return (eof(next, s.buff, s.rlen));
  s.buff[s.rlen] = 0;
  s.buff = my_dup(s.buff, 1);
  while (s.rlen > 0 && my_len(s.buff, 1) != -2 && s.status != 0)
    s = my_rea(s.buff, fd);
  if (s.status == 0)
    return (NULL);
  s.buff = (!next) ? s.buff : newchar(next, s.buff);
  next = (!next) ? next : NULL;
  s.rlen = 0;
  while (s.buff[s.rlen] != 0 && s.buff[s.rlen] != '\n')
    s.rlen++;
  next = (!next) ? (s.buff[s.rlen] == 0) ? NULL :
    my_dup(s.buff + (s.rlen + 1), 0) : newchar(next, s.buff + (s.rlen + 1));
  s.buff[s.rlen] = 0;
  return (fix(next, s.buff, s.rlen));
}

/*
** gnl.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue May 23 11:16:36 2017 Hugo Cousin
** Last update Tue May 23 11:16:40 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"lib.h"
#include	"get_next_line.h"

char		*append_buff(char *next, char buff[READ_SIZE + 1])
{
  char		*new;

  new = malloc(sizeof(char) * (my_strlen(next) + my_strlen(buff) + 1));
  if (!new)
    return (NULL);
  new[0] = 0;
  if (!my_strlen(next))
    my_strcat(new, buff);
  else
    {
      my_strcpy(new, next);
      my_strcat(new, buff);
    }
  free(next);
  return (new);
}

int		store_line(const int fd, char **next)
{
  int		len;
  char		buff[READ_SIZE + 1];

  while (!my_strchr(*next, '\n'))
    {
      len = read(fd, buff, READ_SIZE);
      if (len < 1 && !*next)
	return (0);
      if (len < 1 && *next)
	return (1);
      buff[len] = 0;
      *next = append_buff(*next, buff);
      if (!*next)
	return (0);
    }
  return (1);
}

char		*get_str(char **next)
{
  char		*str;
  size_t	pos;
  char		*tmp;

  if (!*next)
    return (NULL);
  tmp = NULL;
  if (my_strchr(*next, '\n'))
    {
      pos = my_strchr(*next, '\n') - *next;
      (*next)[pos] = 0;
      tmp = my_strdup(*next + (pos + 1));
      if (!my_strlen(tmp))
	{
	  free(tmp);
	  tmp = NULL;
	}
    }
  else
    pos = my_strlen(*next);
  str = my_strndup(*next, pos);
  free(*next);
  *next = tmp;
  return (str);
}

char		*gnl(const int fd)
{
  static char	*next = NULL;
  char		*str;

  if (fd < 0)
    {
      free(next);
      next = NULL;
    }
  if (!store_line(fd, &next))
    return (NULL);
  str = get_str(&next);
  return (str);
}

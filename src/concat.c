/*
** concat.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sat May 27 22:38:13 2017 Sahel Lucas--Saoudi
** Last update Sat May 27 22:40:16 2017 Sahel Lucas--Saoudi
*/

#include <stdarg.h>
#include <stdlib.h>
#include "lib.h"

static int      get_size_arg(int nb, va_list ap)
{
  int           size;
  int           idx;

  idx = 0;
  size = 0;
  while (idx < nb)
    {
      size += my_strlen(va_arg(ap, char *));
      idx++;
    }
  return (size);
}

char            *concat(int nb_str, ...)
{
  va_list       ap;
  char          *str;
  int           size;
  int           idx;

  va_start(ap, nb_str);
  size = get_size_arg(nb_str, ap);
  va_end(ap);
  str = malloc(sizeof(char) * (size + 1));
  if (!str)
    return (NULL);
  va_start(ap, nb_str);
  my_strcpy(str, va_arg(ap, char *));
  idx = 0;
  while (idx < nb_str - 1)
    {
      my_strcat(str, va_arg(ap, char *));
      idx++;
    }
  va_end(ap);
  return (str);
}

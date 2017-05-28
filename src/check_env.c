/*
** check_env.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 23:16:22 2017 Martin Januario
** Last update Sun May 28 23:16:23 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"display.h"

static int	check_name_next(char *str)
{
  if (match(str, "LS_COLORS=*") == 1)
    return (1);
  else if (match(str, "XDG_RUNTIME_DIR=*") == 1)
    return (1);
  return (0);
}

static int	check_name(char *str)
{
  if (match(str, "DISPLAY=*") == 1 && str[8] != '\0')
    return (1);
  else if (match(str, "LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "LD_LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "CPATH=*") == 1)
    return (1);
  else if (check_name_next(str) == 1)
    return (1);
  return (0);
}

int		check_env(char **tab)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 0;
  while (tab[idx] != NULL)
    {
      if (check_name(tab[idx]) == 1)
	cpt++;
      idx++;
    }
  if (cpt != 6)
    return (1);
  return (0);
}

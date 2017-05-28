/*
** dico.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 23:13:48 2017 Martin Januario
** Last update Sun May 28 23:13:49 2017 Martin Januario
*/

#include <stdlib.h>
#include <stdarg.h>

char		**c_dico(int nb_arg, ...)
{
  char		**dico;
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, nb_arg);
  dico = malloc(sizeof(char *) * (nb_arg + 1));
  if (!dico)
    return (NULL);
  while (i < nb_arg)
    {
      dico[i] = va_arg(ap, char *);
      i++;
    }
  dico[i] = NULL;
  return (dico);
}

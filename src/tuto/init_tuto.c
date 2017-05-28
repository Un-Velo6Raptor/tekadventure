/*
** init_tuto.c for init_tuto.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:31:05 2017 Romain Melin
** Last update Thu May 25 14:18:49 2017 Romain Melin
*/

#include		<SFML/Graphics.h>
#include		<stdlib.h>

static sfTexture	**check_image(sfTexture **image)
{
  int			i;

  i = 0;
  while (image[i] != NULL)
    i++;
  if (i != 7)
    return (NULL);
  return (image);
}

sfTexture		**load_image()
{
  sfTexture		**image;

  image = malloc(sizeof(sfTexture *) * 8);
  if (image == NULL)
    return (NULL);
  image[0] = sfTexture_createFromFile("ressources/tuto/sommaire.jpg", NULL);
  image[1] = sfTexture_createFromFile("ressources/tuto/informations_utiles.jpg", NULL);
  image[2] = sfTexture_createFromFile("ressources/tuto/charlotte.jpg", NULL);
  image[3] = sfTexture_createFromFile("ressources/tuto/Sasel.jpg", NULL);
  image[4] = sfTexture_createFromFile("ressources/tuto/l'enfant.jpg", NULL);
  image[5] = sfTexture_createFromFile("ressources/tuto/douceur.jpg", NULL);
  image[6] = sfTexture_createFromFile("ressources/tuto/begin.jpg", NULL);
  image[7] = NULL;
  return (check_image(image));
}

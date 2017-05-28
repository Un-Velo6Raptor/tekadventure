/*
** init_tuto.c for init_tuto.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:31:05 2017 Romain Melin
** Last update Sun May 28 19:36:35 2017 Hugo Cousin
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
  image[0] = sfTexture_createFromFile("ressources/tuto/tutoriel.png", NULL);
  image[1] = sfTexture_createFromFile("ressources/tuto/informations.png",
				      NULL);
  image[2] = sfTexture_createFromFile("ressources/tuto/charlotte.png", NULL);
  image[3] = sfTexture_createFromFile("ressources/tuto/Sasel.png", NULL);
  image[4] = sfTexture_createFromFile("ressources/tuto/l'enfant.png", NULL);
  image[5] = sfTexture_createFromFile("ressources/tuto/douceur.png", NULL);
  image[6] = sfTexture_createFromFile("ressources/tuto/begin.png", NULL);
  image[7] = NULL;
  return (check_image(image));
}

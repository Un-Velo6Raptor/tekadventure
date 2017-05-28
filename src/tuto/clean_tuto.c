/*
** clean_tuto.c for clean_tuto.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:38:00 2017 Romain Melin
** Last update Sat May 27 19:00:15 2017 Martin Januario
*/

#include		<SFML/Graphics.h>
#include		<stdlib.h>

void                    is_closed(sfRenderWindow *window)
{
  sfEvent               event;

  while (sfRenderWindow_pollEvent(window, &event))
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)
	|| sfKeyboard_isKeyPressed(sfKeyReturn))
      sfRenderWindow_close(window);
}

void                    free_image(sfTexture **image)
{
  int                   i;

  i = 0;
  while (image[i] != NULL)
    {
      sfTexture_destroy(image[i]);
      i++;
    }
  free(image);
}

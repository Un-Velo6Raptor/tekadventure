/*
** clean_tuto.c for clean_tuto.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:38:00 2017 Romain Melin
** Last update Thu May 25 11:49:13 2017 Romain Melin
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
      free(image[i]);
      i++;
    }
  free(image);
}

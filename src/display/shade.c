/*
** shade.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 19:29:11 2017 Hugo Cousin
** Last update Fri May 26 19:31:54 2017 Hugo Cousin
*/

#include	"display.h"

void		shade_sprite(sfRenderWindow *window, sfSprite *sprite)
{
  int		color;

  color = 255;
  while (color)
    {
      sfSprite_setColor(sprite, (sfColor){color, color, color, 255});
      sfRenderWindow_draw_Sprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      color -= 2;
    }
  while (color < 254)
    {
      sfSprite_setColor(sprite, (sfColor){color, color, color, 255});
      sfRenderWindow_draw_Sprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      color += 2;
    }
  while (color)
    {
      sfSprite_setColor(sprite, (sfColor){color, color, color, 255});
      sfRenderWindow_draw_Sprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      color -= 2;
    }
}

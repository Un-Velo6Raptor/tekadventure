/*
** shade.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 19:29:11 2017 Hugo Cousin
** Last update Sun May 28 18:49:20 2017 Hugo Cousin
*/

#include	"display.h"

void		shade_sprite(sfRenderWindow *window, sfSprite *sprite,
			     int speed)
{
  int		color;

  color = 0;
  while (color < 255 - speed
	 && sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      sfSprite_setColor(sprite, (sfColor){color, color, color, 255});
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      color += speed;
    }
  color = 255;
  while (color > speed && sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      sfSprite_setColor(sprite, (sfColor){color, color, color, 255});
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      color -= speed;
    }
}

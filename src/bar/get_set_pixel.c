/*
** get_set_pixel.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Thu May 25 14:37:12 2017 Martin Januario
** Last update Sat May 27 22:46:04 2017 Sahel Lucas--Saoudi
*/

#include	"bar.h"
#include	"game.h"

int		is_on_green(t_needs *needs, t_framebuffer *frame_buffer,
			    int pos)
{
  sfColor               color;

  sfRenderWindow_setFramerateLimit(needs->window, 60);
  color.r = frame_buffer->pixels[(frame_buffer->width * 760 +
				  (pos + 25)) * 4];
  color.g = frame_buffer->pixels[(frame_buffer->width * 760 +
				  (pos + 25)) * 4 + 1];
  color.b = frame_buffer->pixels[(frame_buffer->width * 760 +
				  (pos + 25)) * 4 + 2];
  color.a = frame_buffer->pixels[(frame_buffer->width * 760 +
				  (pos + 25)) * 4 + 3];
  if (color.g == 255)
    return (1);
  return (0);
}

void		my_put_pixel(t_framebuffer *frame_buffer, int x, int y,
			     sfColor color)
{
  if (x >= 0 && y >= 0 && x < frame_buffer->width && y < frame_buffer->height)
    {
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4] = color.r;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 1] = color.g;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 2] = color.b;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 3] = color.a;
    }
}

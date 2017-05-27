/*
** my_framebuffer_create.c for  in /home/januar_m/delivery/graphical/bswireframe
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Thu Dec  8 13:58:19 2016
** Last update Sat May 27 22:52:10 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"bar.h"

t_framebuffer		*framebuffer_create(int width, int height)
{
  t_framebuffer		*frame_buf;
  int			idx;

  idx = 0;
  frame_buf = malloc(sizeof(t_framebuffer));
  if (!frame_buf)
    return (NULL);
  frame_buf->width = width;
  frame_buf->height = height;
  frame_buf->pixels = malloc(width * height * 4 * sizeof(frame_buf->pixels));
  if (!frame_buf->pixels)
    return (NULL);
  while (idx < width * height * 4)
    {
      frame_buf->pixels[idx] = 0;
      idx++;
    }
  return (frame_buf);
}

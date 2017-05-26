/*
** reset_frame.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 26 21:48:43 2016 
** Last update Wed May 24 16:33:57 2017 Martin Januario
*/

#include	"bar.h"

void		reset_frame(t_framebuffer *pixel_buffer)
{
  int		idx;

  idx = 0;
  while (idx < pixel_buffer->height * pixel_buffer->width * 4)
    {
      pixel_buffer->pixels[idx] = 0;
      idx++;
    }
}

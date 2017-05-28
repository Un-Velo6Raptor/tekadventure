/*
** reset_frame.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 23:18:11 2017 Martin Januario
** Last update Sun May 28 23:18:12 2017 Martin Januario
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

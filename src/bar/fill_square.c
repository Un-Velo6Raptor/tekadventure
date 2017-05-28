/*
** fill_square.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 14:49:30 2017 Martin Januario
** Last update Sun May 28 10:27:46 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<time.h>
#include	"bar.h"
#include	"game.h"

void			fill_square(t_framebuffer *buffer, int diff)
{
  int			tmp;
  int			x;
  int			y;
  int			idx;

  y = 750;
  diff = 4 - diff;
  srand(time(NULL));
  tmp = rand() % (580 - diff * 20);
  while (y < 860)
    {
      idx = 0;
      x = ((WIDTH - 620) / 2) + 20;
      while (x < 760)
        {
          if (idx >= tmp && idx <= tmp + diff * 20)
            my_put_pixel(buffer, x, y, sfGreen);
          else
            my_put_pixel(buffer, x, y, sfRed);
          idx++;
          x++;
        }
      y++;
    }
}

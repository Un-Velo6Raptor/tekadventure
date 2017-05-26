/*
** click_select.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 23:16:12 2017 Martin Januario
** Last update Fri May 26 20:00:09 2017 Martin Januario
*/

#include	"select.h"

int		click_select(sfVector2i pos,
			     t_needs __attribute__ ((unused))  *needs,
			     int last)
{
  int		idx;
  sfVector2i	tmp;

  idx = 0;
  if (last == -1)
    last = 0;
  while (idx < 4)
    {
      tmp.x = (idx != 1 && idx != 2) ? 250 : 300;
      tmp.y = (idx != 1 && idx != 2) ? 580 : 564;
      if (idx * 200 + 20 * idx + 20 <= pos.x &&
	  idx * 200 + 20 * idx + 220 >= pos.x &&
	  pos.y <= tmp.y && pos.y >= tmp.x)
	{
	  if (idx == 2)
	    idx = 0;
	  else if (idx == 0)
	    idx = 2;
	  return (idx);
	}
      idx++;
    }
  if (pos.x >= 134 && pos.x <= 710 && pos.y >= 710 && pos.y <= 872)
    return (-1);
  return (last);
}

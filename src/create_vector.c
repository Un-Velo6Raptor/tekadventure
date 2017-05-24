/*
** create_vector.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 18:43:03 2017 Martin Januario
** Last update Sat May 20 14:52:24 2017 Martin Januario
*/

#include	"display.h"

sfVector2f	vector_2f(float x, float y)
{
  sfVector2f	tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}

sfVector2i	vector_2i(int x, int y)
{
  sfVector2i	tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}

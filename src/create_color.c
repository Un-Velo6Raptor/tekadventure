/*
** create_color.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 19:38:33 2017 Martin Januario
** Last update Fri May 19 19:39:40 2017 Martin Januario
*/

#include	"display.h"

sfColor		color(int a, int b, int c)
{
  sfColor	tmp;

  tmp.r = a;
  tmp.g = b;
  tmp.b = c;
  tmp.a = 255;
  return (tmp);
}

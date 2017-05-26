/*
** place_select.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 22:55:59 2017 Martin Januario
** Last update Thu May 25 23:30:25 2017 Martin Januario
*/

#include	"select.h"

void		place_select(sfSprite **sprite)
{
  sfSprite_setPosition(sprite[5], vector_2f(150, 50));
  sfSprite_setScale(sprite[5], vector_2f(1.5, 1.5));
  sfSprite_setPosition(sprite[6], vector_2f(140, 700));
  sfSprite_setScale(sprite[6], vector_2f(1.4, 1.4));
  sfSprite_setPosition(sprite[0], vector_2f(0, 0));
}

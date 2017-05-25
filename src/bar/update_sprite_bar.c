/*
** update_sprite_bar.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 15:39:30 2017 Martin Januario
** Last update Thu May 25 15:40:26 2017 Martin Januario
*/

#include	"bar.h"

void		update_sprite_bar(t_needs *needs, sfSprite *tmp,
				  sfSprite *design, sfSprite *cursor)
{
  sfRenderWindow_drawSprite(needs->window, tmp, NULL);
  sfRenderWindow_drawSprite(needs->window, design, NULL);
  sfRenderWindow_drawSprite(needs->window, cursor, NULL);
  sfRenderWindow_display(needs->window);
}

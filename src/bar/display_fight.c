/*
** display_fight.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 06:30:40 2017 Martin Januario
** Last update Sun May 28 15:25:13 2017 Martin Januario
*/

#include	"display.h"
#include	"bar.h"
#include	"refresh.h"

void		display_fight(t_needs *needs)
{
  sfIntRect	tmp;

  tmp = sfSprite_getTextureRect(needs->player[needs->current_player]->sprite);
  tmp.left = 0;
  tmp.top = RIGHT * SPRITE_H;
  sfSprite_setTextureRect(needs->player[needs->current_player]->sprite, tmp);
  sfRenderWindow_drawSprite(needs->window,
			    needs->boss[needs->map[needs->current_map]->boss]->sprite, NULL);
  sfRenderWindow_drawSprite(needs->window,
			    needs->player[needs->current_player]->sprite, NULL);
}

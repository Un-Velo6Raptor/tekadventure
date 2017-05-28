/*
** velleda.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Sun May 28 17:25:43 2017 Hugo Cousin
** Last update Sun May 28 19:41:07 2017 Hugo Cousin
*/

#include	"display.h"

void		display_status(t_needs *needs)
{
  char		quantity[2];

  quantity[1] = 0;
  quantity[0] = 4 - needs->current_veleda + 48;
  sfText_setString(needs->nb_veleda, quantity);
  sfRenderWindow_drawSprite(needs->window, needs->veleda_sprite, NULL);
  sfRenderWindow_drawText(needs->window, needs->nb_veleda, NULL);
}

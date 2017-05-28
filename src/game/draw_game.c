/*
** draw_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 21:41:27 2017 Martin Januario
** Last update Sun May 28 21:45:31 2017 Martin Januario
*/

#include	"game.h"
#include	"display.h"

void		draw_game(t_needs *needs, sfVector2i *to, int *check)
{
  *to = check_room(needs, needs->pos, *to, check);
  needs->pos =
    get_map_move(needs->map[needs->current_map]->map, needs->pos, *to,
		 needs->player[needs->current_player]->sprite);
  sfRenderWindow_drawSprite(needs->window,
			    needs->map[needs->current_map]->map, NULL);
  sfRenderWindow_drawSprite(needs->window,
			    needs->player[needs->current_player]
			    ->sprite, NULL);
  display_status(needs);
  sfRenderWindow_display(needs->window);
}

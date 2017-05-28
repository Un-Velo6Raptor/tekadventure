/*
** get_mouse_pos.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 21:53:55 2017 Martin Januario
** Last update Sun May 28 21:55:21 2017 Martin Januario
*/

#include	"display.h"
#include	"game.h"

void		get_mouse_pos(t_needs *needs, sfVector2i *to,
			      sfEvent *event)
{
  if (event->type == sfEvtClosed ||
      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(needs->window);
  else if (event->type == sfEvtMouseButtonPressed &&
	   event->mouseButton.button == sfMouseLeft)
    *to = check_move_map(vector_2i(event->mouseButton.x,
				   event->mouseButton.y),
			 needs, needs->pos, *to);
}

/*
** loop_game.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Tue May 23 17:18:19 2017 Martin Januario
** Last update Sun May 28 20:22:45 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"
#include	"refresh.h"
#include	"anim.h"

static sfVector2i	check_move_map(sfVector2i to, t_needs *needs,
				       sfVector2i from,
				       sfVector2i last)
{
  sfIntRect		rect;

  rect = sfSprite_getTextureRect(needs->map[needs->current_map]->map);
  to.x += rect.left;
  to.y += rect.top;
  if (check_path(needs->map[needs->current_map], from, to) != 0)
      return (to);
  return (last);
}

static sfVector2i	get_map_move(sfSprite *map, sfVector2i from,
				     sfVector2i to,
				     sfSprite *player)
{
  sfIntRect		rect;
  sfVector2i		tmp;

  rect = sfSprite_getTextureRect(map);
  tmp.x = to.x - from.x + rect.left;
  tmp.y = to.y - from.y + rect.top;
  from = vector_2i(rect.left, rect.top);
  if (from.x != tmp.x || from.y != tmp.y)
    from = move_map(map, from, tmp, 0);
  else
    {
      player_refresh(player, vector_2f(450, 450), from, tmp);
      move_map(map, from, tmp, 1);
    }
  from.x += WIDTH / 2;
  from.y += HEIGHT / 2;
  return (from);
}

int                     loop_game(t_needs *needs)
{
  sfVector2i		to;
  sfEvent               event;
  int			check;

  while (count_dead_player(needs) != 4 && sfRenderWindow_isOpen(needs->window)
	 && needs->current_veleda)
    {
      check = 0;
      music_pause(needs->map[0]->theme, needs);
      if (start_select(needs) == 84)
	return (84);
      music_start(needs->map[0]->theme, needs);
      needs->pos = vector_2i(1560, 1152);
      to = vector_2i(1560, 1152);
      update_rect(needs->map[needs->current_map]->map,
		  vector_2i(needs->pos.x - WIDTH / 2,
			    needs->pos.y - HEIGHT / 2));
      while (check == 0 && sfRenderWindow_isOpen(needs->window)
	     && needs->current_veleda)
	{
	  player_refresh(needs->player[needs->current_player]->sprite,
			 vector_2f(450, 450), needs->pos, to);
	  sfRenderWindow_clear(needs->window, sfBlack);
	  while (sfRenderWindow_pollEvent(needs->window, &event))
	    {
	      if (event.type == sfEvtClosed ||
		  sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
		sfRenderWindow_close(needs->window);
	      else if (event.type == sfEvtMouseButtonPressed &&
		       event.mouseButton.button == sfMouseLeft)
		to = check_move_map(vector_2i(event.mouseButton.x,
					      event.mouseButton.y),
				    needs, needs->pos, to);
	    }
	  to = check_room(needs, needs->pos, to, &check);
	  needs->pos =
	    get_map_move(needs->map[needs->current_map]->map, needs->pos, to,
			 needs->player[needs->current_player]->sprite);
	  sfRenderWindow_drawSprite(needs->window,
				    needs->map[needs->current_map]->map, NULL);
	  sfRenderWindow_drawSprite(needs->window,
				    needs->player[needs->current_player]
				    ->sprite, NULL);
	  display_status(needs);
	  sfRenderWindow_display(needs->window);
	}
    }
  music_pause(needs->map[0]->theme, needs);
  if (!needs->current_veleda)
    final_fight(needs);
  else
    launch_anim(needs->window, "ressources/defeat/", needs->mode->sound, 1);
  return (0);
}

/*
** room.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 20:58:04 2017 Hugo Cousin
** Last update Sun May 28 17:53:45 2017 Hugo Cousin
*/

#include	"lib.h"
#include	"display.h"
#include	"refresh.h"
#include	"game.h"
#include	"boss.h"

void		change_sprite(t_needs *needs, int mode)
{
  if (!mode)
    {
      sfRenderWindow_setFramerateLimit(needs->window, 120);
      sfSprite_setPosition(needs->player[needs->current_player]->sprite,
			   (sfVector2f){150, 500});
      needs->player[needs->current_player]->pos =
	sfSprite_getPosition(needs->player[needs->current_player]->sprite);
    }
  else
    {
      sfSprite_setPosition(needs->player[needs->current_player]->sprite,
			   (sfVector2f){450, 450});
      sfSprite_setScale(needs->player[needs->current_player]->sprite,
			vector_2f(1, 1));
      sfRenderWindow_setFramerateLimit(needs->window, 60);
      needs->current_map = 0;
    }
}

void		refresh_room(t_needs *needs, int opt)
{
  float		scale;

  sfRenderWindow_drawSprite(needs->window,
			    needs->map[needs->current_map]->map, NULL);
  if (opt != 1)
    {
      sfRenderWindow_drawSprite(needs->window,
				needs->player[needs->current_player]->sprite,
				NULL);
      display_status(needs);
      sfRenderWindow_display(needs->window);
      scale = (float)needs->player[needs->current_player]->pos.y / 200.0 + 1.5;
      sfSprite_setScale(needs->player[needs->current_player]->sprite,
			vector_2f(scale, scale));
    }

}

sfVector2i	room_move(t_needs *needs, sfEvent event)
{
  t_char	*player;
  t_map		*map;
  sfVector2i	to;
  sfVector2i	from;
  sfColor	color;

  map = needs->map[needs->current_map];
  player = needs->player[needs->current_player];
  to.x = event.mouseButton.x;
  to.y = event.mouseButton.y;
  color = sfImage_getPixel(map->image, to.x, to.y);
  from.x = player->pos.x;
  from.y = player->pos.y;
  if (!color.r && !color.g && color.b == 255 && from.y < 500 && map->veleda)
    {
      map->veleda = 0;
      needs->current_veleda--;
    }
  if (check_path(map, from, to) != 0)
    return (to);
  to.x = player->pos.x;
  to.y = player->pos.y;
  return (to);
}

sfVector2i		move_player(t_char *player, sfVector2i from,
				    sfVector2i to, int reset)
{
  sfVector2i		delta;
  static sfVector2i	err;

  delta.y = abs(to.y - from.y);
  delta.x = abs(to.x - from.x);
  if (reset)
    {
      err.x = (delta.x > delta.y ? delta.x : -delta.y) / 2;
      return (from);
    }
  err.y = err.x;
  if (err.y > -delta.x)
    {
      err.x -= delta.y;
      from.x += (from.x < to.x) ? 1 : -1;
    }
  if (err.y < delta.y)
    {
      err.x += delta.x;
      from.y += (from.y < to.y) ? 1 : -1;
    }
  player_refresh(player->sprite, player->pos, from, to);
  return (from);
}

void		get_player_move(t_needs *needs, sfVector2i to)
{
  t_char	*player;
  sfVector2i	pos;
  sfColor	color;

  player = needs->player[needs->current_player];
  pos.x = player->pos.x;
  pos.y = player->pos.y;
  if (pos.x != to.x || pos.y != to.y)
    pos = move_player(player, pos, to, 0);
  else
    pos = move_player(player, pos, to, 1);
  player->pos.x = pos.x;
  player->pos.y = pos.y;
  sfSprite_setPosition(player->sprite, player->pos);
  color = sfImage_getPixel(needs->map[needs->current_map]->image,
			   pos.x, pos.y);
  if (color.r == 255 && color.g == 0)
    needs->current_map = 0;
}

int		room_main(t_needs *needs, int *check)
{
  sfEvent	event;
  sfVector2i	to;

  change_sprite(needs, 0);
  to.x = needs->player[needs->current_player]->pos.x + 1;
  to.y = needs->player[needs->current_player]->pos.y;
  *check = check_map_boss(needs, to);
  while (needs->current_map && !*check && sfRenderWindow_isOpen(needs->window))
    {
      refresh_room(needs, 0);
      while (sfRenderWindow_pollEvent(needs->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(needs->window);
	  if (event.type == sfEvtMouseButtonPressed &&
	      event.mouseButton.button == sfMouseLeft)
	    to = room_move(needs, event);
	}
      get_player_move(needs, to);
    }
  change_sprite(needs, 1);
  return (1);
}

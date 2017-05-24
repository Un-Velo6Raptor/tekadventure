/*
** loop_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:18:19 2017 Martin Januario
** Last update Wed May 24 16:08:45 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"

static sfVector2i	check_move_map(sfVector2i to, t_needs *needs, sfVector2i from,
				       sfVector2i last)
{
  sfIntRect		rect;

  rect = sfSprite_getTextureRect(needs->sprite);
  to.x += rect.left;
  to.y += rect.top ;
  if (check_path(&needs->map, from, to) != 0)
      return (to);
  return (last);
}

static sfVector2i	get_map_move(sfSprite *map, sfVector2i from, sfVector2i to,
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
      player_refresh(player, vector_2f(418, 418), from, tmp);
      move_map(map, from, tmp, 1);
    }
  from.x += WIDTH / 2;
  from.y += HEIGHT / 2;
  return (from);
}

int                     loop_game(t_mode_game __attribute__ ((unused))  *mode, t_needs *needs)
{
  sfVector2i		pos;
  sfVector2i		to;
  sfEvent               event;
  sfSprite		*sprite;
  sfTexture		*texture;

  pos = vector_2i(138, 1476);
  to = vector_2i(138, 1476);
  needs->texture = sfTexture_createFromFile("ressources/map/map.png", NULL);
  texture = sfTexture_createFromFile("magic_mike_tek_ad.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setTexture(needs->sprite, needs->texture, sfTrue);
  update_rect(needs->sprite, vector_2i(pos.x - WIDTH / 2, pos.y - HEIGHT / 2));
  while (sfRenderWindow_isOpen(needs->window))
    {
      player_refresh(sprite, vector_2f(418, 418), pos, to);
      sfRenderWindow_clear(needs->window, sfBlack);
      while (sfRenderWindow_pollEvent(needs->window, &event))
        {
          if (event.type == sfEvtClosed ||
              sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(needs->window);
	  if (event.type == sfEvtMouseButtonPressed &&
              event.mouseButton.button == sfMouseLeft)
	    to = check_move_map(vector_2i(event.mouseButton.x, event.mouseButton.y),
				needs, pos, to);
	}
      pos = get_map_move(needs->sprite, pos, to, sprite);
      sfRenderWindow_drawSprite(needs->window, needs->sprite, NULL);
      sfRenderWindow_drawSprite(needs->window, sprite, NULL);
      sfRenderWindow_display(needs->window);
    }
  sfRenderWindow_destroy(needs->window);
  return (0);
}

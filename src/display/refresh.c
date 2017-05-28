/*
** refresh.c for tekadventure in /home/heychsea/MUL/tekadventure/refresh
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon May 22 14:43:49 2017 Hugo Cousin
** Last update Sat May 27 18:06:05 2017 Hugo Cousin
*/

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		"refresh.h"
#include		"lib.h"
#include		"display.h"

static void		update_keep(t_refresh *keep, sfSprite *sprite,
				    int mode)
{
  sfIntRect		rect;

  rect.left = 0;
  rect.top = mode * SPRITE_H;
  rect.width = SPRITE_W;
  rect.height = SPRITE_H;
  keep->sprite = sprite;
  keep->mode = mode;
  keep->rect = rect;
  keep->step = 0;
}

static t_refresh	**init_keep(sfSprite *sprite, int mode,
				    t_refresh **ptr)
{
  t_refresh		**keep;
  t_refresh		*elm;

  keep = malloc(sizeof(t_refresh *) * 2);
  if (!keep)
    return (NULL);
  elm = malloc(sizeof(t_refresh));
  if (!elm)
    return (NULL);
  update_keep(elm, sprite, mode);
  keep[0] = elm;
  keep[1] = NULL;
  *ptr = keep[0];
  return (keep);
}

static t_refresh	**expand(t_refresh **keep, sfSprite *sprite, int mode)
{
  size_t		size;
  t_refresh		*elm;

  size = 0;
  while (keep[size])
    size++;
  keep = my_realloc(keep, sizeof(t_refresh *) * size,
		    sizeof(t_refresh *) * (size + 2));
  if (!keep)
    return (NULL);
  elm = malloc(sizeof(t_refresh));
  if (!elm)
    return (NULL);
  update_keep(elm, sprite, mode);
  keep[size] = elm;
  keep[size + 1] = NULL;
  return (keep);
}

static t_refresh	**update_tab(t_refresh **keep,
				     sfSprite *sprite,
				     int mode,
				     t_refresh **ptr)
{
  size_t		index;

  index = 0;
  while (keep[index])
    {
      if (keep[index]->sprite == sprite)
	{
	  if (keep[index]->mode != mode)
	    update_keep(keep[index], sprite, mode);
	  *ptr = keep[index];
	  return (keep);
	}
      index++;
    }
  keep = expand(keep, sprite, mode);
  *ptr = keep[index];
  return (keep);
}

void			refresh_sprite(sfSprite *sprite,
				       sfVector2f pos,
				       int mode,
				       int step)
{
  static t_refresh	**keep = NULL;
  static t_refresh	*ptr = NULL;

  if (!keep)
    keep = init_keep(sprite, mode, &ptr);
  else
    keep = update_tab(keep, sprite, mode, &ptr);
  ptr->rect.left = SPRITE_W * (int)ptr->step;
  ptr->step += 0.1;
  if (ptr->step >= step)
    ptr->step = 0;
  sfSprite_setTextureRect(sprite, ptr->rect);
  sfSprite_setPosition(sprite, pos);
}

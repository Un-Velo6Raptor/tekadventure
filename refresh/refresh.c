/*
** refresh.c for tekadventure in /home/heychsea/MUL/tekadventure/refresh
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Mon May 22 14:43:49 2017 Hugo Cousin
** Last update Mon May 22 15:40:57 2017 Hugo Cousin
*/

#include		<SFML/Graphics.h>
#include		"refresh.h"

void			update_keep(t_refresh *keep, sfSprite *sprite,
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

void			refresh_sprite(sfSprite *sprite,
				       sfVector2f pos,
				       int mode,
				       int step)
{
  static t_refresh	keep = {NULL, {0, 0, 0, 0}, 0, 0};

  if (sprite != keep.sprite || mode != keep.mode)
    update_keep(&keep, sprite, mode);
  keep.rect.left = SPRITE_W * keep.step;
  keep.step++;
  if (keep.step >= step)
    keep.step = 0;
  sfSprite_setTextureRect(sprite, keep.rect);
  sfSprite_setPosition(sprite, pos);
}

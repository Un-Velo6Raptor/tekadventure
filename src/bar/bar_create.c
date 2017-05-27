/*
** bar_create.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 24 16:15:11 2017 Martin Januario
** Last update Sat May 27 23:39:08 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	<time.h>
#include	"bar.h"
#include	"game.h"

static int			ini_sprite_bar(sfSprite **sprite,
					       t_framebuffer **pattern,
					       sfSprite **cursor)
{
  sfTexture			*tmp;

  *sprite = sfSprite_create();
  *cursor = sfSprite_create();
  if (*sprite == NULL || *cursor == NULL)
    return (84);
  tmp = sfTexture_createFromFile("ressources/bar/bar.png", NULL);
  if (tmp == NULL)
    return (84);
  sfSprite_setTexture(*sprite, tmp, sfTrue);
  tmp = sfTexture_createFromFile("ressources/bar/stick.png", NULL);
  if (tmp == NULL)
    return (84);
  sfSprite_setTexture(*cursor, tmp, sfTrue);
  sfSprite_setPosition(*sprite, vector_2f(((WIDTH - 620) / 2), 650));
  sfSprite_setPosition(*cursor, vector_2f(((WIDTH - 620) / 2 + 15), 735));
  *pattern = framebuffer_create(WIDTH, HEIGHT);
  if (*pattern == NULL)
    return (84);
  return (0);
}

static void		update_dir_bar(int *c_moove,
				       int *move, sfSprite *cursor)
{
  if (*move >= 550)
    *c_moove = -1;
  if (*move <= 0)
    *c_moove = 1;
  sfSprite_setPosition(cursor, vector_2f(((WIDTH - 620) / 2 + 15 + *move),
					 735));
  *move += *c_moove;
}

static int		ini_color_bar(t_needs *needs, sfTexture **tr,
				      sfSprite **tmp)
{
  *tr = sfTexture_create(WIDTH, HEIGHT);
  *tmp = sfSprite_create();
  if (*tr == NULL || *tmp == NULL)
    return (84);
  sfRenderWindow_setFramerateLimit(needs->window, 1000);
  sfSprite_setTexture(*tmp, *tr, sfTrue);
  return (1);
}

int			bar_create(t_needs *needs, int diff)
{
  static sfSprite	*design = NULL;
  static t_framebuffer	*pattern = NULL;
  static sfSprite	*cursor = NULL;
  sfTexture		*tr;
  sfSprite		*tmp;
  int			move;
  int			c_moove;

  move = ini_sprite_bar(&design, &pattern, &cursor);
  c_moove = ini_color_bar(needs, &tr, &tmp);
  if (move == 84 || c_moove == 84)
    return (0);
  fill_square(pattern, diff);
  sfSprite_setPosition(cursor, vector_2f(((WIDTH - 620) / 2 + 15), 735));
  sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, sfWhite);
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	return (is_on_green(needs, pattern, (WIDTH - 620) / 2 + 15 + move));
      update_dir_bar(&c_moove, &move, cursor);
      sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
      update_sprite_bar(needs, tmp, design, cursor);
    }
  return (0);
}

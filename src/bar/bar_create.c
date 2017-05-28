/*
** bar_create.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 24 16:15:11 2017 Martin Januario
** Last update Sun May 28 20:32:20 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<time.h>
#include	"bar.h"
#include	"game.h"
#include	"refresh.h"

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

void		update_dir_bar(int *c_moove,
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
  if ((*tr = sfTexture_create(WIDTH, HEIGHT)) == NULL ||
      (*tmp = sfSprite_create()) == NULL)
    return (84);
  sfRenderWindow_setFramerateLimit(needs->window, 1000);
  sfSprite_setTexture(*tmp, *tr, sfTrue);
  return (1);
}

int			bar_create(t_needs *needs, int diff,
				   sfVector2i __attribute__ ((unused)) to,
				   int opt)
{
  static sfSprite	*design = NULL;
  static t_framebuffer	*pattern = NULL;
  static sfSprite	*cursor = NULL;
  sfTexture		*tr;
  sfSprite		*tmp;
  int			move;
  int			c_moove;
  sfEvent		event;

  move = ini_sprite_bar(&design, &pattern, &cursor);
  c_moove = ini_color_bar(needs, &tr, &tmp);
  if (move == 84 || c_moove == 84)
    return (0);
  fill_square(pattern, diff);
  sfSprite_setPosition(cursor, vector_2f(((WIDTH - 620) / 2 + 15), 735));
  sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
  disp_boss_text(needs);
  while (sfRenderWindow_isOpen(needs->window))
    {
      disp_text_and_bar(needs, &move, &c_moove, cursor);
      choose_print(needs, tr, pattern, opt);
      update_sprite_bar(needs, tmp, design, cursor);
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	return (is_on_green(needs, pattern, (WIDTH - 620) / 2 + 15 + move));
      while (sfRenderWindow_pollEvent(needs->window, &event))
	if (event.type == sfEvtClosed ||
	    sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	  sfRenderWindow_close(needs->window);
    }
  return (0);
}

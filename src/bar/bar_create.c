/*
** bar_create.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 24 16:15:11 2017 Martin Januario
** Last update Sun May 28 19:34:31 2017 Sahel Lucas--Saoudi
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
  if ((*tr = sfTexture_create(WIDTH, HEIGHT)) == NULL ||
      (*tmp = sfSprite_create()) == NULL)
    return (84);
  sfRenderWindow_setFramerateLimit(needs->window, 1000);
  sfSprite_setTexture(*tmp, *tr, sfTrue);
  return (1);
}

static void		disp_player_boss(t_needs *needs)
{
  sfSprite_setPosition(needs->player[needs->current_player]->sprite,
		       vector_2f(100, 770));
  sfSprite_setScale(needs->player[needs->current_player]->sprite,
		    vector_2f(13.5, 13.5));
  sfSprite_setPosition(needs->boss[needs->map[needs->current_map]->boss]
		       ->sprite, vector_2f(800, -100));
  sfSprite_setScale(needs->boss[needs->map[needs->current_map]->boss]
		    ->sprite, vector_2f(13.5, 13.5));
}

static void		display_mike(t_needs *needs)
{
  sfRenderWindow_drawSprite(needs->window, needs->boss[0]->select, NULL);
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

  if ((move = ini_sprite_bar(&design, &pattern, &cursor)) == 84 ||
      (c_moove = ini_color_bar(needs, &tr, &tmp)) == 84)
    return (0);
  fill_square(pattern, diff);
  sfSprite_setPosition(cursor, vector_2f(((WIDTH - 620) / 2 + 15), 735));
  sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
  disp_player_boss(needs);
  print_text(needs);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, sfWhite);
      refresh_room(needs, 1);
      if (needs->texte != NULL)
	sfRenderWindow_drawText(needs->window, needs->texte, NULL);
      update_dir_bar(&c_moove, &move, cursor);
      sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
      if (opt == 0)
	display_fight(needs);
      else
	display_mike(needs);
      update_sprite_bar(needs, tmp, design, cursor);
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue ||
	  sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	return (is_on_green(needs, pattern, (WIDTH - 620) / 2 + 15 + move));
    }
  return (0);
}

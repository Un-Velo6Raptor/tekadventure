/*
** select_player.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 17:08:39 2017 Martin Januario
** Last update Thu May 25 23:29:49 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"select.h"

static void	display_select(t_needs *needs, sfSprite **sprite)
{
  int		idx;

  idx = 0;
  while (sprite[idx] != NULL)
    {
      sfRenderWindow_drawSprite(needs->window, sprite[idx], NULL);
      idx++;
    }
  sfRenderWindow_display(needs->window);
}

static sfSprite	*create_sprite(char *path)
{
  sfTexture		*texture;
  sfSprite              *tmp;

  tmp = sfSprite_create();
  if (tmp == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfSprite_setTexture(tmp, texture, sfTrue);
  return (tmp);
}

static sfSprite	**ini_sprite_select(t_needs *needs)
{
  sfSprite	**sprite;
  int		idx;
  int		tmp;

  idx = 0;
  sprite = malloc(sizeof(sfSprite *) * 8);
  if (sprite == NULL)
    return (NULL);
  sprite[0] = create_sprite("ressources/character/plage.jpg");
  sprite[1] = create_sprite("ressources/character/hugo_select.png");
  sprite[2] = create_sprite("ressources/character/charlotte_select.png");
  sprite[3] = create_sprite("ressources/character/martin_select.png");
  sprite[4] = create_sprite("ressources/character/sahel_select.png");
  sprite[5] = create_sprite("ressources/character/select_title.png");
  sprite[6] = create_sprite("ressources/character/confirm.png");
  sprite[7] = NULL;
  while (sprite[idx] != NULL)
    {
      tmp = (idx != 2 && idx != 3) ? (250) : (300);
      sfSprite_setPosition(sprite[idx], vector_2f((idx - 1) * 200 + 20 *
						  (idx - 1) + 20, tmp));
      idx++;
    }
  if (idx != 7)
    return (NULL);
  place_select(sprite);
  return (sprite);
}

int		select_player(t_needs *needs, t_mode_game *mode)
{
  sfSprite	**sprite;
  sfEvent	event;
  int		current;
  int		tmp;

  current = 0;
  tmp = 0;
  if ((sprite = ini_sprite_select(needs)) == NULL)
    return (0);
  while (sfRenderWindow_isOpen(needs->window) && current != -1)
    {
      sfRenderWindow_clear(needs->window, sfBlack);
      while (sfRenderWindow_pollEvent(needs->window, &event))
	{
	  tmp = current;
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(needs->window);
	  else if (event.type == sfEvtMouseButtonPressed &&
		   event.mouseButton.button == sfMouseLeft)
	    current = click_select(vector_2i(event.mouseButton.x,
					     event.mouseButton.y), needs);
	}
      display_select(needs, sprite);
    }
  return (tmp);
}

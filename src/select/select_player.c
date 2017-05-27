/*
** select_player.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Thu May 25 17:08:39 2017 Martin Januario
** Last update Sat May 27 22:41:15 2017 Sahel Lucas--Saoudi
*/

#include	<stdlib.h>
#include	"select.h"
#include	"lib.h"

static char	*center_text(char *name)
{
  char		*tmp;

  tmp = malloc(10);
  if (tmp == NULL)
    return (name);
  my_strncpy(tmp, "                 ", 6 - my_strlen(name));
  my_strcat(tmp, name);
  return (tmp);
}

static void	display_select(t_needs *needs, sfSprite **sprite, int opt)
{
  sfFont	*font;
  sfText	*text;
  int		idx;

  idx = 0;
  font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
  text = sfText_create();
  while (sprite[idx] != NULL)
    {
      sfRenderWindow_drawSprite(needs->window, sprite[idx], NULL);
      idx++;
    }
  if (opt >= 0 && font != NULL && text != NULL)
    {
      sfText_setString(text, center_text(needs->player[opt]->name));
      sfText_setFont(text, font);
      sfText_setCharacterSize(text, 80);
      sfText_setColor(text, sfBlack);
      sfText_setPosition(text, vector_2f(320, 600));
    }
  sfRenderWindow_drawText(needs->window, text, NULL);
  sfRenderWindow_display(needs->window);
}

static sfSprite	**ini_sprite_select(t_needs *needs)
{
  sfSprite	**sprite;
  int		idx;
  int		tmp;

  idx = 0;
  sprite = set_sprite(needs);
  if (sprite == NULL)
    return (NULL);
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

static void	event_handler(t_needs *needs, int *current, int *tmp)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(needs->window, &event))
    {
      *tmp = *current;
      if (event.type == sfEvtClosed ||
	  sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(needs->window);
      else if (event.type == sfEvtMouseButtonPressed &&
	       event.mouseButton.button == sfMouseLeft)
	*current = click_select(vector_2i(event.mouseButton.x,
					 event.mouseButton.y), needs, *tmp);
    }
}

int		select_player(t_needs *needs)
{
  sfSprite	**sprite;
  int		current;
  int		tmp;

  current = -2;
  tmp = -1;
  sprite = ini_sprite_select(needs);
  if (!sprite)
    return (0);
  while (sfRenderWindow_isOpen(needs->window) && current != -1)
    {
      sfRenderWindow_clear(needs->window, sfBlack);
      event_handler(needs, &current, &tmp);
      display_select(needs, sprite, current);
    }
  if (tmp <= -1)
    return (0);
  return (tmp);
}

/*
** select_player.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Thu May 25 17:08:39 2017 Martin Januario
** Last update Sun May 28 22:59:30 2017 Hugo Cousin
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
  sfText	*text;
  int		idx;
  sfFont	*font;

  idx = 0;
  text = sfText_create();
  font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
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
  sfText_destroy(text);
  sfFont_destroy(font);
}

static int	event_select(t_needs *needs, sfEvent event, int current,
			     int *tmp)
{
  while (sfRenderWindow_pollEvent(needs->window, &event))
    {
      *tmp = current;
      if (event.type == sfEvtClosed ||
	  sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(needs->window);
      else if (event.type == sfEvtMouseButtonPressed &&
	       event.mouseButton.button == sfMouseLeft)
	current = click_select(vector_2i(event.mouseButton.x,
					 event.mouseButton.y),
			       needs, *tmp);
    }
  return (current);
}

int		select_player(t_needs *needs)
{
  sfSprite	**sprite;
  sfEvent	event;
  int		current;
  int		tmp;

  tmp = -2;
  sprite = ini_sprite_select(needs);
  if (!sprite)
    return (0);
  while (tmp == -2 && sfRenderWindow_isOpen(needs->window))
    {
      tmp = -2;
      current = -2;
      while (sfRenderWindow_isOpen(needs->window) && current != -1)
	{
	  sfRenderWindow_clear(needs->window, sfBlack);
	  current = event_select(needs, event, current, &tmp);
	  display_select(needs, sprite, current);
	}
    }
  if (tmp <= -1)
    return (0);
  return (tmp);
}

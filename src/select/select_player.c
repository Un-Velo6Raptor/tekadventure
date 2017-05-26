/*
** select_player.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 17:08:39 2017 Martin Januario
** Last update Fri May 26 22:08:09 2017 Martin Januario
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
  sprite[1] = needs->player[2]->select;
  sprite[2] = needs->player[1]->select;
  sprite[3] = needs->player[0]->select;
  sprite[4] = needs->player[3]->select;
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

int		select_player(t_needs *needs)
{
  sfSprite	**sprite;
  sfEvent	event;
  int		current;
  int		tmp;

  current = -2;
  tmp = -1;
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
					     event.mouseButton.y), needs, tmp);
	}
      display_select(needs, sprite, current);
    }
  return ((tmp <= -1) ? 0 : tmp);
}

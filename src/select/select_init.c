/*
** select_init.c for tekadventure in /home/heychsea/MUL/tekadventure/src/select
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Sun May 28 19:51:04 2017 Hugo Cousin
** Last update Sun May 28 20:28:42 2017 Hugo Cousin
*/

#include	<stdlib.h>
#include	"display.h"
#include	"select.h"

sfSprite	*create_sprite(char *path)
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

static void	fill_tab(t_needs *needs, sfSprite **sprite)
{
  sprite[0] = create_sprite("ressources/character/plage.jpg");
  sprite[1] = needs->player[2]->select;
  sprite[2] = needs->player[1]->select;
  sprite[3] = needs->player[0]->select;
  sprite[4] = needs->player[3]->select;
  sprite[5] = create_sprite("ressources/character/select_title.png");
  sprite[6] = create_sprite("ressources/character/confirm.png");
  sprite[7] = NULL;
}

sfSprite	**ini_sprite_select(t_needs *needs)
{
  sfSprite	**sprite;
  int		idx;
  int		tmp;

  idx = 0;
  sprite = malloc(sizeof(sfSprite *) * 8);
  if (sprite == NULL)
    return (NULL);
  fill_tab(needs, sprite);
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

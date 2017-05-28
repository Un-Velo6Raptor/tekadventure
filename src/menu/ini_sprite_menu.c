/*
** ini_sprite_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 16:58:33 2017 Martin Januario
** Last update Fri May 26 12:12:16 2017 Martin Januario
*/

#include	"menu.h"

static sfSprite		*create_sprite(t_core __attribute__ ((unused)) *core,
					  t_sprite_menu *menu_sprite,
					  char *path, int idx)
{
  sfSprite		*tmp;

  tmp = sfSprite_create();
  if (tmp == NULL)
    return (NULL);
  menu_sprite->m_texture[idx] = sfTexture_createFromFile(path, NULL);
  if (menu_sprite->m_texture[idx] == NULL)
    return (NULL);
  sfSprite_setTexture(tmp, menu_sprite->m_texture[idx], sfTrue);
  return (tmp);
}

static int		check_sprite(t_sprite_menu *menu_sprite)
{
  int			idx;

  idx = 0;
  while (menu_sprite->m_sprite[idx] != NULL)
    idx++;
  if (idx != MAX_SPRITE_MENU)
    return (84);
  return (0);
}

int			ini_sprite_menu(t_sprite_menu *menu_sprite,
					t_core *core)
{
  menu_sprite->m_sprite[TITLE_M] = create_sprite(core, menu_sprite,
					      "ressources/menu/title.png", 0);
  menu_sprite->m_sprite[BUTTON_PLAY] = create_sprite(core, menu_sprite,
					      "ressources/menu/button_play.png",
						 0);
  menu_sprite->m_sprite[MAX_SPRITE_MENU] = NULL;
  return (check_sprite(menu_sprite));
}

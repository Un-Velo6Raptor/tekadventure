/*
** place_sprite_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 18:36:48 2017 Martin Januario
** Last update Sat May 20 16:52:03 2017 Martin Januario
*/

#include	"menu.h"

static void	place_title_menu(t_sprite_menu *menu_sprite)
{
  sfSprite_setScale(menu_sprite->m_sprite[TITLE_M], vector_2f(1.10f, 1.10f));
  sfSprite_setPosition(menu_sprite->m_sprite[TITLE_M],
		       vector_2f(-50.0f, 60.0f));
}

static void	place_button_play(t_sprite_menu *menu_sprite)
{
  sfSprite_setScale(menu_sprite->m_sprite[BUTTON_PLAY],
		    vector_2f(0.80f, 0.80f));
  sfSprite_setPosition(menu_sprite->m_sprite[BUTTON_PLAY],
  		       vector_2f(530.0f, 300.0f));
}

void		place_sprite_menu(t_sprite_menu *menu_sprite)
{
  place_title_menu(menu_sprite);
  place_button_play(menu_sprite);
}

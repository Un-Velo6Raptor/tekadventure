/*
** draw_sprite_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 18:19:41 2017 Martin Januario
** Last update Sat May 20 16:47:30 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"menu.h"

static void	draw_diff_menu(t_core *core, t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfRenderWindow_drawText(core->window, menu_text->title_diff, NULL);
  while (menu_text->diff[idx] != NULL)
    {
      sfRenderWindow_drawText(core->window, menu_text->diff[idx], NULL);
      idx++;
    }
}

static void	draw_lang_menu(t_core *core, t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfRenderWindow_drawText(core->window, menu_text->title_lang, NULL);
  while (menu_text->lang[idx] != NULL)
    {
      sfRenderWindow_drawText(core->window, menu_text->lang[idx], NULL);
      idx++;
    }
}

static void	draw_keyboard_menu(t_core *core, t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfRenderWindow_drawText(core->window, menu_text->title_key, NULL);
  while (menu_text->keyboard[idx] != NULL)
    {
      sfRenderWindow_drawText(core->window, menu_text->keyboard[idx], NULL);
      idx++;
    }
}

static void	draw_sound_menu(t_core *core, t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfRenderWindow_drawText(core->window, menu_text->title_sound, NULL);
  while (menu_text->sound[idx] != NULL)
    {
      sfRenderWindow_drawText(core->window, menu_text->sound[idx], NULL);
      idx++;
    }
}

void		draw_sprite_menu(t_sprite_menu *sprite, t_core *core,
				 t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  while (sprite->m_sprite[idx] != NULL)
    {
      sfRenderWindow_drawSprite(core->window, sprite->m_sprite[idx], NULL);
      idx++;
    }
  draw_diff_menu(core, menu_text);
  draw_lang_menu(core, menu_text);
  draw_keyboard_menu(core, menu_text);
  draw_sound_menu(core, menu_text);
}

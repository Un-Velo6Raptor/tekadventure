/*
** destroy_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Fri May 19 20:06:40 2017 Martin Januario
** Last update Sat May 27 22:06:22 2017 Sahel Lucas--Saoudi
*/

#include	"menu.h"

static void	destroy_menu_diff(t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfText_destroy(menu_text->title_diff);
  while (menu_text->diff[idx] != NULL)
    {
      sfText_destroy(menu_text->diff[idx]);
      idx++;
    }
}

static void	destroy_menu_text(t_text_menu *menu_text)
{
  int		idx;

  idx = 0;
  sfText_destroy(menu_text->title_lang);
  sfText_destroy(menu_text->title_key);
  sfText_destroy(menu_text->title_sound);
  while (menu_text->lang[idx] != NULL)
    {
      sfText_destroy(menu_text->lang[idx]);
      sfText_destroy(menu_text->sound[idx]);
      sfText_destroy(menu_text->keyboard[idx]);
      idx++;
    }
}

void		destroy_music(t_core *needs, int opt,
			      t_mode_game *mode)
{
  int		idx;

  idx = 0;
  while (needs->music[idx] != NULL)
    {
      if (idx != JOKE_MENU)
	{
	  sfMusic_destroy(needs->music[idx]);
	  needs->music[idx] = NULL;
	}
      idx++;
    }
  if (opt == 0)
    {
      sfMusic_destroy(needs->music[JOKE_MENU]);
      return ;
    }
  if (mode->sound == 0)
    sfMusic_play(needs->music[JOKE_MENU]);
  while (sfMusic_getStatus(needs->music[JOKE_MENU]) != sfStopped)
    (void) idx;
  sfMusic_destroy(needs->music[JOKE_MENU]);
  needs->music[JOKE_MENU] = NULL;
}

int		destroy_menu(t_core *needs, t_sprite_menu *menu_sprite,
			     t_text_menu *menu_text, t_mode_game *mode)
{
  int		idx;

  idx = 0;
  destroy_music(needs, 0, mode);
  while (menu_sprite->m_sprite[idx] != NULL)
    {
      sfSprite_destroy(menu_sprite->m_sprite[idx]);
      idx++;
    }
  destroy_menu_diff(menu_text);
  destroy_menu_text(menu_text);
  sfFont_destroy(menu_text->font);
  sfRenderWindow_destroy(needs->window);
  return (0);
}

/*
** gest_mouse_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat May 20 14:51:18 2017 Martin Januario
** Last update Sat May 20 21:58:20 2017 Martin Januario
*/

#include	<stdio.h>
#include	<math.h>
#include	"menu.h"

static void	mouse_diff(sfVector2i pos, t_mode_game *mode,
			   t_text_menu *menu_text, t_core *needs)
{
  sfText_setColor(menu_text->diff[mode->difficult], sfWhite);
  if (pos.x >= 75 && pos.x <= 201 && mode->difficult != 0)
    {
      stop_music_except_one(needs, (mode->sound == 0) ? EASY_MENU : -1);
      mode->difficult = 0;
    }
  else if (pos.x >= 277 && pos.x <= 469 && mode->difficult != 1)
    {
      stop_music_except_one(needs, (mode->sound == 0) ? NORMAL_MENU : -1);
      mode->difficult = 1;
    }
  else if (pos.x >= 545 && pos.x <= 682 && mode->difficult != 2)
    {
      stop_music_except_one(needs, (mode->sound == 0) ? HARD_MENU : -1);
      mode->difficult = 2;
    }
  sfText_setColor(menu_text->diff[mode->difficult], color(0, 255, 0));
}

static void	mouse_lang(sfVector2i pos, t_mode_game *mode,
			   t_text_menu *menu_text)
{
  sfText_setColor(menu_text->lang[mode->lang], sfWhite);
  if (pos.x >= 78 && pos.x <= 259)
    mode->lang = 0;
  else if (pos.x >= 277 && pos.x <= 459)
    mode->lang = 1;
  sfText_setColor(menu_text->lang[mode->lang], color(0, 255, 0));
}

static void	mouse_keyboard(sfVector2i pos, t_mode_game *mode,
			       t_text_menu *menu_text)
{
  sfText_setColor(menu_text->keyboard[mode->keyboard], sfWhite);
  if (pos.x >= 78 && pos.x <= 259)
    mode->keyboard = 0;
  else if (pos.x >= 277 && pos.x <= 459)
    mode->keyboard = 1;
  sfText_setColor(menu_text->keyboard[mode->keyboard], color(0, 255, 0));
}

static void	mouse_sound(sfVector2i pos, t_mode_game *mode,
			    t_text_menu *menu_text, t_core *needs)
{
  sfText_setColor(menu_text->sound[mode->sound], sfWhite);
  if (pos.x >= 79 && pos.x <= 175)
    music_play_menu(mode, needs);
  else if (pos.x >= 277 && pos.x <= 353)
    music_stop_menu(mode, needs);
  sfText_setColor(menu_text->sound[mode->sound], color(0, 255, 0));
}

void		gest_mouse_menu(t_mode_game *mode, sfEvent *event,
				t_text_menu *menu_text, t_core *needs)
{
  sfVector2i	pos;
  float		result;

  pos = vector_2i(event->mouseButton.x, event->mouseButton.y);
  if (pos.y >= 291 && pos.y <= 337)
    mouse_diff(pos, mode, menu_text, needs);
  else if (pos.y >= 433 && pos.y <= 480)
    mouse_lang(pos, mode, menu_text);
  else if (pos.y >= 567 && pos.y <= 624)
    mouse_keyboard(pos, mode, menu_text);
  else if (pos.y >= 709 && pos.y <= 755)
    mouse_sound(pos, mode, menu_text, needs);
  result = powf((pos.x - 764), 2.0f) + powf(pos.y - 541, 2.0f);
  if (result <= 36000.0f)
    {
      mode->play = 1;
      destroy_music(needs, 1, mode);
      sfRenderWindow_close(needs->window);
    }
}

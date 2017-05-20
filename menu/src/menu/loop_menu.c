/*
** loop_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 16:39:40 2017 Martin Januario
** Last update Sat May 20 21:07:10 2017 Martin Januario
*/

#include	"lib.h"
#include	"menu.h"

int			loop_menu(t_mode_game *mode, t_core *needs)
{
  t_text_menu		menu_text;
  t_sprite_menu		menu_sprite;	
  sfEvent		event;

  if (ini_sprite_menu(&menu_sprite, needs) == 84 ||
      ini_text_menu(&menu_text, needs) == 84 ||
      ini_music_menu(needs) == 84)
    return (my_puterror("Error while loading the library.\n"));
  place_sprite_menu(&menu_sprite);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, color(175, 167, 123));
      while (sfRenderWindow_pollEvent(needs->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(needs->window);
	  if (event.type == sfEvtMouseButtonPressed &&
	      event.mouseButton.button == sfMouseLeft)
	    gest_mouse_menu(mode, &event, &menu_text, needs);
	}
      draw_sprite_menu(&menu_sprite, needs, &menu_text);
      sfRenderWindow_display(needs->window);
    }
  return (destroy_menu(needs, &menu_sprite, &menu_text, mode));
}

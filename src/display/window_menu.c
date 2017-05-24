/*
** window_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 16:25:38 2017 Martin Januario
** Last update Sat May 20 17:31:51 2017 Martin Januario
*/

#include	"lib.h"
#include	"menu.h"

int		window_menu(t_mode_game *mode)
{
  t_core	needs;

  mode->difficult = 1;
  mode->lang = 0;
  mode->keyboard = 0;
  mode->sound = 0;
  mode->play = 0;
  needs.window = create_window("Menu <-> Move Backward.", WIDTH, HEIGHT);
  if (needs.window == NULL)
    return (my_puterror("Can't create the window.\n"));
  needs.sprite = sfSprite_create();
  needs.texture = NULL;
  return (loop_menu(mode, &needs));
}

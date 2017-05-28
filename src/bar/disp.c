/*
** disp.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sun May 28 20:13:48 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 20:14:52 2017 Sahel Lucas--Saoudi
*/

#include        <stdlib.h>
#include        <time.h>
#include        "bar.h"
#include        "game.h"
#include        "refresh.h"

void             disp_player_boss(t_needs *needs)
{
  sfSprite_setPosition(needs->player[needs->current_player]->sprite,
                       vector_2f(100, 770));
  sfSprite_setScale(needs->player[needs->current_player]->sprite,
                    vector_2f(13.5, 13.5));
  sfSprite_setPosition(needs->boss[needs->map[needs->current_map]->boss]
                       ->sprite, vector_2f(800, -100));
  sfSprite_setScale(needs->boss[needs->map[needs->current_map]->boss]
                    ->sprite, vector_2f(13.5, 13.5));
}

void             display_mike(t_needs *needs)
{
  sfRenderWindow_drawSprite(needs->window, needs->boss[0]->select, NULL);
}

void    disp_text_and_bar(t_needs *needs,
                int *move,
                int *c_moove,
                sfSprite *cursor)
{
  sfRenderWindow_clear(needs->window, sfWhite);
  refresh_room(needs, 1);
  if (needs->texte)
    sfRenderWindow_drawText(needs->window, needs->texte, NULL);
  update_dir_bar(c_moove, move, cursor);
}

void    choose_print(t_needs *needs,
                     sfTexture *tr,
                     t_framebuffer *pattern,
                     int opt)
{
  sfTexture_updateFromPixels(tr, pattern->pixels, WIDTH, HEIGHT, 0, 0);
  if (opt == 0)
    display_fight(needs);
  else
    display_mike(needs);
}

void    disp_boss_text(t_needs *needs)
{
  disp_player_boss(needs);
  print_text(needs);
}

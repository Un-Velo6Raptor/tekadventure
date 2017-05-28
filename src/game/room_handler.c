/*
** room_handler.c for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sun May 28 21:08:32 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 21:14:56 2017 Sahel Lucas--Saoudi
*/

#include        "lib.h"
#include        "display.h"
#include        "refresh.h"
#include        "game.h"
#include        "boss.h"
#include        "anim.h"

void            get_player_move(t_needs *needs, sfVector2i to)
{
  t_char        *player;
  sfVector2i    pos;
  sfColor       color;

  player = needs->player[needs->current_player];
  pos.x = player->pos.x;
  pos.y = player->pos.y;
  if (pos.x != to.x || pos.y != to.y)
    pos = move_player(player, pos, to, 0);
  else
    pos = move_player(player, pos, to, 1);
  player->pos.x = pos.x;
  player->pos.y = pos.y;
  sfSprite_setPosition(player->sprite, player->pos);
  color = sfImage_getPixel(needs->map[needs->current_map]->image,
                           pos.x, pos.y);
  if (color.r == 255 && color.g == 0)
    needs->current_map = 0;
}

void            refresh_room(t_needs *needs, int opt)
{
  float         scale;

  sfRenderWindow_drawSprite(needs->window,
                            needs->map[needs->current_map]->map, NULL);
  if (opt != 1)
    {
      sfRenderWindow_drawSprite(needs->window,
                                needs->player[needs->current_player]->sprite,
                                NULL);
      display_status(needs);
      sfRenderWindow_display(needs->window);
      scale = (float)needs->player[needs->current_player]->pos.y / 200.0 + 1.5;
      sfSprite_setScale(needs->player[needs->current_player]->sprite,
                        vector_2f(scale, scale));
    }

}

#include        "lib.h"
#include        "display.h"
#include        "refresh.h"
#include        "game.h"
#include        "boss.h"
#include        "anim.h"

/*
** final_fight.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 11:36:31 2017 Martin Januario
** Last update Sun May 28 20:20:55 2017 Martin Januario
*/

#include	<stdio.h>
#include	"boss.h"
#include	"display.h"
#include	"anim.h"
#include	"bar.h"

static sfSprite	*create_theme(char *path, int opt)
{
  sfSprite	*tmp;
  sfTexture	*texture;

  tmp = sfSprite_create();
  if (tmp == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfSprite_setTexture(tmp, texture, sfTrue);
  if (opt == 1)
    sfSprite_setScale(tmp, vector_2f(2, 2));
  return (tmp);

}

static void	fight_mike(t_needs *needs)
{
  int		idx;
  int		save;
  int		cpt;

  idx = 0;
  save = -1;
  cpt = 0;
  if (needs->mode->sound == 0)
    {
      sfMusic_play(needs->boss[0]->music);
      sfMusic_setLoop(needs->boss[0]->music, sfTrue);
    }
  while (sfRenderWindow_isOpen(needs->window) && idx != 10)
    {
      if (cpt % 100000 == 0)
	{
	  save = idx;
	  idx += bar_create(needs, count_dead_player(needs),
			    vector_2i(0, 0), 1);
	}
      if (idx == save)
	{
	  launch_anim(needs->window, "ressources/defeat/",
		      needs->mode->sound, 1);
	  return ;
	}
      cpt++;
    }
  if (needs->mode->sound == 0)
    sfMusic_stop(needs->boss[0]->music);
  launch_anim(needs->window, "ressources/victory/", needs->mode->sound, 1);
}

static void	drawer(t_needs *needs, int tmpx, int tmpy, int idx)
{
  if (needs->player[idx]->death == 0)
    {
      player_refresh(needs->player[idx]->sprite,
		     vector_2f(tmpx, tmpy + 40 * idx),
		     vector_2i(100, 10), vector_2i(1000, 100));
      sfRenderWindow_drawSprite(needs->window,
				needs->player[idx]->sprite, NULL);
    }
}

static void	draw_player(t_needs *needs, sfMusic *music, int cpt)
{
  static int	tmpx = 110;
  static int	tmpy = 470;
  int		idx;

  idx = 0;
  while (idx < 4)
    {
      drawer(needs, tmpx, tmpy, idx);
      idx++;
    }
  sfRenderWindow_display(needs->window);
  if (cpt % 2 == 0)
    tmpx++;
  if (tmpx % 10 == 0)
    tmpy--;
  if (tmpx > 924)
    {
      if (needs->mode->sound == 0)
	sfMusic_stop(music);
      fight_mike(needs);
      sfRenderWindow_close(needs->window);
    }
}

void		final_fight(t_needs *needs)
{
  sfSprite	*back;
  sfMusic	*music;
  sfEvent	event;
  int		idx;

  idx = 0;
  music = sfMusic_createFromFile("ressources/ending/avance.ogg");
  back = create_theme("ressources/ending/back.jpg", 1);
  if (back == NULL || music == NULL)
    return ;
  if (needs->mode->sound == 0)
    sfMusic_play(music);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, sfWhite);
      while (sfRenderWindow_pollEvent(needs->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(needs->window);
	}
      sfRenderWindow_drawSprite(needs->window, back, NULL);
      draw_player(needs, music, idx);
      idx++;
    }
}

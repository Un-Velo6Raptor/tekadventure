/*
** display_fight.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 06:30:40 2017 Martin Januario
** Last update Sun May 28 16:57:59 2017 Martin Januario
*/

#include	<time.h>
#include	<stdlib.h>
#include	"display.h"
#include	"bar.h"
#include	"refresh.h"
#include	"funcs.h"

int		count_sentence(t_text *text)
{
  int		idx;

  idx = 0;
  while (text[idx].sentence != NULL)
    idx++;
  return (idx);
}

void		print_text(t_needs *needs)
{
  char		*tmp;
  sfFont	*font;
  int		cpt;

  srand(time(NULL));
  cpt = rand() % count_sentence(needs->boss[needs->map[needs->current_map]->boss]->phrase) - 1;
  if (cpt < 0)
    cpt = 0;
  if (needs->boss[needs->map[needs->current_map]->boss]->phrase[cpt].sentence == NULL)
    return ;
  tmp = concat(3, needs->boss[needs->map[needs->current_map]->boss]->name, ": ",
	       needs->boss[needs->map[needs->current_map]->boss]->phrase[cpt].sentence);
  if (tmp == NULL)
    return ;
  needs->texte = sfText_create();
  font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
  if (needs->texte == NULL || font == NULL)
    return ;
  sfText_setString(needs->texte, tmp);
  sfText_setFont(needs->texte, font);
  sfText_setCharacterSize(needs->texte, 30);
  sfText_setPosition(needs->texte, vector_2f(10, 0));
  sfText_setColor(needs->texte, sfBlack);
}

void		display_fight(t_needs *needs)
{
  sfIntRect	tmp;

  tmp = sfSprite_getTextureRect(needs->player[needs->current_player]->sprite);
  tmp.left = 0;
  tmp.top = RIGHT * SPRITE_H;
  sfSprite_setTextureRect(needs->player[needs->current_player]->sprite, tmp);
  sfRenderWindow_drawSprite(needs->window,
			    needs->boss[needs->map[needs->current_map]->boss]->sprite, NULL);
  sfRenderWindow_drawSprite(needs->window,
			    needs->player[needs->current_player]->sprite, NULL);
}

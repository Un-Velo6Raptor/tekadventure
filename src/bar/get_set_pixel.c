/*
** get_set_pixel.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 14:37:12 2017 Martin Januario
** Last update Sun May 28 19:12:50 2017 Hugo Cousin
*/

#include	<time.h>
#include	<stdlib.h>
#include	"bar.h"
#include	"game.h"
#include	"funcs.h"
#include	"display.h"

static void	print_text2(t_needs *needs)
{
  char		*tmp;
  sfFont	*font;
  int		cpt;

  srand(time(NULL));
  cpt = rand() % count_sentence(needs->player[needs->current_player]->phrase) - 1;
  if (cpt < 0)
    cpt = 0;
  if (needs->player[needs->current_player]->phrase[cpt].sentence == NULL)
    return ;
  tmp = concat(3, needs->player[needs->current_player]->name, ": ",
               needs->player[needs->current_player]->phrase[cpt].sentence);
  if (tmp == NULL)
    return ;
  needs->texte = sfText_create();
  font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
  if (needs->texte == NULL || font == NULL)
    return ;
  sfText_setString(needs->texte, tmp);
  sfText_setFont(needs->texte, font);
  sfText_setCharacterSize(needs->texte, 30);
  sfText_setPosition(needs->texte, vector_2f(10, 30));
  sfText_setColor(needs->texte, sfBlack);
}

int		is_on_green(t_needs *needs, t_framebuffer *frame_buffer, int pos)
{
  sfColor               color;
  int			idx;

  sfRenderWindow_setFramerateLimit(needs->window, 120);
  color.r = frame_buffer->pixels[(frame_buffer->width * 760 + (pos + 25)) * 4];
  color.g = frame_buffer->pixels[(frame_buffer->width * 760 + (pos + 25)) * 4 + 1];
  color.b = frame_buffer->pixels[(frame_buffer->width * 760 + (pos + 25)) * 4 + 2];
  color.a = frame_buffer->pixels[(frame_buffer->width * 760 + (pos + 25)) * 4 + 3];
  idx = 1;
  if (color.g == 255)
    {
      print_text2(needs);
      if (sfRenderWindow_isOpen(needs->window))
	{
	  sfRenderWindow_drawText(needs->window, needs->texte, NULL);
	  sfRenderWindow_display(needs->window);
	}
      while (idx > 0)
	idx++;
      return (1);
    }
  return (0);
}

void		my_put_pixel(t_framebuffer *frame_buffer, int x, int y,
			     sfColor color)
{
  if (x >= 0 && y >= 0 && x < frame_buffer->width && y < frame_buffer->height)
    {
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4] = color.r;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 1] = color.g;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 2] = color.b;
      frame_buffer->pixels[(frame_buffer->width * y + x) * 4 + 3] = color.a;
    }
}

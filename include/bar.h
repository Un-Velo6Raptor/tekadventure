/*
** bar.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 24 16:15:38 2017 Martin Januario
** Last update Sun May 28 17:02:54 2017 Martin Januario
*/

#ifndef		BAR_H_
# define	BAR_H_

# include	"display.h"
# include	"game.h"
# include	"framefuffer.h"

void		reset_frame(t_framebuffer *);
t_framebuffer	*framebuffer_create(int, int);
int		is_on_green(t_needs *, t_framebuffer *, int);
void		my_put_pixel(t_framebuffer *, int, int, sfColor);
void		fill_square(t_framebuffer *, int);
int		bar_create(t_needs *, int, sfVector2i, int);
void		update_sprite_bar(t_needs *, sfSprite *, sfSprite *, sfSprite *);
void		refresh_room(t_needs *, int);
void		display_fight(t_needs *);
void		print_text(t_needs *);
int		count_sentence(t_text *);

#endif		/* !BAR_H_ */

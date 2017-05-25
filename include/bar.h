/*
** bar.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 24 16:15:38 2017 Martin Januario
** Last update Thu May 25 16:03:30 2017 Martin Januario
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
int		bar_create(t_needs *, int);
void		update_sprite_bar(t_needs *, sfSprite *, sfSprite *, sfSprite *);

#endif		/* !BAR_H_ */

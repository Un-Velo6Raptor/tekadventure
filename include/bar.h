/*
** bar.h for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 24 16:15:38 2017 Martin Januario
** Last update Sun May 28 20:20:12 2017 Sahel Lucas--Saoudi
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
void		update_sprite_bar(t_needs *, sfSprite *, sfSprite *,
				  sfSprite *);
void		refresh_room(t_needs *, int);
void		display_fight(t_needs *);
void		print_text(t_needs *);
int		count_sentence(t_text *);
void		disp_player_boss(t_needs *);
void		display_mike(t_needs *);
void		disp_text_and_bar(t_needs *, int *, int *, sfSprite *);
void		choose_print(t_needs *, sfTexture *, t_framebuffer *, int);
void		disp_boss_text(t_needs *);
void		update_dir_bar(int *, int *, sfSprite *);

#endif		/* !BAR_H_ */

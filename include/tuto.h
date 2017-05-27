/*
** tuto.h for  in /home/romain.melin/delivery/Graphics/tekad
**
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
**
** Started on  Thu May 25 11:40:35 2017 Romain Melin
** Last update Sat May 27 22:05:07 2017 Sahel Lucas--Saoudi
*/

#ifndef		TUTO_H_
# define	TUTO_H_

# include	<SFML/Graphics.h>
# include	"display.h"

# ifndef	SCREEN_WIDTH
#  define	SCREEN_WIDTH 1163
# endif		/* !SCREEN_WIDTH */

# ifndef	SCREEN_HEIGHT
#  define	SCREEN_HEIGHT 800
# endif		/* !SCREEN_HEIGHT */

sfTexture	**load_image();
void		my_sleep();
void		is_closed(sfRenderWindow *);
void		free_image(sfTexture **);
int		tuto(t_mode_game);

#endif		/* !TUTO_H_ */

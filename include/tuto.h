/*
** tuto.h for  in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Thu May 25 11:40:35 2017 Romain Melin
** Last update Sun May 28 21:21:04 2017 Hugo Cousin
*/

#ifndef	TUTO_H_
# define TUTO_H_

# include	<SFML/Graphics.h>
# include	"display.h"

sfTexture	**load_image();
void		my_sleep();
void		is_closed(sfRenderWindow *);
void		free_image(sfTexture **);
int		tuto(t_mode_game);

#endif		/* !TUTO_H_ */

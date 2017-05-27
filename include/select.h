/*
** select.h for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Thu May 25 17:08:54 2017 Martin Januario
** Last update Sat May 27 21:56:36 2017 Sahel Lucas--Saoudi
*/

#ifndef		SELECT_H_
# define	SELECT_H_

# include	"display.h"

int		select_player(t_needs *);
void		place_select(sfSprite **);
int		click_select(sfVector2i, t_needs *, int);
sfSprite	*create_sprite(char *);
sfSprite	**set_sprite(t_needs *);

#endif		/* !SELECT_H_ */

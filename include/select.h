/*
** select.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu May 25 17:08:54 2017 Martin Januario
** Last update Fri May 26 18:47:35 2017 Martin Januario
*/

#ifndef		SELECT_H_
# define	SELECT_H_

# include	"display.h"

int		select_player(t_needs *);
void		place_select(sfSprite **);
int		click_select(sfVector2i, t_needs *, int);

#endif		/* !SELECT_H_ */ 

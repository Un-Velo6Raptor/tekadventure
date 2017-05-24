/*
** game.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:15:37 2017 Martin Januario
** Last update Wed May 24 14:10:39 2017 Martin Januario
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	<display.h>

# define	WIDTH	900
# define	HEIGHT	900

int		loop_game(t_mode_game *, t_needs *);
sfVector2i	move_map(sfSprite *, sfVector2i, sfVector2i, int);
int		check_path(t_map *, sfVector2i, sfVector2i);

#endif		/* !GAME_H_ */

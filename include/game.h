/*
** game.h for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:15:37 2017 Martin Januario
** Last update Sun May 28 08:23:35 2017 Martin Januario
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	<display.h>

# define	WIDTH	900
# define	HEIGHT	900

int		loop_game(t_needs *);
sfVector2i	move_map(sfSprite *, sfVector2i, sfVector2i, int);
int		check_path(t_map *, sfVector2i, sfVector2i);
void		update_rect(sfSprite *, sfVector2i);
void		player_refresh(sfSprite *, sfVector2f, sfVector2i, sfVector2i);
sfVector2i	check_room(t_needs *, sfVector2i, sfVector2i, int *);
int		room_main(t_needs *, int *);

#endif		/* !GAME_H_ */

/*
** game.h for  in /home/januar_m/delivery/graphical/tekadventure
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Tue May 23 17:15:37 2017 Martin Januario
** Last update Sun May 28 21:35:41 2017 Hugo Cousin
*/

#ifndef	GAME_H_
# define GAME_H_

# include	<display.h>

# ifndef WIDTH
#  define WIDTH 900
# endif /* ! WIDTH */

# ifndef HEIGHT
#  define HEIGHT 900
# endif /* ! HEIGHT */

int		loop_game(t_needs *);
sfVector2i	move_map(sfSprite *, sfVector2i, sfVector2i, int);
int		check_path(t_map *, sfVector2i, sfVector2i);
void		update_rect(sfSprite *, sfVector2i);
void		player_refresh(sfSprite *, sfVector2f, sfVector2i, sfVector2i);
sfVector2i	check_room(t_needs *, sfVector2i, sfVector2i, int *);
int		room_main(t_needs *, int *);
void		get_player_move(t_needs *, sfVector2i);
void		refresh_room(t_needs *, int);
sfVector2i	move_player(t_char *, sfVector2i, sfVector2i, int);
void		final_fight(t_needs *);

#endif		/* !GAME_H_ */

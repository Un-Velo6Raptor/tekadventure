/*
** funcs.h for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Apr 13 15:17:59 2017 Hugo Cousin
** Last update Fri May 26 13:48:15 2017 Hugo Cousin
*/

#ifndef FUNC_H_
# define FUNC_H_

# include "struct.h"

# ifndef CHAR_POS
#  define CHAR_POS(s, c) ((my_strchr((s), (c)) - (s)))
# endif /* ! CHAR_POS */

void		free_players(t_player *);
t_player	*get_sentences(const char *);

#endif /* ! FUNC_H_ */

/*
** funcs.h for tekadventure in /home/heychsea/MUL/ceciesttemporaire
**
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
**
** Started on  Thu Apr 13 15:17:59 2017 Hugo Cousin
** Last update Sat May 27 22:39:35 2017 Sahel Lucas--Saoudi
*/

#ifndef FUNC_H_
# define FUNC_H_

# include "struct.h"

# ifndef CHAR_POS
#  define CHAR_POS(s, c) ((my_strchr((s), (c)) - (s)))
# endif /* ! CHAR_POS */

void		free_players(t_player *);
t_player	*get_sentences(const char *, size_t);
size_t		count_files(const char *);
char		*concat(int, ...);

#endif /* ! FUNC_H_ */

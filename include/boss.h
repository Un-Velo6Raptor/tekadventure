/*
** boss.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:34:05 2017 Sahel Lucas--Saoudi
** Last update Sun May 28 20:46:33 2017 Hugo Cousin
*/

#ifndef BOSS_H_
# define BOSS_H_

# ifndef NB_BOSS
#  define NB_BOSS 5
# endif /* !NB_BOSS */

# ifndef MIKE
#  define MIKE 0
# endif /* !MIKE */

# ifndef MALEX
#  define MALEX 1
# endif /* !MALEX */

# ifndef CHLOE
#  define CHLOE 2
# endif /* !CHLOE */

# ifndef REMI
#  define REMI 3
# endif /* !REMI */

# ifndef ARTHUR
#  define ARTHUR 4
# endif /* !ARTHUR */

# include <SFML/Graphics.h>
# include "character.h"
# include "display.h"

t_char			**init_boss();
int			check_map_boss(t_needs *, sfVector2i);
void			fight_mike(t_needs *);

#endif /* !BOSS_H_ */

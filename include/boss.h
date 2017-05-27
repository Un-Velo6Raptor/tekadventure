/*
** boss.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:34:05 2017 Sahel Lucas--Saoudi
** Last update Sat May 27 22:13:57 2017 Lucas Sahel
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

t_char			**init_boss();

#endif /* !BOSS_H_ */

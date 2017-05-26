/*
** player.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:47:49 2017 Sahel Lucas--Saoudi
** Last update Fri May 26 14:55:55 2017 Sahel Lucas--Saoudi
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# ifndef NB_PLAYER
#  define NB_PLAYER 4
# endif /* !NB_PLAYER */

# ifndef MARTIN
#  define MARTIN 0
# endif /* !MARTIN */

# ifndef CHARLOTTE
#  define CHARLOTTE 1
# endif /* !CHARLOTTE */

# ifndef HUGO
#  define HUGO 2
# endif /* !HUGO */

# ifndef SAHEL
#  define SAHEL 3
# endif /* !SAHEL */



# include <SFML/Graphics.h>
# include "character.h"

t_char			**init_player();

#endif /* !PLAYER_H_ */

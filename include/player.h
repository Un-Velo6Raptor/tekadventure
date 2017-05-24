/*
** player.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 16:47:49 2017 Sahel Lucas--Saoudi
** Last update Wed May 24 16:50:16 2017 Sahel Lucas--Saoudi
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# ifndef NB_PLAYER
#  define NB_PLAYER 4
# endif /* !NB_PLAYER */

# include <SFML/Graphics.h>
# include "sahel.h"
# include "hugo.h"
# include "martin.h"
# include "charlotte.h"
# include "character.h"

t_char			**init_player();

#endif /* !PLAYER_H_ */

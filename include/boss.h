/*
** boss.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:34:05 2017 Sahel Lucas--Saoudi
** Last update Wed May 24 16:50:23 2017 Sahel Lucas--Saoudi
*/

#ifndef BOSS_H_
# define BOSS_H_

# ifndef NB_BOSS
#  define NB_BOSS 4
# endif /* !NB_BOSS */

# include <SFML/Graphics.h>
# include "mike.h"
# include "chloe.h"
# include "malex.h"
# include "remi.h"
# include "character.h"

t_char			**init_boss();

#endif /* !BOSS_H_ */

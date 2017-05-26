/*
** boss.h for TekAdventure in /home/sahel/rendu/InfoGraphie/tekadventure
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 24 15:34:05 2017 Sahel Lucas--Saoudi
** Last update Fri May 26 14:54:51 2017 Sahel Lucas--Saoudi
*/

#ifndef BOSS_H_
# define BOSS_H_

# ifndef NB_BOSS
#  define NB_BOSS 4
# endif /* !NB_BOSS */

# include <SFML/Graphics.h>
# include "character.h"

t_char			**init_boss();

#endif /* !BOSS_H_ */

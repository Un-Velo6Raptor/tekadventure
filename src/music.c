/*
** music.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun May 28 19:34:17 2017 Martin Januario
** Last update Sun May 28 19:36:29 2017 Martin Januario
*/

#include	"display.h"

void		music_start(sfMusic *music, t_needs *needs)
{
  if (needs->mode->sound == 0)
    sfMusic_play(music);
}

void		music_pause(sfMusic *music, t_needs *needs)
{
  if (needs->mode->sound == 0)
    sfMusic_pause(music);
}


/*
** struct.h for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Apr 13 11:55:52 2017 Hugo Cousin
** Last update Thu Apr 13 16:39:03 2017 Hugo Cousin
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_text
{
  int		level;
  char		*sentence;
}		t_text;


typedef struct s_player
{
  char		*name;
  t_text	*text;
}		t_player;

#endif /* !STRUCT_H_ */

/*
** config.h for tekadventure in /home/heychsea/MUL/tekadventure/config
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 12:03:54 2017 Hugo Cousin
** Last update Fri May 26 14:17:32 2017 Martin Januario
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# ifndef CONFIG_DIR
#  define CONFIG_DIR 6
# endif /* ! CONFIG_DIR */

typedef struct	s_config
{
  char		*name;
  int		(*func)(char *, size_t, size_t, char **);
}		t_config;

typedef enum	dir
  {
    MAP,
    MAP_BACK,
    BOSS,
    PLAYER_SPRITE,
    PLAYER_MENU,
    PLAYER_TEXT
  }		t_dir;

#endif /* !CONFIG_H_ */

/*
** config.c for tekadventure in /home/heychsea/MUL/tekadventure/config
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 10:41:55 2017 Hugo Cousin
** Last update Fri May 26 12:06:44 2017 Hugo Cousin
*/

#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"config.h"
#include	"display.h"

t_config cmds[CONFIG_DIR + 1] =
  {
    {"MAP_DIR", &check_dir},
    {"MAP_BACK_DIR", &check_dir},
    {"BOSS_DIR", &check_dir},
    {"PLAYER_SPRITE_DIR", &check_dir},
    {"PLAYER_MENU_DIR", &check_dir},
    {"PLAYER_TEXT_DIR", &check_dir},
    {NULL, NULL}
  };

int		check_dir(char *cmd, size_t line, size_t index, char **tab)
{
  DIR		*dir;

  dir = opendir(cmd);
  if (!dir)
    {
      my_putstr(2, "Wrong directory at line: ");
      putnb(2, line);
      write(2, ".\n", 2);
      return (0);
    }
  tab[index] = my_strdup(cmd);
  closedir(dir);
  return (1);
}

int		check_cmd(char **cmd, size_t line, char **tab)
{
  size_t	index;

  index = 0;
  if (!cmd || tablen(cmd) != 2)
    {
      my_putstr(2, "Format error at line: ");
      putnb(2, line);
      write(2, ".\n", 2);
      return (0);
    }
  while (cmds[index].name)
    {
      if (!my_strcmp(cmds[index].name, cmd[0]))
	return (cmds[index].func(cmd[1], line, index, tab));
      index++;
    }
  my_putstr(2, "Wrong variable at line: ");
  putnb(2, line);
  write(2, ".\n", 2);
  return (0);
}

int		read_config(int fd, char **dirs)
{
  char		*cmd;
  size_t	line;
  int		ret;
  char		**tab;

  line = 0;
  ret = 1;
  while ((cmd = gnl(fd)) && ret)
    {
      if (cmd[0] != '#' && cmd[0])
	{
	  tab = my_str_to_wordtab(cmd, '=');
	  ret = check_cmd(tab, line, dirs);
	  tabfree(tab);
	}
      line++;
      free(cmd);
    }
  return (ret);
}

int		config(t_needs *needs)
{
  int		fd;

  fd = open("config.tk", O_RDONLY);
  if (fd == -1)
    {
      my_putstr(2, "Error while opening config file.\n");
      return (84);
    }
  read_config(fd, needs->dirs);
  close(fd);
  return (0);
}

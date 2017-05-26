/*
** config.c for tekadventure in /home/heychsea/MUL/tekadventure/config
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Fri May 26 10:41:55 2017 Hugo Cousin
** Last update Fri May 26 14:42:56 2017 Hugo Cousin
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
  if (cmd[my_strlen(cmd) - 1] != '/')
    tab[index] = my_allocat(cmd, "/", 0);
  else
    tab[index] = my_strdup(cmd);
  closedir(dir);
  return (1);
}

int		check_cmd(char **cmd, size_t line, char **tab,
			  t_config config[CONFIG_DIR + 1])
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
  while (config[index].name)
    {
      if (!my_strcmp(config[index].name, cmd[0]))
	return (config[index].func(cmd[1], line, index, tab));
      index++;
    }
  my_putstr(2, "Wrong variable at line: ");
  putnb(2, line);
  write(2, ".\n", 2);
  return (0);
}

int		read_config(int fd, char **dirs,
			    t_config config[CONFIG_DIR + 1])
{
  char		*cmd;
  size_t	line;
  int		ret;
  char		**tab;

  line = 0;
  ret = 1;
  while (ret && (cmd = gnl(fd)))
    {
      if (cmd[0] != '#' && cmd[0])
	{
	  tab = my_str_to_wordtab(cmd, '=');
	  ret = check_cmd(tab, line, dirs, config);
	  tabfree(tab);
	}
      line++;
      free(cmd);
    }
  line = 0;
  return (ret);
}

void		init_config(t_config config[CONFIG_DIR + 1], char **dirs)
{
  size_t	index;

  index = 0;
  config[0] = (t_config){"MAP_DIR", &check_dir};
  config[1] = (t_config){"MAP_BACK_DIR", &check_dir};
  config[2] = (t_config){"BOSS_DIR", &check_dir};
  config[3] = (t_config){"PLAYER_SPRITE_DIR", &check_dir};
  config[4] = (t_config){"PLAYER_MENU_DIR", &check_dir};
  config[5] = (t_config){"PLAYER_TEXT_DIR", &check_dir};
  config[6] = (t_config){NULL, NULL};
  while (index <= CONFIG_DIR)
    needs[index] = NULL;
}

int		config(t_needs *needs)
{
  int		fd;
  int		ret;
  t_config	config[CONFIG_DIR + 1];
  size_t	index;

  fd = open("config.tk", O_RDONLY);
  if (fd == -1)
    {
      my_putstr(2, "Error while opening config file.\n");
      return (84);
    }
  init_config(config);
  ret = read_config(fd, needs->dirs, config);
  close(fd);
  if (ret != 1)
    return (84);
  index = 0;
  while (index < CONFIG_DIR)
    {
      if (!needs->dirs[index])
	return (84);
      index++;
    }
  return (0);
}

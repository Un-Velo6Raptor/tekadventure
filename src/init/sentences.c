/*
** sentences.c for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Apr 13 15:01:26 2017 Hugo Cousin
** Last update Thu Apr 13 17:31:43 2017 Hugo Cousin
*/

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "funcs.h"
#include "lib.h"

size_t		count_files(void)
{
  struct dirent	*files;
  DIR		*directory;
  size_t	files_number;

  directory = opendir("ressources/players/");
  if (!directory)
    return (84);
  files_number = 0;
  files = readdir(directory);
  while (files)
    {
      if (files->d_name[0] != '.')
	files_number++;
      files = readdir(directory);
    }
  closedir(directory);
  return (files_number);
}

int		get_text(int fd, t_player *player)
{
  size_t	size;
  char		*tmp;

  size = 0;
  player->text = malloc(sizeof(t_text) * 2);
  if (!player->text)
    return (0);
  tmp = get_next_line(fd);
  while (tmp)
    {
      player->text = my_realloc(player->text, sizeof(t_text) * size,
				sizeof(t_text) * (size + 2));
      if (!player->text || !my_strchr(tmp, ':'))
	return (0);
      player->text[size].level = u_getnb(tmp);
      player->text[size].sentence = my_strdup(tmp + (CHAR_POS(tmp, ':') + 1));
      if (!player->text[size].sentence || player->text[size].level == -1)
	return (0);
      free(tmp);
      size++;
      tmp = get_next_line(fd);
    }
  player->text[size] = (t_text) {-1, NULL};
  return (1);
}

int		fill_player(t_player *player, char *path, char *name)
{
  int		fd;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (0);
  player->name = my_strdup(name);
  if (get_text(fd, player) == 0)
    return (0);
  close(fd);
  return (1);
}

int		loop_directory(DIR *directory, t_player *players)
{
  struct dirent	*files;
  char		path[PATH_MAX];
  int		pos;

  files = readdir(directory);
  pos = 0;
  while (files)
    {
      if (files->d_name[0] != '.')
	{
	  my_strcpy(path, "ressources/players/");
	  my_strcat(path, files->d_name);
	  if (fill_player(&(players[pos]), path, files->d_name) == 0)
	    return (0);
	  pos++;
	}
      files = readdir(directory);
    }
  closedir(directory);
  return (1);
}

t_player	*get_sentences(void)
{
  DIR		*directory;
  size_t	files_number;
  t_player	*players;

  files_number = count_files();
  if (files_number != 4)
    return (NULL);
  players = malloc(sizeof(t_player) * 4);
  directory = opendir("ressources/players/");
  if (!directory || !players)
    return (NULL);
  if (loop_directory(directory, players) == 0)
    return (NULL);
  return (players);
}

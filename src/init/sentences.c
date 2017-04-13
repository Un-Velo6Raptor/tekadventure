/*
** sentences.c for tekadventure in /home/heychsea/MUL/ceciesttemporaire
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Apr 13 15:01:26 2017 Hugo Cousin
** Last update Thu Apr 13 15:22:05 2017 Hugo Cousin
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

int		fill_player(t_player *players, char *path, char *name, int pos)
{
  int		fd;
  size_t	size;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (0);
  size = 1;
  players[pos].name = my_strdup(name);
  players[pos].sentences = malloc(sizeof(char *) * 2);
  if (!players[pos].sentences || !players[pos].name)
    return (0);
  players[pos].sentences[0] = get_next_line(fd);
  players[pos].sentences[1] = NULL;
  while (players[pos].sentences[size])
    {
      players[pos].sentences =
	my_realloc(players[pos].sentences, size, size + 2);
      if (!players[pos].sentences)
	return (0);
      players[pos].sentences[size + 1] = NULL;
      players[pos].sentences[size++] = get_next_line(fd);
    }
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
	  if (fill_player(players, path, files->d_name, pos) == 0)
	    return (0);
	}
      files = readdir(directory);
      pos++;
    }
  free_players(players);
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

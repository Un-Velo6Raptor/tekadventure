/*
** anim.c for tekadventure in /home/heychsea/MUL/tekadventure/anim
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu May 25 14:16:34 2017 Hugo Cousin
** Last update Sun May 28 18:48:03 2017 Hugo Cousin
*/

#include	<SFML/Graphics.h>
#include	<SFML/Window/Keyboard.h>
#include	<dirent.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<limits.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<time.h>
#include	"lib.h"
#include	"anim.h"

size_t		count_files(const char *dir_path)
{
  struct dirent	*files;
  DIR		*directory;
  size_t	files_number;

  directory = opendir(dir_path);
  if (!directory)
    return (0);
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

char		**get_files(const char *dir_path, char **tab)
{
  struct dirent	*files;
  DIR		*directory;
  size_t	i;

  if (!tab)
    return (NULL);
  directory = opendir(dir_path);
  if (!directory)
    return (NULL);
  files = readdir(directory);
  i = 0;
  while (files)
    {
      if (files->d_name[0] != '.')
	tab[i++] = my_strdup(files->d_name);
      files = readdir(directory);
    }
  tab[i] = NULL;
  closedir(directory);
  my_sort_wordtab(tab);
  return (tab);
}

sfTexture	**get_textures(const char *dir_path,
			       char **tab, sfTexture **textures)
{
  size_t	number;
  size_t	i;
  char		path[PATH_MAX];

  number = get_images_nb(tab);
  i = 0;
  textures = malloc(sizeof(sfTexture *) * (number + 1));
  if (!textures)
    return (NULL);
  number = 0;
  while (tab[i])
    {
      my_strcpy(path, dir_path);
      my_strcat(path, tab[i]);
      if (extension(tab[i], ".jpg") || extension(tab[i], ".png"))
	textures[number++] = sfTexture_createFromFile(path, NULL);
      i++;
    }
  textures[number] = NULL;
  return (textures);
}

void		display_textures(sfRenderWindow *window, sfTexture **textures,
				 sfSprite *sprite, int speed)
{
  size_t	index;

  index = 0;
  while (textures[index] && sfRenderWindow_isOpen(window) &&
	 sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      sfSprite_setTexture(sprite, textures[index], sfTrue);
      shade_sprite(window, sprite, speed);
      index++;
    }
  index = 0;
  while (textures[index])
    sfTexture_destroy(textures[index++]);
  free(textures);
}

int		launch_anim(sfRenderWindow *window, const char *dir_path,
			    int sound, int speed)
{
  sfSprite	*sprite;
  sfTexture	**textures;
  char		**files;
  size_t	files_number;

  files_number = count_files(dir_path);
  if (!files_number)
    return (0);
  files = malloc(sizeof(char *) * (files_number + 1));
  files = get_files(dir_path, files);
  if (!files)
    return (0);
  textures = NULL;
  textures = get_textures(dir_path, files, textures);
  if (!textures)
    return (0);
  sprite = sfSprite_create();
  back_music(dir_path, files, sound);
  display_textures(window, textures, sprite, speed);
  back_music(dir_path, files, sound);
  sfSprite_destroy(sprite);
  tabfree(files);
  return (1);
}

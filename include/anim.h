/*
** anim.h for tekadventure in /home/heychsea/MUL/tekadventure/anim
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu May 25 17:41:47 2017 Hugo Cousin
** Last update Sat May 27 19:03:47 2017 Hugo Cousin
*/

#ifndef ANIM_H_
# define ANIM_H_

# include	<SFML/Graphics/RenderWindow.h>
# include	<stddef.h>

int		extension(const char *, const char *);
void		my_sort_wordtab(char **);
size_t		get_images_nb(char **);
int		back_music(const char *, char **);
int		launch_anim(sfRenderWindow *, const char *);
void		shade_sprite(sfRenderWindow *, sfSprite *);

#endif /* ! ANIM_H_ */

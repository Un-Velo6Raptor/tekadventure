/*
** lib.h for lib.h in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Tue Apr  4 17:37:58 2017 Hugo Cousin
** Last update Thu Apr 13 12:12:23 2017 Hugo Cousin
*/

#ifndef LIB_H_
# define LIB_H_

#include <stdlib.h>

void	my_putchar(int, char);
void	my_show_wordtab(int, char **, char *);
int	my_strcmp(const char *, const char *);
int	my_strcasecmp(const char *, const char *);
char	*my_strdup(const char *);
char	*my_strndup(const char *, size_t);
char	*my_sdup(char *, int);
char	**my_tabdup(char **, int);
char	**my_tabrea(char **, char *);
char	*my_strncpy(char *, const char *, size_t);
char	**my_str_to_wordtab(const char *, char);
void	tabfree(char **);
void	putnb(int, int);
int	getnb(const char *);
int	u_getnb(const char *);
void	my_putstr(const char *, int);
char	*my_allocat(char *, char *, int);
char	*my_strcat(char *, const char *);
char	*my_strcpy(char *, const char *);
size_t	my_strlen(const char *);
size_t	tablen(char **);
int	my_strncmp(const char *, const char *, size_t );
char	*get_next_line(const int);
int	my_printf(const char *, ...);
void	strclean(char *);
int	alnum(char);
void	*my_memcpy(void *, const void *, int);
void	my_memset(void *, int, int);
int	str_num(const char *);
char	*my_strchr(char *, char);
void	*my_realloc(void *, size_t, size_t);

#endif /* ! LIB_H_ */

/*
** lib.h for tekadventure in /home/heychsea/MUL/tekadventure
**
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
**
** Started on  Tue May 23 11:15:16 2017 Hugo Cousin
** Last update Sat May 27 22:50:00 2017 Sahel Lucas--Saoudi
*/

#ifndef LIB_H_
# define LIB_H_

# include	<stdlib.h>

void		my_putchar(int, char);
void		my_show_wordtab(int, char **, char *);
void		my_putstr(int, const char *);
void		putnb(int, int);
void		strclean(char *);
void		tabclean(char **);
void		my_memset(void *, int, int);
void		tabfree(char **);
void		shift(char *, size_t);
void		shaft(char **, size_t);
void		*my_memcpy(void *, const void *, int);
void		*my_realloc(void *, size_t, size_t);
char		**my_tabdup(char **, int);
char		**my_tabrea(char **, char *);
char		**my_str_to_wordtab(const char *, char);
char		*my_strdup(const char *);
char		*my_strndup(const char *, size_t);
char		*my_sdup(char *, int);
char		*my_strncpy(char *, const char *, size_t);
char		*my_allocat(char *, char *, int);
char		*my_strcat(char *, const char *);
char		*my_strcpy(char *, const char *);
char		*gnl(const int);
char		*my_strchr(char *, char);
char		*my_strstr(const char *, const char *);
int		getnb(const char *);
int		u_getnb(const char *);
int		my_strcmp(const char *, const char *);
int		my_strcasecmp(const char *, const char *);
int		my_strncmp(const char *, const char *, size_t);
int		alnum(char);
int		str_num(const char *);
int		my_puterror(char *);
size_t		my_strlen(const char *);
size_t		tablen(char **);

#endif /* ! LIB_H_ */

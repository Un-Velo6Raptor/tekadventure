/*
** get_next_line.h for getnextline in /home/heychsea/CPE/CPE_2016_getnextline
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Wed Jan  4 16:05:02 2017 Hugo Cousin
** Last update Wed Apr  5 12:20:24 2017 Hugo Cousin
*/

#ifndef GET_NEXT_LINE_H_

# define GET_NEXT_LINE_H_

# ifndef READ_SIZE

#  define READ_SIZE 64

# endif /*! READ_SIZE */

char	*fix(char *next, char *buff, int rlen);
char	*eof(char *next, char *buff, int rlen);

typedef struct s_gnl
{
  char		*buff;
  long		rlen;
  int		status;
}		t_gnl;

#endif /*! GET_NEXT_LINE_H_ */

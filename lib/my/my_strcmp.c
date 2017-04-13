/*
** my_strcmp.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Thu Jan 12 15:03:26 2017 Hugo Cousin
** Last update Tue Apr  4 15:16:08 2017 Hugo Cousin
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

char	my_low(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 32);
}

int	my_strcasecmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (my_low(s1[i]) != my_low(s2[i]))
        return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

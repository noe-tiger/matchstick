/*
** test.c for  in /home/nono/CPE_2016_getnextline
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Jan  2 16:21:45 2017 Noé
** Last update Sat Feb 25 15:33:13 2017 Noe_tiger
*/

#include "../include/include.h"

char			*get_next_line(const int fd)
{
  static	int	toggle = 0;
  int			fc;
  int			i;
  char			*str;
  char			*c;

  fc = fd;
  i = 0;
  if (((c = malloc(sizeof(char) * 2))== NULL)
      || ((str = malloc(sizeof(char) * 1000))== NULL)
      || (toggle == 1 || fd == -1))
    return (NULL);
  c[0] = 'a';
  while (c[0] != '\n' && c[0] != 0)
    {
      if ((read(fc, c, 1)) < 1)
	toggle = 1;
      if (toggle == 1)
	return (NULL);
      str[i] = c[0];
      i++;
    }
  str[i - 1] = '\0';
  free(c);
  return (str);
}

/*
** map_create.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 16:25:32 2017 Noé
** Last update Wed Feb 22 16:24:05 2017 Noe_tiger
*/

#include "../include/include.h"

char	*lign_with_pipe(char *map, int k, int remain, int pipe)
{
  int	i;

  i = 0;
  map[i++] = '*';
  while (k != remain)
    {
      map[i++] = ' ';
      k++;
    }
  k = 0;
  while (k != pipe)
    {
      map[i++] = '|';
      k++;
    }
  k = 0;
  while (k - 1 != remain)
    {
      map[i++] = ' ';
      k++;
    }
  map[i - 1] = '*';
  map[i] = 0;
  return (map);
}

char			*lign_create(int j, int nb, int lign, char *map)
{
  static	int	count = 0;
  static	int	pipe = 1;
  int			remain;
  int			i;
  int			k;

  i = 0;
  k = 0;
  remain = nb + count;
  if (j == 0 || j == nb + 1)
    {
      while (i != lign - 2)
	map[i++] = '*';
      map[i] = 0;
    }
  else
    {
      map = lign_with_pipe(map, k, remain, pipe);
      pipe += 2;
    }
  count--;
  return (map);
}

char	**map_create(int nb)
{
  char	**map;
  int	i;
  int	lign;

  i = 0;
  lign = 4 + (nb * 2) - 1;
  if ((map = malloc(sizeof(char *) * nb * 2 + 10)) == NULL)
    return (NULL);
  while (i < nb + 2)
    {
      if ((map[i] = malloc(sizeof(char) * (nb * 2) + 3)) == NULL)
	return (NULL);
      map[i] = lign_create(i, nb, lign, map[i]);
      i++;
    }
  map[i] = NULL;
  return (map);
}

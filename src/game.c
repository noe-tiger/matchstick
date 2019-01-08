/*
** game.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 19:31:31 2017 Noé
** Last update Wed Feb 22 17:28:31 2017 Noe_tiger
*/

#include "../include/include.h"

int	set_stick(char **map)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  nb = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] == '|')
	    nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

int	retun(int ret, int toogle)
{
  if (toogle == 1 && ret != -1)
    return (2);
  if (toogle == 0 && ret != -1)
    return (1);
  return (-1);
}

int	game(char **map, int turn)
{
  int	toogle;
  int	nb_stick;
  int	ret;

  toogle = 0;
  nb_stick = set_stick(map);
  ret = 0;
  while (nb_stick > 0 && ret != -1)
    {
      if (toogle == 0)
	{
	  ret = player(map, turn);
	  toogle = 1;
	}
      else
	{
	  ret = intelligence(map, turn);
	  toogle = 0;
	}
      nb_stick -= ret;
    }
  return (retun(ret, toogle));
}

/*
** ia_last.c for  in /home/nono/CPE_2016_matchstick
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 14 01:16:05 2017 Noé
** Last update Fri Feb 17 17:15:57 2017 Noe_tiger
*/

#include "../include/include.h"

void    rm_stick(char **map, int line, int sticks)
{
  int   i;

  i = 1;
  while (map[line][i] != '*')
    i++;
  while (map[line][i] != '|')
    i--;
  while (sticks > 0)
    {
      map[line][i] = ' ';
      i--;
      sticks--;
    }
}

int     nb_last(char **map)
{
  int   i;
  int   j;
  int   nb;

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
  if (nb > 1)
    nb--;
  return (nb);
}

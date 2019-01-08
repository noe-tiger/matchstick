/*
** intelligence.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 23:30:47 2017 Noé
** Last update Wed Feb 22 17:29:19 2017 Noe_tiger
*/

#include "../include/include.h"

int	nb_line(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    i++;
  i -= 2;
  return (i);
}

int	nb_stick(int line, char **map)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (map[line][i])
    {
      if (map[line][i] == '|')
	nb++;
      i++;
    }
  return (nb);
}

int	last_line(char **map)
{
  int	toogle;
  int	nb_l;
  int	i;
  int	j;

  nb_l = 0;
  i = 0;
  while (map[i])
    {
      toogle = 0;
      j = 0;
      while (map[i][j] && toogle == 0)
	{
	  if (map[i][j] == '|')
	    nb_l ++;
	  if (map[i][j] == '|')
	    toogle = 1;
	  j++;
	}
      i++;
    }
  if (nb_l != 1)
    return (-1);
  else
    return (nb_last( map));
}

int	nb_l_and_sticks(int line, char **map)
{
  int	i;
  int	j;
  int	count;

  i = 0;
  j = 0;
  count = 0;
  while (map[i])
    i++;
  if (i < line || line <= 0)
    return (-1);
  while (map[line][j])
    {
      if (map[line][j] == '|')
	count++;
      j++;
    }
  if (count >= 1)
    return (count);
  else
    return (-1);
}

int	intelligence(char **map, int turn)
{
  int	ret;
  int	last;
  int	line;
  int	sticks;

  my_print_tab(map);
  my_putstr("\nAI's turn...\n");
  line = 0;
  sticks = turn + 1;
  while ((ret = nb_l_and_sticks(line, map)) == -1)
    line = 1 + rand() % nb_line(map);
  if ((last = last_line(map)) == -1)
    sticks = 1 + rand() % ret;
  else
    sticks = last;
  if (sticks > turn)
    sticks = 1;
  my_putstr("AI removed ");
  my_putnbr(sticks);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putstr("\n");
  rm_stick(map, line, sticks);
  return (sticks);
}

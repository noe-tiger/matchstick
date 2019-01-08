/*
** player.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 19:47:07 2017 Noé
** Last update Wed Feb 22 16:14:53 2017 Noe_tiger
*/

#include "../include/include.h"

void	rm_sticks(char **map, int line, int sticks)
{
  int	i;

  i = 1;
  my_putstr("Player removed ");
  my_putnbr(sticks);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putstr("\n");
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

int	line_exist(int line, char **map, char *str)
{
  int	i;

  i = 0;
  while (map[i])
    i++;
  i -= 2;
  if (line <= i && line != 0)
    return (line);
  if (str[0] < '0' || str[0] > '9')
    my_puterr("Error: invalid input (positive number expected)\n");
  else
    my_puterr("Error: Line is out of range\n");
  return (-1);
}

int	how_many_sticks(char **map, int line)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (map[line][i])
    {
      if (map[line][i] == '|')
	count += 1;
      i++;
    }
  return (count);
}

int	enough_stick(int line, int stick, int turn, char **map)
{
  char	*str;
  int	count;

  if (turn < (stick = my_int((str = get_next_line(0)))))
    {
      my_puterr("Error: you cannot remove more than ");
      my_putnbr(turn);
      my_puterr(" matches per turn\n");
    }
  if (stick == -1)
    return (-1);
  if (str[0] < '0' || str[0] > '9')
    my_puterr("Error: invalid input (positive number expected)\n");
  if ((turn < stick) || (str[0] < '0' || str[0] > '9'))
    return (-2);
  count = how_many_sticks(map, line);
  if (stick == 0)
    my_puterr("Error: you have to remove at least one match\n");
  if (count < stick)
    my_puterr("Error: not enough matches on this line\n");
  if (count < stick || stick == 0)
    return (-2);
  return (stick);
}

int	player(char **map, int turn)
{
  char	*str;
  int	line;
  int	stick;

  turn = turn;
  my_print_tab(map);
  my_putstr("\nYour turn:\n");
  stick = -1;
  while (stick == -1 || stick == -2)
    {
      line = -1;
      while (line == -1)
	{
	  my_putstr("Line: ");
	  if ((line = my_int((str = get_next_line(0)))) == -1)
	    return (-1);
	  line = line_exist(line, map, str);
	}
      my_putstr("Matches: ");
      if ((stick = enough_stick(line, stick, turn, map)) == -1)
	return (-1);
    }
  rm_sticks(map, line, stick);
  return (stick);
}

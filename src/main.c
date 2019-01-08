/*
** main.c for  in /home/nono/CPE_2016_matchstick
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 15:06:20 2017 Noé
** Last update Wed Feb 22 17:23:26 2017 Noe_tiger
*/

#include "../include/include.h"

void	write_help()
{
  write(1, "USAGE\n		./matchstick [number of row"
	"s][number of sticks per turn]\n\nDESCRIPTION\n	"
	"	number of rows	representing the"
	"number of playable rows\n		number of sticks per turn"
	"	representing the"
	" number of maximum sticks every player\n		 can remov"
	"e per turn.\n", 243);
}

void	ending(int ret)
{
  if (ret == 1)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  if (ret == 2)
    my_putstr("You lost, too bad...\n");
}

int	main(int ac, char **av)
{
  int	ret;
  char	**map;
  int	turn;

  if (ac != 3)
    write_help();
  if (ac != 3)
    return (0);
  if ((ret = my_int(av[1])) < 1 || (ret = my_int(av[1])) > 100)
    my_puterr("Wrong number of rows.\n");
  if (((ret = my_int(av[1])) < 1 || (ret = my_int(av[1])) > 100)
      || ((map = map_create(ret)) == NULL))
    return (84);
  if ((turn = my_int(av[2])) < 0)
    my_puterr("Maximum number of catches have to be positive.\n");
  if ((turn = my_int(av[2])) < 0)
    return (84);
  ret = game(map, turn);
  if (ret != -1)
    my_print_tab(map);
  ending(ret);
  free(map);
  if (ret == -1)
    return (0);
  return (ret);
}

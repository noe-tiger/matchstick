/*
** put.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 15:17:13 2017 Noé
** Last update Thu Feb 16 17:28:24 2017 Noe_tiger
*/

#include "../include/include.h"

void	my_putnbr(int nb)
{
  char	c;

  if (nb > 9)
    my_putnbr(nb / 10);
  c = (nb % 10) + 48;
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (1);
}

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
}

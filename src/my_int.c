/*
** my_int.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 16:12:39 2017 Noé
** Last update Tue Feb 21 23:52:05 2017 Noe_tiger
*/

#include "../include/include.h"

int	my_int(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (str == NULL)
    return (-1);
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nb += str[i] - 48;
      nb *= 10;
      i++;
    }
  nb /= 10;
  if (str[i] != 0)
    nb = 0;
  return (nb);
}

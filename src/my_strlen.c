/*
** my_strlen.c for  in /home/nono/CPE_2016_matchstick/src
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 15:19:10 2017 Noé
** Last update Mon Feb 13 15:30:42 2017 Noé
*/

#include "../include/include.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

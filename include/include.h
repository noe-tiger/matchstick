/*
** include.h for  in /home/nono/CPE_2016_matchstick
** 
** Made by Noé
** Login   <noe.tiger@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 13 15:10:54 2017 Noé
** Last update Sat Feb 25 15:32:59 2017 Noe_tiger
*/

#ifndef		INCLUDE_H_
# define	INCLUDE_H_

# include <stdlib.h>
# include <unistd.h>

int	game(char **, int);
char	*get_next_line(const int);
int	intelligence(char **, int);
char	*lign_create(int, int, int, char *);
char	*lign_with_pipe(char *, int , int, int);
int	main(int, char **);
char	**map_create(int);
int	my_int(char *);
void	my_puterr(char *);
void	my_putnbr(int);
int	my_putstr(char *);
void	my_print_tab(char **);
int	my_strlen(char *);
int	nb_last(char **);
int	nb_line(char **);
int	nb_stick(int, char **);
int	nb_sticks(int, int, char **, int);
int	player(char **, int);
void	rm_stick(char **, int, int);
void	rm_sticks(char **, int, int);
int	set_sticks(char **);

#endif		/* !INCLUDE_H_ */

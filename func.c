/*
** my_strlen_modif.c for my_strlen modif in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Dec  7 20:38:43 2011 florian dewulf
** Last update Sun Dec 11 18:10:34 2011 florian dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	*xmalloc(int size)
{
  void	*s;

  s = malloc(size);
  if (s == NULL)
    exit(EXIT_FAILURE);
  return (s);
}

int	my_strlen(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  j++;
	  while (str[i] == ' ')
	    i++;
	}
      else
	i++;
    }
  j++;
  return (j);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	get_plus_copy(char *nbr, char *str, int size, int curs)
{
  int	i;

  i = 0;
  while (i < size)
    {
      nbr[i] = str[curs];
      i++;
      curs++;
    }
  nbr[i] = '\0';
  i = my_getnbr(nbr);
  free(nbr);
  return (i);
}

/*
** main.c for main in /home/dewulf_f//afs/Igraph/fdf/Fil
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Dec 10 14:50:44 2011 florian dewulf
** Last update Mon Jan 16 15:44:07 2012 Florian Dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "header.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
  if (ac != 1)
    my_putstr("Le programme lit sur l'entrée standard\n");
  else
    boucle();
  return (0);
}

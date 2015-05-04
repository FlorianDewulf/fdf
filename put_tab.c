/*
** put_tab.c for put_tab in /home/dewulf_f//afs/Igraph/fdf/Fil
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Dec 10 14:43:26 2011 florian dewulf
** Last update Mon Jan 16 15:43:54 2012 Florian Dewulf
*/

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "header.h"
#include "get_next_line.h"

int	*put_to_star(int *sous_tab, char *s, int count)
{
  int	begin;
  int	en;
  char	*nbr;
  int	i;

  begin = 0;
  en = 0;
  i = 0;
  while (s[begin] == ' ' && s[begin] != '\0')
    begin++;
  while (i < count)
    {
      while ((((s[en] >= '0' && s[en] <= '9') || s[en] == '-') && s[en] != 0))
	en++;
      nbr = xmalloc((en - begin + 1) * sizeof(char));
      sous_tab[i] = get_plus_copy(nbr, s, (en - begin), begin);
      while (s[begin] != ' ' && s[begin] != '\0')
	begin++;
      while (s[begin] == ' ' && s[begin] != '\0')
	begin++;
      en = begin;
      i++;
    }
  sous_tab[i] = 123456789;
  return (sous_tab);
}

int	**to_tab()
{
  int	**tab;
  int	i;
  char	*str;
  int	count;

  i = 0;
  str = get_next_line(0);
  count = my_strlen(str);
  if (count < 6)
    exit(my_putstr("Veuillez entrer au minimum une map de 6x6\n"));
  tab = xmalloc((count + 1) * sizeof(int *));
  tab[i] = xmalloc((count + 1) * sizeof(int));
  tab[i] = put_to_star(tab[i], str, count);
  free(str);
  while (++i < count)
    {
      str = get_next_line(0);
      if (str == 0)
	exit(my_putstr("La map n'est pas carrée\n"));
      tab[i] = xmalloc((count + 1) * sizeof(int));
      tab[i] = put_to_star(tab[i], str, count);
      free(str);
    }
  return (tab);
}

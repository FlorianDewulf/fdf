/*
** get_norme.c for get_next_line in /home/dewulf_f//afs/getnextline-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Dec  8 21:34:36 2011 florian dewulf
** Last update Sun Dec 11 21:25:35 2011 florian dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "get_next_line.h"

t_var	reduc(t_var *p)
{
  p->curs = 0;
  p->str = xmalloc((BUFF_SIZE + 1) * sizeof(char));
  return (*p);
}

char	*big_reduc(t_var *p, int *i, char *buffer)
{
  while (buffer[(*i)] != '\0' && p->curs < BUFF_SIZE)
    {
      if (buffer[(*i)] == '\n')
	{
	  p->str[p->curs] = '\0';
	  return (p->str);
	}
      p->str[p->curs] = buffer[(*i)];
      p->curs++;
      (*i)++;
    }
  return (p->str);
}

char	*get_next_line(const int fd)
{
  static char	buffer[NBREAD + 1];
  static int	i;
  t_var	p;

  p = reduc(&p);
  if (i != 0)
    {
      big_reduc(&p, &i, buffer);
      if (buffer[i] == '\n')
	return (p.str = (i++) ? p.str : p.str);
      i = 0;
      return (p.str);
    }
  while (p.curs < BUFF_SIZE)
    {
      if ((p.tmp = read(fd, buffer, NBREAD)) <= 0)
	return (0);
      buffer[p.tmp] = '\0';
      i = 0;
      big_reduc(&p, &i, buffer);
      if (buffer[i] == '\n')
	return (p.str = (i++) ? p.str : p.str);
    }
  p.str[p.curs] = '\0';
  return (p.str);
}

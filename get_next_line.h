/*
** get_next_line.h for get_next_line in /home/dewulf_f//afs/C_Prog/Brouillon/get_next_line
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Nov 21 12:54:08 2011 florian dewulf
** Last update Fri Dec  9 10:04:45 2011 florian dewulf
*/

#ifndef	__GET_NEXT_LINE_H__
#define	__GET_NEXT_LINE_H__

#define	BUFF_SIZE	4096
#define	NBREAD	4096

typedef struct s_var
{
  int	curs;
  int	tmp;
  char	*str;
}t_var;

char	*get_next_line(const int fd);
t_var	reduc(t_var *p);


#endif

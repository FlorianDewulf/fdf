/*
** header.h for header in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Dec  5 13:17:38 2011 florian dewulf
** Last update Sun Dec 11 18:23:59 2011 florian dewulf
*/

#ifndef __HEADER_H__
#define __HEADER_H__

typedef struct s_mlx
{
  void	*mlx_ptr;
  void	*win_ptr;
  void	*img;
  char	*data;
  int	bpp;
  int	size;
  int	endian;
}t_mlx;

typedef struct s_point
{
  int	x;
  int	xmax;
  int	y;
  int	ymax;
  int	tmp;
  int	segm;
}t_point;

int	gere_expose(t_mlx *);
int	gere_key(int, t_mlx *);
int	gere_mouse(int, int, int, t_mlx *);
void	draw_cas_un(t_point *, t_mlx *);

void	my_putchar(char);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	*xmalloc(int);
int	*put_to_star(int *, char *, int);
int	**to_tab();
int	boucle();
int	get_plus_copy(char *, char *, int, int);

#endif

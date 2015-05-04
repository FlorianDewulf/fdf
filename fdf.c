/*
** tp1_windows_empty.c for tp1_windows_empty in /home/dewulf_f//afs/Igraph/TP1
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Nov  7 15:31:02 2011 florian dewulf
** Last update Mon Jan 16 15:44:31 2012 Florian Dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "header.h"
#include "get_next_line.h"

int	reduction(t_mlx *p, int **tab, int i, t_point *quad)
{
  int	j;

  j = 0;
  while (tab[i][j] != 123456789)
    {
      quad->xmax = quad->x + quad->segm;
      while (quad->tmp - quad->segm - (tab[i][j]) < 0)
	tab[i][j]--;
      quad->ymax = quad->tmp - quad->segm - (tab[i][j]);
      tab[i][j] = quad->ymax;
      draw_cas_un(quad, p);
      quad->y = quad->ymax;
      quad->x = quad->xmax;
      quad->tmp = quad->tmp - quad->segm;
      j++;
    }
  return (0);
}

void	put_quadri(t_mlx *p, int a, int **tab)
{
  t_point	quad;
  int	i;
  int	xbase;
  int	ybase;
  int	count;
  int	j;

  i = 0;
  quad.x = 175;
  quad.y = 500;
  quad.segm = 325 / a;
  count = 0;
  xbase = quad.x;
  ybase = quad.y;
  while (i < a)
    {
      quad.x = xbase + (count * quad.segm);
      quad.y = ybase + (count * quad.segm);
      quad.tmp = quad.y;
      j = 0;
      reduction(p, tab, i, &quad);
      i++;
      count++;
    }
}

int	reduction_two(t_mlx *p, int **tab, int a, t_point *quad)
{
  int	i;

  i = 0;
  while (i < a)
    {
      quad->xmax = quad->x + quad->segm;
      quad->ymax = tab[i][quad->tmp];
      draw_cas_un(quad, p);
      quad->y = quad->ymax;
      quad->x = quad->xmax;
      i++;
    }
  return (0);
}

void	put_quadri_two(t_mlx *p, int a, int **tab)
{
  t_point	quad;
  int	xbase;
  int	ybase;
  int	count;
  int	j;

  j = 0;
  quad.x = 175;
  quad.y = 500;
  quad.segm = 325 / a;
  count = 0;
  xbase = quad.x;
  ybase = quad.y;
  while (j < a)
    {
      quad.x = xbase + (count * quad.segm);
      quad.y = ybase + (count * quad.segm);
      quad.tmp = j;
      reduction_two(p, tab, a, &quad);
      j++;
      count++;
    }
}

int	boucle()
{
  t_mlx ml;
  int	**tab;
  int	count;

  tab = to_tab();
  while (tab[0][count] != 123456789)
    count++;
  ml.mlx_ptr = mlx_init();
  ml.win_ptr = mlx_new_window(ml.mlx_ptr, 1000, 1000, "Fil de fer");
  ml.img = mlx_new_image(ml.mlx_ptr, 1000, 1000);
  ml.data = mlx_get_data_addr(ml.img, &ml.bpp, &ml.size, &ml.endian);
  put_quadri(&ml, count, tab);
  put_quadri_two(&ml, count, tab);
  mlx_put_image_to_window(ml.mlx_ptr, ml.win_ptr, ml.img, 0, 0);
  mlx_expose_hook(ml.win_ptr, gere_expose, &ml);
  mlx_mouse_hook(ml.win_ptr, gere_mouse, &ml);
  mlx_key_hook(ml.win_ptr, gere_key, &ml);
  mlx_loop(ml.mlx_ptr);
  return (0);
}

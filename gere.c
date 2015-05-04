/*
** gere.c for gere in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Dec  5 13:15:24 2011 florian dewulf
** Last update Mon Jan 16 15:44:18 2012 Florian Dewulf
*/

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "header.h"

int	gere_expose(t_mlx *p)
{
  mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
  return (0);
}

int	gere_key(int keycode, t_mlx *p)
{
  if (keycode == 65307)
    exit(EXIT_FAILURE);
  p->data[0]++;
  p->data[0]--;
  return (0);
}

int	gere_mouse(int button, int x, int y, t_mlx *p)
{
  if (button == 1)
    mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, 0x00FF0000);
  else if (button == 2)
    mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, 0x0000FF00);
  else
    mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, 0x000000FF);
  return (0);
}

void	draw_cas_un(t_point *donnee, t_mlx *p)
{
  int	x1;
  int	i;

  if (donnee->x >= donnee->xmax && donnee->y <= donnee->ymax)
    {
      i = donnee->y;
      donnee->y = donnee->ymax;
      donnee->ymax = i;
      i = donnee->x;
      donnee->x = donnee->xmax;
      donnee->xmax = i;
    }
  x1 = donnee->x;
  while (x1 <= donnee->xmax)
    {
      i = (1000 * 4 * (donnee->y + ((donnee->ymax - donnee->y) *
				    (x1 - donnee->x)) /
		       (donnee->xmax - donnee->x + 1)) + x1 * 4);
      p->data[i] = 0;
      p->data[i + 1] = 255;
      p->data[i + 2] = 255;
      p->data[i + 3] = 255;
      x1++;
    }
}

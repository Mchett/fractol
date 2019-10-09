/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:22:17 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 13:37:06 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W_W	1920
# define W_H	1080
# define P_T	4
# include <pthread.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct				s_image
{
	void					*ptr;
	char					*data;
	int						bitspp;
	int						string;
	int						endian;
}							t_image;

typedef struct				s_mouse
{
	int						x;
	int						y;
	int						prevx;
	int						prevy;
	int						down;
	int						right;
}							t_mouse;

typedef struct				s_fract
{
	double					cre;
	double					cim;
	double					pr;
	double					pi;
	double					nre;
	double					nim;
	double					ore;
	double					oim;
	int						color;
	int						maxiterations;
	double					z;
	double					mx;
	double					my;
}							t_fract;

typedef struct				s_mlx
{
	char					*str;
	int						color;
	int						logcolor;
	t_fract					*f;
	void					*mlx_ptr;
	void					*win_ptr;
	t_image					*image;
	t_mouse					*mouse;
}							t_mlx;

double						ft_abs(double a);

void						ft_putimage(t_mlx *mlx);

t_image						*ft_delimage(t_mlx *mlx, t_image *img);

void						image_set_pixel(t_image *image,
		int x, int y, int color);

t_image						*new_image(t_mlx *mlx);

int							key_hook(int keycode, t_mlx *m);

int							mouse_scroll_down(int but, int x, int y,
		t_mlx *m_mlx);

int							mouse_scroll(int but, int x, int y, t_mlx *m_mlx);

t_mlx						*mlxdel(t_mlx *mlx);

t_mlx						*ft_init(char *str, t_fract *fract, void *ini);

void						draw(t_mlx *mlx);

int							ft_mouse_move(int x, int y, t_mlx *mlx);

void						julia(int y, int x, int maxy, t_mlx *m);

void						mandelbrot(int y, int x, int maxy, t_mlx *m);

void						burning_ship(int y, int x, int maxy, t_mlx *m);

void						newton(int y, int x, int maxy, t_mlx *m);

void						color(t_mlx *m, int i);

void						newton_math(t_mlx *m, double *tmp);

void						burningship_math(t_mlx *m, double *tmp);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:07:04 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 12:47:22 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(int y, int x, int maxy, t_mlx *m)
{
	int i;

	while (++y < maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			m->f->nre = 1.5 * (x - W_W / 2) / (0.5 * m->f->z * W_W) + m->f->mx;
			m->f->nim = (y - W_H / 2) / (0.5 * m->f->z * W_H) + m->f->my;
			i = -1;
			while (++i < m->f->maxiterations)
			{
				m->f->ore = m->f->nre;
				m->f->oim = m->f->nim;
				m->f->nre = m->f->ore * m->f->ore - m->f->oim * m->f->oim +
				m->f->cre;
				m->f->nim = 2 * m->f->ore * m->f->oim + m->f->cim;
				if ((m->f->nre * m->f->nre + m->f->nim * m->f->nim) > 4)
					break ;
			}
			color(m, i);
			image_set_pixel(m->image, x, y, m->f->color);
		}
	}
}

void	to_zero(t_mlx *m)
{
	m->f->nre = 0;
	m->f->nim = 0;
	m->f->ore = 0;
	m->f->oim = 0;
}

void	mandelbrot(int y, int x, int maxy, t_mlx *m)
{
	int i;

	while (++y < maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			m->f->pr = 1.5 * (x - W_W / 2) / (0.5 * m->f->z * W_W) + m->f->mx;
			m->f->pi = (y - W_H / 2) / (0.5 * m->f->z * W_H) + m->f->my;
			to_zero(m);
			i = -1;
			while (++i < m->f->maxiterations)
			{
				m->f->ore = m->f->nre;
				m->f->oim = m->f->nim;
				m->f->nre = m->f->ore * m->f->ore - m->f->oim * m->f->oim +
				m->f->pr;
				m->f->nim = 2 * m->f->ore * m->f->oim + m->f->pi;
				if ((m->f->nre * m->f->nre + m->f->nim * m->f->nim) > 4)
					break ;
			}
			color(m, i);
			image_set_pixel(m->image, x, y, m->f->color);
		}
	}
}

void	newton(int y, int x, int maxy, t_mlx *m)
{
	int		i;
	double	tmp;

	while (++y < maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			i = -1;
			tmp = 1.0;
			m->f->nre = 1.5 * (x - W_W / 2) / (0.5 * m->f->z * W_W) + m->f->mx;
			m->f->nim = (y - W_H / 2) / (0.5 * m->f->z * W_H) + m->f->my;
			while (tmp > 0.000001 && ++i < m->f->maxiterations)
				newton_math(m, &tmp);
			color(m, i);
			image_set_pixel(m->image, x, y, m->f->color);
		}
	}
}

void	burning_ship(int y, int x, int maxy, t_mlx *m)
{
	int		i;
	double	tmp;

	while (++y < maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			m->f->ore = 1.5 * (x - W_W / 2) / (0.5 * m->f->z * W_W) + m->f->mx;
			m->f->oim = (y - W_H / 2) / (0.5 * m->f->z * W_H) + m->f->my;
			m->f->nre = m->f->ore;
			m->f->nim = m->f->oim;
			i = -1;
			tmp = 1.0;
			while (++i < m->f->maxiterations)
			{
				burningship_math(m, &tmp);
				if ((m->f->nre * m->f->nre + m->f->nim * m->f->nim) > 4)
					break ;
			}
			color(m, i);
			image_set_pixel(m->image, x, y, m->f->color);
		}
	}
}

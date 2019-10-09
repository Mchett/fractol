/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:03:28 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 13:10:25 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(t_mlx *m, int i)
{
	if (m->logcolor % 2 == 0)
		m->f->color = m->color * (i + 1 - (log(2) /
		sqrt(m->f->nre * m->f->nre + m->f->nim * m->f->nim)) / log(2));
	else
		m->f->color = i * m->color;
}

void	newton_math(t_mlx *m, double *tmp)
{
	m->f->ore = m->f->nre;
	m->f->oim = m->f->nim;
	*tmp = (m->f->nre * m->f->nre + m->f->nim * m->f->nim) *
	(m->f->nre * m->f->nre + m->f->nim * m->f->nim);
	m->f->nre = (2 * m->f->nre * *tmp + m->f->nre *
	m->f->nre - m->f->nim * m->f->nim) / (3.0 * *tmp);
	m->f->nim = (2 * m->f->nim * (*tmp - m->f->ore)) / (3.0 * *tmp);
	*tmp = (m->f->nre - m->f->ore) * (m->f->nre - m->f->ore) +
	(m->f->nim - m->f->oim) * (m->f->nim - m->f->oim);
}

void	burningship_math(t_mlx *m, double *tmp)
{
	*tmp = m->f->nim;
	m->f->nim = fabs((double)(m->f->nre * m->f->nim +
	m->f->nre * m->f->nim + m->f->oim));
	m->f->nre = fabs((double)(m->f->nre * m->f->nre -
	*tmp * *tmp + m->f->ore));
}

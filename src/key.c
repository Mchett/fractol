/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:23:09 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 13:10:52 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	iter(int keycode, t_mlx *m)
{
	if (keycode == 24)
	{
		if (m->f->maxiterations + 5 > m->f->maxiterations)
			m->f->maxiterations += 5;
	}
	else
	{
		if (m->f->maxiterations - 5 > 0)
			m->f->maxiterations -= 5;
	}
}

int		key_hook(int keycode, t_mlx *m)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 257)
	{
		if (m->color < m->color + 1005000)
			m->color = m->color + 1005000;
		else
			m->color = 12345;
	}
	if (keycode == 126)
		m->f->my -= 0.1 / m->f->z;
	else if (keycode == 123)
		m->f->mx -= 0.1 / m->f->z;
	if (keycode == 125)
		m->f->my += 0.1 / m->f->z;
	else if (keycode == 124)
		m->f->mx += 0.1 / m->f->z;
	else if (keycode == 37)
		m->logcolor += 1;
	else if (keycode == 24 || keycode == 27)
		iter(keycode, m);
	ft_putimage(m);
	return (0);
}

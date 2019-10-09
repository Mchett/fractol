/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:22:56 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 13:11:27 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_scroll_down(int but, int x, int y, t_mlx *m_mlx)
{
	x = 0;
	y = 0;
	m_mlx->mouse->down |= (1 << but);
	if (but == 4 || but == 5)
		m_mlx->mouse->down = 0;
	if (but == 5)
		m_mlx->f->z *= 1.1;
	if (but == 4)
		m_mlx->f->z /= 1.1;
	if (but == 2 && m_mlx->mouse->right == 0)
		m_mlx->mouse->right = 1;
	else if (but == 2 && m_mlx->mouse->right == 1)
		m_mlx->mouse->right = 0;
	ft_putimage(m_mlx);
	return (0);
}

int	mouse_scroll(int but, int x, int y, t_mlx *m_mlx)
{
	x = 0;
	y = 0;
	but = 0;
	m_mlx->mouse->down = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse->right == 0)
	{
		if (mlx->mouse->prevx == 0)
			mlx->mouse->prevx = x;
		if (mlx->mouse->prevy == 0)
			mlx->mouse->prevy = y;
		mlx->mouse->prevx = mlx->mouse->x;
		mlx->mouse->prevy = mlx->mouse->y;
		mlx->mouse->x = x;
		mlx->mouse->y = y;
		if (x != mlx->mouse->prevx || y != mlx->mouse->prevy)
		{
			mlx->f->cre += (x - mlx->mouse->prevx) / 1000.f;
			mlx->f->cim += (y - mlx->mouse->prevy) / 1000.f;
			mlx->f->pr += (x - mlx->mouse->prevx) / 1000.f;
			mlx->f->pi += (y - mlx->mouse->prevy) / 1000.f;
		}
		ft_putimage(mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:15:43 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 13:37:17 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*ft_init(char *str, t_fract *fract, void *ini)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	mlx->mlx_ptr = ini;
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_W,
										W_H, str)) == NULL ||
			(mlx->image = new_image(mlx)) == NULL ||
			(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL)
		return (mlxdel(mlx));
	mlx->str = ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(mlx->str, str);
	mlx->logcolor = 1;
	mlx->color = 12345;
	mlx->f = fract;
	mlx->mouse->x = 0;
	mlx->mouse->y = 0;
	mlx->mouse->right = 0;
	return (mlx);
}

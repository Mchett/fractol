/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:51:12 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 12:46:44 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_putimage(t_mlx *mlx)
{
	ft_bzero(mlx->image->data, W_W * W_H * mlx->image->bitspp);
	if (ft_strcmp(mlx->str, "Julia") == 0)
		julia(-1, -1, W_H, mlx);
	else if (ft_strcmp(mlx->str, "Mandelbrot") == 0)
		mandelbrot(-1, -1, W_H, mlx);
	else if (ft_strcmp(mlx->str, "BurningShip") == 0)
		burning_ship(-1, -1, W_H, mlx);
	else if (ft_strcmp(mlx->str, "Newton") == 0)
		newton(-1, -1, W_H, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
}

t_image		*ft_delimage(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, img->ptr);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= W_W || y < 0 || y >= W_H)
		return ;
	*(int *)(image->data + (x * image->bitspp + y * image->string)) = color;
}

t_image		*new_image(t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->ptr = mlx_new_image(mlx->mlx_ptr, W_W, W_H)) == NULL)
		return (ft_delimage(mlx, img));
	img->data = mlx_get_data_addr(img->ptr, &img->bitspp, &img->string,
			&img->endian);
	img->bitspp /= 8;
	return (img);
}

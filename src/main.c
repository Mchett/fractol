/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchett <mchett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:30:30 by mchett            #+#    #+#             */
/*   Updated: 2019/09/24 15:32:25 by mchett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fract(char *str, t_fract *fract)
{
	fract->z = 0.4;
	fract->maxiterations = 25;
	fract->mx = 0;
	fract->my = 0;
	fract->cre = -0.7;
	fract->cim = 0.27015;
	fract->mx = -0.5;
	fract->my = 0;
	if (ft_strcmp(str, "Newton") == 0)
		fract->z = 0.01;
}

int		ft_close(void)
{
	exit(0);
}

void	draw(t_mlx *mlx)
{
	if (mlx->mlx_ptr != NULL)
	{
		ft_putimage(mlx);
		mlx_hook(mlx->win_ptr, 2, 4, key_hook, mlx);
		mlx_hook(mlx->win_ptr, 5, 0, mouse_scroll, mlx);
		mlx_hook(mlx->win_ptr, 4, 0, mouse_scroll_down, mlx);
		mlx_hook(mlx->win_ptr, 6, 0, ft_mouse_move, mlx);
		mlx_hook(mlx->win_ptr, 17, 0, ft_close, mlx);
	}
}

void	st(t_mlx **mlx, int argc, char **argv, t_fract *fract)
{
	int		i;
	void	*init;

	i = -1;
	init = mlx_init();
	while (++i < argc - 1)
	{
		init_fract(argv[i + 1], &fract[i]);
		mlx[i] = ft_init(argv[i + 1], &fract[i], init);
		draw(mlx[i]);
	}
	mlx_loop(init);
}

int		main(int argc, char **argv)
{
	t_mlx	**mlx;
	t_fract	*fract;
	int		i;

	i = 0;
	while (++i < argc)
		if (ft_strcmp(argv[i], "Julia") != 0 &&
		ft_strcmp(argv[i], "Mandelbrot") != 0 &&
		ft_strcmp(argv[i], "BurningShip") != 0 &&
		ft_strcmp(argv[i], "Newton") != 0)
			break ;
	if (i >= argc && argc >= 2)
	{
		fract = (t_fract*)ft_memalloc(sizeof(t_fract) * argc - 1);
		mlx = (t_mlx**)ft_memalloc(sizeof(t_mlx*) * argc - 1);
		if (mlx != NULL)
			st(mlx, argc, argv, fract);
		else
			ft_putstr("Error im malloc\n");
		free(mlx);
		return (0);
	}
	ft_putstr("List of parametrs:\n1) Julia\n");
	ft_putstr("2) Mandelbrot\n3) BurningShip\n4) Newton");
	return (0);
}

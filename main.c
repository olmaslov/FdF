/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:14:28 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/05 13:14:31 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 53 escape for mac, on linux 65307
** 78 - on mac keyboard, on linux 65453
*/

static int	my_key_funct(int keycode, t_mlx *mlx)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 78 || keycode == 65453)
	{
		if (mlx->animate == 1)
			mlx->animate = 0;
		else
			mlx->animate = 1;
	}
	if (keycode == 6)
		spin_z(mlx);
	if (keycode == 7)
		spin_x(mlx);
	if (keycode == 8)
		spin_y(mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx *mlx;

	if (argc > 1)
	{
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		mlx->file = argv[1];
		mlx_init();
		mlx->mlx_ptr = mlx_init();
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "mlx test");
		mlx_hook(mlx->win_ptr, 2, 5, my_key_funct, mlx);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
		mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr,
												&(mlx->bpp), &(mlx->sl), &(mlx->end));
		mlx->x = 40;
		mlx->y = 1;
		read_file(mlx);
		mlx_loop_hook(mlx->mlx_ptr, draw, mlx);
		mlx_loop(mlx->mlx_ptr);
		free(mlx);
	}
	return (0);
}

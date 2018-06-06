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
	if (keycode == 15)
	{
		if (mlx->animate == 1)
			mlx->animate = 0;
		else
			mlx->animate = 1;
	}
	if (keycode == 6)
	{
		mlx->z++;
		spin_z(mlx);
	}
	if (keycode == 7)
	{
		mlx->x++;
		spin_x(mlx);
	}
	if (keycode == 8)
	{
		mlx->y++;
		spin_y(mlx);
	}
	if (keycode == 0)
	{
		mlx->z--;
		spin_z(mlx);
	}
	if (keycode == 1)
	{
		mlx->x--;
		spin_x(mlx);
	}
	if (keycode == 2)
	{
		mlx->y--;
		spin_y(mlx);
	}
	if (keycode == 124)
		mlx->move_x++;
	if (keycode == 123)
		mlx->move_x--;
	if (keycode == 125)
		mlx->move_y++;
	if (keycode == 126)
		mlx->move_y--;
	if (keycode == 78 || keycode == 65453)
		mlx->set -= 0.001;
	if (keycode == 69)
		mlx->set += 0.001;
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
												&(mlx->bpp), &(mlx->sl), &(mlx->img_end));
		mlx->set = 1;
		mlx->x = 45;
		mlx->y =10;
		mlx->z = 0;
		mlx->move_x = 0;
		mlx->move_y = 0;
		read_file(mlx);
		net_print(mlx);
		mlx_loop_hook(mlx->mlx_ptr, draw, mlx);
		mlx_loop(mlx->mlx_ptr);
		free(mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 22:56:13 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 22:56:15 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 53 escape for mac, on linux 65307
** 78 - on mac keyboard, on linux 65453
*/

static int	keys_a(int keycode, t_mlx *mlx)
{
	if (keycode == 1)
	{
		if (mlx->x > 0)
			mlx->x *= -1;
		spin_x(mlx);
	}
	if (keycode == 2)
	{
		if (mlx->y > 0)
			mlx->y *= -1;
		spin_y(mlx);
	}
	return (0);
}

static int	keys_spin(int keycode, t_mlx *mlx)
{
	if (keycode == 6)
	{
		if (mlx->z < 0)
			mlx->z *= -1;
		spin_z(mlx);
	}
	if (keycode == 7)
	{
		if (mlx->x < 0)
			mlx->x *= -1;
		spin_x(mlx);
	}
	if (keycode == 8)
	{
		if (mlx->y < 0)
			mlx->y *= -1;
		spin_y(mlx);
	}
	if (keycode == 0)
	{
		if (mlx->z > 0)
			mlx->z *= -1;
		spin_z(mlx);
	}
	return (0);
}

static int	keys_zoom(int keycode, t_mlx *mlx)
{
	if (keycode == 78 || keycode == 65453)
	{
		mlx->set *= 0.95;
//		zoom(mlx);
	}
	if (keycode == 69)
	{
		mlx->set *= 1.05;
//		zoom(mlx);
	}
	return (0);
}

static int	keys_move(int keycode, t_mlx *mlx)
{
	if (keycode > 122 && keycode < 127)
	{
		if (keycode == 124)
			mlx->move_x = 1;
		if (keycode == 123)
			mlx->move_x = -1;
		if (keycode == 125)
			mlx->move_y = 1;
		if (keycode == 126)
			mlx->move_y = -1;
		move_map(mlx);
		mlx->move_x = 0;
		mlx->move_y = 0;
	}
	return (0);
}

int			keys(int keycode, t_mlx *mlx)
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
	if (keycode == 34)
	{
		if (mlx->instruction == 0)
			mlx->instruction = 1;
		else
			mlx->instruction = 0;
	}
	keys_a(keycode, mlx);
	keys_spin(keycode, mlx);
	keys_zoom(keycode, mlx);
	keys_move(keycode, mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:29:47 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 18:29:52 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->start_x;
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].x -= mlx->max_x / 2;
			mlx->pix[x][y].y -= mlx->max_y / 2;
			y += mlx->space;
		}
		x += mlx->space;
	}
}

void	rev_center(t_mlx *mlx)
{
	int		x;
	int		y;

	x = mlx->start_x;
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].x += mlx->max_x / 2;
			mlx->pix[x][y].y += mlx->max_y / 2;
			y += mlx->space;
		}
		x += mlx->space;
	}
}

void	spin_x(t_mlx *mlx)
{
	int		x;
	int		y;
	float	py;

	x = mlx->start_x;
	center(mlx);
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			py = mlx->pix[x][y].y;
			mlx->pix[x][y].y = (py * COS(mlx->x) +
					mlx->pix[x][y].z * SIN(mlx->x));
			mlx->pix[x][y].z = ((-(py) * SIN(mlx->x)) +
					mlx->pix[x][y].z * COS(mlx->x));
			y += mlx->space;
		}
		x += mlx->space;
	}
	rev_center(mlx);
}

void	spin_y(t_mlx *mlx)
{
	int		x;
	int		y;
	float	px;

	y = mlx->start_y;
	center(mlx);
	while (y < mlx->max_y)
	{
		x = mlx->start_x;
		while (x < mlx->max_x)
		{
			px = mlx->pix[x][y].x;
			mlx->pix[x][y].x = (px * COS(mlx->y) +
					mlx->pix[x][y].z * SIN(mlx->y));
			mlx->pix[x][y].z = ((-(px) * SIN(mlx->y)) +
					mlx->pix[x][y].z * COS(mlx->y));
			x += mlx->space;
		}
		y += mlx->space;
	}
	rev_center(mlx);
}

void	spin_z(t_mlx *mlx)
{
	int		x;
	int		y;

	x = mlx->start_x;
	center(mlx);
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].x = (mlx->pix[x][y].x * COS(mlx->z) -
					mlx->pix[x][y].y * SIN(mlx->z));
			mlx->pix[x][y].y = ((mlx->pix[x][y].x * SIN(mlx->z)) +
					mlx->pix[x][y].y * COS(mlx->z));
			y += mlx->space;
		}
		x += mlx->space;
	}
	rev_center(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:46:52 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/05 13:47:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_y(t_mlx *mlx)
{
	t_brz_in	*brz_out;
	int			x;
	int			y;

	brz_out = (t_brz_in*)malloc(sizeof(t_brz_in));
	y = mlx->start_y;
	while (y < 1000)
	{
		x = mlx->start_x;
		while (x < 1000)
		{
			if (mlx->pix[x][y].next_y != 0)
			{
				brz_out->color = mlx->pix[x][y].col;
				brz_out->x0 = mlx->pix[x][y].x;
				brz_out->x1 = mlx->pix[x][(int)mlx->pix[x][y].next_y].x;
				brz_out->y0 = mlx->pix[x][y].y;
				brz_out->y1 = mlx->pix[x][(int)mlx->pix[x][y].next_y].y;
				brezenham(mlx, brz_out);
			}
			x += mlx->space;
		}
		y += mlx->space;
	}
	free(brz_out);
}

void	print_x(t_mlx *mlx)
{
	t_brz_in	*brz_out;
	int			x;
	int			y;

	brz_out = (t_brz_in*)malloc(sizeof(t_brz_in));
	y = mlx->start_y;
	while (y < 1000)
	{
		x = mlx->start_x;
		while (x < 1000)
		{
			brz_out->color = mlx->pix[x][y].col;
			brz_out->x0 = mlx->pix[x][y].x;
			brz_out->x1 = mlx->pix[((int)mlx->pix[x][y].next_x) ?
								(int)mlx->pix[x][y].next_x : x][y].x;
			brz_out->y0 = mlx->pix[x][y].y;
			brz_out->y1 = mlx->pix[((int)mlx->pix[x][y].next_x) ?
								(int)mlx->pix[x][y].next_x : x][y].y;
			brezenham(mlx, brz_out);
			x += mlx->space;
		}
		y += mlx->space;
	}
	free(brz_out);
}

void	print_triangle(t_mlx *mlx)
{
	t_brz_in	*brz_out;
	int			x;
	int			y;

	brz_out = (t_brz_in*)malloc(sizeof(t_brz_in));
	y = mlx->start_y;
	while (y < 1000)
	{
		x = mlx->start_x;
		while (x < 1000)
		{
			if ((int)mlx->pix[x][(int)mlx->pix[x][y].next_y].next_x != 0 && (int)mlx->pix[x][y].next_y)
			{
				brz_out->color = mlx->pix[x][y].col;
				brz_out->x0 = mlx->pix[x][y].x;
				brz_out->x1 = mlx->pix[(int)mlx->pix[x][(int)mlx->pix[x][y].next_y].next_x][(int)mlx->pix[x][y].next_y].x;
				brz_out->y0 = mlx->pix[x][y].y;
				brz_out->y1 = mlx->pix[(int)mlx->pix[x][(int)mlx->pix[x][y].next_y].next_x][(int)mlx->pix[x][y].next_y].y;
				brezenham(mlx, brz_out);
			}
			x += mlx->space;
		}
		y += mlx->space;
	}
	free(brz_out);
}

void	move_map(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->max_x && x < 1000)
	{
		y = 0;
		while (y < mlx->max_y && y < 1000)
		{
			mlx->pix[x][y].x += mlx->move_x;
			mlx->pix[x][y].y += mlx->move_y;
			y++;
		}
		x++;
	}
}

int		draw_loop(t_mlx *mlx)
{
	print_x(mlx);
	print_y(mlx);
	print_triangle(mlx);
	if (mlx->animate == 1)
		spin_y(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (mlx->instruction == 1)
		print_instruction(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	return (0);
}

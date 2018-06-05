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

void		print_y(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x != 1000)
	{
		y = 0;
		while (y != 1000)
		{
			if (mlx->pix[x][y].next_y != 0)
			{
				//mlx->img_str[i * mlx->sl / 4 + 0] = 0xFFFFFF;
				print_lines(mlx->pix[x][y].nx, mlx->pix[x][y].nx, mlx->pix[x][y].ny, mlx->pix[x][ mlx->pix[x][y].next_y].ny, mlx, mlx->pix[x][y].col);
			}
			y++;
		}
		x++;
	}
}

void		print_x(t_mlx *mlx)
{
	int x;
	int y;
	int i;

	y = 0;
	while (y != 1000)
	{
		x = 0;
		while (x != 1000)
		{
			if (mlx->pix[x][y].next_x != 0)
			{
				//mlx->img_str[i * mlx->sl / 4 + 0] = 0xFFFFFF;
				print_lines(mlx->pix[x][y].nx, mlx->pix[x][y].next_x, mlx->pix[x][y].ny, mlx->pix[mlx->pix[x][y].next_x][y].ny, mlx, mlx->pix[x][y].col);
			}
			x++;
		}
		y++;
	}
}

void		print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx, int color)
{
	int deltax;
	int deltay;
	int error;
	int deltaerr;
	int y;
	int x;
	int x2;
	int diry;

	deltax = abs(x1 - x0);
	deltay = abs(y1 - y0);
	error = 0;
	deltaerr = deltay;
	y = y0;
	diry = y1 -  y0;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	if (x0 < x1)
	{
		x = x0;
		x2 = x1;
	}
	else
	{
		x = x1;
		x2 = x0;
	}
	if (x != x2)
	while (x != x2)
	{
		mlx->img_str[y * mlx->sl / 4 + x] = color;
		error += deltaerr;
		x++;
		if (2 * error >= deltax)
		{
			y += diry;
			error -= deltax;
		}
	}
	else if (x == x2)
	{
		while (y0 != y1 && y0 < y1)
		{
			mlx->img_str[y0 * mlx->sl / 4 + x] = color;
			y0++;
		}
	}
}

int		ft_atoi_hex(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[0] == 48 && str[1] == 120)
		i = 2;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 102)
			nb = (nb * 16) + (str[i] - 87);
		else if (str[i] >= 48 && str[i] <= 57)
			nb = (nb * 16) + (str[i] - 48);
		else if (str[i] >= 65 && str[i] <= 70)
			nb = (nb * 16) + (str[i] - 55);
		else
			return (nb);
		i++;
	}
	return (nb);
}

void	spin_x(t_mlx *mlx)
{
	int		x;
	int		y;
	int		py;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			py = mlx->pix[x][y].ny;
			mlx->pix[x][y].ny = (int)(py * COS(mlx->x) - mlx->pix[x][y].nz * SIN(mlx->x));
			mlx->pix[x][y].nz = (int)((-(py) * SIN(mlx->x)) - mlx->pix[x][y].nz * COS(mlx->x));
			y++;
		}
		x++;
	}
}

void	spin_y(t_mlx *mlx)
{
	int		x;
	int		y;
	int		px;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			px = mlx->pix[x][y].nx;
			mlx->pix[x][y].nx = (int)(px * COS(mlx->y) + mlx->pix[x][y].nz * SIN(mlx->y));
			mlx->pix[x][y].nz = (int)((-(px) * SIN(mlx->y)) + mlx->pix[x][y].nz * COS(mlx->y));
			y++;
		}
		x++;
	}
}

void	spin_z(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].nx = (int)(mlx->pix[x][y].nx * COS(mlx->y) - mlx->pix[x][y].ny * SIN(mlx->y));
			mlx->pix[x][y].ny = (int)((mlx->pix[x][y].nx * SIN(mlx->y)) + mlx->pix[x][y].ny * COS(mlx->y));
			y++;
		}
		x++;
	}
}

int		net_print(t_mlx *mlx)
{
	int y;
	int x;
	int i;
	int j;
	int k;
	int col;

	x = 0;
//	if (mlx->animate == 1)
//		mlx->y += 1;
	if (!mlx->space)
		mlx->space = 1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height));
//		mlx->space = 5;
	if (mlx->width >= mlx->height)
	{
		y = (1000 - ((mlx->space * mlx->height)- mlx->space)) / 2;
		mlx->start[0] = y;
	}
	else
	{
		y = (1000 - (mlx->space * (mlx->height - 1))) / 2;
		mlx->start[0] = y;
	}
	j = 0;
	while (*(mlx->line) && j < mlx->height)
	{
		x = (1000 - ((mlx->space * mlx->width)- mlx->space)) / 2;
		mlx->start[1] = x;
		i = 0;
		while (i < mlx->width && x < 1000 && *(mlx->line))
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
				mlx->pix[x][y].z = ft_atoi(&*(mlx->line));
				printf("%d ", mlx->pix[x][y].z);
//				mlx->img_str[y * mlx->sl / 4 + x] = 0xFFFFFF;
				mlx->pix[x][y].col = 0xFFFF00;
				mlx->pix[x][y].x = x;
				mlx->pix[x][y].y = y;
				mlx->pix[x][y].nx = x;
				mlx->pix[x][y].ny = y;
				mlx->pix[x][y].nz = mlx->pix[x][y].z;
//				k = y;
//				while (k < y + mlx->space)
//				{
					mlx->pix[x][y].col = 0xFFFFFF; //+ (mlx->pix[x][y].z * 20);
				if (mlx->pix[x][y].nz > 0)
					mlx->pix[x][y].col = 0xFFFF00;
//					k++;
//				}
				i++;
				if (y + mlx->space < 1000 && j + 1 != mlx->height)
					mlx->pix[x][y].next_y = y + mlx->space;
				if (i != mlx->width)
					mlx->pix[x][y].next_x = x + mlx->space;
				if (y + mlx->space > mlx->max_y)
					mlx->max_y = y + mlx->space;
				if (x + mlx->space > mlx->max_x)
					mlx->max_x = x + mlx->space;
				x += mlx->space;
			}
			if (*mlx->line == ',')
			{
				//k = y;
				col = ft_atoi_hex(&*(mlx->line) + 1);
				//while (k < mlx->pix[x - mlx->space][y].next_y)
				//{
				mlx->pix[x - mlx->space][y].col = col;
				//	k++;
				//}
				mlx->line = &(*mlx->line) + 9;
			}
			while(*(mlx->line) > 47 && *(mlx->line) < 58)
				*(mlx->line)++;
			mlx->line++;
		}
		j++;
		y += mlx->space;
		printf("\n");
	}
	mlx->map_y = y - mlx->space;
	mlx->map_x = x - mlx->space;
//	spin_x(mlx);
//	spin_x(mlx);
//	spin_y(mlx);
//	spin_z(mlx);
	print_x(mlx);
	print_y(mlx);
	return (0);
}

int		draw(t_mlx *mlx)
{
	spin_x(mlx);
	spin_y(mlx);
	spin_z(mlx);
	net_print(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	return (0);
}
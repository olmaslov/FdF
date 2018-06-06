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

	y = mlx->start_y;
	while (y <= 1000)
	{
		x = mlx->start_x;
		while (x <= 1000)
		{
			if (mlx->pix[x][y].next_y != 0)
			{
					print_lines(mlx->pix[x][y].nx, mlx->pix[x][(int)mlx->pix[x][y].next_y].nx, mlx->pix[x][y].ny, mlx->pix[x][(int)mlx->pix[x][y].next_y].ny, mlx, mlx->pix[x][y].col);
			}
			x += mlx->space;
		}
		y += mlx->space;
	}
}

void		print_x(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int col;

	y = mlx->start_y;
	while (y <= 1000)
	{
		x = mlx->start_x;
		while (x <= 1000)
		{
			if (mlx->pix[x][y].next_x != 0)
			{
				col = (mlx->pix[(int)mlx->pix[x][y].next_x][y].col != 0xFFFFFF) ? mlx->pix[(int)mlx->pix[x][y].next_x][y].col : mlx->pix[x][y].col;
				print_lines(mlx->pix[x][y].nx, mlx->pix[(int)mlx->pix[x][y].next_x][y].nx, mlx->pix[x][y].ny, mlx->pix[(int)mlx->pix[x][y].next_x][y].ny, mlx, col);

			}
			x += mlx->space;
		}
		y += mlx->space;
	}
}

void	draw_line_int_first(float *p0, float *p1, int color, t_mlx *mlx)
{
	int dx;
	int dy;
	int d;
	int y;
	int x;

	x = (int)p0[0];
	y = (int)p0[1];
	dx = (int)p1[0] - x;
	dy = (int)p1[1] - y;
	if (dy < 0)
		dy *= -1;
	d = (2 * dy) - dx;
	while (x <= (int)p1[0])
	{
		mlx->img_str[y * mlx->sl / 4 + x] = color;
//		mlx_pixel_put(mlx[0], mlx[1], x, y, color);
		if (d > 0)
		{
			((int)p1[1] - (int)p0[1] < 0) ? y-- : y++;
			d += 2 * (dy - dx);
		}
		else
			d += 2 * dy;
		x++;
	}
}

/*
**	second - is octet 0 <= |x1 - x0| <= (y1 - y0)
*/

void	draw_line_int_second(float *p0, float *p1, int color, t_mlx *mlx)
{
	int dx;
	int dy;
	int d;
	int y;
	int x;

	x = (int)p0[0];
	y = (int)p0[1];
	dx = (int)p1[0] - x;
	dy = (int)p1[1] - y;
	if (dx < 0)
		dx *= -1;
	d = (2 * dx) - dy;
	while (y <= (int)p1[1])
	{
		mlx->img_str[y * mlx->sl / 4 + x] = color;
//		mlx_pixel_put(mlx[0], mlx[1], x, y, color);
		if (d > 0)
		{
			((int)p1[0] - (int)p0[0] < 0) ? x-- : x++;
			d += 2 * (dx - dy);
		}
		else
			d += 2 * dx;
		y++;
	}
}

void	print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx, int color)
{
	int absx;
	int absy;
	float p0[2];
	float p1[2];

	p0[0] = (float)x0;
	p0[1] = (float)y0;
	p1[0] = (float)x1;
	p1[1] = (float)y1;
	if ((int)p1[0] - (int)p0[0] >= 0)
		absx = (int)p1[0] - (int)p0[0];
	else
		absx = (int)p0[0] - (int)x1;
	if ((int)p1[1] - (int)p0[1] >= 0)
		absy = (int)p1[1] - (int)p0[1];
	else
		absy = (int)p0[1] - (int)p1[1];
	if (absy < absx)
	{
		if ((int)p0[0] > (int)p1[0])
			draw_line_int_first(p1, p0, color, mlx);
		else
			draw_line_int_first(p0, p1, color, mlx);
	}
	else
	{
		if ((int)p0[1] > (int)p1[1])
			draw_line_int_second(p1, p0, color, mlx);
		else
			draw_line_int_second(p0, p1, color, mlx);
	}
}



//void		print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx, int color)
//{
//	int deltax;
//	int deltay;
//	int error;
//	int deltaerr;
//	int y;
//	int x;
//	int x2;
//	int diry;
//
//	deltax = abs(x1 - x0);
//	deltay = abs(y1 - y0);
//	error = 0;
//	deltaerr = deltay;
//	y = y0;
//	diry = y1 -  y0;
//	if (diry > 0)
//		diry = 1;
//	if (diry < 0)
//		diry = -1;
//	if (x0 < x1)
//	{
//		x = x0;
//		x2 = x1;
//	}
//	else
//	{
//		x = x1;
//		x2 = x0;
//	}
//	if (x != x2)
//	while (x != x2)
//	{
//		mlx->img_str[y * mlx->sl / 4 + x] = color;
//		error += deltaerr;
//		x++;
//		if (2 * error >= deltax)
//		{
//			y += diry;
//			error -= deltax;
//		}
//	}
//	else if (x == x2)
//	{
//		while (y0 != y1 && y0 < y1)
//		{
//			mlx->img_str[y0 * mlx->sl / 4 + x] = color;
//			y0++;
//		}
//	}
//}

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
	float		py;

	x = mlx->start_x;
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			py = mlx->pix[x][y].y;
			mlx->pix[x][y].ny = roundf(py * COS(mlx->x) + mlx->pix[x][y].z * SIN(mlx->x));
			mlx->pix[x][y].nz = roundf((-(py) * SIN(mlx->x)) + mlx->pix[x][y].z * COS(mlx->x));
			y += mlx->space;
		}
		x += mlx->space;
	}
}

void	spin_y(t_mlx *mlx)
{
	int		x;
	int		y;
	float	px;

	y = mlx->start_y;
	while (y < mlx->max_y)
	{
		x = mlx->start_x;
		while (x < mlx->max_x)
		{
			px = mlx->pix[x][y].x;
			mlx->pix[x][y].nx = (px * COS(mlx->y) + mlx->pix[x][y].z * SIN(mlx->y));
			mlx->pix[x][y].nz = ((-(px) * SIN(mlx->y)) + mlx->pix[x][y].z * COS(mlx->y));
			x += mlx->space;
		}
		y += mlx->space;
	}
}

void	spin_z(t_mlx *mlx)
{
	int		x;
	int		y;

	x = mlx->start_x;
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].nx = (mlx->pix[x][y].nx * COS(mlx->z) - mlx->pix[x][y].y * SIN(mlx->z));
			mlx->pix[x][y].ny = ((mlx->pix[x][y].nx * SIN(mlx->z)) + mlx->pix[x][y].y * COS(mlx->z));
			y += mlx->space;
		}
		x += mlx->space;
	}
}

void	map_init(t_mlx *mlx)
{

}

int		net_print(t_mlx *mlx)
{
	int y;
	int x;
	int i;
	int j;
	int k;
	int col;

	if (!mlx->space)
		mlx->space = (1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height)));
	if (mlx->width >= mlx->height)
		y = (1000 - (((int)mlx->space * mlx->height)- (int)mlx->space)) / 2;
	else
		y = (1000 - ((int)mlx->space * (mlx->height - 1))) / 2;
	j = 0;
	x = (1000 - (((int)mlx->space * mlx->width)- (int)mlx->space)) / 2;
	mlx->start_x = x;
	mlx->start_y = y;
	while (*(mlx->line) && j < mlx->height)
	{
		x = (1000 - (((int)mlx->space * mlx->width)- (int)mlx->space)) / 2;
		i = 0;
		while (i < mlx->width && x < 1000 && *(mlx->line))
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
				mlx->pix[x][y].z = ft_atoi(&*(mlx->line));
				mlx->pix[x][y].col = 0xFFFF00;
				mlx->pix[x][y].x = x;
				mlx->pix[x][y].y = y;
				mlx->pix[x][y].nx = x;
				mlx->pix[x][y].ny = y;
				mlx->pix[x][y].nz = mlx->pix[x][y].z;
				k = y;
				while (k < y + mlx->space)
				{
//					if (mlx->pix[x][y].z > 0)
						mlx->pix[x][k].col = (0x009f00 - (1000 * (mlx->pix[x][y].z)));
//					else
//						mlx->pix[x][y].col = 0x5de7fc;
					k++;
				}
				i++;
				if (y + mlx->space < 1000 && j + 1 != mlx->height)
					mlx->pix[x][y].next_y = y + mlx->space;
				if (i != mlx->width)
					mlx->pix[x][y].next_x = x + mlx->space;
				mlx->max_y = y + mlx->space;
				mlx->max_x = x + mlx->space;
				x += mlx->space;
			}
			if (*mlx->line == ',')
			{
				k = y;
				col = ft_atoi_hex(&*(mlx->line) + 1);
				while (k < mlx->pix[x - (int)mlx->space][k].next_y)
				{
				mlx->pix[x - (int)mlx->space][k].col = col;
					k++;
				}
				mlx->line = &(*mlx->line) + 9;
			}
			while(*(mlx->line) > 47 && *(mlx->line) < 58)
				*(mlx->line)++;
			mlx->line++;
		}
		j++;
		y += mlx->space;
	}
//	mlx->map_y = y;
//	mlx->map_x = x;
	return (0);
}

void	set_mid_pos(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].nx += mlx->move_x;
			mlx->pix[x][y].ny += mlx->move_y;
			y++;
		}
		x++;
	}
}

void	zoom(t_mlx *mlx)
{
	int		x;
	int		y;

	x = mlx->start_x;
	while (x < mlx->max_x)
	{
		y = mlx->start_y;
		while (y < mlx->max_y)
		{
			mlx->pix[x][y].nx *= mlx->set;
			mlx->pix[x][y].ny *= mlx->set;
			y += mlx->space;
		}
		x += mlx->space;
	}
}

int		draw(t_mlx *mlx)
{

//	spin_x(mlx);
//	spin_z(mlx);
	set_mid_pos(mlx);
//	net_print(mlx);

	zoom(mlx);
	print_x(mlx);
	print_y(mlx);
	if (mlx->animate == 1)
	{
		mlx->y += 1;
		spin_y(mlx);
	}
//	print_lines(50, 12, 50, 12, mlx, 0xffffff);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	return (0);
}
//
// Created by Oleksii MASLOV on 5/24/18.
//

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
				print_lines(mlx->pix[x][y].x, mlx->pix[x][y].x, mlx->pix[x][y].y, mlx->pix[x][y].next_y, mlx);
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
				i = mlx->pix[x][y].y;
				if (mlx->pix[x][y].next_y != 0)
					while (i != mlx->pix[x][y].next_y)
					{
						print_lines(mlx->pix[x][y].x, mlx->pix[x][y].next_x, i, i, mlx);
						i++;
					}
				else
					print_lines(mlx->pix[x][y].x, mlx->pix[x][y].next_x, mlx->pix[x][y].y, mlx->pix[x][y].y, mlx);
			}
			x++;
		}
		y++;
	}
}

void		print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx)
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
	while (x != x2)
	{
		mlx->img_str[y * mlx->sl / 4 + x] = mlx->pix[x0][y0].col;
		error += deltaerr;
		x++;
		if (2 * error >= deltax)
		{
			y += diry;
			error -= deltax;
		}
	}
	if (x == x2)
	{
		while (y0 != y1)
		{
			mlx->img_str[y0 * mlx->sl / 4 + x] = mlx->pix[x][y].col;
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
	int		px;

	x = 0;
	while (x < mlx->map_y)
	{
		y = 0;
		while (y < mlx->map_x)
		{
			px = mlx->pix[x][y].x;
//			mlx->pix[mlx->pix[x][y].next_x][y].x = (int)(px * COS(mlx->y) + mlx->pix[x][y].z * SIN(mlx->y));
			mlx->pix[x][y].x = (int)(px * COS(mlx->y) + mlx->pix[x][y].z * SIN(mlx->y));
			mlx->pix[x][y].z = (int)((-(px) * SIN(mlx->y)) + mlx->pix[x][y].z * COS(mlx->y));
			y++;
		}
		x++;
	}
}

void	spin_y(t_mlx *mlx)
{
	int		x;
	int		y;
	int		py;

	x = 0;
	while (x < mlx->map_y)
	{
		y = 0;
		while (y < mlx->map_x )
		{
			py = mlx->pix[x][y].y;
			if (mlx->pix[x][y].y != 0)
				mlx->pix[x][y].next_y = (int)(py * COS(mlx->y) + mlx->pix[x][y].z * SIN(mlx->y));
			mlx->pix[x][y].z = (int)((-(py) * SIN(mlx->y)) + mlx->pix[x][y].z * COS(mlx->y));
			y++;
		}
		x++;
	}
}


void		net_print(t_mlx *mlx)
{
	int y;
	int x;
	int i;
	int j;
	int k;
	int col;

	x = 0;
	if (!mlx->space)
		mlx->space = 1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height));
	if (mlx->width >= mlx->height)
	{
		y = (1000 - ((mlx->space * mlx->height)- mlx->space)) / 2;
//		y = 0;
		mlx->start[0] = y;
	}
	else
	{
//		y = 0;
		y = (1000 - (mlx->space * mlx->height)) / 2;
		mlx->start[0] = y;
	}
	j = 0;
	while (*(mlx->line) && j < mlx->height)
	{
		if (mlx->width <= mlx->height)
		{
			x = (1000 - ((mlx->space * mlx->width)- mlx->space)) / 2;
			mlx->start[1] = x;
		}
		x = mlx->start[1];
		i = 0;
		while (i < mlx->width && x < 1000 && *(mlx->line)++)
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
				mlx->pix[x][y].z = ft_atoi(&*(mlx->line));
				mlx->img_str[y * mlx->sl / 4 + x] = 0xFFFFFF;
				mlx->pix[x][y].col = 0xFFFF00;
				mlx->pix[x][y].x = x;
				mlx->pix[x][y].y = y;
				//k = y;
				//while (k < y + mlx->space)
				//{
					mlx->pix[x][y].col = 0xFFFFFF;//0x000000 + (mlx->pix[x][y].z * 20);
				//	k++;
				//}
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
		}
		j++;
		y += mlx->space;
	}
	mlx->map_y = y - mlx->space;
	mlx->map_x = x - mlx->space;
	i = 0;
//	while (i < 500)
//	{
//		i++;
//
//	}
	spin_x(mlx);
//	spin_y(mlx);
	print_x(mlx);
	print_y(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

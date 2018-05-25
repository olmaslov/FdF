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

	y = 0;
	while (y != 1000)
	{
		x = 0;
		while (x != 1000)
		{
			if (mlx->pix[x][y].next_x != 0)
			{
				//mlx->img_str[i * mlx->sl / 4 + 0] = 0xFFFFFF;
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

void		net_print(t_mlx *mlx)
{
	int y;
	int x;
	int i;
	int j;
	int space;

	space = 1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height));
	if (mlx->width >= mlx->height)
	{
		y = (1000 - ((space * mlx->height)- space)) / 2;
		mlx->start[0] = y;
	}
	else
	{
		y = (1000 - (space * mlx->height)) / 2;
		mlx->start[0] = y;
	}
	j = 0;
	while (*(mlx->line) && j < mlx->height)
	{
		if (mlx->width <= mlx->height)
		{
			x = (1000 - ((space * mlx->width)- space)) / 2;
			mlx->start[1] = x;
		}
		i = 0;
		while (i < mlx->width && x < 1000)
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
				mlx->img_str[y * mlx->sl / 4 + x] = 0xFFFFFF;
				mlx->pix[x][y].col = 0xFFFF00;
				mlx->pix[x][y].x = x;
				mlx->pix[x][y].y = y;
				i++;
				if (y + space < 1000 && j + 1 != mlx->height)
					mlx->pix[x][y].next_y = y + space;
				if (i != mlx->width)
					mlx->pix[x][y].next_x = x + space;
				if (y + space > mlx->max_y)
					mlx->max_y = y + space;
				if (x + space> mlx->max_x)
					mlx->max_x = x + space;
				x += space;
			}
			if (*mlx->line == ',')
			{
				*mlx->line++;
				mlx->pix[x - space][y].col = ft_atoi_hex(mlx->line);
			}
			*(mlx->line)++;
		}
		j++;
		y += space;
	}
	print_x(mlx);
	print_y(mlx);
}

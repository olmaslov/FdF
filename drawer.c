//
// Created by Oleksii MASLOV on 5/24/18.
//

#include "fdf.h"

void		print_y(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y != mlx->max_y)
	{
		if (mlx->pix[0][y].col != 0)
		{
			//mlx->img_str[i * mlx->sl / 4 + 0] = 0xFFFFFF;
			print_lines(mlx->pix[x][y].x, mlx->pix[x][y].x, mlx->pix[x][y].y, mlx->pix[x][y].next_y, mlx);
		}
		y = mlx->pix[x][y].next_y;
	}
//	y = 0;
//	while (x != mlx->max_x)
//	{
//		if (mlx->pix[0][y].col != 0)
//		{
//			//mlx->img_str[i * mlx->sl / 4 + 0] = 0xFFFFFF;
//			print_lines(mlx->pix[x][y].x, mlx->pix[x][y].next_x, mlx->pix[x][y].y, mlx->pix[x][y].next_y, mlx);
//		}
//		x = mlx->pix[x][y].next_x;
//	}
}

void		print_x(t_mlx *mlx)
{

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
		mlx->img_str[y * mlx->sl / 4 + x++] = 0xFFFFFF;
		error += deltaerr;
		if (2 * error >= deltax)
		{
			y += diry;
			error -= deltax;
		}
	}
}

void		net_print(t_mlx *mlx)
{
	int y;
	int x;
	int i;
	int j;
	int space;

	space = 1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height) + 1);
	if (mlx->width >= mlx->height)
		y = ((space * mlx->height) / 2) - space;
	else
		y = (1000 - (space * mlx->height)) / 2;
	j = 0;
	while (*(mlx->line) && j <= mlx->height)
	{
		if (mlx->width < mlx->height)
			x = (1000 - (space * mlx->width)) / 2;
		i = 0;
		while (i <= mlx->width)
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
//				mlx->img_str[y * mlx->sl / 4 + x] = 0xFFFFFF;
//				mlx->pix[x][y].col = 0xFFFFFF;
//				mlx->pix[x][y].x = x;
//				mlx->pix[x][y].y = y;
//				mlx->pix[x][y].next_x = x + space;
//				mlx->pix[x][y].next_y = y + space;
//				if (y + space > mlx->max_y)
//					mlx->max_y = y + space;
//				if (x + space> mlx->max_x)
//					mlx->max_x = x + space;
				i++;
				if (*(mlx->line) + 1 > 47  && *(mlx->line) + 1 < 58)
					print_lines(x, x + space, y, y, mlx);
				x += space;
			}
			if (*mlx->line == ',')
				mlx->line = &*mlx->line + 9;
			*(mlx->line)++;
		}
		j++;
		y += space;
	}
//	print_y(mlx);
}

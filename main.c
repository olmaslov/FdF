#include "fdf.h"

static int	my_key_funct(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
/*	if (keycode == 49) 												*/
/*		drawCircle(500, 500, mlx->i++, mlx);*/
	return (0);
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
	int space = 1000 / (((mlx->width >= mlx->height) ? mlx->width : mlx->height));

	y = 0;
	j = 0;
	while (*(mlx->line) && j <= mlx->height)
	{
		x = 0;
		i = 0;
		while (i <= mlx->width)
		{
			if (*(mlx->line) > 47 && *(mlx->line) < 58)
			{
				mlx->img_str[y * mlx->sl / 4 + x] = 0xFFFFFF;
				i++;
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
		read_file(mlx);
		net_print(mlx);
//		print_lines(0,1000,0,1000, mlx);
//		print_lines(500,0,1000,0, mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		mlx_loop(mlx->mlx_ptr);
		free(mlx);
	}
	return (0);
}

#include "fdf.h"

static int	my_key_funct(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		drawCircle(500, 500, mlx->i++, mlx);
	return (0);
}
// void put_pixel()

void drawCircle(int x0, int y0, int radius, t_mlx *mlx)
{
	int x = 0;
	int y = radius;
	float c = 1;
	int delta = 1 - 2 * radius;
	int error = 0;
	int z = 0;
	while(y >= 0)
	{
		z = (x / c);
		mlx->img_str[(y0 + y) * mlx->sl / 4 + (x0 + z)] = 0xFFFFFF;
		mlx->img_str[(y0 - y) * mlx->sl / 4 + (x0 + z)] = 0xFFFFFF;
		mlx->img_str[(y0 + y) * mlx->sl / 4 + (x0 - z)] = 0xFFFFFF;
		mlx->img_str[(y0 - y) * mlx->sl / 4 + (x0 - z)] = 0xFFFFFF;
		error = 2 * (delta + y) - 1;
		if(delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if(delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int drawCircle2(t_mlx *mlx)
{
	int x0 = 500;
	int y0 = 500;
	int radius = 200;
	int x = 0;
	int y = radius;
	int c = 5;
	int delta = 1 - 2 * radius;
	int error = 0;
	int z = 0;
	while (1)
	{
		while (y >= 0)
		{
			z = (x / c);
			mlx->img_str[(y0 + y) * mlx->sl / 4 + (x0 + z)] = 0xFFFFFF;
			mlx->img_str[(y0 - y) * mlx->sl / 4 + (x0 + z)] = 0xFFFFFF;
			mlx->img_str[(y0 + y) * mlx->sl / 4 + (x0 - z)] = 0xFFFFFF;
			mlx->img_str[(y0 - y) * mlx->sl / 4 + (x0 - z)] = 0xFFFFFF;
			error = 2 * (delta + y) - 1;
			if (delta < 0 && error <= 0)
			{
				++x;
				delta += 2 * x + 1;
				continue;
			}
			error = 2 * (delta - x) - 1;
			if (delta > 0 && error > 0)
			{
				--y;
				delta += 1 - 2 * y;
				continue;
			}
			++x;
			delta += 2 * (x - y);
			--y;
		}
		c++;
		printf("%d\n", c);
		if (c >= 10)
			return (1);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_mlx *mlx;

	if (argc > 1)
	{
		mlx = (t_mlx *) malloc(sizeof(t_mlx));
//		mlx->i = 100;
		mlx->file = argv[1];
		read_file(mlx);
//		mlx->mlx_ptr = mlx_init();
//		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "mlx test");
//		mlx_hook(mlx->win_ptr, 2, 5, my_key_funct, mlx);
//		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
//		mlx->img_str = (int *) mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), &(mlx->sl), &(mlx->end));
//		mlx_loop_hook(mlx->mlx_ptr, drawCircle2, mlx);
//		drawCircle(500, 500, mlx->i, mlx);
//		mlx_loop(mlx->mlx_ptr);
		free(mlx);
	}
	return 0;
}

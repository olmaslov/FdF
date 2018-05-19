#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "stdio.h"
#include "unistd.h"

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


int main()
{
	t_mlx *mlx;


	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->i = 100;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "mlx test");
	mlx_hook(mlx->win_ptr, 2, 5, my_key_funct, mlx);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	mlx->img_str = (int*)mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), &(mlx->sl), &(mlx->end));
	drawCircle(500, 500, mlx->i, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}

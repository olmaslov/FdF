#include "mlx.h"
#include "stdio.h"
#include "unistd.h"

void drawCircle(int x0, int y0, int radius, void *mlx_ptr, void *win_ptr) 
{
	int x = 0;
	int y = radius;
	float c = 1;
	int delta = 1 - 2 * radius;
	int error = 0;
	int flag = 0;
	while (1)
	{
		mlx_clear_window(mlx_ptr, win_ptr);
		y = radius;
		x = 0;
		delta = 1 - 2 * radius;
		error = 0;
		while(y >= 0) 
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + (x / c), y0 + y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + (x / c), y0 - y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - (x / c), y0 + y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - (x / c), y0 - y, 0xFFFFFF);
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
		usleep((c > 16) ? ((c > 20) ? 5000 : 15000) : 55000);
		printf("%f\n", c);
		if (flag == 0)
			{
				c += 0.1;
				flag = (c > 100) ? 1 : 0;
			}
		else if (flag == 1)
			{
				c -= 0.1;
				flag = (c < 1) ? 0 : 1;
			}
	}
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx test");
	drawCircle(500, 500, 300, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return 0;
}

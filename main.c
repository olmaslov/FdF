#include "mlx.h"

void drawCircle(int x0, int y0, int radius, void *mlx_ptr, void *win_ptr) 
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while(y >= 0) {
		mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 + y, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 - y, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 + y, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 - y, 0xFFFFFF);
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
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx test");
	drawCircle(100, 100, 100, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return 0;
}
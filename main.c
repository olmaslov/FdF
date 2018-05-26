#include "fdf.h"

static int	my_key_funct(int keycode)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
/*	if (keycode == 49) 												*/
/*		drawCircle(500, 500, mlx->i++, mlx);*/
	return (0);
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

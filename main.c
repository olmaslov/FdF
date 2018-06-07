/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:14:28 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/05 13:14:31 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	exit_x(void *par)
{
	par = NULL;
	exit(0);
	return (0);
}

static void	init_fdf(t_mlx *mlx)
{
	mlx->set = 1;
	mlx->x = 1;
	mlx->y = 1;
	mlx->z = 1;
	mlx->move_x = 0;
	mlx->move_y = 0;
	read_file(mlx);
	map_init(mlx);
}

void		print_instruction(t_mlx *mlx)
{
	char *tmp;

	tmp = ft_itoa(mlx->x);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1, 1, 0xFFFFFF, tmp);
	free(tmp);
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
		mlx_hook(mlx->win_ptr, 2, 5, keys, mlx);
		mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_x, mlx);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
		mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr,
							&(mlx->bpp), &(mlx->sl), &(mlx->img_end));
		init_fdf(mlx);
		mlx_loop_hook(mlx->mlx_ptr, draw_loop, mlx);
		mlx_loop(mlx->mlx_ptr);
		free(mlx);
	}
	return (0);
}

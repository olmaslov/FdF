/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:09:57 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 19:09:59 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_point_color(t_mlx *mlx, t_draw *dw)
{
	if (*mlx->line == ',')
	{
		dw->col = ft_atoi_hex(&*(mlx->line) + 1);
		mlx->pix[dw->x - (int)mlx->space][dw->y].col = dw->col;
		while (*mlx->line != ' ')
			mlx->line = &(*mlx->line) + 1;
	}
}

static void	point_set(t_mlx *mlx, t_draw *dw)
{
	if ((*(mlx->line) > 47 && *(mlx->line) < 58) || *(mlx->line) == '-')
	{
		mlx->pix[dw->x][dw->y].x = dw->x;
		mlx->pix[dw->x][dw->y].y = dw->y;
		dw->z = ft_atoi(&*(mlx->line));
		mlx->pix[dw->x][dw->y].z = dw->z * mlx->space;
		mlx->line = mlx->line + ft_nbrlen(dw->z);
		if (mlx->pix[dw->x][dw->y].z > 0)
			mlx->pix[dw->x][dw->y].col = (256 * (0x009f00 - dw->z));
		else
			mlx->pix[dw->x][dw->y].col = 0x5de7fc;
		dw->i++;
		if (dw->y + mlx->space < 1000 && dw->j + 1 != mlx->height)
			mlx->pix[dw->x][dw->y].next_y = dw->y + mlx->space;
		if (dw->x + mlx->space < 1000 && dw->i != mlx->width)
			mlx->pix[dw->x][dw->y].next_x = dw->x + mlx->space;
		if (mlx->height != 1 && mlx->width != 1)
		{
			mlx->max_x = (int)(dw->x + mlx->space);
			mlx->max_y = (int)(dw->y + mlx->space);
		}
		dw->x += mlx->space;
	}
	put_point_color(mlx, dw);
}

static void	fill_map(t_mlx *mlx, t_draw *dw)
{
	while (*(mlx->line) && dw->j < mlx->height)
	{
		dw->x = (1000 - (((int)mlx->space * mlx->width) - (int)mlx->space)) / 2;
		dw->i = 0;
		while (dw->i < mlx->width && dw->x < 1000 && *(mlx->line))
		{
			point_set(mlx, dw);
			while ((*(mlx->line) > 47 && *(mlx->line) < 58) ||
					*(mlx->line) == '-')
				mlx->line++;
			if (*mlx->line == ' ')
				mlx->line++;
		}
		dw->j++;
		dw->y += mlx->space;
	}
}

int			map_init(t_mlx *mlx)
{
	t_draw	*dw;
	char	*s;

	dw = (t_draw*)malloc(sizeof(t_draw));
	s = &(*mlx->line);
	if (!mlx->space)
		mlx->space = (1000 / (((mlx->width >= mlx->height) ?
							mlx->width : mlx->height)));
	if (mlx->width >= mlx->height)
		dw->y = (1000 - (((int)mlx->space * mlx->height) - (int)mlx->space)) / 2;
	else
		dw->y = (1000 - ((int)mlx->space * (mlx->height - 1))) / 2;
	dw->j = 0;
	dw->x = (1000 - (((int)mlx->space * mlx->width) - (int)mlx->space)) / 2;
	mlx->start_x = dw->x;
	mlx->start_y = dw->y;
	fill_map(mlx, dw);
	free(s);
	free(dw);
	return (0);
}

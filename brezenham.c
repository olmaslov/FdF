/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:49:50 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 20:49:54 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	brez_x(t_mlx *mlx, t_brz *brz, t_brz_in *brz_in)
{
	brz->d = (brz->dy << 1) - brz->dx;
	brz->d1 = brz->dy << 1;
	brz->d2 = (brz->dy - brz->dx) << 1;
	if (brz_in->y0 < 1001 && brz_in->y0 > -1 &&
			brz_in->x0 < 1000 && brz_in->x0 > -1)
		mlx->img_str[brz_in->y0 * mlx->sl / 4 + brz_in->x0] = brz_in->color;
	brz->x = brz_in->x0 + brz->sx;
	brz->y = brz_in->y0;
	brz->i = 1;
	while (brz->i <= brz->dx)
	{
		if (brz->d > 0)
		{
			brz->d += brz->d2;
			brz->y += brz->sy;
		}
		else
			brz->d += brz->d1;
		if (brz->y < 1001 && brz->y > -1 && brz->x < 1000 && brz->x > -1)
			mlx->img_str[brz->y * mlx->sl / 4 + brz->x] = brz_in->color;
		brz->i++;
		brz->x += brz->sx;
	}
}

static void	brez_y(t_mlx *mlx, t_brz *brz, t_brz_in *brz_in)
{
	brz->d = (brz->dx << 1) - brz->dy;
	brz->d1 = brz->dx << 1;
	brz->d2 = (brz->dx - brz->dy) << 1;
	if (brz_in->y0 < 1001 && brz_in->y0 > -1 &&
			brz_in->x0 < 1000 && brz_in->x0 > -1)
		mlx->img_str[brz_in->y0 * mlx->sl / 4 + brz_in->x0] = brz_in->color;
	brz->y = brz_in->y0 + brz->sy;
	brz->x = brz_in->x0;
	brz->i = 1;
	while (brz->i <= brz->dy)
	{
		if (brz->d > 0)
		{
			brz->d += brz->d2;
			brz->x += brz->sx;
		}
		else
			brz->d += brz->d1;
		if (brz->y < 1001 && brz->y > -1 && brz->x < 1000 && brz->x > -1)
			mlx->img_str[brz->y * mlx->sl / 4 + brz->x] = brz_in->color;
		brz->i++;
		brz->y += brz->sy;
	}
}

void		brezenham(t_mlx *mlx, t_brz_in *brz_in)
{
	t_brz *brz;

	brz = (t_brz*)malloc(sizeof(t_brz));
	brz->dx = abs(brz_in->x1 - brz_in->x0);
	brz->dy = abs(brz_in->y1 - brz_in->y0);
	brz->sx = brz_in->x1 >= brz_in->x0 ? 1 : -1;
	brz->sy = brz_in->y1 >= brz_in->y0 ? 1 : -1;
	if (brz->dy <= brz->dx)
	{
		brez_x(mlx, brz, brz_in);
	}
	else
	{
		brez_y(mlx, brz, brz_in);
	}
	free(brz);
}

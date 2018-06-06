/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:47:14 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/05 13:47:18 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LINUX_FDF_H
# define FDF_LINUX_FDF_H
# define PI 3.14159265359
# define SIN(val) sin(val * PI / 90)
# define COS(val) cos(val * PI / 90)

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <stdlib.h>
#include "math.h"
#include "mlx.h"
#include "stdio.h"
#include "unistd.h"



typedef	struct		s_pixel
{
	float 			x;
	float 			y;
	float 			z;
	float 			ny;
	float 			nx;
	float 			nz;
	float			next_x;
	float 			next_y;
	int				col;
}					t_pixel;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void 			*img_ptr;
	char			*file;
	char 			*line;
	int 			*img_str;
	int 			max_y;
	int 			max_x;
	int 			width;
	int				height;
	int 			sl;
	int				start_x;
	int				start_y;
	int 			img_end;
	int 			bpp;
	int 			i;
	int				x;
	int 			y;
	int 			z;
	int 			move_x;
	int             move_y;
	float 			space;
	int 			animate;
	float			set;
	t_pixel			pix[3000][3000];
}					t_mlx;

void				print_y(t_mlx *mlx);
void				print_x(t_mlx *mlx);
void				read_file(t_mlx *mlx);
void				print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx, int color);
int					net_print(t_mlx *mlx);
void				spin_x(t_mlx *mlx);
void				spin_y(t_mlx *mlx);
void				spin_z(t_mlx *mlx);
int 				draw(t_mlx *mlx);
void 				zoom(t_mlx *mlx);

#endif //FDF_LINUX_FDF_H

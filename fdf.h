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
# define SIN(val) sinf(val * PI / 90)
# define COS(val) cosf(val * PI / 90)
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <stdlib.h>
# include "math.h"
# include "mlx.h"
# include "stdio.h"
# include "unistd.h"

typedef	struct		s_pixel
{
	float			y;
	float			x;
	float			z;
	float			next_x;
	float			next_y;
	int				col;
}					t_pixel;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*file;
	char			*line;
	int				*img_str;
	int				max_y;
	int				max_x;
	int				width;
	int				height;
	int				sl;
	int				start_x;
	int				start_y;
	int				img_end;
	int				bpp;
	int				i;
	int				x;
	int				y;
	int				z;
	int				move_x;
	int				move_y;
	float			space;
	int				animate;
	int 			instruction;
	float			set;
	t_pixel			pix[1000][1000];
}					t_mlx;

typedef struct		s_draw
{
	int				y;
	int				x;
	int				i;
	int				j;
	int				z;
	int				col;
}					t_draw;

typedef struct		s_brz
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
	int				i;
	int				d;
	int				d1;
	int				d2;
}					t_brz;

typedef struct		s_brz_in
{
	int				color;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_brz_in;

void				print_y(t_mlx *mlx);
void				print_x(t_mlx *mlx);
void				read_file(t_mlx *mlx, int tmpclp, int height);
void				brezenham(t_mlx *mlx, t_brz_in *brz_in);
int					map_init(t_mlx *mlx);
void				spin_x(t_mlx *mlx);
void				spin_y(t_mlx *mlx);
void				spin_z(t_mlx *mlx);
int					draw_loop(t_mlx *mlx);
void				zoom(t_mlx *mlx);
void				move_map(t_mlx *mlx);
void				center(t_mlx *mlx);
void				rev_center(t_mlx *mlx);
int					ft_nbrlen(int num);
int					ft_atoi_hex(char *str);
void				print_instruction(t_mlx *mlx);
int					keys(int keycode, t_mlx *mlx);

#endif

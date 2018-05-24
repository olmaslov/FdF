//
// Created by Oleksii MASLOV on 5/19/18.
//

#ifndef FDF_LINUX_FDF_H
# define FDF_LINUX_FDF_H
# define PI 3.14159265359
# define SIN(val) sin(val * PI / 180)
# define COS(val) cos(val * PI / 180)

#include "libft/libft.h"
#include <stdlib.h>
#include "mlx.h"
#include "stdio.h"
#include "unistd.h"

#define SPACE = 10

typedef	struct		s_pixel
{
	int 			x;
	int 			y;
	int				next_x;
	int 			next_y;

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
	int 			end;
	int 			bpp;
	int 			i;
	t_pixel			pix[1001][1001];
}					t_mlx;

void				print_y(t_mlx *mlx);
void				print_x(t_mlx *mlx);
void				read_file(t_mlx *mlx);
void				print_lines(int x0, int x1, int y0, int y1, t_mlx *mlx);
void				net_print(t_mlx *mlx);

#endif //FDF_LINUX_FDF_H

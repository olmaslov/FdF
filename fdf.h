//
// Created by Oleksii MASLOV on 5/19/18.
//

#ifndef FDF_LINUX_FDF_H
#define FDF_LINUX_FDF_H

#include "libft/libft.h"
#include <stdlib.h>
#include "mlx.h"
#include "stdio.h"
#include "unistd.h"

#define SPACE = 10

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void 			*img_ptr;
	char			*file;
	char 			*line;
	int 			*img_str;
	int 			width;
	int 			sl;
	int 			end;
	int 			bpp;
	int 			i;
}					t_mlx;

void				drawCircle(int x0, int y0, int radius, t_mlx *mlx);
void				read_file(t_mlx *mlx);

#endif //FDF_LINUX_FDF_H

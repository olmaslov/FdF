//
// Created by Oleksii MASLOV on 5/19/18.
//

#ifndef FDF_LINUX_FDF_H
#define FDF_LINUX_FDF_H

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void 			*img_ptr;
	int 			*img_str;
	int 			sl;
	int 			end;
	int 			bpp;
	int 			i;
}					t_mlx;

void drawCircle(int x0, int y0, int radius, t_mlx *mlx);


#endif //FDF_LINUX_FDF_H

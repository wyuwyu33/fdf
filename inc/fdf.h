/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 03:22:33 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:04:56 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

# define WIN_HEIGHT	1080
# define WIN_WIDTH	1920

typedef struct s_vector
{
	int			color;
	double		x;
	double		y;
	double		z;
}	t_vector;

typedef struct s_map
{
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_vector	**vectors;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
}	t_mlx;

typedef struct s_chekerboard
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_checkerboard;

// terminate.c
void	terminate(char *str);

// read_fdf.c
int		read_fdf(int fd, t_map *map);

// parse_line.c
char	**get_parseline(int fd);
void	clear_parseline(char **parse_line);

// width.c
int		widthcmp(int c_width, char **parse_line);
int		init_width(char **parse_line);

// get_map.c
int		get_map(t_map *map, t_list *vectors_lst);

// convert_into_number.c
int		convert_into_number(char *str, int default_value);

// atoi_base.c
int		atoi_base(const char *str, int base);

// get_mlx.c
t_mlx	*get_mlx(t_map *map);

// render.c
void	render(t_mlx mlx);

// rotate.c
void	rotate_x(double *y, double *z, double radian);
void	rotate_y(double *x, double *z, double radian);
void	rotate_z(double *x, double *y, double radian);

// bresenham.c
void	bresenham(t_checkerboard start, t_checkerboard end, t_img img);

// iso.c
void	iso(t_map map);

// place.c
void	place(t_map *map);

// setup_controller.c
void	setup_controller(t_mlx *mlx);

#endif
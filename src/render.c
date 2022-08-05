/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:29:54 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 12:03:16 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
t_checkerboard	vector_round(t_vector vector)
{
	t_checkerboard	ret;

	ret.x = (int)(vector.x + 0.5);
	ret.y = (int)(vector.y + 0.5);
	ret.z = (int)(vector.z + 0.5);
	ret.color = vector.color;
	return (ret);
}

static
void	render_line(t_vector vector_o1, t_vector vector_o2, t_mlx mlx)
{
	t_checkerboard	board_1;
	t_checkerboard	board_2;

	board_1 = vector_round(vector_o1);
	board_2 = vector_round(vector_o2);
	bresenham(board_1, board_2, *mlx.img);
}

void	render(t_mlx mlx)
{
	int			i_height;
	int			i_width;

	iso(*mlx.map);
	place(mlx.map);
	i_height = 0;
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	while (i_height < mlx.map->height)
	{
		i_width = 0;
		while (i_width < mlx.map->width)
		{
			if (i_width + 1 < mlx.map->width)
				render_line(mlx.map->vectors[i_height][i_width], \
							mlx.map->vectors[i_height][i_width + 1], mlx);
			if (i_height + 1 < mlx.map->height)
				render_line(mlx.map->vectors[i_height][i_width], \
							mlx.map->vectors[i_height + 1][i_width], mlx);
			i_width++;
		}
		i_height++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img->img_ptr, 0, 0);
}

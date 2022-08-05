/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:50:18 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:00:53 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
t_img	*get_img(t_mlx mlx)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		terminate("Dynamic allocation error");
	img->img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		return (NULL);
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
									&img->size_line, &img->endian);
	if (!img->data_addr)
	{
		mlx_destroy_image(mlx.mlx_ptr, img->img_ptr);
		return (NULL);
	}
	return (img);
}

t_mlx	*get_mlx(t_map *map)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		terminate("Dynamic allocation error");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!mlx->win_ptr)
		return (NULL);
	mlx->img = get_img(*mlx);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (NULL);
	}
	mlx->map = map;
	return (mlx);
}

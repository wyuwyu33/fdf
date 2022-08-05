/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:32:28 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 02:44:24 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
int	hook_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

void	setup_controller(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
}

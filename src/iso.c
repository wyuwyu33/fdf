/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:09:07 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:00:58 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
void	transfrom(t_vector *vector, t_map map)
{
	vector->x -= (map.width - 1) / 2.0;
	vector->y -= (map.height - 1) / 2.0;
	vector->z -= (map.z_max - map.z_min) / 2.0;
	rotate_z(&vector->x, &vector->y, -0.785398);
	rotate_x(&vector->y, &vector->z, 0.57735);
}

void	iso(t_map map)
{
	int			i_height;
	int			i_width;
	t_vector	**vectors;

	vectors = map.vectors;
	i_height = 0;
	while (i_height < map.height)
	{
		i_width = 0;
		while (i_width < map.width)
		{
			transfrom(&vectors[i_height][i_width], map);
			i_width++;
		}
		i_height++;
	}
}

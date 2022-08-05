/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:12:13 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:40 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
void	extreme_init(t_map *map)
{
	map->x_max = INT_MIN;
	map->x_min = INT_MAX;
	map->y_max = INT_MIN;
	map->y_min = INT_MAX;
}

static
void	extreme(t_map *map)
{
	int	i_height;
	int	i_width;

	extreme_init(map);
	i_height = 0;
	while (i_height < map->height)
	{
		i_width = 0;
		while (i_width < map->width)
		{
			if (map->y_max < (int)map->vectors[i_height][i_width].y)
				map->y_max = (int)map->vectors[i_height][i_width].y;
			if (map->y_min > (int)map->vectors[i_height][i_width].y)
				map->y_min = (int)map->vectors[i_height][i_width].y;
			if (map->x_max < (int)map->vectors[i_height][i_width].x)
				map->x_max = (int)map->vectors[i_height][i_width].x;
			if (map->x_min > (int)map->vectors[i_height][i_width].x)
				map->x_min = (int)map->vectors[i_height][i_width].x;
			i_width++;
		}
		i_height++;
	}
}

static
void	zoom(t_vector *vector, int height_range, int width_range)
{
	int	magni_y;
	int	magni_x;

	magni_x = WIN_WIDTH / width_range;
	magni_y = WIN_HEIGHT / height_range;
	vector->x *= magni_x;
	vector->y *= magni_y;
	vector->x += WIN_WIDTH / 2.0;
	vector->y += WIN_HEIGHT / 2.0;
}

void	place(t_map *map)
{
	int	i_height;
	int	i_width;

	extreme(map);
	i_height = 0;
	while (i_height < map->height)
	{
		i_width = 0;
		while (i_width < map->width)
		{
			zoom(&map->vectors[i_height][i_width], \
				map->y_max - map->y_min, map->x_max - map->x_min);
			i_width++;
		}
		i_height++;
	}
}

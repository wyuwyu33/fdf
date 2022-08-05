/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 04:39:08 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:00:27 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
void	get_vectors(t_map *map, t_list *vectors_lst)
{
	t_vector	**vector;
	int			i_height;
	int			i_width;
	char		**part;

	vector = map->vectors;
	i_height = 0;
	while (i_height < map->height)
	{
		i_width = 0;
		while (i_width < map->width)
		{
			part = ft_split((char *)vectors_lst->content, ',');
			vector[i_height][i_width].x = (double)i_width;
			vector[i_height][i_width].y = (double)i_height;
			vector[i_height][i_width].z = \
					(double)convert_into_number(part[0], 0);
			vector[i_height][i_width].color = \
					convert_into_number(part[1], 0xFFFFFF);
			clear_parseline(part);
			vectors_lst = vectors_lst->next;
			i_width++;
		}
		i_height++;
	}
}

static
void	get_z(t_map *map)
{
	int			i_height;
	int			i_width;
	int			*z_min;
	int			*z_max;
	t_vector	**vectors;

	z_min = &map->z_min;
	z_max = &map->z_max;
	vectors = map->vectors;
	*z_min = INT_MAX;
	*z_max = INT_MIN;
	i_height = 0;
	while (i_height < map->height)
	{
		i_width = 0;
		while (i_width < map->width)
		{
			if (*z_min > (int)vectors[i_height][i_width].z)
				*z_min = (int)vectors[i_height][i_width].z;
			if (*z_max < (int)vectors[i_height][i_width].z)
				*z_max = (int)vectors[i_height][i_width].z;
			i_width++;
		}
		i_height++;
	}
}

int	get_map(t_map *map, t_list *vectors_lst)
{
	int	i_height;

	if (!map || !vectors_lst)
		return (0);
	map->vectors = (t_vector **)ft_calloc(sizeof(t_vector *), map->height);
	if (!map->vectors)
		terminate("Dynamic allocation error");
	i_height = 0;
	while (i_height < map->height)
	{
		map->vectors[i_height] = \
				(t_vector *)ft_calloc(sizeof(t_vector), map->width);
		if (!map->vectors[i_height])
			terminate("Dynamic allocation error");
		i_height++;
	}
	get_vectors(map, vectors_lst);
	get_z(map);
	return (1);
}

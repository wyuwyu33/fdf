/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 03:22:15 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:26 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
void	fdf_init(t_map *map)
{
	errno = 0;
	ft_bzero(map, sizeof(t_map));
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_mlx	*mlx;

	fdf_init(&map);
	if (argc != 2)
		terminate("Argument error");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		terminate("FD error");
	if (!read_fdf(fd, &map))
		terminate("FDF error");
	mlx = get_mlx(&map);
	if (!mlx)
		terminate("MLX error");
	render(*mlx);
	setup_controller(mlx);
	mlx_loop(mlx->mlx_ptr);
	terminate("LOOP error");
}

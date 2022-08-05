/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 04:34:12 by wyu               #+#    #+#             */
/*   Updated: 2022/08/04 04:35:32 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	widthcmp(int c_width, char **parse_line)
{
	int	i_width;

	i_width = 0;
	while (parse_line[i_width])
		i_width++;
	if (c_width != i_width)
		return (1);
	return (0);
}

int	init_width(char **parse_line)
{
	int	i_width;

	i_width = 0;
	while (parse_line[i_width])
		i_width++;
	return (i_width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 04:33:45 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:35 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	**get_parseline(int fd)
{
	char	*line;
	char	**ret;

	line = get_next_line(fd);
	if (line && ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	ret = ft_split(line, ' ');
	free(line);
	return (ret);
}

void	clear_parseline(char **parse_line)
{
	int	i;

	i = 0;
	while (parse_line[i])
	{
		free(parse_line[i]);
		i++;
	}
	free(parse_line[i]);
	free(parse_line);
}

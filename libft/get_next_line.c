/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:37:27 by wyu               #+#    #+#             */
/*   Updated: 2022/07/29 01:41:14 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_lf(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i);
	return (-1);
}

static char	*ft_read_all(char **s1, char *s2)
{
	s2 = ft_strdup(*s1);
	if (!s2 || !ft_strlen(s2))
	{
		free((void *)s2);
		s2 = NULL;
	}
	free((void *)*s1);
	*s1 = NULL;
	return (s2);
}

static char	*ft_linedup(char **s1, int s2_size)
{
	char	*s2;
	char	*tmp;

	s2 = NULL;
	if (s2_size < 0)
		return (ft_read_all(s1, s2));
	tmp = ft_strdup(*s1 + s2_size + 1);
	s2 = (char *)malloc(s2_size + 2);
	if (!s2)
	{
		free((void *)tmp);
		return (NULL);
	}
	ft_strlcpy(s2, *s1, (size_t)s2_size + 2);
	free((void *)*s1);
	*s1 = tmp;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*backup[FD_SIZE] = {0, };
	char		buffer[BUFFER_SIZE + 1];
	int			read_size;
	int			find_lf;

	if (fd < 0 || FD_SIZE <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		find_lf = ft_is_lf(backup[fd]);
		if (find_lf >= 0)
			return (ft_linedup(&backup[fd], find_lf));
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		backup[fd] = ft_strjoin_gnl(backup[fd], buffer);
		if (!backup[fd])
			return (NULL);
	}
	return (ft_linedup(&backup[fd], -1));
}

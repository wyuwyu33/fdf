/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:02:54 by wyu               #+#    #+#             */
/*   Updated: 2022/07/26 21:54:51 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *)malloc((s1_len + s2_len + 1));
	if (!new_s)
	{
		free((void *)s1);
		return (NULL);
	}
	ft_strlcpy(new_s, s1, s1_len + 1);
	ft_strlcpy(new_s + s1_len, s2, s2_len + 1);
	free((void *)s1);
	return (new_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_into_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 05:10:45 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:00:11 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
int	is_hexadecimal(char *s)
{
	if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
		return (1);
	return (0);
}

static
int	is_octal(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

static
int	is_decimal(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

static
void	to_uppercase(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}

int	convert_into_number(char *str, int default_value)
{
	int	notation;

	if (!str)
		return (default_value);
	if (is_hexadecimal(str))
		notation = 16;
	else if (is_octal(*str))
		notation = 8;
	else if (is_decimal(*str))
		notation = 10;
	else
		return (0);
	to_uppercase(str);
	return (atoi_base(str, notation));
}

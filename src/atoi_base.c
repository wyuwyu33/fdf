/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 05:12:04 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 14:59:55 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
int	valid_number(char c, int base)
{
	int		i;
	char	*symbol;

	i = 0;
	symbol = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == symbol[i])
			return (1);
		i++;
	}
	return (0);
}

static
int	ctoi(char c, int base)
{
	int		i;
	char	*symbol;

	i = 0;
	symbol = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == symbol[i])
			return (i);
		i++;
	}
	return (0);
}

int	atoi_base(const char *str, int base)
{
	long long	nbr;
	long long	sign;
	size_t		i;

	i = 0;
	sign = 1;
	if (base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while (str[i] && valid_number(str[i], base))
	{
		nbr = (nbr * base) + ctoi(str[i], base);
		if (sign * nbr > 0xFFFFFF)
			return (INT_MAX);
		if (sign * nbr < -0xFFFFFF)
			return (INT_MIN);
		i++;
	}
	return ((int)(sign * nbr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:15:18 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 13:25:12 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static
void	bres_init(t_checkerboard *delta, t_checkerboard *sign, \
				t_checkerboard start, t_checkerboard end)
{
	delta->x = ft_abs(end.x - start.x);
	delta->y = -ft_abs(end.y - start.y);
	if (start.x < end.x)
		sign->x = 1;
	else if (start.x > end.x)
		sign->x = -1;
	else
		sign->x = 0;
	if (start.y < end.y)
		sign->y = 1;
	else if (start.y > end.y)
		sign->y = -1;
	else
		sign->y = 0;
}

static
void	put_pixel(t_img img, int x, int y, int color)
{
	int	i;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	i = (x * img.bpp / 8) + (y * img.size_line);
	img.data_addr[i] = color;
	img.data_addr[++i] = color >> 8;
	img.data_addr[++i] = color >> 16;
}

void	bresenham(t_checkerboard start, t_checkerboard end, t_img img)
{
	t_checkerboard	delta;
	t_checkerboard	sign;
	int				err[2];

	bres_init(&delta, &sign, start, end);
	err[0] = delta.x + delta.y;
	while (1)
	{
		put_pixel(img, start.x, start.y, end.color);
		if (start.x == end.x && start.y == end.y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= delta.y)
		{
			err[0] += delta.y;
			start.x += sign.x;
		}
		if (err[1] <= delta.x)
		{
			err[0] += delta.x;
			start.y += sign.y;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:01:55 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:02:04 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_x(double *y, double *z, double radian)
{
	double	previous_y;
	double	previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(radian) + previous_z * -sin(radian);
	*z = previous_y * sin(radian) + previous_z * cos(radian);
}

void	rotate_y(double *x, double *z, double radian)
{
	double	previous_x;
	double	previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(radian) + previous_z * sin(radian);
	*z = previous_x * -sin(radian) + previous_z * cos(radian);
}

void	rotate_z(double *x, double *y, double radian)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(radian) + previous_y * -sin(radian);
	*y = previous_x * sin(radian) + previous_y * cos(radian);
}

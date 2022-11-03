/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:39:22 by wismith           #+#    #+#             */
/*   Updated: 2022/11/03 17:14:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct s_polar
{
	double	r;
	double	angle;
}	t_polar;

typedef struct s_cord
{
	double	x;
	double	y;
}	t_cord;

t_polar	to_polar(t_cord *cord)
{
	t_polar	polar;

	polar.r = sqrt((cord->x * cord->x) + (cord->y * cord->y));
	polar.angle = atan(cord->y / cord->x);
	return (polar);
}

t_cord	to_cord(t_polar *polar)
{
	t_cord	cord;

	cord.x = polar->r * cos(polar->angle);
	cord.y = polar->r * sin(polar->angle);
	return (cord);
}

void	print_degrees(double radian)
{
	printf("degrees: %f\n", radian * (180 / 3.14159));
}

int	main(void)
{
	t_polar	polar;
	t_cord	cord;
	t_cord	res;

	cord.x = 4;
	cord.y = 4;
	polar = to_polar(&cord);
	res = to_cord(&polar);
	printf("radius: %f\t", polar.r);
	print_degrees(polar.angle);
	printf("x: %f\t\ty: %f\n", res.x, res.y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:21:48 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 20:41:49 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FDF.h"

void	image_rotate(t_point **map, t_data *img, double h, double v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img->wy)
	{
		j = -1;
		while (++j < img->wx)
		{
			map[i][j].xx = (cos(-M_PI_4 + h) * map[i][j].x \
					- sin(-M_PI_4 + h) * map[i][j].y) * img->relx;
			map[i][j].yy = (sin(-M_PI_4 + h) * map[i][j].x \
					+ cos(-M_PI_4 + h) * map[i][j].y) * img->rely;
			map[i][j].zz = map[i][j].z * img->relz * cos(v);
			map[i][j].yy = map[i][j].yy * sin(M_PI / 6 + v);
			map[i][j].yz = map[i][j].yy - map[i][j].zz;
		}
	}
}

void	plot_low(t_data *img, t_point p1, t_point p2)
{
	t_plot	dot;

	dot.dx = p2.xx - p1.xx;
	dot.dy = p2.yz - p1.yz;
	dot.x = p1.xx + img->move.x;
	dot.y = p1.yz + img->move.y;
	dot.i = 1;
	if (dot.dy < 0)
	{
		dot.dy *= -1;
		dot.i = -1;
	}
	dot.deter = 2 * dot.dy - dot.dx;
	while (dot.x <= p2.xx + img->move.x)
	{
		my_mlx_pixel_put(img, dot.x, dot.y, p2.color);
		if (dot.deter > 0)
		{
			dot.y = dot.y + dot.i;
			dot.deter = dot.deter + (2 * (dot.dy - dot.dx));
		}
		else
			dot.deter = dot.deter + 2 * dot.dy;
		dot.x++;
	}
}

void	plot_high(t_data *img, t_point p1, t_point p2)
{
	t_plot	dot;

	dot.dx = p2.xx - p1.xx;
	dot.dy = p2.yz - p1.yz;
	dot.x = p1.xx + img->move.x;
	dot.y = p1.yz + img->move.y;
	dot.i = 1;
	if (dot.dx < 0)
	{
		dot.dx *= -1;
		dot.i = -1;
	}
	dot.deter = 2 * dot.dx - dot.dy;
	while (dot.y <= p2.yz + img->move.y)
	{
		my_mlx_pixel_put(img, dot.x, dot.y, p2.color);
		if (dot.deter > 0)
		{
			dot.x = dot.x + dot.i;
			dot.deter = dot.deter + (2 * (dot.dx - dot.dy));
		}
		else
			dot.deter = dot.deter + 2 * dot.dx;
		dot.y++;
	}
}

void	bresenham(t_data *img, t_point p1, t_point p2)
{
	int	dx;
	int	dy;

	dx = ft_abs(p2.xx - p1.xx);
	dy = ft_abs(p2.yz - p1.yz);
	if (dy <= dx)
	{
		if (p1.xx > p2.xx)
			plot_low(img, p2, p1);
		else
			plot_low(img, p1, p2);
	}
	else
	{
		if (p1.yz > p2.yz)
			plot_high(img, p2, p1);
		else
			plot_high(img, p1, p2);
	}
}

void	plot_line(t_point **map, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img->wy)
	{
		j = -1;
		while (++j < img->wx)
		{
			if (i - 1 >= 0)
				bresenham(img, map[i - 1][j], map[i][j]);
			if (j - 1 >= 0)
				bresenham(img, map[i][j - 1], map[i][j]);
		}
	}
}

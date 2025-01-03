/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:24:06 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 18:54:22 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	ft_key_action(int key, t_data *img)
{
	if (key == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	else if (key >= 123 && key <= 126)
		image_move(img, 5, key);
	else if (key == 6 || key == 7)
		z_value_change(img, 0.1, key);
	else if (key == 34)
		value_init(img);
	else if (key == 31)
		image_side_view(img);
	else if (key == 0)
		image_rotate_key(img, -0.1, 0);
	else if (key == 2)
		image_rotate_key(img, 0.1, 0);
	else if (key == 13)
		image_rotate_key(img, 0, 0.1);
	else if (key == 1)
		image_rotate_key(img, 0, -0.1);
	window_draw(img->map, img);
	return (0);
}

int	ft_press_cross(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
	return (0);
}

int	ft_zoom(int button, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (button == 5)
		image_resizing(img, -0.1);
	else if (button == 4)
		image_resizing(img, 0.1);
	window_draw(img->map, img);
	return (0);
}

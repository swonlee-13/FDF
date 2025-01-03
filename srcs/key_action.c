/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:43:37 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 19:22:43 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	image_move(t_data *img, int num, int key)
{
	if (key == 123)
		img->move.x += -num;
	if (key == 124)
		img->move.x += num;
	if (key == 125)
		img->move.y += num;
	if (key == 126)
		img->move.y += -num;
}

void	z_value_change(t_data *img, double num, int key)
{
	if (key == 7)
		num *= -1;
	img->relz += num;
	if (img->relz < 0)
		img->relz = 0;
}

void	image_resizing(t_data *img, double num)
{
	img->relx *= (1 + num);
	img->rely *= (1 + num);
	img->relz *= (1 + num);
}

void	image_rotate_key(t_data *img, double hor, double ver)
{
	img->move.hor += hor;
	img->move.ver += ver;
}

void	image_side_view(t_data *img)
{
	relative_val_init(img);
	img->move.x = img->winx / 2;
	img->move.y = img->winy / 2;
	img->move.hor = M_PI_4;
	img->move.ver = -M_PI / 6;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:39:08 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 19:24:43 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FDF.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || y < 0) || x > img->winx - 2 || y > img->winy - 2)
		return ;
	dst = img->addr + ((y * img->line_length) + \
			x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	window_draw(t_point **map, t_data *img)
{
	img->img = mlx_new_image(img->mlx, img->winx, img->winy);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
			&(img->line_length), &(img->endian));
	image_rotate(img->map, img, img->move.hor, img->move.ver);
	plot_line(map, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	relative_val_init(t_data *img)
{
	if (img->wx < 10)
		img->relx = 24;
	else if (img->wx < 40)
		img->relx = 16;
	else if (img->wx < 300)
		img->relx = 5;
	else
		img->relx = 1;
	if (img->wy < 10)
		img->rely = 24;
	else if (img->wy < 40)
		img->rely = 16;
	else if (img->wy < 300)
		img->rely = 5;
	else
		img->rely = 1;
	img->relz = 2;
	init_max_coordinate(img);
}

void	value_init(t_data *img)
{
	relative_val_init(img);
	img->winx = (img->wx) * 2 * img->relx;
	img->winy = (img->wy) * 2 * img->rely;
	img->move.x = img->winx / 2;
	img->move.y = img->winy / 2;
	img->move.hor = 0;
	img->move.ver = 0;
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac != 2 || strcmp(av[1] + ft_strlen(av[1]) - 4, ".fdf") != 0)
	{
		write(1, "Usage : ./fdf <filename>\n", 25);
		return (0);
	}
	map_size_check(av[1], &img);
	value_init(&img);
	img.map = coordinate_init(av[1], &img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.winx, img.winy, "FDF");
	window_draw(img.map, &img);
	mlx_hook(img.mlx_win, 2, 0, ft_key_action, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_press_cross, &img);
	mlx_hook(img.mlx_win, 4, 1L << 2, ft_zoom, &img);
	mlx_loop(img.mlx);
}

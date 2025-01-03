/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:35:39 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 21:33:12 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				xx;
	int				yy;
	int				zz;
	double			yz;
	unsigned int	color;
}	t_point;

typedef struct s_move
{
	int		x;
	int		y;
	double	hor;
	double	ver;
}	t_move;

typedef struct s_data
{
	t_point	**map;
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wx;
	int		wy;
	double	relx;
	double	rely;
	double	relz;
	int		winx;
	int		winy;
	t_move	move;
}	t_data;

typedef struct s_plot
{
	int	dx;
	int	dy;
	int	deter;
	int	x;
	int	y;
	int	i;
}	t_plot;

//plot_line.c
void			bresenham(t_data *img, t_point p1, t_point p2);
void			image_rotate(t_point **map, t_data *img, double h, double v);
void			plot_line(t_point **map, t_data *img);

//main.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			window_draw(t_point **map, t_data *img);
int				map_x(char *path);
int				map_y(char *path);
void			value_init(t_data *img);
void			relative_val_init(t_data *img);

//map_init.c
t_point			**coordinate_init(char *file, t_data *img);
void			win_init(char *file, t_data *img);
void			map_size_check(char *path, t_data *img);
void			init_max_coordinate(t_data *img);

//key_action.c
void			image_move(t_data *img, int num, int key);
void			z_value_change(t_data *img, double num, int key);
void			image_resizing(t_data *img, double num);
void			image_side_view(t_data *img);
void			image_rotate_key(t_data *img, double hor, double ver);

//util.c
unsigned int	ft_atoi_hex(char *str);
int				ft_abs(int nb);
int				ft_strslen(char **strs);
void			ft_free(char **str);

//bonus.c
int				ft_key_action(int key, t_data *img);
int				ft_press_cross(t_data *img);
int				ft_zoom(int button, int x, int y, t_data *img);
#endif

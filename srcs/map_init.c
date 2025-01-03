/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:29:30 by seongwol          #+#    #+#             */
/*   Updated: 2023/10/11 23:13:27 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	line_init(t_point **map, int i, int fd, t_data *img)
{
	char	**temp;
	char	*buffer;
	int		j;

	buffer = get_next_line(fd);
	temp = ft_split(buffer, ' ');
	free(buffer);
	map[i] = ft_calloc(sizeof(t_point), img->wx);
	j = -1;
	while (++j < img->wx)
	{
		map[i][j].x = j - (img->wx - 1) / 2;
		map[i][j].y = i - (img->wy - 1) / 2;
		map[i][j].z = ft_atoi(temp[j]);
		if (ft_strchr(temp[j], ','))
			map[i][j].color = ft_atoi_hex((ft_strchr(temp[j], ',') + 3));
		else
			map[i][j].color = 0xffffff;
	}
	ft_free(temp);
}

t_point	**coordinate_init(char *file, t_data *img)
{
	t_point	**map;
	int		fd;
	int		i;

	map = ft_calloc(sizeof(t_point *), img->wy);
	fd = open(file, O_RDONLY);
	i = -1;
	while (++i < img->wy)
		line_init(map, i, fd, img);
	close(fd);
	return (map);
}

int	map_size_x(char *buffer)
{
	char	**temp;
	int		x_max;

	temp = ft_split(buffer, ' ');
	if (!temp)
		exit(1);
	x_max = ft_strslen(temp);
	if (temp[x_max - 1] != 0 && temp[x_max - 1][0] == '\n')
		x_max--;
	ft_free(temp);
	return (x_max);
}

void	map_size_check(char *path, t_data *img)
{
	int		fd;
	char	*buffer;
	int		y_max;

	fd = open(path, O_RDONLY);
	buffer = get_next_line(fd);
	if (!buffer)
	{
		write(1, "File doesn't exist\n", 19);
		exit(0);
	}
	img->wx = map_size_x(buffer);
	y_max = 1;
	while (buffer)
	{
		free(buffer);
		buffer = NULL;
		buffer = get_next_line(fd);
		y_max++;
	}
	y_max--;
	free(buffer);
	close(fd);
	img->wy = y_max;
}

void	init_max_coordinate(t_data *img)
{
	if (img->wx > img->wy)
		img->rely = img->relx;
	if (img->wy > img->wx)
		img->relx = img->rely;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:21:36 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/26 20:39:26 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static int	ft_hex_isdigit(char c)
{
	if (ft_isdigit(c) || (c >= 97 && c <= 102) || (c >= 65 && c <= 70))
		return (1);
	return (0);
}

unsigned int	ft_atoi_hex(char *str)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (ft_hex_isdigit(str[i]))
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res * 16 + str[i] - 48;
		else if (str[i] >= 97 && str[i] <= 102)
			res = res * 16 + str[i] - 87;
		else
			res = res * 16 + str[i] - 55;
		i++;
	}
	return (res);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return (0);
	while (strs[i])
		i++;
	return (i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

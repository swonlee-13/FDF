/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:49:35 by seongwol          #+#    #+#             */
/*   Updated: 2023/07/07 21:04:58 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **strs, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static const char	*ft_cut_length(char const *str, char c, size_t *len)
{
	while (*str && *str == c)
		str++;
	while (*(str + *len) && *(str + *len) != c)
		(*len)++;
	return (str);
}

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}	
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	index;
	size_t	count;
	size_t	len;

	index = 0;
	count = ft_word_count(s, c);
	strs = (char **)ft_calloc(sizeof(char *), count + 1);
	if (strs == 0)
		return (NULL);
	strs[count] = NULL;
	while (index < count)
	{
		len = 0;
		s = ft_cut_length(s, c, &len);
		strs[index] = ft_substr(s, 0, len);
		if (!strs[index])
			return (ft_free(strs, index));
		s += len + 1;
		index++;
	}
	if (strs[0] == NULL)
		return (ft_free(strs, 0));
	return (strs);
}

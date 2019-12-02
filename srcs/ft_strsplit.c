/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:35:39 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 13:48:33 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_strccount(char const *s, char c)
{
	size_t	nb;
	size_t	i;
	int		flag;
	char	*source;

	source = (char *)s;
	flag = 0;
	nb = 0;
	i = 0;
	while (source[i] == c && source[i])
		i++;
	while (source[i])
	{
		if (source[i] == c)
			flag = 0;
		if (source[i] != c && !flag)
		{
			flag = 1;
			nb++;
		}
		i++;
	}
	return (nb);
}

static size_t	increment_i(size_t i, char **result, char const *s, char c)
{
	size_t	nb;

	nb = 0;
	while (s[i + nb] != c && s[i + nb])
		nb++;
	if (!(*result = (char *)malloc(sizeof(char) * (nb + 1))))
		return (0);
	nb = 0;
	while (s[i + nb] != c && s[i + nb])
	{
		(*result)[nb] = s[i + (nb)];
		nb++;
	}
	(*result)[nb] = '\0';
	return (nb + i);
}

static void		clean(char **result)
{
	while (*result)
	{
		free(*result);
		result++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	nb;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	nb = ft_strccount(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	ft_bzero(result, sizeof(char*) * (nb + 1));
	while (j < nb)
	{
		while (s[i] == c)
			i++;
		if ((i = increment_i(i, &result[j], s, c)) == 0)
		{
			clean(result);
			return (NULL);
		}
		j++;
	}
	return (result);
}

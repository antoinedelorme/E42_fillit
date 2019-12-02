/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:01 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/14 12:57:40 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && (i < dstsize))
		i++;
	if (i == dstsize)
	{
		while ((src[j]))
			j++;
		return (i + j);
	}
	while (((j) < (dstsize - i - 1)))
	{
		if (src[j] == '\0')
			break ;
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while ((src[j]))
		j++;
	return (i + j);
}

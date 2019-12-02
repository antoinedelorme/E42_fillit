/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:55:53 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/14 12:56:53 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst,
	const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*result;

	i = 0;
	from = (unsigned char*)src;
	result = (unsigned char*)dst;
	while (i < n)
	{
		result[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (result + i + 1);
		i++;
	}
	return (NULL);
}

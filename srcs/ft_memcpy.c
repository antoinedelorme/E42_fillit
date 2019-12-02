/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:44:20 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/14 12:56:33 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*from;
	size_t			i;

	result = (unsigned char*)dst;
	from = (unsigned char*)src;
	if (!(dst) && !(src))
		return (dst);
	i = 0;
	while (i < n)
	{
		result[i] = from[i];
		i++;
	}
	return (result);
}

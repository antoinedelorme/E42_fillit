/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:15:14 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/12 16:10:07 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*result;

	from = (unsigned char *)src;
	result = (unsigned char *)dst;
	if (!(dst) && !(src))
		return (dst);
	i = 0;
	while (i < len)
	{
		if (src > dst)
			result[i] = from[i];
		else
			result[len - i - 1] = from[len - i - 1];
		i++;
	}
	return (result);
}

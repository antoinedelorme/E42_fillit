/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:27:18 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/08 12:02:41 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*from;

	i = 0;
	from = (char*)s;
	while (i < n)
	{
		if (from[i] == (signed char)c)
			return (from + i);
		i++;
	}
	return (NULL);
}

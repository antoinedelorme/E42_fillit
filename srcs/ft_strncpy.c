/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:11:45 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/11 14:50:06 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((i < len))
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	while ((i < len))
		dst[i++] = '\0';
	return (dst);
}

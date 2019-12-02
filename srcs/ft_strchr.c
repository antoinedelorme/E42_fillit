/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:20:54 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/08 18:26:54 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*loop;
	size_t	i;

	i = 0;
	loop = (char*)s;
	while (loop[i])
	{
		if (loop[i] == (signed char)c)
			return (loop + i);
		loop++;
	}
	if (c == '\0')
		return (loop);
	return (NULL);
}

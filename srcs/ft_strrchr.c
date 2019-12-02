/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:07:06 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/14 11:45:24 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*loop;
	size_t	i;

	i = 0;
	loop = (char*)s;
	while (loop[i])
		i++;
	if ((signed char)c == '\0')
		return (loop + i);
	while (i >= 0)
	{
		if (loop[i] == (signed char)c)
			return (loop + i);
		if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}

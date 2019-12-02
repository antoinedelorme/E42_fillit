/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:02:19 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/26 12:02:06 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*result;
	char	*source;

	if (!s || !f)
		return ((char*)s);
	source = (char*)s;
	len = ft_strlen(source);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (source[i])
	{
		result[i] = (*f)(source[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

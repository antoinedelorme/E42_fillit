/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:21:53 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/26 11:47:27 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*result;
	char			*source;

	if (!s)
		return (NULL);
	if (!f)
		return ((char*)s);
	source = (char*)s;
	len = ft_strlen(source);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (source[i])
	{
		result[i] = (*f)(i, source[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

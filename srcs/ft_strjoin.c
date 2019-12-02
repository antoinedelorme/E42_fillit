/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:04:34 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/26 11:30:06 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;
	char	*source1;
	char	*source2;

	source1 = (char*)s1;
	source2 = (char*)s2;
	if (source1)
		len1 = ft_strlen(source1);
	else
		len1 = 0;
	if (source2)
		len2 = ft_strlen(source2);
	else
		len2 = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_memcpy(ptr, source1, len1);
	ft_memcpy(ptr + len1, source2, len2);
	ptr[len1 + len2] = '\0';
	return (ptr);
}

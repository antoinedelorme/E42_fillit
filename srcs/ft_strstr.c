/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:09:29 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/11 14:24:26 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*loop;

	i = 0;
	loop = (char*)haystack;
	if (!*haystack && !*needle)
		return (loop);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] && (needle[j] == haystack[i + j]))
			j++;
		if (needle[j] == '\0')
			return (loop + i);
		i++;
	}
	return (NULL);
}

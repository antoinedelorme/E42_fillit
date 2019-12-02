/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:13:11 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/11 15:00:59 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*loop;

	i = 0;
	loop = (char*)haystack;
	if (!*haystack && !*needle)
		return (loop);
	if (!*needle && (len == 0))
		return (loop);
	while (haystack[i] && (i < len))
	{
		j = 0;
		while (needle[j] && haystack[i + j] &&
	((i + j) < len) && (needle[j] == haystack[i + j]))
			j++;
		if (needle[j] == '\0')
			return (loop + i);
		i++;
	}
	return (NULL);
}

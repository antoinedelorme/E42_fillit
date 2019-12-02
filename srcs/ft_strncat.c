/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:34:13 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/14 12:57:11 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s1;
	while (*s1)
		s1++;
	while (s2[i] && (i < n))
	{
		*s1 = s2[i];
		s1++;
		i++;
	}
	*s1 = '\0';
	return (ptr);
}

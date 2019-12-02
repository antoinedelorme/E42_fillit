/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:22:39 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 13:49:02 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	test_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static void	init(size_t index[3])
{
	index[0] = 0;
	index[1] = 0;
}

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	index[3];

	if (!s)
		return ("");
	init(index);
	while (s[index[1]] && test_char(s[index[1]]))
		index[1]++;
	if (!s[index[1]])
	{
		if (!(ptr = (char *)malloc(sizeof(char))))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (s[index[0] + index[1]])
	{
		if (!test_char(s[index[0] + index[1]]))
			index[2] = index[0] + index[1];
		index[0]++;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (index[2] - index[1] + 2))))
		return (NULL);
	ft_strlcpy(ptr, s + index[1], index[2] - index[1] + 2);
	return (ptr);
}

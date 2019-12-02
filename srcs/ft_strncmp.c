/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:06:41 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 14:33:28 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				r;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	while (string1[i] && string2[i] && (string1[i] == string2[i]))
	{
		if (i == n - 1)
		{
			r = (int)(string1[i] - string2[i]);
			return (r);
		}
		i++;
	}
	r = ((int)string1[i] - (int)string2[i]);
	if (r == 0)
		return (0);
	r = r > 0 ? 1 : -1;
	return (r);
}

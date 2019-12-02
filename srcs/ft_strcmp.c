/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:20 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 14:28:33 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				r;
	size_t			i;

	i = 0;
	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	while (string1[i] && string2[i] && (string1[i] == string2[i]))
		i++;
	r = (int)(string1[i] - string2[i]);
	if (r == 0)
		return (0);
	r = r > 0 ? 1 : -1;
	return (r);
}

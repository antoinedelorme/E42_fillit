/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:08:37 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/26 12:03:55 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				r;
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (string1[i] && string2[i] && (string1[i] == string2[i]))
		i++;
	r = (string1[i] == string2[i]) ? 1 : 0;
	return (r);
}

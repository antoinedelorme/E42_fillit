/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:25:20 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 13:48:03 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_temp_itoa(int n, int *k, char *output)
{
	long	i;

	i = n;
	if (i < 0)
	{
		output[*k] = '-';
		(*k)++;
		i = -i;
	}
	if (i < 10)
	{
		output[*k] = (char)i + '0';
		(*k)++;
	}
	else
	{
		ft_temp_itoa(i / 10, k, output);
		ft_temp_itoa(i % 10, k, output);
	}
}

char		*ft_itoa(int n)
{
	char	tab[11];
	char	*ptr;
	int		nb;

	nb = 0;
	ft_temp_itoa(n, &nb, tab);
	if (!(ptr = (char *)malloc(nb + 1)))
		return (NULL);
	ft_memcpy(ptr, tab, nb);
	ptr[nb] = '\0';
	return (ptr);
}

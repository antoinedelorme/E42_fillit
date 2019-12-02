/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:39:30 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/13 09:58:44 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		signe;
	long	result;

	signe = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while ((*str >= '0' && (*str <= '9')))
	{
		result = result * 10 + (*str - '0');
		if (result < 0)
		{
			if (signe == 1)
				return (-1);
			return (0);
		}
		str++;
	}
	return (signe * (int)result);
}

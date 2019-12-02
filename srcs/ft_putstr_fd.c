/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:16:57 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/26 12:16:58 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	char *text;

	if (s)
	{
		text = (char*)s;
		write(fd, s, ft_strlen(text));
	}
}

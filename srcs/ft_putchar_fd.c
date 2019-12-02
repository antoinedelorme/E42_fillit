/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:39:32 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 13:48:21 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	u_to_utf8(char *dest, int ch)
{
	if (ch < 0x800)
	{
		dest[0] = (ch >> 6) | 0xC0;
		dest[1] = (ch & 0x3F) | 0x80;
		return (2);
	}
	if (ch < 0x10000)
	{
		dest[0] = (ch >> 12) | 0xE0;
		dest[1] = ((ch >> 6) & 0x3F) | 0x80;
		dest[2] = (ch & 0x3F) | 0x80;
		return (3);
	}
	if (ch < 0x110000)
	{
		dest[0] = (ch >> 18) | 0xF0;
		dest[1] = ((ch >> 12) & 0x3F) | 0x80;
		dest[2] = ((ch >> 6) & 0x3F) | 0x80;
		dest[3] = (ch & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

int			ft_putchar_fd(int c, int fd)
{
	int		nb;
	char	dest[4];

	if (c < 0x80)
	{
		dest[0] = (char)c;
		write(fd, &dest, 1);
	}
	else
	{
		nb = u_to_utf8(dest, c);
		write(fd, dest, nb);
	}
	return (c);
}

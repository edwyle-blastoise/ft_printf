/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:18:59 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/26 15:53:41 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_len(unsigned long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char		*ft_itoa_hex(unsigned long n, char type)
{
	char			*res;
	const char		*str;
	unsigned int	len;

	if (type == 'x' || type == 'p')
		str = "0123456789abcdef";
	else if (type == 'X')
		str = "0123456789ABCDEF";
	len = n_len(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[len - 1] = str[(n % 16)];
		n = n / 16;
		len--;
	}
	return (res);
}

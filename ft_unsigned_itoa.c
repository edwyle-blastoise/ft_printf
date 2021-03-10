/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:18:35 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/23 15:18:39 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		len;

	len = n_len(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:02:52 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/26 15:55:11 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_char_if_minus(t_var *flags, char c)
{
	ft_putchar(c);
	flags->res += 1;
	while (flags->width-- > 1)
	{
		ft_putchar(' ');
		flags->res += 1;
	}
}

static void		print_char_if_zero(t_var *flags, char c)
{
	while (flags->width-- > 1)
	{
		ft_putchar('0');
		flags->res += 1;
	}
	ft_putchar(c);
	flags->res += 1;
}

void			print_char(t_var *flags, va_list ap)
{
	char	c;

	if (flags->type == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (flags->minus == 1)
		print_char_if_minus(flags, c);
	else if (flags->zero == 1)
		print_char_if_zero(flags, c);
	else
	{
		while (flags->width-- > 1)
		{
			ft_putchar(' ');
			flags->res += 1;
		}
		ft_putchar(c);
		flags->res += 1;
	}
}

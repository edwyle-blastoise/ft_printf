/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pdiuxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:00:05 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/25 21:00:07 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_prefix(t_var *flags, int *remainder, char symbol)
{
	if (flags->sign == 1)
	{
		(*remainder)--;
		if (symbol == '0')
		{
			ft_putchar('-');
			flags->res += 1;
		}
	}
	else if (flags->sign == 2)
	{
		(*remainder) -= 2;
		if (symbol == '0')
		{
			ft_putstr("0x");
			flags->res += 2;
		}
	}
}

static void	check_remaind(t_var *flags, int *remainder, char symbol)
{
	if (*remainder)
	{
		check_prefix(flags, remainder, symbol);
		while ((*remainder)-- > 0)
		{
			ft_putchar(symbol);
			flags->res += 1;
		}
		if ((flags->sign == 1) && (symbol == ' ' && !flags->nulls))
		{
			ft_putchar('-');
			flags->res += 1;
		}
		else if ((flags->sign == 2) && (symbol == ' ' && !flags->nulls))
		{
			ft_putstr("0x");
			flags->res += 2;
		}
	}
}

static void	check_nulls(t_var *flags)
{
	if (flags->sign == 1)
	{
		ft_putchar('-');
		flags->res += 1;
	}
	else if (flags->sign == 2)
	{
		ft_putstr("0x");
		flags->res += 2;
	}
	while (flags->nulls-- > 0)
	{
		ft_putchar('0');
		flags->res += 1;
	}
}

void		check_zero(t_var *flags, int *remainder, int len, char *result)
{
	char	symbol;

	symbol = ' ';
	if (flags->zero == 1)
		symbol = '0';
	if ((flags->nulls && (flags->width > (len + flags->nulls))) || \
	((flags->precision != -1) && (flags->precision <= len) && \
	(flags->precision < flags->width)))
		symbol = ' ';
	check_remaind(flags, remainder, symbol);
	if (flags->nulls)
		check_nulls(flags);
	if ((flags->sign == 1) && (!flags->nulls && !*remainder))
	{
		ft_putchar('-');
		flags->res += 1;
	}
	if ((flags->sign == 2) && (!flags->nulls && !*remainder))
	{
		ft_putstr("0x");
		flags->res += 2;
	}
	ft_putstr(result);
	if ((ft_strcmp(result, "") != 0))
		free(result);
}

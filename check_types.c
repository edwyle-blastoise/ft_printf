/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:35:04 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/25 21:06:06 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*define_result(t_var *flags, char *result)
{
	if (flags->type == 'p')
		flags->sign = 2;
	if ((flags->type == 'd') || (flags->type == 'i'))
		result = ft_itoa(flags->arg3);
	else if (flags->type == 'u')
		result = ft_unsigned_itoa(flags->arg2);
	else if ((flags->type == 'x') || (flags->type == 'X'))
		result = ft_itoa_hex(flags->arg2, flags->type);
	else if (flags->type == 'p')
		result = ft_itoa_hex(flags->arg1, flags->type);
	return (result);
}

static void	check_flags(t_var *flags, char *result)
{
	int		len;
	int		remainder;

	remainder = 0;
	len = ft_strlen(result);
	if ((ft_strcmp(result, "0") == 0) && (flags->precision == 0))
	{
		result = "";
		len = 0;
	}
	if ((flags->precision > 0) && (len < flags->precision))
		flags->nulls = flags->precision - len;
	if (flags->width > len)
		remainder = flags->width - len;
	if (flags->width > (len + flags->nulls))
		remainder = flags->width - (len + flags->nulls);
	else
		remainder = 0;
	flags->res += len;
	if (flags->minus == 1)
		print_if_min(flags, &remainder, result);
	else
		check_zero(flags, &remainder, len, result);
}

void		check_types(t_var *flags, va_list ap)
{
	char	*result;

	result = NULL;
	if (flags->type == 'p')
		flags->arg1 = va_arg(ap, unsigned long);
	else if ((flags->type == 'u') || (flags->type == 'x') ||\
			(flags->type == 'X'))
		flags->arg2 = va_arg(ap, unsigned int);
	else
		flags->arg3 = va_arg(ap, int);
	if (flags->arg3 < 0)
	{
		flags->sign = 1;
		flags->arg3 *= (-1);
	}
	result = define_result(flags, result);
	check_flags(flags, result);
}

static void	prefix_print(t_var *flags, int *remainder)
{
	if (flags->sign == 1)
	{
		(*remainder)--;
		ft_putchar('-');
		flags->res += 1;
	}
	else if (flags->sign == 2)
	{
		(*remainder) -= 2;
		ft_putstr("0x");
		flags->res += 2;
	}
}

void		print_if_min(t_var *flags, int *remainder, char *result)
{
	prefix_print(flags, remainder);
	if (flags->nulls)
		while (flags->nulls-- > 0)
		{
			ft_putchar('0');
			flags->res += 1;
		}
	ft_putstr(result);
	if (*remainder)
		while ((*remainder)-- > 0)
		{
			ft_putchar(' ');
			flags->res += 1;
		}
	if ((ft_strcmp(result, "") != 0))
		free(result);
}
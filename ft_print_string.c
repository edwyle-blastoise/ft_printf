/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:07:38 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/25 18:51:21 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*define_print_str(const char *str, int len)
{
	char	*print_str;

	if (!(print_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(print_str, str, (len + 1));
	return (print_str);
}

static void	print_str_if_minus(t_var *flags, char *print_str, int remainder)
{
	ft_putstr(print_str);
	while (remainder-- > 0)
	{
		ft_putchar(' ');
		flags->res += 1;
	}
}

static void	print_str_if_zero(t_var *flags, char *print_str, int remainder)
{
	while (remainder-- > 0)
	{
		ft_putchar('0');
		flags->res += 1;
	}
	ft_putstr(print_str);
}

static void	check_flags(t_var *flags, char *print_str, int remainder)
{
	if (flags->minus)
		print_str_if_minus(flags, print_str, remainder);
	else if (flags->zero)
		print_str_if_zero(flags, print_str, remainder);
	else
	{
		while (remainder-- > 0)
		{
			ft_putchar(' ');
			flags->res += 1;
		}
		ft_putstr(print_str);
	}
}

int			print_string(t_var *flags, va_list ap)
{
	const char	*str;
	char		*print_str;
	int			len;
	int			remainder;

	print_str = NULL;
	str = va_arg(ap, const char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0)
		if (len > flags->precision)
			len = flags->precision;
	remainder = flags->width - len;
	print_str = define_print_str(str, len);
	flags->res += (len);
	if (len >= flags->width)
		ft_putstr(print_str);
	else
		check_flags(flags, print_str, remainder);
	free(print_str);
	return (0);
}

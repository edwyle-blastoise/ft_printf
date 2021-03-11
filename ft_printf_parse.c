/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:46:36 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/26 15:47:42 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_null(t_var *flags, const char **format)
{
	if (**format == '0')
	{
		if (flags->minus == 0)
			flags->zero = 1;
		(*format)++;
		return (1);
	}
	return (0);
}

static int	check_minus(t_var *flags, const char **format)
{
	if (**format == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
		(*format)++;
		return (1);
	}
	return (0);
}

static int	check_width(t_var *flags, const char **format, va_list ap)
{
	if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			flags->width = flags->width * 10 + ((**format) - '0');
			(*format)++;
		}
		return (1);
	}
	else if (**format == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= (-1);
		}
		(*format)++;
		return (1);
	}
	return (0);
}

static int	check_precision(t_var *flags, const char **format, va_list ap)
{
	if (**format == '.')
	{
		flags->precision = 0;
		(*format)++;
		if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
			{
				flags->precision = flags->precision * 10 + ((**format) - '0');
				(*format)++;
			}
		}
		else if (**format == '*')
		{
			flags->precision = va_arg(ap, int);
			if (flags->precision < 0)
				flags->precision = -1;
			(*format)++;
		}
		return (1);
	}
	return (0);
}

int			ft_parse(t_var *flags, const char *format, va_list ap)
{
	const char		*ptr;

	ptr = format;
	while (*format)
	{
		if (check_null(flags, &format))
			continue ;
		else if (check_minus(flags, &format))
			continue ;
		else if (check_width(flags, &format, ap))
			continue ;
		else if (check_precision(flags, &format, ap))
			continue ;
		if (ft_strchr(flags->types, *format))
		{
			flags->type = *format;
			check_type(flags, ap);
			return (format - ptr);
		}
		else
			return (-1);
	}
	return (format - ptr);
}

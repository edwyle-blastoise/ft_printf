/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:40:39 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/24 20:39:25 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_var	*flags;
	int		result;

	result = 0;
	if (!(flags = (t_var*)malloc(sizeof(t_var))))
		return (-1);
	flags->res = 0;
	va_start(ap, format);
	while (*format)
	{
		struct_init(flags);
		if (!(format = check_format((char*)format, flags, ap)))
		    return (result);
		format++;
	}
	va_end(ap);
	result = flags->res;
	free(flags);
	return (result);
}

void 	struct_init(t_var *n_list)
{
	n_list->minus = 0;
	n_list->zero = 0;
	n_list->width = 0;
	n_list->precision = -1;
	n_list->types = "cspdiuxX%";
	n_list->type = 0;
	n_list->sign = 0;
	n_list->nulls = 0;
	n_list->arg1 = 0;
	n_list->arg2 = 0;
	n_list->arg3 = 0;
}

char	*check_format(char *format, t_var *flags, va_list ap)
{
	if (*format == '%')
	{
		format++;
		if (*format == '\0')
		    return (NULL);
		format = format + (ft_parse(flags, format, ap));
	}
	else
	{
		ft_putchar(*format);
		flags->res += 1;
	}
	return (format);
}

void 	check_type(t_var *flags, va_list ap)
{
    if (flags->type == 'c' || (flags->type == '%'))
        print_char(flags, ap);
    else if (flags->type == 's')
        print_string(flags, ap);
    else if (flags->type == 'd' || flags->type == 'i' || flags->type == 'u' || flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
        check_types(flags, ap);
}

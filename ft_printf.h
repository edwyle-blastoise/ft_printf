/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:41:49 by eblastoi          #+#    #+#             */
/*   Updated: 2021/01/26 16:33:23 by eblastoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_var
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	const char		*types;
	char			type;
	int				res;
	int				sign;
	int				nulls;
	unsigned long	arg1;
	unsigned int	arg2;
	int				arg3;
}					t_var;

int					ft_printf(const char *format, ...);
char				*check_format(char *format, t_var *flags, va_list ap);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(const char *str);
int					ft_strlcpy(char *dst, const char *src, int dstsize);
char				*ft_strdup(const char *s1);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(unsigned int n);
char				*ft_itoa_hex(unsigned long n, char type);
int					ft_isdigit(int c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
void				struct_init(t_var *n_list);
int					ft_parse(t_var *flags, const char *format, va_list ap);
void				check_type(t_var *flags, va_list ap);
void				print_char(t_var *flags, va_list ap);
int					print_string(t_var *flags, va_list ap);
void				check_types(t_var *flags, va_list ap);
void				print_if_min(t_var *flags, int *remainder, char *res);
void				check_zero(t_var *flags, int *remainder, int len, \
					char *res);

#endif

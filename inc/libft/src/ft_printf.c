/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:13:39 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:37:26 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

const char	*ft_format_finder(const char *format, va_list args, int *len)
{
	if (*format == 'c')
		ft_write_format_c(args, len);
	else if (*format == 'd' || *format == 'i')
		ft_write_format_int(args, len);
	else if (*format == 's')
		ft_write_format_s(args, len);
	else if (*format == 'u')
		ft_write_format_u(args, len);
	else if (*format == 'x')
		ft_write_format_x(args, len);
	else if (*format == 'X')
		ft_write_format_x2(args, len);
	else if (*format == 'p')
		ft_write_format_p(args, len);
	else if (*format == '%')
		ft_write_format_percent(len);
	else
	{
		ft_putchar_printf('%');
		ft_putchar_printf(*format);
		*len = *len + 2;
	}
	return (format + 1);
}

const char	*read_until_percent(const char	*str, int *len)
{
	while (*str != '%' && *str)
	{
		ft_putchar_printf(*str);
		str++;
		*len = *len + 1;
	}
	return (str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != 0)
			str = ft_format_finder((str + 1), args, &len);
		else if (*str != '%')
			str = read_until_percent(str, &len);
		else
			str++;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:16 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 17:00:54 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ptrlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr <= 9)
	{
		ft_putchar_printf(ptr + '0');
	}
	else if (ptr < 16)
		ft_putchar_printf((ptr - 10) + 'a');
	else if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
}

void	ft_write_format_p(va_list args, int *len)
{
	long unsigned int	ptr;

	ptr = va_arg(args, long unsigned int);
	if (!ptr)
	{
		ft_putstr_printf("(nil)");
		*len = *len + 5;
		return ;
	}
	ft_putchar_printf('0');
	ft_putchar_printf('x');
	ft_putptr(ptr);
	*len = *len + ptrlen(ptr) + 2;
}

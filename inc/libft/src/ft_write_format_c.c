/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:57 by rledoux           #+#    #+#             */
/*   Updated: 2022/09/26 16:50:09 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c)
{
	write(1, &c, 1);
}

void	ft_write_format_c(va_list args, int *len)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	*len = *len + 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:49 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 16:24:55 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexalen(unsigned int n)
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

void	ft_putnbrhexa1(unsigned int nbr)
{
	if (nbr <= 9)
	{
		ft_putchar_printf(nbr + '0');
	}
	else if (nbr < 16)
		ft_putchar_printf((nbr - 10) + 'a');
	else if (nbr >= 16)
	{
		ft_putnbrhexa1(nbr / 16);
		ft_putnbrhexa1(nbr % 16);
	}
}

void	ft_write_format_x(va_list args, int *len)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (!nbr)
	{
		ft_putchar_printf('0');
		*len = *len + 1;
		return ;
	}
	ft_putnbrhexa1(nbr);
	*len = *len + hexalen(nbr);
}

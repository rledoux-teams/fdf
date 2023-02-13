/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_x2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:56 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 16:30:24 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbrhexa2(unsigned int nbr)
{
	if (nbr <= 9)
	{
		ft_putchar_printf(nbr + '0');
	}
	else if (nbr < 16)
		ft_putchar_printf((nbr - 10) + 'A');
	else if (nbr >= 16)
	{
		ft_putnbrhexa2(nbr / 16);
		ft_putnbrhexa2(nbr % 16);
	}
}

void	ft_write_format_x2(va_list args, int *len)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (!nbr)
	{
		ft_putchar_printf('0');
		*len = *len + 1;
		return ;
	}
	ft_putnbrhexa2(nbr);
	*len = *len + hexalen(nbr);
}

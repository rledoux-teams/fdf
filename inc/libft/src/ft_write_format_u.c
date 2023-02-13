/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:43 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 16:35:31 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_uputnbr(unsigned int nbr)
{
	if (nbr <= 9)
		ft_putchar_printf(nbr + 48);
	else
	{
		ft_uputnbr(nbr / 10);
		ft_uputnbr(nbr % 10);
	}
}

void	ft_write_format_u(va_list args, int *len)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_uputnbr(nbr);
	*len = *len + uintlen(nbr);
}

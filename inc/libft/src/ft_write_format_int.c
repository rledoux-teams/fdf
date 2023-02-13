/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:24 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 16:31:17 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_write_format_int(va_list args, int *len)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_printf(nbr);
	*len = *len + intlen(nbr);
}

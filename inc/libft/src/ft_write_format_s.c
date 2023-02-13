/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:29:08 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/25 16:48:55 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_strlen_printf(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_write_format_s(va_list args, int *len)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_printf("(null)");
		*len = *len + 6;
		return ;
	}
	else
		ft_putstr_printf(str);
	*len = *len + ft_strlen_printf(str);
}

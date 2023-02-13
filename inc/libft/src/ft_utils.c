/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:39:32 by rledoux           #+#    #+#             */
/*   Updated: 2022/10/19 16:41:04 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr_printf(char *s)
{
	while (*s != '\0')
	{
		ft_putchar_printf(*s);
		s++;
	}
}

char	*ft_strdup_printf(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(*dest) * (ft_strlen_printf(s) + 1));
	if (dest == NULL)
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static unsigned int	ft_negative(long int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	intlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n > 0)
	{
		while (n >= 1)
		{
			if (n == 10)
				n = 1;
			else
				n = n / 10;
			len++;
		}
		return (len);
	}
	else if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		return (intlen(n) + 1);
	}
	else
		return (11);
}

void	ft_putnbr_printf(long int n)
{
	unsigned int	nbr;

	if (n < 0)
		ft_putchar_printf(45);
	nbr = ft_negative(n);
	if (nbr < 10)
		ft_putchar_printf(nbr + '0');
	else
	{
		ft_putnbr_printf(nbr / 10);
		ft_putnbr_printf(nbr % 10);
	}
}

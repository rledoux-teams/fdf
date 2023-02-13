/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:22:14 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/26 17:51:39 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long int n)
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

int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			bool_negative;
	int			len;
	long int	n2;

	n2 = n;
	len = intlen(n2) - 1;
	bool_negative = is_negative(n2);
	res = ft_calloc(sizeof(char), len + 2);
	if (!res)
		return (NULL);
	if (n < 0)
		n2 = n2 * -1;
	while (n2 >= 1 || (len == 0 && !bool_negative))
	{
		res[len] = (n2 % 10) + '0';
		if (n2 == 10)
			n2 = 1;
		else
			n2 = n2 / 10;
		len--;
	}
	if (bool_negative)
		res[len] = '-';
	return (res);
}

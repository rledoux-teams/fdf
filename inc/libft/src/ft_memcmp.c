/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:06:20 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/26 17:59:36 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i)
	&& i < n - 1)
		i++;
	if (i == n || *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		return (0);
	if (*(unsigned char *)(s1 + i) > *(unsigned char *)(s2 + i))
		return (1);
	return (-1);
}

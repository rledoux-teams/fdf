/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:13:40 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/28 19:00:43 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == little || *little == '\0')
		return ((char *)big);
	if (len <= 0 || little == NULL)
		return (0);
	i = 0;
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while ((little[j] == big[i + j]) && (i + j < len))
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (0);
}

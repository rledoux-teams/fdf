/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:06:33 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/08 13:20:52 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	index;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (size + len_src);
	index = 0;
	while (*(src + index) != '\0' && ((index + len_dst) < size - 1))
	{
		*(dst + index + len_dst) = *(src + index);
		index++;
	}
	*(dst + index + len_dst) = '\0';
	return (len_dst + len_src);
}

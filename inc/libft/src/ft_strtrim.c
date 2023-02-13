/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:50:00 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/28 17:59:08 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (check_set(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
	{
		res = malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	while (check_set(s1[j], set))
		j--;
	res = ft_substr(s1, i, (j - i + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}

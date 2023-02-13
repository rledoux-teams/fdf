/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:19 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/28 16:12:31 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == 0)
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (s[i] != c && i > 0)
		i--;
	if ((unsigned char)s[i] == (unsigned char)c)
	{
		index = 0;
		while (index < i)
		{
			index++;
			s++;
		}
		return ((char *)s);
	}
	return (0);
}

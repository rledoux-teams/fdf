/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:44:42 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/08 15:35:17 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	signe;

	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	signe = 1;
	if (nptr[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	value = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	return (value * signe);
}

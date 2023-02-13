/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:20 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:41:40 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"

size_t	ft_strlen_fdf(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

void	ft_maps_init(t_maps *maps, char **av)
{
	maps->nb_col = 0;
	ft_count_rows_in_fd(maps, av);
	maps->matrix = malloc(maps->nb_lines * sizeof(t_matrix *));
	if (!maps->matrix)
		ft_error(maps, NULL);
	maps->fd = open(av[1], O_RDONLY);
	if (maps->fd < 0 || maps->fd > 1024)
		ft_error(maps, NULL);
	return ;
}

t_matrix	ft_rotate(t_matrix	points, float angle)
{
	float	x;
	float	y;
	float	z;
	float	rad;

	x = points.x;
	y = points.y;
	z = points.z;
	rad = M_PI / 180;
	points.x = x * cos(angle * rad) + y * cos((angle + 120) * rad);
	points.x = points.x + z * cos((angle - 120) * rad);
	points.y = x * sin(angle * rad) + y * sin((angle + 120) * rad);
	points.y = points.y + z * sin((angle - 120) * rad);
	return (points);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:20 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/06 20:25:18 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_math_matrix.h"
#include <math.h>
#include <stdlib.h>

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

t_matrix	ft_rotate_utils(t_matrix points, float **rotationxy, float isometric[3][3])
{
	int	x;
	int	y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			isometric[y][x] = rotationxy[y][x];
			x++;
		}
		y++;
	}
	points = ft_matrix_mul(points, isometric);
	ft_double_free((void **)rotationxy, 2);
	return (points);
}

t_matrix	ft_rotate(t_matrix	points, float angle)
{
	float	x;
	float	y;
	float	z;
	
	x = points.x;
	y = points.y;
	z = points.z;
	points.x = x*cos(angle * (M_PI / 180)) + y*cos((angle + 120) * (M_PI / 180)) + z*cos((angle - 120) * (M_PI / 180));
	points.y = x*sin(angle * (M_PI / 180)) + y*sin((angle + 120) * (M_PI / 180)) + z*sin((angle - 120) * (M_PI / 180));
	return (points);
}

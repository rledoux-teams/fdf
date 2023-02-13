/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:59:50 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/06 20:04:25 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"
#include "../inc/ft_math_matrix.h"
#include <stdlib.h>

t_matrix	ft_matrix_mul(t_matrix a, float	b[3][3])
{
	a.x = b[0][0] * a.x + b[0][1] * a.y + b[0][2] * a.z;
	a.y = b[1][0] * a.x + b[1][1] * a.y + b[1][2] * a.z;
	a.z = b[2][0] * a.x + b[2][1] * a.y + b[2][2] * a.z;
	return (a);
}

float	**ft_matrix_mul2(float a[3][3], float b[3][3])
{
	float	**c;
	int i;
	int	j;
	int	k;
	float	sum;

	i = 0;
	c = malloc(sizeof(float *) * 3);
	if (!c)
		return (NULL);
	while (i < 3)
	{
		c[i] = malloc(sizeof(float) * 3);
		if (!c[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			sum = 0;
			k = 0;
			while (k < 3)
			{
				sum = sum + a[i][k] * b[k][j];
				k++;
			}
			c[i][j] = sum;
			j++;
		}
		i++;
	}
	return (c);
}

void	ft_init_rotationx(float	rotationx[3][3], int angle)
{
	rotationx[0][0] = 1;
	rotationx[0][1] = 0;
	rotationx[0][2] = 0;
	rotationx[1][0] = 0;
	rotationx[1][1] = cos(angle);
	rotationx[1][2] = 0 - sin(angle);
	rotationx[2][0] = 0;
	rotationx[2][1] = sin(angle);
	rotationx[2][2] = cos(angle);
}

void	ft_init_rotationy(float	rotationy[3][3], int angle)
{	
	rotationy[0][0] = cos(angle);
	rotationy[0][1] = 0;
	rotationy[0][2] = sin(angle);
	rotationy[1][0] = 0;
	rotationy[1][1] = 1;
	rotationy[1][2] = 0;
	rotationy[2][0] = 0 - sin(angle);
	rotationy[2][1] = 0;
	rotationy[2][2] = cos(angle);
}

void	ft_init_rotationz(float	rotationz[3][3], int angle)
{	
	rotationz[0][0] = cos(angle);
	rotationz[0][1] = 0 - sin(angle);
	rotationz[0][2] = 0;
	rotationz[1][0] = sin(angle);
	rotationz[1][1] = cos(angle);
	rotationz[1][2] = 0;
	rotationz[2][0] = 0;
	rotationz[2][1] = 0;
	rotationz[2][2] = 1;
}

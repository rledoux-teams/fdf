/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_matrix.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:00:46 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/06 18:21:06 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_MATRIX_H
#define FT_MATH_MATRIX_H

#include "ft_fdf.h"
#include "ft_color.h"
#include "ft_mlx.h"

t_matrix	ft_matrix_mul(t_matrix a, float	b[3][3]);
float	**ft_matrix_mul2(float a[3][3], float	b[3][3]);
void	ft_init_rotationx(float	rotationx[3][3], int angle);
void	ft_init_rotationy(float	arotationy[3][3], int angle);
void	ft_init_rotationz(float	rotationz[3][3], int angle);


#endif

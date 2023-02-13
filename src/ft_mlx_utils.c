/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:15:24 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/10 15:15:26 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"
#include "../inc/ft_math_matrix.h"

int ft_gradient(int rgb1, int rgb2, float i, float max)
{
    int diffr;
    int diffg;
    int diffb;
    float influence;

    diffr = ft_get_r(rgb1) - ft_get_r(rgb2);
    diffg = ft_get_g(rgb1) - ft_get_g(rgb2);
    diffb = ft_get_b(rgb1) - ft_get_b(rgb2);
    influence = i / max;
    printf("%d %d %d %f\n--------\n", diffr, diffg, diffb, influence);
    return (ft_create_rgba(ft_get_r(rgb1) + (diffr * influence), ft_get_g(rgb1) + (diffg * influence), ft_get_b(rgb1) + (diffb * influence), 255));
}

void	ft_rotate_mat(t_var *var, int angle)
{
	t_rotmat	mat;
	int	i;
	int	j;

	j = 0;
	ft_init_rotationx(mat.rotationx, angle * (M_PI / 180));
	ft_init_rotationy(mat.rotationy, angle * (M_PI / 180));
	ft_init_rotationz(mat.rotationz, angle * (M_PI / 180));
	while (j < var->maps->nb_lines)
	{
		i = 0;
		while (i < var->maps->nb_col)
		{
			var->matrix[j][i] = ft_matrix_mul(var->matrix[j][i], mat.rotationy);
			i++;
		}
		j++;
	}
	return ;
}

void ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_var		*var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(var->mlx);
		ft_error(var->maps, "Program leave by user");
	}
	if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_PRESS)
		var->dist++;
	if (keydata.key == MLX_KEY_PAGE_DOWN && keydata.action == MLX_PRESS && var->dist > 1)
		var->dist--;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		var->offsetx = var->offsetx + 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		var->offsetx = var->offsetx - 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		var->offsety = var->offsety + 5;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		var->offsety = var->offsety - 5;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		ft_rotate_mat(var, 30);
	return ;
}
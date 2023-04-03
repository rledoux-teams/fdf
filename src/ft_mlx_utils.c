/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:15:24 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:44:49 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"

void	ft_pixel(int x, int y, int rgba, mlx_image_t *img)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		mlx_put_pixel(img, x, y, rgba);
	return ;
}

int	fround(float n)
{
	if (n - (int)n < 0.5)
		return ((int)n);
	return ((int)n + 1);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_var		*var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_error(var, "Program leave by user");
	if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_PRESS)
		var->dist++;
	if (keydata.key == MLX_KEY_PAGE_DOWN && keydata.action == MLX_PRESS
		&& var->dist > 1)
		var->dist--;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		var->offsetx = var->offsetx + 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		var->offsetx = var->offsetx - 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		var->offsety = var->offsety + 5;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		var->offsety = var->offsety - 5;
	return ;
}

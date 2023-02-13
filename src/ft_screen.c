/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:26:40 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:44:29 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"

void	ft_fill_background(mlx_image_t	*img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_pixel(x, y, color, img);
			x++;
		}
		y++;
	}
	return ;
}

mlx_image_t	*ft_new_image(t_var *var, int width, int height, int x0)
{
	mlx_image_t	*img;

	img = mlx_new_image(var->mlx, width, height);
	if (!img)
		ft_error(var->maps, NULL);
	if (mlx_image_to_window(var->mlx, img, x0, 0) < 0)
		ft_error(var->maps, NULL);
	return (img);
}

void	ft_create_menu(t_var *var, int width, int height, int x0)
{
	int	color;

	color = ft_create_rgba(50, 50, 50, 255);
	var->menu = ft_new_image(var, width, height, x0);
	ft_fill_background(var->menu, width, height, color);
	color = ft_create_rgba(250, 250, 250, 255);
	mlx_put_string(var->mlx, "Help menu", 50, 20);
	mlx_put_string(var->mlx, "Esc: Leave program", 5, 50);
	mlx_put_string(var->mlx, "PgUp: Zoom in", 5, 80);
	mlx_put_string(var->mlx, "PgDn: Zoom out", 5, 110);
	mlx_put_string(var->mlx, "All move are by 5px", 5, 140);
	mlx_put_string(var->mlx, "Up: Move up", 5, 160);
	mlx_put_string(var->mlx, "Down: Move down", 5, 190);
	mlx_put_string(var->mlx, "Left: Move left", 5, 220);
	mlx_put_string(var->mlx, "Right: Move right", 5, 250);
	return ;
}

void	ft_create_display(t_var *var, int width, int height, int x0)
{
	int	color;

	color = ft_create_rgba(10, 10, 10, 255);
	var->disp = ft_new_image(var, width, height, x0);
	ft_fill_background(var->disp, width, height, color);
	return ;
}

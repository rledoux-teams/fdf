/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:48:16 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/06 20:13:07 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"
#include "../inc/ft_math_matrix.h"
#include <stdlib.h>

void	ft_put_pixel(int x, int y, int rgba, mlx_image_t *img)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		mlx_put_pixel(img, x, y, rgba);
	return ;
}

int	ft_round(float n)
{
	if (n - (int)n < 0.5)
		return ((int)n);
	return ((int)n + 1);
}

void	ft_dda(t_todraw draw, t_var *var, int x, int y)
{
	t_dda	dda;
	//int	color;

	dda.dx = draw.x2 - draw.x1;
	dda.dy = draw.y2 - draw.y1;
	if (dda.dx >= dda.dy)
		dda.step =  fabs(dda.dx);
	else
		dda.step = fabs(dda.dy);
	dda.dx = dda.dx / dda.step;
	dda.dy = dda.dy / dda.step;
	dda.x = draw.x1;
	dda.y = draw.y1;

	dda.i = 1;
	while(dda.i <= dda.step)
	{
		//color = ft_gradient(var->matrix[y][x].color, draw.color2, dda.i, dda.step);
		ft_put_pixel(ft_round(dda.x), ft_round(dda.y), var->matrix[y][x].color, var->disp);
		dda.x = dda.x + dda.dx;
		dda.y = dda.y + dda.dy;
		dda.i++;
	}
}

void	ft_to_draw_init(t_var *var, int x, int y)
{
	t_todraw	todraw;
	int	dist;
	int	offset[2];

	dist = var->dist;
	offset[0] = var->disp->width / 2 + var->offsetx;
	offset[1] = var->disp->height / 2 + var->offsety;
	todraw.x1 = dist * var->matrix[y][x].x + offset[0];
	todraw.x2 = dist * var->matrix[y][x + 1].x + offset[0];
	todraw.y1 = dist * var->matrix[y][x].y + offset[1];
	todraw.y2 = dist * var->matrix[y][x + 1].y + offset[1];
	todraw.color2 = var->matrix[y][x + 1].color;
	ft_dda(todraw, var, x, y);
	todraw.x1 = dist * var->matrix[y][x].x + offset[0];
	todraw.x2 = dist * var->matrix[y + 1][x].x + offset[0];
	todraw.y1 = dist * var->matrix[y][x].y + offset[1];
	todraw.y2 = dist * var->matrix[y + 1][x].y + offset[1];
	todraw.color2 = var->matrix[y + 1][x].color;
	ft_dda(todraw, var, x, y);
	return ;
}

void	ft_to_draw_final(t_var *var, int x, int y)
{
	t_todraw	todraw;
	int	dist;
	int	offset[2];

	dist = var->dist;
	offset[0] = var->disp->width / 2 + var->offsetx;
	offset[1] = var->disp->height / 2 + var->offsety;
	todraw.x1 = dist * var->matrix[y][0].x + offset[0];
	todraw.x2 = dist * var->matrix[y][x].x + offset[0];
	todraw.y1 = dist * var->matrix[y][0].y + offset[1];
	todraw.y2 = dist * var->matrix[y][x].y + offset[1];
	todraw.color2 = var->matrix[y][0].color;
	ft_dda(todraw, var, x, y);
	todraw.x1 = dist * (var->matrix[0][x].x + offset[0]);
	todraw.x2 = dist * (var->matrix[y][x].x + offset[0]);
	todraw.y1 = dist * (var->matrix[0][x].y + offset[1]);
	todraw.y2 = dist * (var->matrix[y][x].y + offset[1]);
	todraw.color2 = var->matrix[0][x].color;
	ft_dda(todraw, var, x, y);
	return ;
}

void	ft_render(void	*param)
{
	t_var		*var;
	int			x;
	int			y;
	
	var = param;
	y = 0;
	ft_create_display(var, WIDTH_I, HEIGHT_I, 200, 0);
	while (y < var->maps->nb_lines - 1)
	{
		x = 0;
		while (x < var->maps->nb_col - 1)
		{
			ft_to_draw_init(var, x, y);
			x++;
		}
		y++;
	}
	ft_to_draw_final(var, x, y);
	return ;
}

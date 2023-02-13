/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:56:14 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/06 14:36:58 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"
#include "../inc/ft_math_matrix.h"

void	ft_error(t_maps *maps, char *message)
{
	ft_free_all(maps);
	if (!message)
		perror(strerror(errno));
	else
		perror(message);
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_maps *maps)
{
	free(maps->temp_line);
	ft_double_free((void **)maps->matrix, maps->nb_lines - 1);
}

void	ft_double_free(void **ptr, int size)
{
	int	i;

	i = 0;
	while (i < (size + 1))
	{
		free(*(ptr + i));
		i++;
	}
	free(ptr);
	ptr = NULL;
	return ;
}

int main(int ac, char **av)
{
	t_maps	maps;
	t_var	var;
	mlx_t	*mlx;

	if (ac <= 1)
		return (0);
	ft_maps(av, &maps);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf by rledoux", true);
	if (!mlx)
		ft_error(&maps, NULL);
	var.maps = &maps;
	var.matrix = maps.matrix;
	var.mlx = mlx;
	var.dist = 10;
	var.offsetx = 0;
	var.offsety = 0;
	ft_create_display(&var, WIDTH_I, HEIGHT_I, 300, 0);
	ft_create_menu(&var, WIDTH_M, HEIGHT_M, 0, 0);
	mlx_loop_hook(mlx, ft_render, &var);
	mlx_key_hook(mlx, ft_key_hook, &var);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_error(var.maps, "Program leave by user");
	return (EXIT_SUCCESS);
}

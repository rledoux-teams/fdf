/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:40:46 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:39:05 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"
#include "../inc/ft_mlx.h"

void	ft_count_cols(t_maps *maps)
{
	int	i;

	i = 0;
	while (maps->temp_line[i] != '\n')
	{
		if (maps->temp_line[i] == ' ')
		{
			maps->nb_col++;
			while (maps->temp_line[i + 1] == ' ')
				i++;
		}
		i++;
	}
	return ;
}

void	ft_count_rows_in_fd(t_maps *maps, char **av)
{
	int		read_output;
	char	buf[1];

	maps->nb_lines = 0;
	maps->fd = open(av[1], O_RDONLY);
	if (maps->fd < 0 || maps->fd > 1024)
		ft_error2(maps, NULL);
	read_output = read(maps->fd, buf, 1);
	if (*buf == '\n')
		maps->nb_lines++;
	while (read_output)
	{
		read_output = read(maps->fd, buf, 1);
		if (*buf == '\n')
			maps->nb_lines++;
	}
	maps->nb_lines--;
	close(maps->fd);
}

void	ft_init_matrix(t_maps *maps, int y)
{
	int		x;
	char	**line_split;
	int		color;

	x = 0;
	maps->matrix[y] = malloc(sizeof(t_matrix) * maps->nb_col);
	if (!maps->matrix[y])
		ft_error2(maps, NULL);
	line_split = ft_split(maps->temp_line, ' ');
	while (x < maps->nb_col)
	{
		maps->matrix[y][x].x = x - (maps->nb_col / 2);
		maps->matrix[y][x].y = y - (maps->nb_lines / 2);
		maps->matrix[y][x].z = ft_atoi(line_split[x]);
		color = ft_create_rgba(255 / maps->matrix[y][x].z + 50, 0, 0, 255);
		if (maps->matrix[y][x].z)
			maps->matrix[y][x].color = color;
		else
			maps->matrix[y][x].color = ft_create_rgba(100, 100, 100, 255);
		maps->matrix[y][x] = ft_rotate(maps->matrix[y][x], 30);
		x++;
	}
	ft_double_free((void **)line_split, x);
	return ;
}

void	ft_maps(char **av, t_maps *maps)
{
	int	y;

	y = 0;
	ft_maps_init(maps, av);
	maps->temp_line = get_next_line(maps->fd);
	ft_count_cols(maps);
	ft_init_matrix(maps, y);
	while (maps->temp_line && y < maps->nb_lines)
	{
		free(maps->temp_line);
		y++;
		maps->temp_line = get_next_line(maps->fd);
		if (!maps->temp_line)
			break ;
		ft_init_matrix(maps, y);
	}
	close(maps->fd);
	return ;
}

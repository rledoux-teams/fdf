/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:36:36 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:34:59 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "./libft/src/libft.h"
# include "./libft/src/ft_printf.h"
# include "./libft/src/get_next_line.h"	

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <math.h>

typedef struct s_matrix
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_matrix;

typedef struct s_maps
{
	char		*temp_line;
	int			nb_lines;
	int			nb_col;
	int			fd;
	t_matrix	**matrix;
}	t_maps;

void		ft_error2(t_maps *maps, char *message);
void		ft_free_all(t_maps *maps);
void		ft_double_free(void **ptr, int size);
void		ft_maps(char **av, t_maps *maps);
size_t		ft_strlen_fdf(const char *s);
void		ft_maps_init(t_maps *maps, char **av);
void		ft_count_rows_in_fd(t_maps *maps, char **av);
void		ft_count_cols(t_maps *maps);
t_matrix	ft_rotate(t_matrix	points, float angle);

#endif

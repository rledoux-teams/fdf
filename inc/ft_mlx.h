/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:51:02 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:42:58 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "MLX42/include/MLX42/MLX42.h"
# include "ft_fdf.h"

# define WIDTH 1920
# define HEIGHT 1080
# define WIDTH_M 600
# define HEIGHT_M 1080
# define WIDTH_I 1620
# define HEIGHT_I 1080

typedef struct s_var
{
	mlx_t		*mlx;
	t_maps		*maps;
	t_matrix	**matrix;
	mlx_image_t	*disp;
	mlx_image_t	*menu;
	int			dist;
	int			offsetx;
	int			offsety;
}	t_var;

typedef struct s_dda
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	step;
	float	i;
}			t_dda;

typedef struct s_todraw
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	color2;
}			t_todraw;

typedef struct s_rotmat
{
	float	rotationx[3][3];
	float	rotationy[3][3];
	float	rotationz[3][3];
}				t_rotmat;

void		ft_error(t_var *var, char *message);
void		ft_translate(int x, int y, t_var *var);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_pixel(int x, int y, int rgba, mlx_image_t *img);
void		ft_fill_background(mlx_image_t	*img, int w, int h, int rgb);
mlx_image_t	*ft_new_image(t_var *var, int width, int height, int x0);
void		ft_create_menu(t_var *var, int width, int height, int x0);
void		ft_create_display(t_var *var, int width, int height, int x0);
void		ft_render(void	*var);
int			fround(float n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:48:10 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/02 16:29:40 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fdf.h"
#include "../inc/ft_color.h"

int	ft_create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	ft_get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	ft_get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}


int	ft_get_a(int rgba)
{
	return (rgba & 0xFF);
}


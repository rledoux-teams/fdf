/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:50:24 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/13 16:35:09 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

int	ft_create_rgba(int r, int g, int b, int a);
int	ft_get_r(int rgba);
int	ft_get_g(int rgba);
int	ft_get_b(int rgba);
int	ft_get_a(int rgba);

#endif

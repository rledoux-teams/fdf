/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:29:50 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/23 13:25:46 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_write_format_c(va_list args, int *len);
void	ft_write_format_int(va_list args, int *len);
void	ft_write_format_s(va_list args, int *len);
void	ft_write_format_u(va_list args, int *len);
void	ft_write_format_x(va_list args, int *len);
void	ft_write_format_x2(va_list args, int *len);
void	ft_write_format_p(va_list args, int *len);
void	ft_write_format_percent(int *len);
int		intlen(long int n);
void	ft_putchar_printf(char c);
char	*ft_strdup_printf(const char *s);
size_t	ft_strlen_printf(const char *s);
void	ft_putstr_printf(char *s);
void	ft_putnbr_printf(long int n);
int		hexalen(unsigned int n);

#endif

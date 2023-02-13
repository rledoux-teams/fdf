/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:30:04 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/17 18:17:07 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_return_line(t_gnl *s_gnl, char *buf)
{
	int	i;
	int	len_buf;
	int	pos_new_line;

	i = 0;
	len_buf = s_gnl->start + s_gnl->read_size;
	pos_new_line = s_gnl->lineread + 1;
	s_gnl->save_buf = ft_calloc_gnl(len_buf);
	while (i < len_buf)
	{
		*(s_gnl->save_buf + i) = *(buf + i);
		i++;
	}
	free(buf);
	if ((len_buf - pos_new_line) <= 0)
		return (NULL);
	buf = ft_calloc_gnl(len_buf - pos_new_line + 2);
	i = 0;
	while (i < len_buf - pos_new_line)
	{
		*(buf + i) = *(s_gnl->save_buf + i + pos_new_line);
		i++;
	}
	*(buf + i) = 0;
	return (buf);
}

char	*return_first_line(t_gnl *s_gnl, char *buf)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc_gnl(s_gnl->lineread + 2);
	while (i <= s_gnl->lineread)
	{
		res[i] = *(buf + i);
		i++;
	}
	if (buf[0] == '\n')
		res[0] = '\n';
	return (res);
}

char	*is_data_in_buf(t_gnl *s_gnl, char *buf)
{
	int	i;

	i = 0;
	if (!buf)
	{
		s_gnl->start = 0;
		s_gnl->read_size = 0;
		return (buf);
	}
	while (buf[i] != 0)
		i++;
	s_gnl->start = i;
	s_gnl->read_size = 0;
	s_gnl->output = 0;
	return (buf);
}

char	*read_data(t_gnl *s_gnl, char *buf, int fd)
{
	s_gnl->temp_buf = ft_calloc_gnl(BUFFER_SIZE);
	buf = ft_realloc(s_gnl, buf);
	if (is_line_read(s_gnl, buf) == 0)
	{
		while (is_line_read(s_gnl, buf) == 0)
		{
			s_gnl->output = read(fd, s_gnl->temp_buf, BUFFER_SIZE);
			if (s_gnl->output <= 0)
				break ;
			buf = ft_realloc(s_gnl, buf);
		}
	}
	free(s_gnl->temp_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	t_gnl		*s_gnl;
	static char	*buf = NULL;
	char		*res;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	s_gnl = (t_gnl *)ft_calloc_gnl(sizeof(t_gnl));
	buf = is_data_in_buf(s_gnl, buf);
	buf = read_data(s_gnl, buf, fd);
	if (s_gnl->output < 1 && !s_gnl->start && !s_gnl->lineread)
	{
		free(buf);
		buf = NULL;
		free(s_gnl);
		return (NULL);
	}
	res = return_first_line(s_gnl, buf);
	buf = remove_return_line(s_gnl, buf);
	free(s_gnl->save_buf);
	free(s_gnl);
	return (res);
}

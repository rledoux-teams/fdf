/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:30:04 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/17 18:17:48 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remove_return_line_bonus(t_gnl *s_gnl, char *buf)
{
	int	i;
	int	len_buf;
	int	pos_new_line;

	i = 0;
	len_buf = s_gnl->start + s_gnl->read_size;
	pos_new_line = s_gnl->lineread + 1;
	s_gnl->save_buf = ft_calloc_bonus(len_buf);
	while (i < len_buf)
	{
		*(s_gnl->save_buf + i) = *(buf + i);
		i++;
	}
	free(buf);
	if ((len_buf - pos_new_line) <= 0)
		return (NULL);
	buf = ft_calloc_bonus(len_buf - pos_new_line + 2);
	i = 0;
	while (i < len_buf - pos_new_line)
	{
		*(buf + i) = *(s_gnl->save_buf + i + pos_new_line);
		i++;
	}
	*(buf + i) = 0;
	return (buf);
}

char	*return_first_line_bonus(t_gnl *s_gnl, char *buf)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc_bonus(s_gnl->lineread + 2);
	while (i <= s_gnl->lineread)
	{
		res[i] = *(buf + i);
		i++;
	}
	if (buf[0] == '\n')
		res[0] = '\n';
	return (res);
}

char	*is_data_in_buf_bonus(t_gnl *s_gnl, char *buf)
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

char	*read_data_bonus(t_gnl *s_gnl, char *buf, int fd)
{
	s_gnl->temp_buf = ft_calloc_bonus(BUFFER_SIZE);
	buf = ft_realloc_bonus(s_gnl, buf);
	if (is_line_read_bonus(s_gnl, buf) == 0)
	{
		while (is_line_read_bonus(s_gnl, buf) == 0)
		{
			s_gnl->output = read(fd, s_gnl->temp_buf, BUFFER_SIZE);
			if (s_gnl->output <= 0)
				break ;
			buf = ft_realloc_bonus(s_gnl, buf);
		}
	}
	free(s_gnl->temp_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	t_gnl		*s_gnl;
	static char	*buf[1024];
	char		*res;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	s_gnl = (t_gnl *)ft_calloc_bonus(sizeof(t_gnl));
	buf[fd] = is_data_in_buf_bonus(s_gnl, buf[fd]);
	buf[fd] = read_data_bonus(s_gnl, buf[fd], fd);
	if (s_gnl->output < 1 && !s_gnl->start && !s_gnl->lineread)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		free(s_gnl);
		return (NULL);
	}
	res = return_first_line_bonus(s_gnl, buf[fd]);
	buf[fd] = remove_return_line_bonus(s_gnl, buf[fd]);
	free(s_gnl->save_buf);
	free(s_gnl);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:34:25 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/17 18:17:37 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line_read(t_gnl *s_gnl, char *buf)
{
	int	i;

	i = 0;
	while (*(buf + i) && *(buf + i) != '\n')
		i++;
	if (*(buf + i) == '\n')
	{
		s_gnl->lineread = i;
		return (1);
	}
	s_gnl->lineread = i;
	return (0);
}

char	*ft_strdup_gnl(t_gnl *s_gnl, char *buf)
{
	int		i;

	i = 0;
	s_gnl->save_buf = ft_calloc_gnl(s_gnl->read_size + s_gnl->start);
	while (i < s_gnl->read_size + s_gnl->start)
	{
		*(s_gnl->save_buf + i) = *(buf + i);
		i++;
	}
	free(buf);
	buf = ft_calloc_gnl(s_gnl->read_size + BUFFER_SIZE + s_gnl->start + 1);
	i = 0;
	while (i < s_gnl->read_size + s_gnl->start)
	{
		*(buf + i) = *(s_gnl->save_buf + i);
		i++;
	}
	*(buf + i) = 0;
	free(s_gnl->save_buf);
	return (buf);
}

char	*ft_realloc(t_gnl *s_gnl, char *buf)
{
	s_gnl->read_size = s_gnl->read_size + s_gnl->output;
	if (!s_gnl->read_size && !s_gnl->start)
	{
		buf = ft_calloc_gnl(BUFFER_SIZE);
		return (buf);
	}
	buf = ft_strdup_gnl(s_gnl, buf);
	if (s_gnl->read_size > 0)
		buf = ft_strjoin_gnl(s_gnl, buf);
	return (buf);
}

char	*ft_strjoin_gnl(t_gnl *s_gnl, char *buf)
{
	int	i;
	int	index_buf;

	i = 0;
	index_buf = s_gnl->start + s_gnl->read_size - s_gnl->output;
	while (i < s_gnl->output)
	{
		*(buf + i + index_buf) = *(s_gnl->temp_buf + i);
		i++;
	}
	return (buf);
}

char	*ft_calloc_gnl(size_t nmemb)
{
	void	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	size = sizeof(char);
	if (nmemb == 0)
		return (malloc(0));
	if ((nmemb * size) > 2147483647 || nmemb > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return ((char *)ptr);
}

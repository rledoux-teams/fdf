/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:31:03 by rledoux           #+#    #+#             */
/*   Updated: 2023/02/01 19:47:39 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_gnl
{
	char	*save_buf;
	char	*temp_buf;
	int		lineread;
	int		read_size;
	int		output;
	int		start;
}	t_gnl;

char	*get_next_line(int fd);
int		is_line_read(t_gnl *s_gnl, char *buf);
char	*ft_realloc(t_gnl *s_gnl, char *buf);
char	*ft_strjoin_gnl(t_gnl *s_gnl, char *buf);
char	*ft_strdup_gnl(t_gnl *s_gnl, char *buf);
char	*return_first_line(t_gnl *s_gnl, char *buf);
char	*remove_return_line(t_gnl *s_gnl, char *buf);
char	*is_data_in_buf(t_gnl *s_gnl, char *buf);
char	*read_data(t_gnl *s_gnl, char *buf, int fd);
char	*ft_calloc_gnl(size_t nmemb);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif

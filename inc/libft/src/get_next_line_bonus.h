/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:31:03 by rledoux           #+#    #+#             */
/*   Updated: 2023/01/17 18:17:59 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
int		is_line_read_bonus(t_gnl *s_gnl, char *buf);
char	*ft_realloc_bonus(t_gnl *s_gnl, char *buf);
char	*ft_strjoin_bonus(t_gnl *s_gnl, char *buf);
char	*ft_strdup_bonus(t_gnl *s_gnl, char *buf);
char	*return_first_line_bonus(t_gnl *s_gnl, char *buf);
char	*remove_return_line_bonus(t_gnl *s_gnl, char *buf);
char	*is_data_in_buf_bonus(t_gnl *s_gnl, char *buf);
char	*read_data_bonus(t_gnl *s_gnl, char *buf, int fd);
char	*ft_calloc_bonus(size_t nmemb);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif

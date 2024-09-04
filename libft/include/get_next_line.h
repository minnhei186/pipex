/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:23:24 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 13:01:21 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/select.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		gnl_strlen(char *str);
char	*gnl_strchr(char *str, char find_c);
char	*gnl_strjoin(char *left_str, char *right_str);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_double_free(char **pt_1, char **pt_2);

#endif

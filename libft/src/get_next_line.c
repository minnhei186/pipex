/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:22:56 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 13:01:59 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_loop_by_nl(int fd, char *prosess_line, char *buff)
{
	int		read_byte_len;
	char	*temp_line;

	read_byte_len = -1;
	while ((gnl_strchr(prosess_line, '\n') == NULL) && (read_byte_len != 0))
	{
		read_byte_len = read(fd, buff, BUFFER_SIZE);
		if (read_byte_len == -1)
		{
			free(prosess_line);
			return (NULL);
		}
		buff[read_byte_len] = '\0';
		temp_line = prosess_line;
		prosess_line = gnl_strjoin(temp_line, buff);
		if (!prosess_line)
		{
			free(temp_line);
			temp_line = NULL;
			return (NULL);
		}
		free(temp_line);
		temp_line = NULL;
	}
	return (prosess_line);
}

char	*read_by_nline(int fd, char *prosess_line)
{
	char	*buff;

	if (prosess_line == NULL)
	{
		prosess_line = (char *)malloc(sizeof(char) * 1);
		if (prosess_line == NULL)
			return (NULL);
		prosess_line[0] = '\0';
	}
	buff = (char *)gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (gnl_double_free(&prosess_line, &buff));
	prosess_line = read_loop_by_nl(fd, prosess_line, buff);
	if (prosess_line == NULL)
		return (gnl_double_free(&prosess_line, &buff));
	free(buff);
	buff = NULL;
	return (prosess_line);
}

char	*cut_by_nl(char *prosess_line)
{
	int		len_by_nl;
	char	*out_line;

	len_by_nl = 0;
	while ((prosess_line)[len_by_nl] && (prosess_line)[len_by_nl] != '\n')
		len_by_nl++;
	out_line = (char *)gnl_calloc(len_by_nl + 2, sizeof(char));
	if (!out_line)
		return (NULL);
	len_by_nl = 0;
	while ((prosess_line)[len_by_nl] && (prosess_line)[len_by_nl] != '\n')
	{
		out_line[len_by_nl] = (prosess_line)[len_by_nl];
		len_by_nl++;
	}
	if ((prosess_line)[len_by_nl] == '\n')
		out_line[len_by_nl++] = '\n';
	out_line[len_by_nl] = '\0';
	return (out_line);
}

char	*reshape_line(char *prosess_line)
{
	int		after_nl_len;
	int		i;
	char	*nl_pt;
	char	*reshape_line;

	nl_pt = gnl_strchr(prosess_line, '\n');
	nl_pt++;
	after_nl_len = gnl_strlen(nl_pt);
	reshape_line = (char *)gnl_calloc((after_nl_len + 2), sizeof(char));
	if (!reshape_line)
		return (NULL);
	i = 0;
	while (i < after_nl_len)
	{
		reshape_line[i] = nl_pt[i];
		i++;
	}
	reshape_line[i] = '\0';
	free(prosess_line);
	prosess_line = NULL;
	return (reshape_line);
}

char	*get_next_line(int fd)
{
	char		*out_line;
	static char	*prosess_line;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (gnl_double_free(&prosess_line, NULL));
	prosess_line = read_by_nline(fd, prosess_line);
	if (prosess_line == NULL)
		return (NULL);
	out_line = cut_by_nl(prosess_line);
	if (out_line == NULL)
		return (gnl_double_free(&prosess_line, &out_line));
	else if (out_line[0] == '\0')
		return (gnl_double_free(&prosess_line, &out_line));
	if (gnl_strchr(prosess_line, '\n') == NULL)
	{
		gnl_double_free(&prosess_line, NULL);
		return (out_line);
	}
	else
	{
		prosess_line = reshape_line(prosess_line);
		if (prosess_line == NULL)
			return (gnl_double_free(&prosess_line, &out_line));
	}
	return (out_line);
}

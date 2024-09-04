/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:14:43 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 13:02:13 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_double_free(char **pt_1, char **pt_2)
{
	if (pt_1 && *pt_1 != NULL)
	{
		free(*pt_1);
		*pt_1 = NULL;
	}
	if (pt_2 && *pt_2 != NULL)
	{
		free(*pt_2);
		*pt_2 = NULL;
	}
	return (NULL);
}

int	gnl_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strchr(char *str, char find_c)
{
	if (!str)
		return (NULL);
	if (find_c == '\0')
		return ((char *)&str[gnl_strlen(str)]);
	while (*str)
	{
		if (*str == find_c)
			return (str);
		str++;
	}
	return (NULL);
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*headp;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	if (p == NULL)
		return (0);
	headp = p;
	while (i < count * size)
	{
		*p = 0;
		p++;
		i++;
	}
	return (headp);
}

char	*gnl_strjoin(char *left_str, char *right_str)
{
	int		i;
	int		j;
	char	*join_str;

	i = 0;
	j = 0;
	i = gnl_strlen(left_str);
	j = gnl_strlen(right_str);
	join_str = (char *)gnl_calloc((i + j + 1), sizeof(char));
	if (!join_str)
		return (NULL);
	i = 0;
	while (left_str[i])
	{
		join_str[i] = left_str[i];
		i++;
	}
	j = 0;
	while (right_str[j])
	{
		join_str[i] = right_str[j];
		i++;
		j++;
	}
	return (join_str);
}

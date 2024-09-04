/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:31:02 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 12:57:00 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_pf_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_pf_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(STDOUT_FILENO, str, ft_pf_strlen(str));
	return ;
}

char	*ft_pf_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*p;
	char	*phead;

	i = 0;
	len = ft_pf_strlen(s1);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	phead = p;
	while (i < len)
	{
		*p = *s1;
		p++;
		s1++;
		i++;
	}
	*p = '\0';
	return (phead);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:50:26 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 17:19:43 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = (char *)ft_calloc((len + 1), 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s + (start), len + 1);
	return (p);
}

//#include <stdio.h>
//#include <string.h>
//#include <libc.h>
//int main(void)
//{
//	char *str = "tripouille";
//
//	char *dest= ft_substr(str, 0, 42000);
//	int dest_len = strlen(dest);
//	printf("%s[%d]\n",dest, dest_len);
//	return (0);
//}

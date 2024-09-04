/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:24:38 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 17:58:49 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*p;
	char	*phead;

	i = 0;
	len = ft_strlen(s1);
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

//#include <stdio.h>
//#include <string.h>
//
//#define STR "string"
//
//int main(void)
//{
//  char *s, *t;
//
//  s = ft_strdup(STR);
//  printf("s = %s\n", s);
//
//  t = strndup(STR, 3);
//  printf("t = %s\n", t);
//
//  return (0);
//}

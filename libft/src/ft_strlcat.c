/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:25:47 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/07/27 12:56:20 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t destsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;
	char	*d;

	if (dest == NULL && destsize == 0)
		return (ft_strlen(str));
	slen = ft_strlen(str);
	dlen = ft_strlen(dest);
	d = dest + dlen;
	i = 0;
	if (destsize <= dlen)
		return (slen + destsize);
	else
	{
		while (i < destsize - dlen - 1 && *str != '\0')
		{
			*d = *str;
			d++;
			str++;
			i++;
		}
		*d = '\0';
	}
	return (dlen + slen);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char src[]="1234";
//	char dest[20]="ABCDE";
//
//	unsigned int result=ft_strlcat(dest,src,7);
//
//	printf("dest:%s,result=%u\n",dest,result);
//
//	return (0);
//}

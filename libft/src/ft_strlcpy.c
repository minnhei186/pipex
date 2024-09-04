/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:16 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 17:59:31 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (destsize == 0)
	{
		return (len);
	}
	while (i < destsize - 1 && *src != '\0')
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (len);
}

//#include <stdio.h>
//#include <string.h>

//int main(void)
//{
//    char str1[] = "ABCDEF";
//    char str2[] = "123";
//    char *p = "abcd";
//
//    strcpy(str1, str2);     /* 文字型配列に文字型配列をコピー */
//    printf("%s\n", str1);
//
//    strcpy(str1, p);        /* 文字型配列にポインタの指す文字列リテラルをコピー */
//    printf("%s\n", str1);
//
//    ft_strlcpy(str1, "xyz",3);    /* 文字型配列に文字列リテラルをコピー */
//    printf("%s\n", str1);
//
//    return (0);
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:42:13 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:46:48 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*tmp;
	size_t			i;
	unsigned char	c;

	c = (unsigned char)ch;
	tmp = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
		i++;
	}
	return (0);
}

//#include        <stdio.h>
//#include        <string.h>
//
//int main(void)
//{
//        char str[] = "abcdef\0ghij";    /* 途中に空文字のある文字列 */
//        char *p;
//
//        p = ft_memchr(str, 'h', 12);
//        printf("検索文字は文字列の%ld番目\n",p - str);
//
//        return (0);
//}

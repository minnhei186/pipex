/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:27:07 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:29:09 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*bsrc;
	unsigned char	*bdest;

	if ((buf1 == NULL && buf2 == NULL) || (n == 0))
		return (buf1);
	i = 0;
	bdest = (unsigned char *)buf1;
	bsrc = (unsigned char *)buf2;
	while (i < n)
	{
		*bdest = *bsrc;
		bdest++;
		bsrc++;
		i++;
	}
	return (buf1);
}

//#include        <stdio.h>
//#include        <string.h>
//
//int main(void)
//{
//        char str1[128] = {1,1,1,1,1,1,1};
//        char str2[] = "ab\0cde";        /* 途中に空文字のある文字列 */
//        int i;
//		i=0;
//
//        printf("コピー前　中身の確認\n");
//        printf("%s ",str1);
//        printf("\n");
//
//       ft_memcpy(str1, str2, 5);
//
//        printf("コピー後　中身の確認\n");
//        printf("%s ",str1);
//        printf("\n");
//
//        return (0);
//}
//

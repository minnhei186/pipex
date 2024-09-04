/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:35:27 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:48:04 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(unsigned char *s1mem, unsigned char *s2mem, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*s1mem != *s2mem)
			return ((int)*s1mem - (int)*s2mem);
		s1mem++;
		s2mem++;
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1mem;
	unsigned char	*s2mem;

	s1mem = (unsigned char *)s1;
	s2mem = (unsigned char *)s2;
	return (ft_cmp(s1mem, s2mem, n));
}

//#include        <stdio.h>
//#include        <string.h>
//
//int main(void)
//{
//        char buf1[] = "\0abc\0de";      /* 途中に空文字のある文字列 */
//        char buf2[] = "\0abc\0de";
//        char buf3[] = "\0abcdef";
//
//        if (memcmp(buf1, buf2, 7) == 0)
//                printf("buf1 = buf2\n");
//        else
//                printf("buf1 != buf2\n");
//
//        if (memcmp(buf1, buf3, 7) == 0)
//                printf("buf1 = buf3\n");
//        else
//                printf("buf1 != buf3\n");
//
//        return (0);
//}

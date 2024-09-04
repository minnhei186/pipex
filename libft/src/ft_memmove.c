/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:21:45 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/10 15:32:57 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*not_dup(unsigned char *bdest, unsigned char *bsrc, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = bdest;
	i = 0;
	while (i < n)
	{
		*bdest = *bsrc;
		bsrc++;
		bdest++;
		i++;
	}
	return (tmp);
}

static void	*my_dup(unsigned char *bdest, unsigned char *bsrc, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = bdest;
	i = 0;
	bdest = bdest + n - 1;
	bsrc = bsrc + n - 1;
	while (i < n)
	{
		*bdest = *bsrc;
		bsrc--;
		bdest--;
		i++;
	}
	return (tmp);
}

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*bdest;
	unsigned char	*bsrc;

	if (((buf1 == NULL) && (buf2 == NULL)) || n == 0)
		return (buf1);
	bdest = (unsigned char *)buf1;
	bsrc = (unsigned char *)buf2;
	if (bdest <= bsrc)
	{
		return (not_dup(bdest, bsrc, n));
	}
	return (my_dup(bdest, bsrc, n));
}

// //#include        <stdio.h>
// //#include        <string.h>
// //
// //int main(void)
// //{
// //        char str[] = "abcdefghijklmnopqrstu";
// //
// //        printf("移動前：%s\n",str);
// //		ft_memmove(str+5,str,10);
// //        printf("移動後：%s\n",str);
// //
// //        return (0);
// //}

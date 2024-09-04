/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:21:41 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/05/29 17:40:04 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = '\0';
		i++;
		p++;
	}
}

//#include        <stdio.h>
//#include        <string.h>
//
//int main(void)
//{
//        char str[] = "0123456789";
//
//        ft_bzero(str,2);
//
//        printf("%s\n",str);
//
//        return (0);
//}

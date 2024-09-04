/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:46:46 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:26:55 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[];
//
//	str[] = "0123456789";
//	ft_memset(str + 2, '*', 5);
//	printf("%s\n", str);
//	return (0);
//}

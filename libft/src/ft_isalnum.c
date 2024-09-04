/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:36:43 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:22:39 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

//#include <ctype.h>
//#include <limits.h>
//#include <stdio.h>
//
//int	main(void)
//{
//	for (int i = 0; i < UCHAR_MAX; ++i)
//	{
//		if (isalnum(i))
//		{
//			printf("%c (%d)\n", i, isalnum(i));
//		}
//		if (ft_isalnum(i))
//		{
//			printf("%c (%d)\n", i, isalnum(i));
//		}
//	}
//}

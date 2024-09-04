/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:35:21 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/05/30 13:58:27 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//#include <ctype.h>
//#include <limits.h>
//
//int main(void)
//{
//    for (int i = 0; i < UCHAR_MAX; ++i) {
//        if (isprint(i)) {
//            printf("%c (%x)\n", i, i);
//		}
//		if(ft_isprint(i)){
//				printf("%c (%x)\n", i, i);
//        }
//    }
//}
